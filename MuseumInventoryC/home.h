#pragma once
#include "Item.h"
#include "ItemTools.h"
#include "Inspect.h"
#include <iostream>
#include <limits>
#include <ios>
class Home
{
private:
	Item items[100];
	ItemTools tools;

	void createItem(Item item)
	{
		if (this->size == 100)
		{
			std::cout << "Maximum item count reached, cannot add more!\n";
			return;
		}

		Item search = this->tools.binarySearch(this->items, this->size, item.name);

		if (search.name == item.name)
		{
			std::cout << "Item name already exists, item not added!\n";
			return;
		}

		this->items[this->size] = item;

		this->tools.bubbleSort(this->items, this->size);

		this->size++;
	}

	Item getItem()
	{
		std::cout << "What item name would you like to get?\n";
		std::string input;
		std::cin >> input;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		return this->tools.binarySearch(this->items, this->size, input);
	}

	void showItems()
	{
		std::cout << "--------------------------------\n";
		for (int i = 0; i < this->size; i++)
		{
			std::string* str = new std::string();
			items[i].toString(str);
			std::cout << i + 1 << ": " + *str;
		}
		std::cout << "--------------------------------\n";
	}

	void removeItem(Item item)
	{
		if (this->size <= 0)
		{
			return;
		}

		bool removed = false;
		for (int i = 0; i < this->size; i++)
		{
			if (this->items[i].name == item.name)
			{
				this->items[i] = Item();
				removed = true;
			}
			else if (removed)
			{
				this->items[i - 1] = this->items[i];
			}
		}

		this->items[this->size - 1] = Item();
		this->size--;
	}

	void showInspect()
	{
		Inspect inspect = Inspect(getItem());
		inspect.show();
	}
public:
	static int size;

	Home() : items()
	{
		
	}

	void show() 
	{
		while (true)
		{
			std::cout << "Welcome to the museum inventory software. Please type an option to continue:\n";
			std::cout << "l - List all items\n";
			std::cout << "i - Go to item inspection\n";
			std::cout << "d - Delete an item\n";
			std::cout << "c - Create an item\n";

			char option;

			std::cin >> option;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << option << " chosen\n\n";

			switch (option)
			{
			case 'l':
				std::cout << "Listing all items...\n";
				showItems();
				break;
			case 'i':
				std::cout << "Inspect item!\n";
				showInspect();
				break;
			case 'd':
				std::cout << "Delete item!\n";
				removeItem(getItem());
				break;
			case 'c':
				std::cout << "Create a new item!\n";
				createItem(this->tools.createItemInput());
				break;
			default:
				std::cout << "Character was not valid. Please try again!\n";
				break;
			}

			std::cout << "\n\n";
		}

		return;
	}
};

