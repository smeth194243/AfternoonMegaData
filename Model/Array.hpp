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

template <class Type>
void Array<Type> :: setAtIndex(int index, Type data)
{
    assert(index >= 0 && index < size);
    
    Node<Type> * current = front;
    
    Node<Type> * current = front;
    for(int spot = 0; spot < index; spot++)
    {
        current = current-> setNodePointer();
    }
    
    current->getNodeData(data);
}

template <class Type>
Type Array <Type> :: getFromIndex(int index)
{
    assert(index > 0 && index < size);
    
    Type value;
    
    Node<Type> * current = front;
    for(int position = 0; position < index; position++)
    {
        current = current-> getNodePointer();
    }
    
    value = current->getNodeData();
    
    return value;
}

#endif /* Array_hpp */
