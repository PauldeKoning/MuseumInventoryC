#pragma once
#include "Item.h"
#include "Question.h"
class Inspect
{
private:
	Item item;

	void printQuestions()
	{
		Question** arr = NULL;
		int sizeArr;

		item.inspection.questions.createQuestionsArr(arr, sizeArr);

		for (int i = 0; i < sizeArr; i++)
		{
			std::cout << arr[i]->question << " - " << arr[i]->answer << "\n";
		}

	}

	void answerQuestions()
	{
		if (item.inspection.questions.count() == 0) return;

		while (true)
		{
			Question* question = item.inspection.questions.dequeue();;
			question->getUserAnswer();
			item.inspection.questions.enqueue(question);

			std::cout << "Would you like to continue? [Y/n]\n";

			char option;

			std::cin >> option;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (option == 'n') break;
		}
	}

	void answerQuestions(bool unanswered)
	{
		if (item.inspection.questions.count() == 0) return;
		int failed = 0;
		while (true && failed <= item.inspection.questions.count())
		{
			Question* question = item.inspection.questions.dequeue();;
			if (unanswered && question->answer == "")
			{
				question->getUserAnswer();
				item.inspection.questions.enqueue(question);

				std::cout << "Would you like to continue? [Y/n]\n";

				char option;

				std::cin >> option;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				if (option == 'n') break;
				failed = 0;
			}
			else
			{
				item.inspection.questions.enqueue(question);
				failed++;
			}
		}
	}
public:
	Inspect(Item item)
	{
		this->item = item;
	}

	void show()
	{
		std::cout << "You are currently inspecting item: " + this->item.name + "\n";
		std::cout << "a - Answer questions\n";
		std::cout << "s - Answer unanswered questions only\n";
		std::cout << "e - Get list of all questions and answers\n";
		std::cout << "x - Exit back to item overview\n";

		char option;

		std::cin >> option;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << option << " chosen\n\n";

		switch (option)
		{
		case 'a':
			std::cout << "Answer questions\n";
			answerQuestions();
			break;
		case 's':
			std::cout << "Answer unanswered questions!\n";
			answerQuestions(true);
			break;
		case 'e':
			std::cout << "Get list of all questions and answers!\n";
			printQuestions();
			break;
		case 'x':
			std::cout << "Exiting back to item overview!\n";
			return;
		default:
			std::cout << "Character was not valid. Please try again!\n";
			break;
		}

		std::cout << "\n\n";

		return show();
	}
};

