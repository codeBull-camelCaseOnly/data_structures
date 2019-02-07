#pragma once
#include<memory>
#include<iostream>

template <typename T>
class BinarySearchTree{

struct Node{
        T data;
        Node *left, *right;

        Node()
        {
            left = right = NULL;
        }

        void print(){
            if(left != NULL)
                left->print();
            std::cout << data <<" ";
            if(right != NULL)
                right->print();
        }
    }*root;



public:
BinarySearchTree(){
        root = NULL;
    }
void insert(T data){
        bool added = false;
        Node *temp = new Node();
        //std::unique_ptr<Node> temp(new Node());
        temp->data = data;

        Node *top = root;

        while(!added)
        {
            if(top = NULL)
            {
                top = temp;   
            }
            else
            {
                    if(top->data <= data){
                        if(top->left = NULL)
                            top->left = temp;
                        else
                            top = top->left;
                    }

                    else{
                        if(top->right = NULL)
                            top->right = temp;
                        else
                            top = top->right;
                    }
            }
            
        }


    }



void print(){
        root->print();
    }
};