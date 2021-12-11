#pragma once

#include <iostream>
#include "LinkedNode.h"
class LinkedListQueue
{
private:
	int size;
	LinkedNode* head;
	LinkedNode* tail;
public:
	void enqueue(Question* item)
	{
		LinkedNode* node = new LinkedNode();
		node->data = item;

		if (this->size == 0)
		{
			this->head = node;
			this->tail = node;
		}
		else
		{
			this->tail->next = node;
			this->tail = node;
		}

		this->size++;
	}

	Question* dequeue()
	{
		if (this->size == 0)
		{
			return NULL;
		}

		Question* question = this->head->data;
		this->head = this->head->next;

		this->size--;

		return question;
	}

	int count()
	{
		return this->size;
	}

	void createQuestionsArr(Question**& arr, int& size)
	{
		arr = new Question*[this->size];
		size = this->size;
		for (int i = 0; i < this->size; i++)
		{
			arr[i] = dequeue();
			enqueue(arr[i]);
		}
	}
};

