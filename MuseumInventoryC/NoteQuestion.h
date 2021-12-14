#pragma once
#include "Question.h"
#include <iostream>
class NoteQuestion : public Question
{
protected:
	bool validateUserInput(std::string input)
	{
		return true; // Allow all user input
	}
public:
	NoteQuestion(std::string name, std::string question)
	{
		this->name = name;
		this->question = question;
	}

	void getUserAnswer()
	{
		// Get user input and print question
		std::string input;
		std::cout << "Name: " + name + "\n";
		std::cout << "This is a note question, please input any string of characters\n";
		std::cout << "Question: " + question + "\n";
		std::cin >> input;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear CIN buffer

		// If input is valid, set question answer to input
		if (validateUserInput(input))
		{
			answer = input;
		}
		else
		{ // Else ask again (recursive)
			std::cout << "User input was not valid, please type correct input";
			getUserAnswer();
		};
	}
};

