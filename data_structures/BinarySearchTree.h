#pragma once
#include<memory>

template <typename T>
class BinarySearchTree{

struct Node{
        T data;
        std::unique_ptr<Node> left,right;
        //Same as "Node *left, *right" but More safer

    }*Root;


public:
void insert(T data)
bool search(T data)
void deleteLastNode
};