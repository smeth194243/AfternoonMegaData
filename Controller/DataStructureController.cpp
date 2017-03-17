//
//  DataStructureController.cpp
//  AfternoonMegaData
//
//  Created by Morris, Seth on 2/8/17.
//  Copyright © 2017 Morris, Seth. All rights reserved.
//

#include "DataStructureController.hpp"
#include <iostream>
#include "../Model/IntNodeArray.hpp"
#include "../Model/List.h"
#include "../Model/Queue.hpp"
#include "../Model/FoodItem.hpp"
#include "../Model/Stack.hpp"
#include "../Model/CircularList.hpp"
#include "../Model/DoubleList.hpp"

using namespace std;

DataStructureController:: DataStructureController()
{
    wordNode = Node<string> ("Derpy McConfuzzledface");
    numberNode = Node<int> ();
    sample = List<int> ();
}

void DataStructureController:: testNodes()
{
    cout << "THe contents of the Node<string>" << endl;
    cout << wordNode.getNodeData() << endl;
    cout << "Here is the Node<int>" << endl;
    cout << numberNode.getNodeData() << endl;
    
}

void DataStructureController :: start()
{
    cout << "Starting the project" << endl;
    
    cout << "Switching to the array testing" << endl;
    //testIntArray();
    //testAdvancedFeatures();
    //testListIntro();
    testFoodQueue();
    testIntStack();
    
    cout << "Finished testing" << endl;
}

void DataStructureController :: testIntArray()
{
    cout << "Testing the array" << endl;
    
    IntNodeArray temp = IntNodeArray(3);
    
    for(int index = 0; index < 3; index++)
    {
        cout << temp.getFromIndex(index) << " is at spot " << index << endl;
    }
    
    cout << "Testing IntNodeArray input " << endl;
    
    for(int index = 0; index < 3; index++)
    {
        temp.setAtIndex(index, index);
    }
    
    for(int index = 0; index < temp.getSize(); index++)
    {
        cout << temp.getFromIndex(index) << " is at spot " << index << endl;
    }
}

void DataStructureController :: testAdvancedFeatures()
{
    int showDestructor = 0;
    
    if(showDestructor < 1)
    {
        Array<string> words = Array<string>(5);
        cout << "there should be messages about the destructor next" << endl;
    }
    Array<string> words = Array<string>(4);
    words.setAtIndex(0, "at zero");
    words.setAtIndex(3, "in the last spot");
    Array<string> copiedWords = Array<string>(words);
    
    cout <<"these should match:" << endl;
    cout << words.getFromIndex(0) << " should be the same as "
    << copiedWords.getFromIndex(0) << endl;
    
    copiedWords.setAtIndex(3, "Changed the contents of the copied Array");
    
}

void DataStructureController:: testListIntro()
{
    List<int> sample;
    sample.addFront(2);
    sample.addEnd(3);
    sample.addFront(1);
    cout << "This should go 1, 2, 3" << endl;
    
    for(int index = 0; index < sample.getSize(); index++)
    {
        cout << sample.getFromIndex(index) << endl;
    }
    
    cout << "Size should read 3 and is " << sample.getSize() << endl;
}

void DataStructureController:: testIntStack()
{
    Stack<int> numberStack;
    numberStack.add(2315);
    numberStack.push(32);
    int testValue = numberStack.pop();
    numberStack.peek();
    //numberStack.remove(2);
    
    cout << "Test value is " << testValue << " and should be 32" << endl;
}

void DataStructureController:: testFoodQueue()
{
    Queue<FoodItem>tastyFood;
    FoodItem MLGPasta("dankest pasta ever");
    
    cout << "The size is: " << tastyFood.getSize() << endl;
    
    tastyFood.enqueue(MLGPasta);
    FoodItem boring;
    tastyFood.add(boring);
    tastyFood.peek();
    
//  FoodItem added = tastyFood.enqueue(FoodItem data);
 //   cout << "The item added to the queue was: " << added.getCost() << " and should be: 424.20" << endl;
    
    
    FoodItem removed = tastyFood.dequeue();
    cout << "The item removed from the queue was: " << removed.getFoodName() << " and should be: dankest pasta ever" << endl;
    
    cout << "The size is: " << tastyFood.getSize() << endl;
}

void DataStructureController:: testStack()
{
    
}

void DataStructureController:: testQueue()
{
    Queue<FoodItem> tastyFood;
    FoodItem SteakBurger("Finest piece of meat on Earth");
    
    cout << "The size is: " << tastyFood.getSize() << endl;
    
    tastyFood.enqueue(SteakBurger);
    FoodItem boring2;
    tastyFood.add(boring2);
    tastyFood.peek();
    
    FoodItem removed2 = tastyFood.dequeue();
    cout << "The item removed from the queue was: " << removed2.getFoodName()
    << " and should be : Finest piece of meat on Earth" << endl;
    
    cout << "The size is: " << tastyFood.getSize() << endl;
    
}

void DataStructureController:: testDoubleList()
{
    
}


