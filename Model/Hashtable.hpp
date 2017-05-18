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
    long nextPrime();
    long findPosition(HashNode<Type> * data);
    long handleCollision(HashNode<Type> * data, long currentPosition);
    
public:
    HashTable();
    ~HashTable();
    void add(Type data);
    bool remove(Type data);
    void displayContents();
    long getSize();
};

template <class Type>
HashTable<Type> :: HashTable()
{
    this->capacity= 101;
    this->efficiencyPercentage = 0.667;
    this->size = 0;
    this->hashTableStorage = new HashNode<Type> * [capacity];
    std:: fill_n(hashTableStorage, capacity, nullptr);
}

template <class Type>
HashTable<Type> :: ~HashTable()
{
    delete [ ] hashTableStorage;
}

template <class Type>
long HashTable<Type> :: nextPrime()
{
    long nextPrime = (this->capacity * 2) +1;
    
    while(!isPrime(nextPrime))
    {
        nextPrime += 2;
    }
    return nextPrime;
}

template <class Type>
bool HashTable<Type> :: isPrime(long canidateNumber)
{
    if(canidateNumber <= 1)
    {
        return false;
    }
    else if(canidateNumber == 2|| canidateNumber == 3)
    {
        return true;
    }
    else if(canidateNumber % 2 == 0)
    {
        return false;
    }
    else
    {
        for(int next = 3; next <= sqrt(canidateNumber) +1; next +=2)
        {
            if(canidateNumber % next == 0)
            {
                return false;
            }
        }
        return true;
    }
}

template <class Type>
long HashTable<Type> :: findPosition(HashNode<Type> * data)
{
    long insertPosition = data->getKey() % this->capacity;
    return insertPosition;
}

template <class Type>
long HashTable<Type> :: handleCollision(HashNode<Type> * data, long currentPosition)
{
    long shift = 17;
    
    for(long position = currentPosition + shift; position != currentPosition; position += shift)
    {
        if(position >= capacity)
        {
            position = position % capacity;
        }
        
        if(hashTableStorage[position] == nullptr)
        {
            return position;
        }
    }
    return -1;
}

template <class Type>
void HashTable<Type> :: displayContents()

{
    for(long index = 0; index < capacity; index ++)
    {
        if(hashTableStorage[index] != nullptr)
        {
            cout << index << ": " << hashTableStorage[index]->getData() << endl;
        }
    }
}

template <class Type>
bool HashTable<Type> :: remove(Type data)
{
    bool removed = false;
    
    HashNode<Type> * find(data);
    long hashIndex = findPosition(find);
    
    if(hashTableStorage[hashIndex] != nullptr)
    {
        hashTableStorage[hashIndex] = nullptr;
        removed = true;
        this->size--;
    }
    
    return removed;
}

template <class Type>
void HashTable<Type> :: resize()
{
    long updatedCapacity = nextPrime();
    HashNode<Type> ** tempStorage = new HashNode<Type> * [updatedCapacity];
    
    std:: fill_n(tempStorage, updatedCapacity, nullptr);
    
    long oldCapacity = this->capacity;
    this->capacity = updatedCapacity;
    
    for(long index = 0; index < oldCapacity; index++)
    {
        if(hashTableStorage[index] != nullptr)
        {
            HashNode<Type> * temp = hashTableStorage[index];
            
            long position = findPosition(temp);
            if(tempStorage[position] == nullptr)
            {
                tempStorage[position] = temp;
            }
            else
            {
                long updatedPosition = handleCollision(temp, position);
                tempStorage[updatedPosition] = temp;
            }
        }
    }
    
    hashTableStorage = tempStorage;
}

template <class Type>
void HashTable<Type> :: add(Type data)
{
    this->size++;
    if(((this->size * 1.00)/ this->capacity) > this->efficiencyPercentage)
    {
        resize();
    }
    
    HashNode<Type> * temp = new HashNode<Type>(data);
    long index = findPosition(temp);
    
    if(hashTableStorage[index] == nullptr)
    {
        hashTableStorage[index] = temp;
    }
    else
    {
        long updatedPosition = handleCollision(temp, index);
        hashTableStorage[updatedPosition] = temp;
    }
}
#endif /* Hashtable_h */
