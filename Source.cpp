#pragma once
#include<iostream>

template <typename T>
class Stack{

struct Node{
        T data;
        Node *down;

        Node()
        {
            down = NULL;
        }
    }*top;


public:

Stack(){
    top = NULL;
    }
        
        
void push(T data){
        Node *temp = new Node;
        temp->data = data;

        if(top == NULL)
        top = temp;
        else
        {
            temp->down = top;
            top = temp;
        }
    }


void pop(){
    Node *temp = top;
    top = top->down;
    delete temp;
    }
T returnTop(){
        return top->data;
    }
        

bool isEmpty(){
        if(top == NULL)
        return true;
        else return false;
    }
        
        
int search(T data){
        Node *temp = top;
        int count = 0;
        while(temp){
            if(temp->data == data)
                return count;
            count++;
            temp = temp->down;
        }
        return -1;
    }


~Stack()
{
    while(temp)
    {
        Node *temp = top;
        top = top->next;
        std::cout<<"Deleted "<<temp->data<<"\n";
        delete temp;
    }
}
};


int main()
    {
        Stack<int> S;
    S.push(3);
    S.push(4);
    S.push(23);
    S.push(31);
    return 0;
    
}