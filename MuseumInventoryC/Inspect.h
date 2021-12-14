#pragma once
#include "Item.h"
#include "Question.h"
class Inspect
{
private:
	Item item;

	void printQuestions()
	{
		// Create a pointer of a question pointer and an array size value
		Question** arr = NULL;
		int sizeArr;

		// Pass the pointer and int to function that initializes an array and returns size
		item.inspection.questions.createQuestionsArr(arr, sizeArr);

		// Loop over the array and print a summary of questions
		for (int i = 0; i < sizeArr; i++)
		{
			std::cout << arr[i]->question << " - " << arr[i]->answer << "\n";
		}
	}

	void answerQuestions()
	{
		// Return if there are no questions in the list
		if (item.inspection.questions.count() == 0) return;

		while (true)
		{
			// Get question and ask for answer
			Question* question = item.inspection.questions.dequeue();;
			question->getUserAnswer();
			item.inspection.questions.enqueue(question);

			// Ask whether the user would like to continue
			std::cout << "Would you like to continue? [Y/n]\n";

			char option;

			std::cin >> option;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (option == 'n') break;
		}
	}

	void answerQuestions(bool unanswered)
	{
		// Return if there are no questions in the list
		if (item.inspection.questions.count() == 0) return;

		// Loop through the questions. Quit when no unanswered questions are found.
		int failed = 0;
		while (failed <= item.inspection.questions.count())
		{
			// Remove one question from the queue
			Question* question = item.inspection.questions.dequeue();;
			if (unanswered && question->answer == "")
			{
				// Get answer
				question->getUserAnswer();
				item.inspection.questions.enqueue(question);
				// Check whether the user would like to continue looping through unanswered questions
				std::cout << "Would you like to continue? [Y/n]\n";

				char option;

				std::cin >> option;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				if (option == 'n') break;
				failed = 0;
			}
			else
			{
				// If item is answered, enqueue item again and increase 'failed' loop
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

