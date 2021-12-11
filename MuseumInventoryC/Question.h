#pragma once

#include <string>
class Question
{
protected:
	virtual bool validateUserInput(std::string input) = 0;
public:
	std::string name;
	std::string question;
	std::string answer;
	virtual void getUserAnswer() = 0;
};

