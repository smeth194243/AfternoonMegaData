//
//  Hashtable.hpp
//  AfternoonMegaData
//
//  Created by Morris, Seth on 5/1/17.
//  Copyright © 2017 Morris, Seth. All rights reserved.
//

#ifndef Hashtable_h
#define Hashtable_h

#include <cmath>
#include <assert.h>
#include "HashNode.hpp"

using namespace std;
template <class Type>
class HashTable

{
private:
    long capacity;
    long size;
    double efficiencyPercentage;
    HashNode<Type> ** hashTableStorage;
    bool isPrime(long sampleNumber);
    void resize();
    long nextPrime(long current);
    long findPosition(HashNode<Type> * data);
    long handleCollision(HashNode<Type> * data, long currentPosition);
    
public:
    HashTable();
    ~HashTable();
    void add(Type data);
    bool remove(Type data);
    void displayContents();
};


#endif /* Hashtable_h */
