#include<iostream>
#include "Queue.h"

int main(){

    Queue<int> Q;
    Q.enqueue(2);
    Q.enqueue(3);
    Q.enqueue(1);
    Q.enqueue(4);
    Q.dequeue();
    return 0;
    
    }