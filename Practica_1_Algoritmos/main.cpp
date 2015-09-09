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
//    BinarySearchTree<int> * bst = new BinarySearchTree<int>();
    
//    BNode<int> * five = new BNode<int>(5);
//    BNode<int> * three = new BNode<int>(3);
//    BNode<int> * four = new BNode<int>(4);
//    BNode<int> * six = new BNode<int>(6);
//    BNode<int> * nine = new BNode<int>(9);
//    BNode<int> * ten = new BNode<int>(10);
//
//    bst->insert(five);
//    bst->insert(three);
//    bst->insert(four);
//    bst->insert(six);
//    bst->insert(nine);
//    bst->insert(ten);
//    bst->insert(new BNode<int>(12));
//    bst->insert(new BNode<int>(14));
//    bst->insert(new BNode<int>(16));
//    
//    std::cout << "Imprimiendo en orden ascendente" << std::endl;
//    bst->inOrder();
//    
//    std::cout << "Imprimiendo en orden descendente" << std::endl;
//    bst->inverseInOrder();
//    
//    std::cout << (bst->search(5)? "Encontre 5" : "No encontre 5") << std::endl;
//    std::cout << (bst->search(6)? "Encontre 6" : "No encontre 6") << std::endl;
//    std::cout << (bst->search(8)? "Encontre 8" : "No encontre 8") << std::endl;
//    
//    std::cout << "Altura del arbol: " << bst->getHeight() << std::endl;
//    
//    std::cout << "Altura del elemento 10: " << bst->getHeight(ten) << std::endl;
//    std::cout << "Profundidad del elemento 10: " << bst->getDepth(ten) << std::endl;
//    std::cout << "Nivel del elemento 10: " << bst->getLevel(ten) << std::endl;
    
    //arbol no balanceado cubells
//    bst->insert(new BNode<int>(21));
//    bst->insert(new BNode<int>(13));
//    bst->insert(new BNode<int>(10));
//    bst->insert(new BNode<int>(18));
//    bst->insert(new BNode<int>(33));
//    bst->insert(new BNode<int>(25));
//    bst->insert(new BNode<int>(40));
//    bst->insert(new BNode<int>(26));
//    bst->insert(new BNode<int>(27));
    
    
    //arbol no balanceado gerry
//     bst->insert(new BNode<int>(10));
//    bst->insert(new BNode<int>(6));
//    bst->insert(new BNode<int>(4));
//    bst->insert(new BNode<int>(2));
//    bst->insert(new BNode<int>(3));
//    bst->insert(new BNode<int>(12));
//    bst->insert(new BNode<int>(11));
//    bst->insert(new BNode<int>(13));
//    bst->insert(new BNode<int>(15));
     
//    if(bst->isAvl(bst->getRoot()))
//    {
//        std::cout << "arbol balanceado" << std::endl;
//    }
//    else
//        std::cout << "Arbol no balanceado" << std::endl;
//    
//    bst->clear();
    
//    RedBlackTree<int>* bst = new RedBlackTree<int>();
//    
//         bst->insert(new RBNode<int>(10));
//        bst->insert(new RBNode<int>(6));
//        bst->insert(new RBNode<int>(4));
//        bst->insert(new RBNode<int>(2));
//        bst->insert(new RBNode<int>(3));
//        bst->insert(new RBNode<int>(12));
//        bst->insert(new RBNode<int>(11));
//        bst->insert(new RBNode<int>(13));
//        bst->insert(new RBNode<int>(15));
//    
//    bst->prettyPrint();
    TTTree<int>* jesusTakeTheWheel = new TTTree<int>();
    
    jesusTakeTheWheel->insert23(10);
    jesusTakeTheWheel->insert23(20);
    jesusTakeTheWheel->insert23(5);
    jesusTakeTheWheel->insert23(30);
    jesusTakeTheWheel->insert23(50);
    jesusTakeTheWheel->insert23(1);
    jesusTakeTheWheel->insert23(23);
    jesusTakeTheWheel->insert23(19);
    jesusTakeTheWheel->insert23(2);
    jesusTakeTheWheel->insert23(2);
    jesusTakeTheWheel->insert23(2);
    jesusTakeTheWheel->insert23(70);
    jesusTakeTheWheel->insert23(40);
    jesusTakeTheWheel->insert23(80);
    jesusTakeTheWheel->insert23(90);
    
   // ========PRUEBA CON 100,000 NUMEROS======
//    srand((int) time(NULL));
//    
//    for(int i=0; i<100000; i++)
//    {
//        jesusTakeTheWheel->insert23(rand()%1000);
//    }

    if(jesusTakeTheWheel->isTT(jesusTakeTheWheel->getRoot()))
        std::cout << "si es 2-3 y su nivel es " << jesusTakeTheWheel->getHeight(jesusTakeTheWheel->getRoot())+1 <<std::endl;
    else
    {
        std::cout << "no es 2-3" << std::endl;
    }
    
    int n =10;
    if(jesusTakeTheWheel->findNode(jesusTakeTheWheel->getRoot(), n))
    {
        std::cout << "Si se encontro " << n << std::endl;
    }
    else
        std::cout << "No se encontro " << n << std::endl;

    return 0;
}