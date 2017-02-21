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



#endif /* List_h */
