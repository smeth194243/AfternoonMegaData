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
};

template <class Type>
Queue<Type> :: Queue() : DoublyLinkedList()
{
    
}

Queue<Type> :: ~Queue()
{
    BiDirectionalNode<Type> * remove = this->getFront();
    while(remove != nullptr)
    {
        
    }
}

template <class Type>
void Queue<Type> :: add(Type value)
{
    enqueue(value);
}

/*
 Add to Queue:
 Create Node
 If First - adjust front
 else add to end
 move end 
 adjust size
 */

template <class Type>
void Queue<Type> :: enqueue(Type insertedValue)
{
    BiDirectionalNode<Type> * added = BiDirectionalNode<Type>(insertedValue);
    
    if(this->getSize() == 0 || this->getFront() == nullptr || this->getEnd() == nullptr)
    {
        this->setFront(added);
    }
    else
    {
        this->getEnd()->setNextPointer(added);
    }
    this->setEnd(added);
    this->setSize(this->getSize() + 1);
}


//Remove from Queue
//check valid index
//call dequeue

template <class Type>
Type Queue<Type> :: remove(int index)
{
    assert(index == 0 && this->getSize() > 0);
    return dequeue();
}

//check size
// if size == 1
//      adjust front/end to null
//else
//   move front to next
//delete node
//adjust size
//return value


template <class Type>
Type Queue<Type> :: dequeue()
{
    assert(this->getSize() > 0);
    
    Type removedValue = this->getFront()->getNodeData();
    BiDirectionalNode<type> * removeMe = front;
    
    if(this->getSize() == 1)
    {
        this->setFront(nullptr);
        this->setEnd(nullptr);
    }
    else
    {
        this->setFront(removeMe->getNextPointer());
    }
    delete removeMe;
    this->setSize(this->getSize()-1);
    
    return removedValue;
}
#endif /* Queue_h */
