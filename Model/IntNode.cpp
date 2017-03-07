//
//  IntNode.cpp
//  AfternoonMegaData
//
//  Created by Morris, Seth on 2/6/17.
//  Copyright © 2017 Morris, Seth. All rights reserved.
//

#include "IntNode.hpp"

IntNode :: IntNode()
{
    this->nextPointer = nullptr;
    this->nodeData = -9999;
}

IntNode :: IntNode(int value)
{
    this->nextPointer = nullptr;
    this->nodeData = value;
}

IntNode :: IntNode(int value, IntNode * nextPointer)
{
    this->nextPointer = nextPointer;
    this->nodeData = value;
}

void IntNode:: setNodeData(int newValue)
{
    nodeData = newValue;
}

void IntNode:: setNodePointer(IntNode * nextPointer)
{
    this->nextPointer = nextPointer;
}

int IntNode:: getNodeData()
{
    return nodeData;
}

IntNode * IntNode :: getNextPointer()
{
    return this->nextPointer;
}
