//
//  IntNode.hpp
//  AfternoonMegaData
//
//  Created by Morris, Seth on 2/6/17.
//  Copyright © 2017 Morris, Seth. All rights reserved.
//

#ifndef IntNode_hpp
#define IntNode_hpp

class IntNode
{
private:
    int nodeData;
    IntNode * nodePointer;
public:
    //Constructor
    IntNode();
    IntNode(int value);
    /*
     Creates an IntNode with a specified value and next node pointer.
     */
    IntNode(int value, IntNode * nextNode);
    
    //Methods
    int getNodeData();
    IntNode * getNodePointer();
    void setNodeData(int value);
    
    void setNodePointer(IntNode * next);
    
};

#endif /* IntNode_hpp */
