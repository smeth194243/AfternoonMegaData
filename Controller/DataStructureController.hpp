//
//  DataStructureController.hpp
//  AfternoonMegaData
//
//  Created by Morris, Seth on 2/8/17.
//  Copyright © 2017 Morris, Seth. All rights reserved.
//

#ifndef DataStructureController_hpp
#define DataStructureController_hpp

#include "../Model/Node.hpp"
#include <string>
#include "../Model/Array.hpp"
#include "../Model/List.h"

using namespace std;

class DataStructureController
{
private:
    void testIntArray();
    Node<int> numberNode;
    Node<string> wordNode;
    List<int> sample;
    void testNodes();
    void testAdvancedFeatures();
    void testListIntro();
public:
    DataStructureController();
    void start();
};
#endif /* DataStructureController_hpp */
