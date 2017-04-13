//
//  BinarySearchTree.h
//  AfternoonMegaData
//
//  Created by Morris, Seth on 4/11/17.
//  Copyright © 2017 Morris, Seth. All rights reserved.
//

#ifndef BinarySearchTree_h
#define BinarySearchTree_h
#include "BinarySearchTreeNode.hpp"
#include "Tree.hpp"
template<class Type>
class BinarySearchTree: public Tree<Type>
{
private:
    BinarySearchTreeNode<Type> * root;
    int calculateSize(BinarySearchTreeNode<Type> * start);
    void inOrderTraversal(BinarySearchTreeNode<Type> * root);
    void preOrderTraversal(BinarySearchTreeNode<Type> * root);
    void postOrderTraversal(BinarySearchTreeNode<Type> * root);
    
    void removeNode(BinarySearchTreeNode<Type> * root);
public:
    BinarySearchTree();
    ~BinarySearchTree();
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
    BinarySearchTreeNode<Type> * getRoot();
    void setRoot(BinarySearchTreeNode<Type> * root);
    void printToFile();
    void demoTraversalSteps(BinarySearchTreeNode<Type> * node);
    
    bool contains(Type value);
    void insert(Type itemToInsert);
    void remove(Type value);
};
template<class Type>
BinarySearchTree<Type>::BinarySearchTree() : Tree<Type>()
{
    this->root = nullptr;
}

template<class Type>
BinarySearchTreeNode<Type> * BinarySearchTree<Type>::getRoot()
{
    return root;
}
template<class Type>
void BinarySearchTree<Type>::setRoot(BinarySearchTreeNode<Type> * root)
{
    this->root = root;
}

template<class Type>
BinarySearchTree<Type>::~BinarySearchTree()
{
    
}
template<class Type>
void BinarySearchTree<Type>::printToFile()
{
    
}
template<class Type>
void BinarySearchTree<Type>::inOrderTraversal()
{
    
}
template<class Type>
void BinarySearchTree<Type>::preOrderTraversal()
{
    
}
template<class Type>
void BinarySearchTree<Type>::postOrderTraversal()
{
    
}
template<class Type>
void BinarySearchTree<Type>::inOrderTraversal(BinarySearchTreeNode<Type> * root)
{
    
}
template<class Type>
void BinarySearchTree<Type>::preOrderTraversal(BinarySearchTreeNode<Type> * root)
{
    
}
template<class Type>
void BinarySearchTree<Type>::postOrderTraversal(BinarySearchTreeNode<Type> * root)
{
    
}
template<class Type>
int BinarySearchTree<Type>::calculateSize(BinarySearchTreeNode<Type> * start)
{
    return -99;
}

#endif /* BinarySearchTree_h */
