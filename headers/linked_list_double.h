#pragma once
#include<iostream>

template <typename T>
struct Node
{
    T data;
    Node *next, *prev;
};

template <typename T>
class doubleLinkedList
{
private:
    Node<T> *top, *last;
public:
    doubleLinkedList()
    {
        top = nullptr;
		last = nullptr;
    }

    void addAtBegin(T data)
    {
        Node<T> *temp = new Node<T>;

        temp->data = data;
		temp->prev = nullptr;
        temp->next = top;
		if (top != nullptr)
			top->prev = temp;
		else
			last = temp;
        top = temp;
    }

	void addAtLast(T data)
	{
		Node<T> *temp = new Node < T > ;
		
		temp->data = data;
		temp->prev = last;
		temp->next = nullptr;
		if (last != nullptr)
			last->next = temp;
		else
			top = temp;
		last = temp;
	}

	void deleteAtBegin()
	{
        if(top != nullptr)
        {
            Node<T> *temp;
            temp = top;
            top = top->next;
			top->prev = nullptr;
            delete temp;
        }
	}

	void deleteAtLast()
	{
        if(last != nullptr)
        {
            Node<T> *temp;
            temp = last;
            last = last->prev;
			last->next = nullptr;
            delete temp;
        }
	}

    void displayFromBegin()
    {
        Node<T> *temp;
        temp = top;
        while(temp != nullptr)
        {
            std::cout<<temp->data;
			if (temp->next != nullptr)
				std::cout << " <---> ";
            temp = temp->next;
        }
		std::cout << "\n";
    }


    void displayFromLast()
    {
        Node<T> *temp;
        temp = last;
        while(temp != nullptr)
        {
            std::cout<<temp->data;
			if (temp->prev != nullptr)
				std::cout << " <---> ";
            temp = temp->prev;
        }
		std::cout << "\n";
    }

    T getElementFromBegin(int index)
    {
        Node<T> *temp;
        temp = top;
        int count = 0;
		while (index > size)
			index -= size;
		while (index < 0)
			index += size;
        while(count != index)
        {
			count++;
            temp = temp->next;
        }
		return temp->data;
    }

    T getElementFromLast(int index)
    {
        Node<T> *temp;
        temp = last;
        int count = 0;
		while (index > size)
			index -= size;
		while (index < 0)
			index += size;
        while(count != index)
        {
			count++;
            temp = temp->prev;
        }
		return temp->data;
    }

	void insertFromBegin(T data, int index)
	{
		Node<T> *temp;
		temp = top;
		int count = 0;
		while (count != index)
		{
			count++;
			temp = temp->next;
			if (temp == nullptr)
				temp = top;
		}
		Node<T> *newNode = new Node < T > ;
		newNode->data = data;
		newNode->prev = temp;
		newNode->next = temp->next;
		(temp->next)->prev = newNode;
		temp->next = newNode;
	}

	void insertFromLast(T data, int index)
	{
		Node<T> *temp;
		temp = last;
		int count = 0;
		while (count++ != index)
		{
			temp = temp->prev;
			if (temp == nullptr)
				temp = last;
		}
		Node<T> *newNode = new Node < T >;
		newNode->data = data;

		newNode->next = temp;
		newNode->prev = temp->prev;
		(temp->prev)->next = newNode;
		temp->prev = newNode;
	}

    ~doubleLinkedList()
    {
        Node<T> *temp;
		temp = top;
        while(top != nullptr)
        {
            temp = top;
            top = top->next;
            std::cout<<"deleted "<<temp->data<<"\n";
            delete temp;
        }
    }

};



















