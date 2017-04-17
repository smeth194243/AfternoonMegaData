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
protected:
    BinarySearchTreeNode<Type> * root;
    
    int calculateSize(BinarySearchTreeNode<Type> * root);
    int calculateHeight(BinarySearchTreeNode<Type>* root);
    bool isBalanced(BinarySearchTreeNode<Type>* root);
    bool isComplete(BinarySearchTreeNode<Type>* root);
    
    void inOrderTraversal(BinarySearchTreeNode<Type> * inStart);
    void preOrderTraversal(BinarySearchTreeNode<Type> * preStart);
    void postOrderTraversal(BinarySearchTreeNode<Type> * postStart);
    
    void removeNode(BinarySearchTreeNode<Type> * removeMe);
public:
    BinarySearchTree();
    ~BinarySearchTree();
    
    BinarySearchTreeNode<Type> * getRoot();
    void setRoot(BinarySearchTreeNode<Type> * root);
    
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
    
    
    //void printToFile();
    void demoTraversalSteps(BinarySearchTreeNode<Type> * node);
    
    int getSize();
    int getHeight();
    bool isComplete();
    bool isBalanced();
    
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
    inOrderTraversal(root);
}
template<class Type>
void BinarySearchTree<Type>::preOrderTraversal()
{
    preOrderTraversal(root);
}
template<class Type>
void BinarySearchTree<Type>::postOrderTraversal()
{
    postOrderTraversal(root);
}
template<class Type>
void BinarySearchTree<Type>::inOrderTraversal(BinarySearchTreeNode<Type> * inStart)
{
    if(inStart != nullptr)
    {
        inOrderTraversal(inStart->getLeftChild());
        cout << "Node Contents: " << inStart->getNodeData() << endl;
        inOrderTraversal(inStart->getRightChild());
    }
}
template<class Type>
void BinarySearchTree<Type>::preOrderTraversal(BinarySearchTreeNode<Type> * root)
{
    if(preStart != nullptr)
    {
        cout << "Node Contents: " << preStart->getNodeData() << endl;
        preOrderTraversal(preStart->getLeftChild());
        preOrderTraversal(preStart->getRightChild());
    }
}
template<class Type>
void BinarySearchTree<Type>::postOrderTraversal(BinarySearchTreeNode<Type> * root)
{
    if(postStart != nullptr)
    {
        postOrderTraversal(postStart->getLeftChild());
        postOrderTraversal(postStart->getRightChild());
        cout << "Node Contents: " << postStart->getNodeData() << endl;
    }
}
template<class Type>
int BinarySearchTree<Type>::calculateSize(BinarySearchTreeNode<Type> * start)
{
    return -99;
}

template <class Type>
void BinarySearchTree<Type> :: insert(Type itemToInsert)
{
    BinarySearchTreeNode<Type> * insertMe = new BinarySearchTreeNode<Type>(itemToInsert);
    BinarySearchTreeNode<Type> * previous = nullptr;
    BinarySearchTreeNode<Type> * current = root;
    
    if(current == nullptr)
    {
        root = insertMe;
    }
    else
    {
        while (current != nnullptr)
        {
            previous = current;
            if(itemToInsert < current->getNodeData())
            {
                current = current->getLeftChild();
            }
            else if(ItemToInsert > current->getNodeData())
            {
                current = current->getRightChild();
            }
            else
            {
                cerr << "Item exists already - Exiting" << endl;
                delete insertMe;
                return;
            }
        }
        if (previous->getNodeData() > itemToInsert)
        {
            previous->setLeftChild(InsertMe);
        }
        else
        {
            previous->setRightChild(insertMe);
        }
        insertMe->setRootPointer(previous);
    }
}

template <class Type>
Bool BinarySearchTree<Type> :: contains(Type itemToFind)
{
    BinarySearchTreeNode<Type> * current = root;
    if(current == nullptr)
    {
        return false;
    }
    else
    {
        while (current != nullptr)
        {
            if(itemToFind == current->getNodeData())
            {
                return true;
            }
            else if(itemToFind < current->getNodeData())
            {
                current = current->getLeftChild();
            }
            else
            {
                current = current->getRightChild();
            }
        }
        return false;
    }
}

