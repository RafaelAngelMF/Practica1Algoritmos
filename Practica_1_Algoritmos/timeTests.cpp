//
//  main.cpp
//  Practica_1_Algoritmos
//
//  Created by alexis matuk on 9/5/15.
//  Copyright (c) 2015 alexis matuk. All rights reserved.
//

/*
 
 
#include <iostream>
#include <iterator>
#include <cstring>
#include <chrono>
#include "TTTree.h"
#include "RedBlackTree.h"
#include "BTree.h"
#include "AVLTree.h"
#define N 100000

int main()
{
    TTTree<int> * dosTres = new TTTree<int>();
    RedBlackTree<int> * rojiNegro = new RedBlackTree<int>();
    BTree<int> * bTree = new BTree<int>(3);
    AVLTree<int> * arbolAVL = new AVLTree<int>();
    
    srand((int) time(NULL));
    
    int numeros[N];
    int busqueda[10];
    
    for(int i=0;i<N;i++)
    {
        numeros[i] = rand()%10000;
    }
    
    for(int i=0;i<10;i++)
    {
        busqueda[i] = numeros[i];
    }
    
    for(int i=0; i<N; i++)
    {
        dosTres->insert23(numeros[i]);
    }

    for(int i = 0; i < 10; i++)
    {
        bool found = false;
        auto begin = std::chrono::high_resolution_clock::now();
        found = dosTres->findNode(dosTres->getRoot(),busqueda[i]);
        auto end = std::chrono::high_resolution_clock::now();
        
        if (found)
        {
            std::cout << i+1 << ") " << "El valor: " << busqueda[i] << " se encuentra en el árbol" << std::endl;
            auto tiempo = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
            std::cout << "Le tomo: " << tiempo.count() << " nano segundos encontrarlo en el arbol 2-3" << std::endl;
        }
    }
    
    std::cout << std::endl;
    
    for(int i = 0; i < N; i++)
    {
        rojiNegro->RBinsert(numeros[i]);
    }
    
    for(int i = 0; i < 10; i++)
    {
        bool found = false;
        auto begin = std::chrono::high_resolution_clock::now();
        found = rojiNegro->search(busqueda[i]);
        auto end = std::chrono::high_resolution_clock::now();
        
        if (found)
        {
            std::cout << i+1 << ") " << "El valor: " << busqueda[i] << " se encuentra en el árbol" << std::endl;
            auto tiempo = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
            std::cout << "Le tomo: " << tiempo.count() << " nano segundos encontrarlo en el arbol rojinegro" << std::endl;
        }
    }
    
    
    std::cout << std::endl;
    
    for(int i=0; i<N; i++)
    {
        bTree->Insert(numeros[i]);
    }
    
    for(int i = 0; i<10; i++)
    {
        bool found = false;
        auto begin = std::chrono::high_resolution_clock::now();
        found = bTree->searchForNode(busqueda[i]);
        auto end = std::chrono::high_resolution_clock::now();
        
        if (found)
        {
            std::cout << i+1 << ") " << "El valor: " << busqueda[i] << " se encuentra en el árbol" << std::endl;
            auto tiempo = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
            std::cout << "Le tomo: " << tiempo.count() << " nano segundos encontrarlo en el B Tree" << std::endl;
        }
    }

    
    std::cout << std::endl;

    for(int i=0; i<N; i++)
    {
        arbolAVL->insert(numeros[i]);
    }
    
    for(int i = 0; i<10; i++)
    {
        bool found = false;
        auto begin = std::chrono::high_resolution_clock::now();
        found = arbolAVL->search(busqueda[i]);
        auto end = std::chrono::high_resolution_clock::now();
        
        if (found)
        {
            std::cout << i+1 << ") " << "El valor: " << busqueda[i] << " se encuentra en el árbol" << std::endl;
            auto tiempo = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
            std::cout << "Le tomo: " << tiempo.count() << " nano segundos encontrarlo en el arbol AVL" << std::endl;
        }
    }
    
    return 0;
}

*/