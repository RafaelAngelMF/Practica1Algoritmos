//
//  main.cpp
//  Practica_1_Algoritmos
//
//  Created by alexis matuk on 9/5/15.
//  Copyright (c) 2015 alexis matuk. All rights reserved.
//
#include <iostream>
#include "TTTree.h"
#include "RedBlackTree.h"
#include "BinarySearchTree.h"

int main(int argc, const char * argv[])
{
    TTTree<int>* jesusTakeTheWheel = new TTTree<int>();
     
    jesusTakeTheWheel->insert23(10);
    jesusTakeTheWheel->insert23(20);
    jesusTakeTheWheel->insert23(5);
    jesusTakeTheWheel->insert23(30);
    jesusTakeTheWheel->insert23(40);
    jesusTakeTheWheel->insert23(60);
    jesusTakeTheWheel->insert23(70);
    
    jesusTakeTheWheel->insert23(50);
    jesusTakeTheWheel->insert23(55);
    jesusTakeTheWheel->insert23(56);
    jesusTakeTheWheel->insert23(45);
    jesusTakeTheWheel->insert23(57);
    
    jesusTakeTheWheel->insert23(54);
    jesusTakeTheWheel->insert23(43);
    jesusTakeTheWheel->insert23(70);
    jesusTakeTheWheel->insert23(80);
    jesusTakeTheWheel->insert23(90);
    jesusTakeTheWheel->insert23(100);
    jesusTakeTheWheel->insert23(1);
    jesusTakeTheWheel->insert23(2);
    jesusTakeTheWheel->insert23(3);
    jesusTakeTheWheel->insert23(4);
    jesusTakeTheWheel->insert23(56);
    jesusTakeTheWheel->insert23(46);
    jesusTakeTheWheel->insert23(47);
    jesusTakeTheWheel->insert23(48);
    jesusTakeTheWheel->insert23(49);
    
    if(jesusTakeTheWheel->isTT())
        std::cout << "Si es 2-3" << std::endl;
    else
        std::cout << "No es 2-3" << std::endl;
    
    jesusTakeTheWheel->deleteNode(70);
    
    if(jesusTakeTheWheel->isTT())
        std::cout << "Si es 2-3" << std::endl;
    else
        std::cout << "No es 2-3" << std::endl;

    return 0;
}