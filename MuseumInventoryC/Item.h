#pragma once
#include <string>
#include "Inspection.h"

class Item
{
public:
	std::string name;
	std::string description;
	std::string date;
	std::string region;
	Inspection inspection;

	void toString(std::string* str, bool compact = true)
	{
		if (compact)
		{
			*str += this->name + " - " + this->description + "\n";
		}
		else
		{
			*str += "Name: " + this->name + "\n";
			*str += "Description: " + this->description + "\n";
			*str += "Date: " + this->date + "\n";
			*str += "Region: " + this->region + "\n";
		}
	}
};


