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
#include <assert.h>
#include <iostream>
using namespace std;

template <class Type>

class  Array
{
private:
    int size;
    Node<Type> * front;
public:
    //Constructor
    Array();
    Array(int size);
    
    //Destructor
    ~Array<Type>();
    //Copy Constructor
    Array<Type>(const Array<Type> & toBeCopied);
    
    //Methods
    int getSize() const;
    Node<Type> * getFront() const;
    
    void setAtIndex(int index, Type value);
    Type getFromIndex(int index);
    int indexOf(Type toFind);
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
        Node<Type> *  current= new Node<Type>();
        current->setNextPointer(front);
        front = current;
    }
}

template <class Type>
void Array<Type> :: setAtIndex(int index, Type data)
{
    assert(index >= 0 && index < size);
    
    Node<Type> * current = front;
    
   // Node<Type> * current = front;
    for(int spot = 0; spot < index; spot++)
    {
        current = current-> getNextPointer();
    }
    
    current->setNodeData(data);
}

template <class Type>
Type Array <Type> :: getFromIndex(int index)
{
    assert(index >= 0 && index < size);
    
    Type value;
    
    Node<Type> * current = front;
    for(int position = 0; position < index; position++)
    {
        current = current-> getNextPointer();
    }
    
    value = current->getNodeData();
    
    return value;
}



//const denotes that the method doesnt impact the state of the object

template <class Type>
int Array<Type> :: getSize() const
{
    return size;
}


/*
 the role of the destructor is to de-allocate all memory 
 called by the use of the 'new' keyword. This is to prevent
 problems such as memory leaks.
 the destructor is never called by the programmer; rather, 
 the destructor is called with either the variable goes out of scope or the pointer to the variable is deleted.
 the count and cout statements are temporary and will be deleted.
 */
template <class Type>
Array<Type> :: ~Array()
{
    int count = size;
    Node<Type> * remove = front;
    while(front != nullptr)
    {
        //move the next node in array
        front = front->getNextPointer();
        cout << "Moving to the next node. At: " << count << endl;
        //Delete the front pointer
        delete remove;
        cout << "Deleting the old pointer." << endl;
        //Move delete to the next front
        remove = front;
        cout <<  "Moving the new front pointer." << endl;
        count--;
        cout << "Front is at: " << front << " count is: " << count << endl;
    }
}



template <class Type>
Array<Type> :: Array(const Array<Type> & toBeCopied)
{
    this->size = toBeCopied.getSize();
    
    //Build Data Structure
    this->front = new Node<Type>();
    for(int index = 1; index < size; index++)
    {
        Node<Type> * temp = new Node<Type>();
        temp->setNextPointer(front);
        front = temp;
    }
    //Copy values into new Array.
    //This could be done at the same time as the build step
    //but this is easier to explain
    Node<Type> * copyTemp = toBeCopied.getFront();
    Node<Type> * updated = this-> front;
    for(int index = 0; index < size; index++)
    {
        updated->setNodeData(copyTemp->getNodeData());
        updated = updated->getNextPointer();
        copyTemp = copyTemp->getNextPointer();
    }
}


//const modifier at the end of method is used to denote that the method
//doesnt impact the state of the object.
template <class Type>
Node<Type> * Array<Type> :: getFront() const
{
    return front;
}

template <class Type>
int Array<Type> :: indexOf(Type toFind)
{
    int index = -1;
    
    Node<Type> * searchPointer = this->getFront();
    
    for (int spot = 0; spot < this->getSize(); spot++)
    {
        if(toFind == searchPointer->getNodeData())
        {
            return spot;
        }
        searchPointer = searchPointer->getNextPointer();
    }
    
    return index;
}

#endif /* Array_hpp */
