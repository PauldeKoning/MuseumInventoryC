#pragma once
#include "Item.h"
#include <iostream>
class ItemTools
{
public:
	Item binarySearch(Item items[], int size, std::string x) 
	{
		// Set a return item, low, high and amount of tries.
		Item result;
		int low = 0;
		int high = size;
		int tries = size / 2; // Try a maximum of half the 

		while (low <= high) {
			// Set the middle of the high and low guess
			int mid = (int)floor((high - low) / 2.0);

			// If item is found, set result to item
			if (items[mid].name == x)
			{
				result = items[mid];
			}
			
			// If item is lower than found set low to guess
			if (items[mid].name < x)
			{
				low = mid;
			}
			else // ELse it is higher, high low to guess
			{
				high = mid;
			}

			// Remove one from tries and break if too many tries have occurred
			tries--;
			if (tries <= 0) break;
		}

		return result;
	}

	void bubbleSort(Item items[], int size)
	{
		// Set sorted amount
		int sorted = 0;
		while (sorted < size - 1) // Loop over array if not sorted
		{
			// Reset sorted amount
			sorted = 0;
			// Nested loop over array
			for (int i = 0; i < size - 1; i++) 
			{
				// If name is alphabetically higher than next index swap
				if (items[i].name > items[i + 1].name)
				{
					Item temp = items[i];
					items[i] = items[i + 1];
					items[i + 1] = temp;
				}
				else // Else its sorted, add one to sorted
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