template <class Type>

void BinarySearchTree<Type> :: remove(Type getRidOfMe)
{
    if(root == nullptr)
    {
        cout << "Empty tree so removal is not possible" << endl;
    }
    else
    {
        BinarySearchTreeNode<Type> * current = root;
        BinarySearchTreeNode<Type> * previous = nullptr;
        bool hasBeenFound = false;
        
        while(current != nullptr && !hasBeenFound)
        {
            if(current->getNodeData() == getRidOfMe)
            {
                hasBeenFound = true;
            }
            else
            {
                previous = current;
                if(getRidOfMe < current->getNodeData())
                {
                    current = current->getLeftChild();
                }
                else
                {
                    current = current->getRightChild();
                }
            }
        }
        
        if(current == nullptr)
        {
            cerr << "Item not found, removal unsuccessful" << endl;
        }
        else if(hasBeenFound)
        {
            if(current == root)
            {
                removeNode(root);
            }
            else if(getRidOfMe < previous->getNodeData())
            {
                removeNode(previous->getLeftChild());
            }
            else
            {
                removeNode(previous->getRightChild());
            }
        }
    }
}

template <class Type>
void BinarySearchTree<Type> :: removeNode(BinarySearchTreeNode<Type> * & removeMe)
{
    BinarySearchTreeNode<Type> * current;
    BinarySearchTreeNode<Type> * previous;
    BinarySearchTreeNode<Type> * temp;
    
    previous = removeMe->getRootPointer();
    
    //leaf-has no kiddo
    if(removeMe->getRightChild() == nullptr && removeMe->getLeftChild() == nullptr)
    {
        temp = removeMe;
        removeMe= nullptr;
        
        if(previous != nullptr && removeMe->getNodeData() < previous->getNodeData())
        {
            previous->setLeftChild(removeMe);
        }
        else if(previous != nullptr && removeMe->getNodeData() > previous->getNodeData())
        {
            previous->setRightChild(removeMe);
        }
        
        delete temp;
    }
    //has only left child
    else if(removeMe->getRightChild() == nullptr)
    {
        temp = removeMe;
        removeMe = removeMe->getLeftChild();
        
        if(previous != nullptr && temp->getNodeData() previous->getNodeData())
        {
            previous->setLeftChild(removeMe);
        }
        else if(previous != nullptr && temp->getNodeData() > previous->getNodeData())
        {
            previous->setRightChild(removeMe);
        }
        
        removeMe->setRootPointer(previous);
        delete temp;
    }
    //has only right child
    else if(removeMe->getLeftChild() == nullptr)
    {
        temp = removeMe;
        removeMe = removeMe->getRightChild();
        
        if(previous != nullptr && temp->getNodeData() previous->getNodeData())
        {
            previous->setLeftChild(removeMe);
        }
        else if(previous != nullptr && temp->getNodeData() > previous->getNodeData())
        {
            previous->setRightChild(removeMe);
        }
        
        removeMe->setRootPointer(previous);
        delete temp;
    }
    //has both kiddos
    else
    {
        current = removeMe->getLeftChild();
        previous = nullptr;
        
        while(current->getRightChild() != nullptr)
        {
            previous = current;
            current = current->getRightChild();
        }
        
        removeMe->setNodeData(current->getNodeData());
        
        if(previous == nullptr)
        {
            removeMe->setLeftChild(Current->getLeftChild());
            current->getLeftChild()->setRootPointer(removeMe);
        }
        else
        {
            previous->setRightChild(current->getLeftChild());
            current->getLeftChild()->setRootPointer(previous);
        }
        
        delete current;
    }
    if(removeMe== nullptr||removeMe->getRootPointer == nullptr)
    {
        setRoot(removeMe);
    }
}
#endif /* BinarySearchTree_h */
