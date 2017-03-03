//
//  Queue.hpp
//  AfternoonMegaData
//
//  Created by Morris, Seth on 3/3/17.
//  Copyright © 2017 Morris, Seth. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include "DoublyLinkedList.hpp"

template <class Type>
class Queue : public  DoublyLinkedList<Type>
{
private:
    
public:
    Queue();
    ~Queue();
    void add(Type data);
    Type remove(int index);
    void enqueue(Type data);
    Type dequeue();
    Type peek();
}
#endif /* Queue_h */
