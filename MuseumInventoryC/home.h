#pragma once
#include "Item.h"
class Home
{
private:
	Item items[100];
	int size = 0;

public:
	void show() 
	{

	}

	void createItem(Item item)
	{
		this->items[this->size] = item;
		this->size++;
	}

	void getItem()
	{

	}
};

