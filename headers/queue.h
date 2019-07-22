#pragma once
#include<iostream>


template <typename T>
struct Node
{
	T data;
	Node *next;
};

template <typename T>
class queue
{
private:
	Node<T> *front, *rear;
public:
	queue()
	{
		front = rear = nullptr;
	}

	void insert(T data)
	{
		Node<T> *temp = new Node<T>;
		temp->data = data;

		if (front == nullptr)
		{
			front = temp;
			rear = temp;
			rear->next = nullptr;
		}
		else
		{
			rear->next = temp;
			rear = temp;
			rear->next = nullptr;
		}
	}

	void qdelete()
	{
		Node<T> *temp;
		temp = front;
		if (temp != nullptr)
		{
			front = front->next;
			delete temp;
		}
	}

	void display()
	{
		Node<T> *temp;
		temp = front;
		while (temp != nullptr)
		{
			std::cout << temp->data;
			if (temp->next != nullptr)
				std::cout << " ---> ";
			temp = temp->next;
		}
	}

	~queue()
	{
		Node<T> *temp;
		while (front != nullptr)
		{
			temp = front;
			front = front->next;
			delete temp;
		}
	}
};


