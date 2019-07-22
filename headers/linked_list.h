#pragma once

#include<iostream>

template <typename T>
struct Node
{
    T data;
    Node *next;
};

template <typename T>
class linkedList
{    
private:
    Node<T> *head, *tail;
public:

    linkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void add(T data)
    {
        Node<T> *temp = new Node<T>;
        temp->data = data;
    
        if(head == nullptr)
        {
            head = temp;
            tail = temp;
            temp->next = nullptr; 
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

  void print()
  {
    Node<T> *temp;
    temp = head;
    while(temp != tail->next)
    {
        std::cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    std::cout<<"null\n";
  }

  void remove(int index)
  {
    Node<T> *temp, *tempPrev;
    tempPrev = head;
    temp = head->next;
    int count = 0;

    if(index == 0)
    {
        head = head->next;
        delete tempPrev;
    }
    else
    {
        while(++count != index || temp == nullptr)
        {
            tempPrev = temp;
            temp = temp->next;
        }
		if (temp != nullptr)
		{
			tempPrev->next = temp->next;
			delete temp;
		}
    }
  }

    ~linkedList()
    {
        Node<T> *temp;
        temp = head;
        while(head != tail)
        {   
            temp = head;
            head = head->next;
            delete temp;
        }
		delete head;
    }
};