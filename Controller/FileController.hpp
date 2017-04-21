//
//  FileController.hpp
//  AfternoonMegaData
//
//  Created by Morris, Seth on 3/27/17.
//  Copyright © 2017 Morris, Seth. All rights reserved.
//

#ifndef FileController_hpp
#define FileController_hpp

#include "../Model/DoubleList.hpp"
#include "../Model/FoodItem.hpp"
#include "../Model/CrimeData.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

class FileController
{
private:
    DoubleList<FoodItem> foodItemList;
    
public:
    DoubleList<FoodItem> readFoodItemDataFromFileAsList(string filename);
    void writeFoodItemDataStatistics(DoubleList<FoodItem> source, string filename);
    void readCrimeDataToBinarySearchTree(string filename);
    void readCrimeDataToAVLTree(string filename);
};

#endif /* FileController_hpp */
