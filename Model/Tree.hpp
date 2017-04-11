//
//  Tree.hpp
//  AfternoonMegaData
//
//  Created by Morris, Seth on 4/11/17.
//  Copyright © 2017 Morris, Seth. All rights reserved.
//

#ifndef Tree_h
#define Tree_h

template<class Type>
class Tree
{
private:
    int size;
    int height;
    bool complete;
    bool balanced;
public:
    Tree();
    int getSize() const;
    int getHeight() const;
    bool isComplete() const;
    bool isBalanced() const;
    void setSize(int size);
    void setHeight(int height);
    void setComplete(bool complete);
    void setBalanced(bool balanced);
    virtual ~Tree();
    virtual void printToFile() = 0;
    virtual void inOrderTranversal() = 0;
    virtual void preOrderTraversal() = 0;
    virtual void postOrderTraversal() = 0;
};

template<class Type>
Tree<Type>::Tree()
{
    size = 0;
    height = 0;
    complete = false;
    balanced = false;
}
template<class Type>
int Tree<Type>::getSize() const
{
    return size;
}
template <class Type>
int Tree<Type>::getHeight() const
{
    return height;
}
template<class Type>
bool Tree<Type> :: isComplete() const
{
    return complete;
}
template <class Type>
bool Tree<Type> :: isBalanced() const
{
    return balanced;
}
template <class Type>
void Tree<Type> :: setSize(int size)
{
    this->size = size;
}
template <class Type>
void Tree<Type> :: setHeight(int height)
{
    this -> height = height;
}
template<class Type>
void Tree<Type>  :: setComplete(bool complete)
{
    this->complete = complete;
}
template<class Type>
void Tree<Type>:: setBalanced(bool balanced)
{
    this->balanced = balanced;
}
#endif /* Tree_h */
