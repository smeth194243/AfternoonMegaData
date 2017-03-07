//
//  Stack.hpp
//  AfternoonMegaData
//
//  Created by Morris, Seth on 3/1/17.
//  Copyright © 2017 Morris, Seth. All rights reserved.
//

#ifndef Stack_h
#define Stack_h
#include "DoublyLinkedList.hpp"
using namespace std;

template <class Type>
class Stack: public DoublyLinkedList<Type>
{
private:
    
public:
    Stack();
    ~Stack();
    void add(Type value);
    Type remove(int index);
    Type pop();
    Type peek();
    Type push(Type data);
}

template <class Type>
Stack<Type> :: Stack() : DoublyLinkedList<Type>()
{
    
}

template <class Type>
Stack<Type> :: ~Stack()
{
    
}

template <class Type>
void Stack<Type> :: add(Type valueToAdd)
{
    push(valueToAdd);
}

#endif /* Stack_h */
