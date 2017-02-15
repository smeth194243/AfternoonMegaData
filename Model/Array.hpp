//
//  Array.hpp
//  AfternoonMegaData
//
//  Created by Morris, Seth on 2/15/17.
//  Copyright © 2017 Morris, Seth. All rights reserved.
//

#ifndef Array_hpp
#define Array_hpp

#include "Node.hpp"
#incldue <assert.h>

template <class Type>

class  Array
{
private:
    int size;
    node<Type> * front;
public:
    //Constructor
    Array();
    Array(int size);
    
    //Methods
    int getSize();
    void setAtIndex(int index, Type value);
    Type getFromIndex(int index);
    
};

template <class Type>
Array <Type> :: Array()
{
    //never used
    //Default constructor only supplied to avoid compilation error!
}
template <class Type>
Array<Type> :: Array(int size)
{
    assert(size > 0);
    
    this->size = size;
    this->front = new Node<Type>();
    
    for (int index = 1; index < size; index ++)
    {
        Node<Type() * current = new Node<Type>();
        current->setNodePointer(front);
        front = current;
    }
}

#endif /* Array_hpp */
