//
//  Timer.cpp
//  FirstAfternoonCPlusPlus
//
//  Created by Morris, Seth on 1/31/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#include <iostream>
#include "Timer.hpp"

using namespace std;

Timer :: Timer()
{
    executionTime = 0;
}

void Timer:: resetTimer()
{
    executionTime = 0;
}

void Timer:: startTimer()
{
    executionTime = clock();
}

void Timer:: stopTimer()
{
    executionTime = clock();
}

void Timer:: finishTimer()
{
    executionTime = clock() - executionTime;
}

long Timer:: getExectutionTimeInMicroseconds()
{
    return executionTime;
}

void Timer:: displayTimerInformation()
{
    cout << "It took this long to execute: " << executionTime<< endl;
    cout << "That is this many seconds: " << executionTime/CLOCKS_PER_SEC << endl;
}
