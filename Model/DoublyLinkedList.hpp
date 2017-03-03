//
//  DoublyLinkedList.hpp
//  AfternoonMegaData
//
//  Created by Morris, Seth on 3/1/17.
//  Copyright © 2017 Morris, Seth. All rights reserved.
//

#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h
#include "BiDirectionalNode.hpp"

template <class Type>
class DoublyLinkedList
{
private:
    BiDirectionalNode<Type> * front;
    BiDirectionalNode<Type> * end;
    int size;
public:
    DoublyLinkedList();
    virtual ~DoublyLinkedList() = 0;
    int getSize() const;
    BiDirectionalNode<Type> * getFront() const;
    BiDirectionalNode<Type> * getEnd() const;

    virtual void add(Type data) = 0;
    virtual Type remove(int index) = 0;
    
    void setFront(BiDirectionalNode<Type> * front);
    void setSize(int updated);
    void setEnd(BiDirectionalNode<Type> * end);
};

template <class Type>
DoublyLinkedList<Type> :: DoublyLinkedList()
{
    size = 0;
    front = nullptr;
    end = nullptr;
}

template <class Type>
DoublyLinkedList<Type> :: ~DoublyLinkedList()

template <class Type>
int DoublyLinkedList<Type> :: getSize()
{
    return size;
}

template <class Type>
BiDirectionalNode<Type> * DoublyLinkedList<Type> :: getFront()
{
    return front;
}

template <class Type>
BiDirectionalNode<Type> * DoublyLinkedList<Type> :: getEnd()
{
    return end;
}

template <class Type>
BiDirectionalNode<Type> * DoublyLinkedList<Type> :: getSize()
{
    return size;
}

template <class Type>
BiDirectionalNode<Type> * DoublyLinkedList<Type> :: setFront()
{
    this->front = front;
}

template <class Type>
BiDirectionalNode<Type> * DoublyLinkedList<Type> :: setEnd()
{
    this->end = end;
}

template <class Type>
BiDirectionalNode<Type> * DoublyLinkedList<Type> :: setSize()
{
    this->size = size;
}

#endif /* DoublyLinkedList_h */
