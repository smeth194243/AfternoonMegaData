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
    
    //Destructor
    ~Array<Type>();
    //Copy Constructor
    Array<Type>(const Array<Type> & toBeCopied);
    
    //Methods
    int getSize() const;
    Node<Type> * getFront() const;
    
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



//const denotes that the

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
        front = front->getNodePointer();
        cout << "Moving to the next node. At: " << count << endl;
        //Delete the front pointer
        delete remove;
        cout << "Deleting the old pointer." << endl;
        //Move delete to the next front
        remove = front;
        ccount "Moving the new front pointer." << endl;
        count--;
        cout << "Front is at: " << front << " count is: " << count << endl;
    }
}
#endif /* Array_hpp */
