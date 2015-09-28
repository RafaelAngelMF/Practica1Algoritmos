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
#include "ArbolB.h"

int main(int argc, const char * argv[])
{
/*
    ===== Two Three Tree Tests =====
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
*/


    int orden = 2;
    
    ArbolB<int> * arbol = new ArbolB<int>(orden);
    
    //cout << arbol->cantidadNodos();
    arbol->Insertar(5);
    cout << endl;
    
    
    arbol->Insertar(9);
    cout << endl;
    
    arbol->Insertar(3);
    cout << endl;
    arbol->Insertar(7);
    cout << endl;
    arbol->Insertar(1);
    cout << endl;
    arbol->Insertar(2);
    cout << endl;
    arbol->Insertar(8);
    cout << endl;
    arbol->Insertar(6);
    cout << endl;
    arbol->Insertar(0);
    cout << endl;
    arbol->Insertar(4);
    cout << endl;
    
    
    
    //
    //    NodoArbolB<int> * nodo = new NodoArbolB<int>(orden);
    //    nodo->insertarDato(10);
    //    nodo->insertarDato(20);
    //    nodo->insertarDato(30);
    //    nodo->insertarDato(40);
    //    nodo->setLlave(0);
    //    nodo->save(orden,true);
    //    arbol->cantidadNodos();
    //    NodoArbolB<int> * nuevo = new NodoArbolB<int>(orden);
    //    nuevo->carga(0,orden);
    //    nuevo->print();
    //    cout << nodo->getUsed();
    //nodo->save();
    
    //BNode<int> * m_two = new BNode<int>(2);
    return 0;
}