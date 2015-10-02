//
//  main.cpp
//  Practica_1_Algoritmos
//
//  Created by alexis matuk on 9/5/15.
//  Copyright (c) 2015 alexis matuk. All rights reserved.
//
#include <iostream>
#include <iterator>
#include <cstring>
#include <chrono>
#include "TTTree.h"
#include "RedBlackTree.h"
#include "ArbolB.h"
#include "AVLTree.h"
#define N 100

int main(int argc, const char * argv[])
{

    //===== Two Three Tree Tests =====
    TTTree<int>* jesusTakeTheWheel = new TTTree<int>();
     
//    jesusTakeTheWheel->insert23(10);
//    jesusTakeTheWheel->insert23(20);
//    jesusTakeTheWheel->insert23(5);
//    jesusTakeTheWheel->insert23(30);
//    jesusTakeTheWheel->insert23(40);
//    jesusTakeTheWheel->insert23(60);
//    jesusTakeTheWheel->insert23(70);
//    
//    jesusTakeTheWheel->insert23(50);
//    jesusTakeTheWheel->insert23(55);
//    jesusTakeTheWheel->insert23(56);
//    jesusTakeTheWheel->insert23(45);
//    jesusTakeTheWheel->insert23(57);
//    
//    jesusTakeTheWheel->insert23(54);
//    jesusTakeTheWheel->insert23(43);
//    jesusTakeTheWheel->insert23(70);
//    jesusTakeTheWheel->insert23(80);
//    jesusTakeTheWheel->insert23(90);
//    jesusTakeTheWheel->insert23(100);
//    jesusTakeTheWheel->insert23(1);
//    jesusTakeTheWheel->insert23(2);
//    jesusTakeTheWheel->insert23(3);
//    jesusTakeTheWheel->insert23(4);
//    jesusTakeTheWheel->insert23(56);
//    jesusTakeTheWheel->insert23(46);
//    jesusTakeTheWheel->insert23(47);
//    jesusTakeTheWheel->insert23(48);
//    jesusTakeTheWheel->insert23(49);

    jesusTakeTheWheel->insert23(20);
    jesusTakeTheWheel->insert23(5);
    jesusTakeTheWheel->insert23(10);
    jesusTakeTheWheel->insert23(1);
    jesusTakeTheWheel->insert23(30);
    jesusTakeTheWheel->insert23(33);
    jesusTakeTheWheel->insert23(50);
    jesusTakeTheWheel->deleteNode(5);
    jesusTakeTheWheel->printAsc();
    jesusTakeTheWheel->printDesc();
    if(jesusTakeTheWheel->isTT())
        std::cout << "Si es 2-3" << std::endl;
    else
        std::cout << "No es 2-3" << std::endl;


    return 0;


//    int orden = 2;
//    
//    ArbolB<int> * arbol = new ArbolB<int>(orden);
//    
//    arbol->Insertar(5);
//    
//    arbol->Insertar(9);
//    
//    arbol->Insertar(3);
//    
//    arbol->Insertar(7);
//
//    arbol->Insertar(1);
//
//    arbol->Insertar(2);
//
//    arbol->Insertar(8);
//
//    arbol->Insertar(6);
// 
//    arbol->Insertar(0);
//
//    arbol->Insertar(4);
//
//    //    NodoArbolB<int> * nodo = new NodoArbolB<int>(orden);
//    //    nodo->insertarDato(10);
//    //    nodo->insertarDato(20);
//    //    nodo->insertarDato(30);
//    //    nodo->insertarDato(40);
//    //    nodo->setLlave(0);
//    //    nodo->save(orden,true);
//    //    arbol->cantidadNodos();
//    //    NodoArbolB<int> * nuevo = new NodoArbolB<int>(orden);
//    //    nuevo->carga(0,orden);
//    //    nuevo->print();
//    //    cout << nodo->getUsed();
//    //nodo->save();
//    
//    //BNode<int> * m_two = new BNode<int>(2);
//    return 0;
}
//
////int main()
////{
////    TTTree<int> * dosTres = new TTTree<int>();
////    RedBlackTree<int> * rojiNegro = new RedBlackTree<int>();
////    ArbolB<int> * bTree = new ArbolB<int>(3);
////    AVLTree<int> * arbolAVL = new AVLTree<int>();
////    
////    srand((int) time(NULL));
////    
////    int numeros[N];
////    int busqueda[10];
////    
////    for(int i=0;i<N;i++)
////    {
////        numeros[i] = rand()%10000;
////    }
////    
////    for(int i=0;i<10;i++)
////    {
////        busqueda[i] = numeros[i];
////    }
////    
////    for(int i=0; i<N; i++)
////    {
////        dosTres->insert23(numeros[i]);
////    }
////
////    for(int i = 0; i < 10; i++)
////    {
////        bool found = false;
////        auto begin = std::chrono::high_resolution_clock::now();
////        found = dosTres->findNode(dosTres->getRoot(),busqueda[i]);
////        auto end = std::chrono::high_resolution_clock::now();
////        
////        if (found)
////        {
////            std::cout << i+1 << ") " << "El valor: " << busqueda[i] << " se encuentra en el árbol" << std::endl;
////            auto tiempo = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
////            std::cout << "Le tomo: " << tiempo.count() << " nano segundos encontrarlo en el arbol 2-3" << std::endl;
////        }
////    }
////    
////    std::cout << std::endl;
////    
////    for(int i = 0; i < N; i++)
////    {
////        rojiNegro->RBinsert(numeros[i]);
////    }
////    
////    for(int i = 0; i < 10; i++)
////    {
////        bool found = false;
////        auto begin = std::chrono::high_resolution_clock::now();
////        found = rojiNegro->search(busqueda[i]);
////        auto end = std::chrono::high_resolution_clock::now();
////        
////        if (found)
////        {
////            std::cout << i+1 << ") " << "El valor: " << busqueda[i] << " se encuentra en el árbol" << std::endl;
////            auto tiempo = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
////            std::cout << "Le tomo: " << tiempo.count() << " nano segundos encontrarlo en el arbol rojinegro" << std::endl;
////        }
////    }
////    
////    
////    std::cout << std::endl;
////    
////    for(int i=0; i<N; i++)
////    {
////        bTree->Insertar(numeros[i]);
////    }
////    
////    for(int i = 0; i<10; i++)
////    {
////        bool found = false;
////        auto begin = std::chrono::high_resolution_clock::now();
////        found = bTree->searchForNode(busqueda[i]);
////        auto end = std::chrono::high_resolution_clock::now();
////        
////        if (found)
////        {
////            std::cout << i+1 << ") " << "El valor: " << busqueda[i] << " se encuentra en el árbol" << std::endl;
////            auto tiempo = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
////            std::cout << "Le tomo: " << tiempo.count() << " nano segundos encontrarlo en el B Tree" << std::endl;
////        }
////    }
////
////    
////    std::cout << std::endl;
////
////    for(int i=0; i<N; i++)
////    {
////        arbolAVL->insert(numeros[i]);
////    }
////    
////    for(int i = 0; i<10; i++)
////    {
////        bool found = false;
////        auto begin = std::chrono::high_resolution_clock::now();
////        found = arbolAVL->search(busqueda[i]);
////        auto end = std::chrono::high_resolution_clock::now();
////        
////        if (found)
////        {
////            std::cout << i+1 << ") " << "El valor: " << busqueda[i] << " se encuentra en el árbol" << std::endl;
////            auto tiempo = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
////            std::cout << "Le tomo: " << tiempo.count() << " nano segundos encontrarlo en el arbol AVL" << std::endl;
////        }
////    }
////    
////    return 0;
////}