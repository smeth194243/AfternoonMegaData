//
//  List.h
//  AfternoonMegaData
//
//  Created by Morris, Seth on 2/21/17.
//  Copyright © 2017 Morris, Seth. All rights reserved.
//

#ifndef List_h
#define List_h

#include <assert.h>
#include 

using namespace std;

template <class Type>
class List
{
private:
    int size;
    Node<Type> * front;
    Node<Type> * end;
public:
    //Constructor
    List<Type>();
    //Copy constructor
    List<Type>(const List<Type> & source);
    //Destructor
    ~List<Type>();
    
    //Methods
    void addAtIndex(int index, Type value);
    void add(Type value);
    Type remove(int index);
    Type setAtIndex(int index, Type data);
    Type getFromIndex(int index);
    bool contains(Type data);
    int getSize();
    Node<Type>* getFront();

};

template <class Type>
List<Type> :: List<Type>()
{
    //Hi.
}

template <class Type>
List<Type> :: List()
{
    //Hi.
}


template <class Type>
Node<Type> * List<Type> :: addFront(Type value)
{
    if(size ==0)
    {
        Node<Type> * first = new Node<Type>(value);
        this->front = first;
        this->end = first;
    }
    else
    {
        Node<Type> * newFirst = new Node<Type>();
        newFirst->setNodeData(value);
        newFirst->setNodePointer(front);
        this->front = newFirst;
    }
    size++;
}

template <class Type>
void List<Type> :: addEnd(Type data)
{
    Node<Type> * added = new Node<Type>(data);
    if(size == 0)
    {
        this->front = added;
        this->end = added;
    }
    else
    {
        end->setNodePointer(added);
        this->end = added;
    }
    size++;
}

template <class Type>
void List<Type> :: addAtIndex(int index, Type value)
{
    assert (index >= 0 && index <= size);
    
    if(index == 0)
    {
        addFront(value);
    }
    else if (index == size)
    {
        addEnd(value);
    }
    else
    {
        Node<Type> * insertedNode = new Node<Type>(value);
        Node<Type> * current = front;
        Node<Type> * previous = nullptr;
        
        for(int position = 0; position < index; position++)
        {
            previous = current;
            current = current->getNodePointer();
        }
        previous->setNodePointer(inserted);
        insertedNode->setNodePointer(current);
        
        size++;
    }
}
#endif /* List_h */
