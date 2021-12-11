#pragma once
#include "Item.h"
#include <iostream>
class ItemTools
{
public:
	Item binarySearch(Item items[], int size, std::string x) 
	{
		// Binary search
		Item result;
		int lastMid = 0;
		int low = 0;
		int high = size;
		int tries = size / 2;

		while (low <= high) {
			int mid = (int)floor((high - low) / 2.0);

			if (items[mid].name == x)
			{
				result = items[mid];
			}

			if (items[mid].name < x)
			{
				low = mid;
			}
			else
			{
				high = mid;
			}

			tries--;
			if (tries <= 0) break;
		}

		return result;
	}

	void bubbleSort(Item items[], int size)
	{
		int sorted = 0;
		while (sorted < size - 1)
		{
			sorted = 0;
			for (int i = 0; i < size - 1; i++) 
			{
				if (items[i].name > items[i + 1].name)
				{
					Item temp = items[i];
					items[i] = items[i + 1];
					items[i + 1] = temp;
				}
				else
				{
					sorted++;
				}
			}
		}
	}

	Item createItemInput()
	{
		Item item;

		std::string name, description, date, region;

		this->getInput("What is the name of the item?", name);
		this->getInput("What is the description of the item?", description);
		this->getInput("What is the creation date of the item?", date);
		this->getInput("What is the region of the item?", region);

		item.name = name;
		item.description = description;
		item.date = date;
		item.region = region;

		return item;
	}

private:
	void getInput(std::string question, std::string &output)
	{
		std::string input;
		std::cout << question + "\n";
		std::cin >> input;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		output = input;
	}
};

