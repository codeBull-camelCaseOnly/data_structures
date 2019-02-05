#pragma once

template <typename T>
class Queue{

struct Node{
        T data;
        Node *next;

        Node()
        {
            next = NULL;
        }
    }*front,*rear;


public:

Queue(){
    front = NULL;
    rear = NULL;
    }
    
void enqueue(T data){
        Node *temp = new Node;
        temp->data = data;

        if(front == NULL)
        {
            front = rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }

void dequeue(){
        Node *temp = front;
        front =front->next;
        delete temp;
    }
T getFront(){
        return front->data;
    }
bool isEmpty(){
        if(front == NULL)
            return true;
            else return false;
    }
~Queue(){
        while(temp)
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }
};