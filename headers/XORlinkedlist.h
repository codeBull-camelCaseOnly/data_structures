#pragma once
#include<iostream>

template <typename T>
struct Node
{
    T data;
    Node *XORcode;
};

template <typename T>
Node<T> * XOR(struct Node<T> *x, struct Node<T> *y)
{
    return (Node<T>*)( (uintptr_t)(x) ^ (uintptr_t)(y) );
}


template <typename T>
class XORlinkedList
{
private:
    Node<T> *top, *last;
	int size;
public:
    XORlinkedList()
    {
        top = last = nullptr;
		size = 0;
    }

    void addAtBegin(T data)
    {
        Node<T> *temp = new Node<T>;
        temp->data = data;

		temp->XORcode = top;
        if(top != nullptr)
            top->XORcode = XOR(top->XORcode, temp);
		else last = temp;
        top = temp;

		size++;
    }

    void addAtLast(T data)
    {
        Node<T> *temp = new Node<T>;
        temp->data = data;

        temp->XORcode = last;
        if(last != nullptr)
            last->XORcode = XOR(last->XORcode, temp);
		else top = temp;
        last = temp;

		size++;
    }

	void displayFromBegin()
	{
		Node<T> *temp, *storeCode, *storer;
		temp = top;
		storeCode = nullptr;

		while (temp != nullptr)
		{
			std::cout << temp->data;
			storer = temp;
			temp = XOR(temp->XORcode, storeCode);
			if (temp != nullptr)
				std::cout << " <---> ";
			storeCode = storer;
		}
	}

	void displayFromLast()
	{
		Node<T> *temp, *storeCode, *storer;
		temp = last;
		storeCode = nullptr;

		while (temp != nullptr)
		{
			std::cout << temp->data;
			storer = temp;
			temp = XOR(temp->XORcode, storeCode);
			if (temp != nullptr)
				std::cout << " <---> ";
			storeCode = storer;
		}
	}

	void deleteFromBegin()
	{
		if (size != 0)
		{
			Node<T> *temp;
			temp = top;
			top = top->XORcode;
			top->XORcode = XOR(temp, top->XORcode);
			delete temp;
			size--;
		}
	}

	void deleteFromLast()
	{
		if (size != 0)
		{
			Node<T> *temp;
			temp = last;
			top = top->XORcode;
			top->XORcode = XOR(temp, top->XORcode);
			delete temp;
		}
	}

	T getElementFromBegin(int index)
	{
		Node<T> *temp, *storeCode, *storer;
		temp = top;
		storeCode = nullptr;
		int count = 0;
		while (index > size)
			index -= size;
		while (index < 0)
			index += size;
		while (count != index)
		{
			count++;
			storer = temp;
			temp = XOR(temp->XORcode, storeCode);
			storeCode = storer;
		}
		return temp->data;
	}


	T getElementFromLast(int index)
	{
		Node<T> *temp, *storeCode, *storer;
		temp = last;
		storeCode = nullptr;
		int count = 0;
		while (index > size)
			index -= size;
		while (index < 0)
			index += size;
		while (count != index)
		{
			count++;
			storer = temp;
			temp = XOR(temp->XORcode, storeCode);
			storeCode = storer;
		}
		return temp->data;
	}



    ~XORlinkedList()
    {
        Node<T> *temp, *storeCode;
        temp = top;
        storeCode = nullptr;

        while(top != nullptr)
        {
            temp = top;
            top = XOR(top->XORcode, storeCode);
            storeCode = temp;
            delete temp;
        }
    }
};





