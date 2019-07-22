#pragma once
#include<iostream>

template <typename T>
struct Node
{
    T data;
    Node *prev;
};

template <typename T>
class Stack
{
private:
    Node<T> *top;
public:
    Stack()
    {
        top = nullptr;
    }

    void push(T data)
    {
        Node<T> *temp = new Node<T>;
        temp->data = data;
        
        temp->prev = top;
        top = temp;
    }

    void pop()
    {
        if(top != nullptr)
        {
            Node<T> *temp;
            temp = top;
            top = top->prev;
            delete temp;
        }
    }

    T peek()
    {
        return top->data;
    }

    ~Stack()
    {
        Node<T> *temp;
        while(top != nullptr)
        {
            temp = top;
            top = top->prev;
            delete temp;
        }
    }
};