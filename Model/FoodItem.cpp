//
//  FoodItem.cpp
//  AfternoonMegaData
//
//  Created by Morris, Seth on 3/13/17.
//  Copyright © 2017 Morris, Seth. All rights reserved.
//

#include "FoodItem.hpp"

FoodItem:: FoodItem()
{
    this->calories = 666;
    this->foodName = "MLG Pasta";
    this-> cost = 4.20;
    this->delicious = true;
}

FoodItem:: FoodItem(string name)
{
    this->foodName = name;
    this->cost = 424.20;
    this->calories = 69;
    this->delicious = true;
}

int FoodItem:: getCalories()
{
    return calories;
}

double FoodItem::getCost()
{
    return cost;
}

string FoodItem::getFoodName()
{
    return foodName;
}

bool FoodItem::isDelicious()

{
    return delicious;
}

void FoodItem:: setCalories(int calories)
{
    this->calories = calories;
}

void FoodItem:: setCost(double cost)
{
    this->cost = cost;
}

void FoodItem:: setFoodName(string foodName)
{
    this->foodName = foodName;
}

void FoodItem:: setDelicious(bool delicious)
{
    this->delicious = delicious;
}
