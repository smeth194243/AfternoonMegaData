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
    this->nodePointer = nullptr;
    this->nodeData = -9999;
}

IntNode :: IntNode(int value)
{
    this->nodePointer = nullptr;
    this->nodeData = value;
}

IntNode :: IntNode(int value, IntNode * nodePointer)
{
    this->nodePointer = nodePointer;
    this->nodeData = value;
}

void IntNode:: setNodeData(int newValue)
{
    nodeData = newValue;
}

void IntNode:: setNodePointer(IntNode * nodePointer)
{
    this->nodePointer = nodePointer;
}

int IntNode:: getNodeData()
{
    return nodeData;
}

IntNode * IntNode :: getNodePointer()
{
    return this->nodePointer;
}
