//
//  CircularList.hpp
//  AfternoonMegaData
//
//  Created by Morris, Seth on 3/1/17.
//  Copyright © 2017 Morris, Seth. All rights reserved.
//

#ifndef CircularList_h
#define CircularList_h

#include "DoublyLinkedList.hpp"

template <class Type>
class CircularList : public DoublyLinkedList<Type>
{
private:
    //No need to redefine the private data members!!!
public:
    CircularList();
    ~CircularList();
    
    void add(Type data);
    Type remove(int index);
    //other methods as needed :D
    
};

template <class Type>
CircularList<Type> :: CircularList() : DoublyLinkedList<Type>()
{
    //deal with circle list stuff only here
}

template <class Type>
void CircularList<Type> :: add(Type data)
{
    
}
#endif /* CircularList_h */
