#pragma once

#include "LinkedNode.h";
template <typename T>
class LinkedListQueue
{
private:
	int size = 0;
	LinkedNode<T> head;
	LinkedNode<T> tail;
public:
	T peek() 
	{
		return &this->head;
	}

	void enqueue(T item)
	{
		this->tail->next = item;
		this->tail = this->tail->next;
		this->size++;
	}

	T dequeue()
	{
		if (this->size == 0)
		{
			return 0;
		}

		LinkedNode temp = &this->head;
		this->head = this->head.next;

		this->size--;
	}

	int count()
	{
		return this->size;
	}
};

