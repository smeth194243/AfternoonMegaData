//
//  DataStructureController.cpp
//  AfternoonMegaData
//
//  Created by Morris, Seth on 2/8/17.
//  Copyright © 2017 Morris, Seth. All rights reserved.
//

#include "DataStructureController.hpp"
#include <iostream>
#include "../Model/Node.hpp"
#include "../Model/Array.hpp"
#include "../Model/Timer.hpp"
#include "../Model/IntNodeArray.hpp"
#include "../Model/List.h"
#include "../Model/DoubleList.hpp"
#include "../Model/Queue.hpp"
#include "../Model/Stack.hpp"
#include "../Model/BiDirectionalNode.hpp"
#include "../Model/CircularList.hpp"
#include "../Model/Tree.hpp"
#include "../Model/BinarySearchTree.h"
#include "../Model/BinarySearchTreeNode.hpp"
#include "../Model/CrimeData.hpp"
#include "../Controller/FileController.hpp"
#include <string>

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
    //testQueue();
    testStack();
    
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
    Stack<int> plateStack;
    plateStack.add(1234);
    plateStack.push(5678);
    plateStack.push(7384);
    cout << "The size of the list before removing is: " << plateStack.getSize() << endl;
    int testValue = plateStack.pop();
    
    cout << "The size of the list after removing is: " << plateStack.getSize() << endl;
    plateStack.peek();
    //plateStack.remove(1234);
    
    
    cout << "Test value is " << testValue << " and should be 7384" << endl;
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

void DataStructureController :: testListTiming()
{
    DoubleList<int> timingList;
    Timer totalTimer;
    totalTimer.startTimer();
    for(int index = 0; index < 10000; index++)
    {
        
        timingList.add(rand());
        
    }
    long slowTime [1000];
    long fastTime [1000];
    double averageSlow = 0.00, averageFast = 0.00;
    Timer doubleTimer;
    
    for(int index = 0; index < 1000; index++)
    {
        
        int randomIndex = rand() % 10000;
        doubleTimer.startTimer();
        timingList.getFromIndex(randomIndex);
        doubleTimer.startTimer();
        slowTime[index] = doubleTimer.getExectutionTimeInMicroseconds();
        doubleTimer.resetTimer();
        
        
        doubleTimer.startTimer();
        timingList.getFromIndexFast(randomIndex);
        doubleTimer.stopTimer();
        fastTime[index] = doubleTimer.getExectutionTimeInMicroseconds();
        doubleTimer.resetTimer();
        
        averageSlow += slowTime[index];
        averageFast += fastTime[index];
        
        
    }
    
    averageSlow += averageSlow/1000.00;
    averageFast += averageFast/1000.00;
    
    cout << "When you do it in one diretion searching you get an average of: "  << averageSlow<< endl;
    cout << "When you do the BiDirectional way you get: " << averageFast << endl;
}

void DataStructureController :: testList()
{
    List<string> theList;
    theList.addFront("method ");
    theList.addEnd("works");
    theList.addFront("The add");
    theList.addEnd("as it should.");
    
    for(int index = 0; index < theList.getSize(); index++)
    {
        cout << theList.getFromIndex(index) << endl;
    }
    
    for(int index = 0; index < theList.getSize(); index++)
    {
        cout << theList.remove(index) << endl;
    }
    
    theList.addFront("The list is as new");
    theList.addFront("Now it contains these words");
    
    for(int index = 0; index < theList.getSize(); index++)
    {
        cout << theList.getFromIndex(index) << endl;
    }
    
    if (theList.contains("words"))
    {
        cout << "The contains function works" << endl;
    }
}

void DataStructureController::testBinarySearchTreeOperations()

{
    
    BinarySearchTree<int> numbers;
    
    numbers.insert(9843);
    
    numbers.insert(10);
    
    numbers.insert(43);
    
    numbers.insert(-123);
    
    numbers.insert(23465);
    
    numbers.insert(10); // won't go in
    
    numbers.insert(43243);
    
    numbers.insert(-45677654);
    
    numbers.insert(92165);
    
    
    
    cout << "Size should be 8 and is: " << numbers.getSize() << endl;
    
    cout << "In order traversal should be: \n\t-45677654 \n\t-123 \n\t10 \n\t43 \n\t9843 \n\t23465 \n\t43243 \n\t92165" << endl;
    
    numbers.inOrderTraversal();
    
    
    
    cout << "Height should be 4 and is: " << numbers.getHeight() << endl;
    
    cout << "Balanced should be false || 0 and is: " << numbers.isBalanced() << endl;
    
}

void DataStructureController::testBinarySearchData()
{
    
    FileController fileData;
    
    Timer treeTimer;
    
    treeTimer.startTimer();
    
    BinarySearchTree<CrimeData> crimeTree = fileData.readCrimeDataToBinarySearchTree("/Users/seth.morris/Documents/crimes.csv");
    
    treeTimer.stopTimer();
    
    
    
    int count = crimeTree.getSize();
    
    int height = crimeTree.getHeight();
    
    bool complete = crimeTree.isComplete();
    
    bool balanced = crimeTree.isBalanced();
    
    
    
    cout << "The count of the tree is: " << count << ", the height is " << height << ".\n The tree's balanced status is " << balanced << ", and its complete status is " << complete << endl;
    
    cout << "The time to read in the tree was: " << endl;
    
    treeTimer.displayTimerInformation();
}

void DataStructureController:: testAVLTreeOperations()
{
    BinarySearchTree<int> numbers;
    
    AVLTree<int> numbers;
    
    numbers.insert(9843);
    
    numbers.insert(10);
    
    numbers.insert(43);
    
    numbers.insert(-123);
    
    numbers.insert(23465);
    
    numbers.insert(10); // won't go in
    
    numbers.insert(43243);
    
    numbers.insert(-45677654);
    
    numbers.insert(92165);
    
    
    
    cout << "Size should be 8 and is: " << numbers.getSize() << endl;
    
    cout << "In order traversal should be: \n\t-45677654 \n\t-123 \n\t10 \n\t43 \n\t9843 \n\t23465 \n\t43243 \n\t92165" << endl;
    
    numbers.inOrderTraversal();
    
    
    
    cout << "Height should be 4 and is: " << numbers.getHeight() << endl;
    
    cout << "Balanced should be true || 1 and is: " << numbers.isBalanced() << endl;
    
}

void DataStructureController::testAVLData()
{
    
    FileController fileData;
    
    Timer treeTimer;
    
    treeTimer.startTimer();
    
    AVLTree<CrimeData> crimeTree = fileData.readCrimeDataToAVLTree("/Users/cody.henrichsen/Documents/crimes.csv");
    
    treeTimer.stopTimer();
    
    
    
    int count = crimeTree.getSize();
    
    int height = crimeTree.getHeight();
    
    bool complete = crimeTree.isComplete();
    
    bool balanced = crimeTree.isBalanced();
    
    
    
    cout << "The count of the tree is: " << count << ", the height is " << height << ".\n The tree's balanced status is " << balanced << ", and its complete status is " << complete << endl;
    
    cout << "The time to read in the tree was: " << endl;
    
    treeTimer.displayTimerInformation();
    
}

