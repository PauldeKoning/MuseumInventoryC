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
	// Get a question of either Note or Binary type
	void enqueue(Question* item) 
	{
		// Create a new node and add data
		LinkedNode* node = new LinkedNode();
		node->data = item;

		// If first element set the head and tail to current node
		if (this->size == 0)
		{
			this->head = node;
			this->tail = node;
		}
		else // Else move up the tail
		{
			this->tail->next = node;
			this->tail = node;
		}

		// Increase size by one
		this->size++;
	}

	Question* dequeue()
	{
		// If the queue is empty return nothing
		if (this->size == 0)
		{
			return NULL;
		}

		// Get the pointer to the question and move the head up by one
		Question* question = this->head->data;
		this->head = this->head->next;

		// Decrease the size by one
		this->size--;

		// Return the pointer
		return question;
	}

	int count()
	{
		return this->size;
	}

	void createQuestionsArr(Question**& arr, int& size)
	{
		// Create an array of linked list size, set ref var size
		arr = new Question*[this->size];
		size = this->size;
		// Loop over linked list and fill array
		for (int i = 0; i < this->size; i++)
		{
			arr[i] = dequeue();
			enqueue(arr[i]);
		}
	}
};

