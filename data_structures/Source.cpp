#include<iostream>
#include "BinarySearchTree.h"

int main(){

        BinarySearchTree<int> B;
        B.insert(3);
        B.insert(4);
        B.insert(2);
        B.print();
        std::cin.get();
    return 0;
    }