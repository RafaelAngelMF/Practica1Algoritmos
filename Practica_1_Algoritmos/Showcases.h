//
//  Showcases.h
//  Practica_1_Algoritmos
//
//  Created by alexis matuk on 10/1/15.
//  Copyright (c) 2015 alexis matuk. All rights reserved.
//

#ifndef Showcases_h
#define Showcases_h
#include <iostream>
#include <iterator>
#include <cstring>
#include <chrono>
#include "TTTree.h"
#include "RedBlackTree.h"
#include "BTree.h"
#include "AVLTree.h"
template <class T>
void showcaseAVL(AVLTree<T>* avlTree)
{
    int choice;
    bool done = false;
    while(!done)
    {
        std::cout << "===== Árbol AVL ===== " << std::endl;
        std::cout << "1) Mostrar ejemplo de funcionamiento" << std::endl;
        std::cout << "2) Insertar Dato" << std::endl;
        std::cout << "3) Borrar Dato" << std::endl;
        std::cout << "4) Buscar Dato" << std::endl;
        std::cout << "5) Imprimir ascendentemente" << std::endl;
        std::cout << "6) Imprimir descendentemente" << std::endl;
        std::cout << "7) Obtener la altura de un nodo" << std::endl;
        std::cout << "8) Obtener la profundidad de un nodo" << std::endl;
        std::cout << "9) Obtener el nivel de un nodo" << std::endl;
        std::cout << "10) Verificar si el árbol es AVL" << std::endl;
        std::cout << "11) Salir" << std::endl;
        std::cout << "Elige una opción: ";
        while(!(std::cin >> choice)){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada inválida, intenta otra vez: ";
        }
        switch(choice)
        {
            case 1:{
                std::cout << "=======Inserción=======" << std::endl;
                std::cout << "Insertando 20" << std::endl;
                avlTree->insert(20);
                std::cout << "Insertando 5" << std::endl;
                avlTree->insert(5);
                std::cout << "Insertando 10" << std::endl;
                avlTree->insert(10);
                std::cout << "Insertando 1" << std::endl;
                avlTree->insert(1);
                std::cout << "Insertando 30" << std::endl;
                avlTree->insert(30);
                std::cout << "Insertando 33" << std::endl;
                avlTree->insert(33);
                std::cout << "Insertando 50" << std::endl;
                avlTree->insert(50);
                std::cout << "=======Borrado=======" << std::endl;
                std::cout << "Borrando 5" << std::endl;
                avlTree->remove(5);
                std::cout << "=======Búsqueda=======" << std::endl;
                avlTree->search(20) ? std::cout << "Se encontró 20" << std::endl : std::cout << "No se encontró 20" << std::endl;
                avlTree->search(100) ? std::cout << "Se encontró 100" << std::endl : std::cout << "No se encontró 100" << std::endl;
                std::cout << "=======Impresión ascendente=======" << std::endl;
                avlTree->inOrder();
                std::cout << "=======Impresión descendente=======" << std::endl;
                avlTree->reverseInOrder();
                std::cout << "=======Altura=======" << std::endl;
                std::cout << "Altura de 1: " << avlTree->getHeight(avlTree->search(1)) << std::endl;
                std::cout << "=======Profundidad=======" << std::endl;
                std::cout << "Profundidad de 1: " << avlTree->getDepth(avlTree->search(1)) << std::endl;
                std::cout << "=======Nivel=======" << std::endl;
                std::cout << "Nivel de 1: " << avlTree->getLevel(avlTree->search(1)) << std::endl;
                std::cout << "=======Verificación=======" << std::endl;
                avlTree->isAvl() ? std::cout << "Sí es AVL!" << std::endl : std::cout << "No es AVL" << std::endl;
                break;}
            case 2:{
                int val;
                std::cout << "Valor a insertar: ";
                while(!(std::cin >> val)){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Entrada inválida, intenta otra vez: ";
                }
                avlTree->insert(val);
                std::cout << "Valor insertado correctamente..." << std::endl;
                break;}
            case 3:{
                int val;
                std::cout << "Valor a borrar: ";
                while(!(std::cin >> val)){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Entrada inválida, intenta otra vez: ";
                }
                avlTree->remove(val);
                std::cout << "Valor borrado correctamente..." << std::endl;
                break;}
            case 4:{
                int val;
                std::cout << "Valor a buscar: ";
                while(!(std::cin >> val)){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Entrada inválida, intenta otra vez: ";
                }
                avlTree->search(val) ? std::cout << "Valor encontrado!" << std::endl : std::cout << "Valor no encontrado" << std::endl;
                break;}
            case 5:{
                std::cout << "==============Árbol ascendente==============" << std::endl;
                avlTree->inOrder();
                break;}
            case 6:{
                std::cout << "==============Árbol descendente==============" << std::endl;
                avlTree->reverseInOrder();
                break;}
            case 7:{
                int val;
                std::cout << "Nodo a evaluar: ";
                while(!(std::cin >> val)){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Entrada inválida, intenta otra vez: ";
                }
                BNode<T>* node = avlTree->search(val);
                std::cout << "Altura: " << avlTree->getHeight(node) << std::endl;
                break;}
            case 8:{
                int val;
                std::cout << "Nodo a evaluar: ";
                while(!(std::cin >> val)){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Entrada inválida, intenta otra vez: ";
                }
                BNode<T>* node = avlTree->search(val);
                std::cout << "Profundidad: " << avlTree->getDepth(node) << std::endl;
                break;}
            case 9:{
                int val;
                std::cout << "Nodo a evaluar: ";
                while(!(std::cin >> val)){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Entrada inválida, intenta otra vez: ";
                }
                BNode<T>* node = avlTree->search(val);
                std::cout << "Nivel: " << avlTree->getLevel(node) << std::endl;
                break;}
            case 10:{
                avlTree->isAvl() ? std::cout << "Sí es AVL!" << std::endl : std::cout << "No es AVL" << std::endl;
                break;}
            case 11:{
                std::cout << "Adios!" << std::endl;
                done = true;
                break;}
            default:
                std::cout << "Opción inválida, elige otra" << std::endl;
                break;
        }
    }
}

template <class T>
void showcaseRedBlack(RedBlackTree<T>* redBlackTree)
{
    int choice;
    bool done = false;
    while(!done)
    {
        std::cout << "===== Árbol Rojinegro ===== " << std::endl;
        std::cout << "1) Mostrar ejemplo de funcionamiento" << std::endl;
        std::cout << "2) Insertar Dato" << std::endl;
        std::cout << "3) Borrar Dato" << std::endl;
        std::cout << "4) Buscar Dato" << std::endl;
        std::cout << "5) Imprimir ascendentemente" << std::endl;
        std::cout << "6) Imprimir descendentemente" << std::endl;
        std::cout << "7) Verificar si el árbol es RojiNegro" << std::endl;
        std::cout << "8) Salir" << std::endl;
        std::cout << "Elige una opción: ";
        while(!(std::cin >> choice)){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada inválida, intenta otra vez: ";
        }
        switch(choice)
        {
            case 1:{
                std::cout << "=======Inserción=======" << std::endl;
                std::cout << "Insertando 35" << std::endl;
                redBlackTree->RBinsert(35);
                std::cout << "Insertando 7" << std::endl;
                redBlackTree->RBinsert(7);
                std::cout << "Insertando 10" << std::endl;
                redBlackTree->RBinsert(10);
                std::cout << "Insertando 1" << std::endl;
                redBlackTree->RBinsert(1);
                std::cout << "Insertando 57" << std::endl;
                redBlackTree->RBinsert(57);
                std::cout << "Insertando 33" << std::endl;
                redBlackTree->RBinsert(33);
                std::cout << "Insertando 68" << std::endl;
                redBlackTree->RBinsert(68);
                std::cout << "=======Borrado=======" << std::endl;
                std::cout << "Borrando 57" << std::endl;
                redBlackTree->RBdelete(57);
                std::cout << "=======Búsqueda=======" << std::endl;
                redBlackTree->search(35) ? std::cout << "Se encontró 35" << std::endl : std::cout << "No se encontró 35" << std::endl;
                redBlackTree->search(100) ? std::cout << "Se encontró 100" << std::endl : std::cout << "No se encontró 100" << std::endl;
                std::cout << "=======Impresión ascendente=======" << std::endl;
                redBlackTree->inOrder();
                std::cout << "=======Impresión descendente=======" << std::endl;
                redBlackTree->reverseInOrder();
                std::cout << "=======Altura=======" << std::endl;
                std::cout << "Altura de 1: " << redBlackTree->getHeight(redBlackTree->search(1)) << std::endl;
                std::cout << "=======Profundidad=======" << std::endl;
                std::cout << "Profundidad de 1: " << redBlackTree->getDepth(redBlackTree->search(1)) << std::endl;
                std::cout << "=======Nivel=======" << std::endl;
                std::cout << "Nivel de 1: " << redBlackTree->getLevel(redBlackTree->search(1)) << std::endl;
                std::cout << "=======Verificación=======" << std::endl;
                redBlackTree->verificarArbol();
                break;}
            case 2:{
                int val;
                std::cout << "Valor a insertar: ";
                while(!(std::cin >> val)){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Entrada inválida, intenta otra vez: ";
                }
                redBlackTree->RBinsert(val);
                std::cout << "Valor insertado correctamente..." << std::endl;
                break;}
            case 3:{
                int val;
                std::cout << "Valor a borrar: ";
                while(!(std::cin >> val)){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Entrada inválida, intenta otra vez: ";
                }
                redBlackTree->RBdelete(val);
                std::cout << "Valor borrado correctamente..." << std::endl;
                break;}
            case 4:{
                int val;
                std::cout << "Valor a buscar: ";
                while(!(std::cin >> val)){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Entrada inválida, intenta otra vez: ";
                }
                redBlackTree->search(val) ? std::cout << "Valor encontrado!" << std::endl : std::cout << "Valor no encontrado" << std::endl;
                break;}
            case 5:{
                std::cout << "==============Árbol ascendente==============" << std::endl;
                redBlackTree->inOrder();
                break;}
            case 6:{
                std::cout << "==============Árbol descendente==============" << std::endl;
                redBlackTree->reverseInOrder();
                break;}
            case 7:{
                redBlackTree->verificarArbol();
                break;}
            case 8:{
                std::cout << "Adios!" << std::endl;
                done = true;
                break;}
            default:
                std::cout << "Opción inválida, elige otra" << std::endl;
                break;
        }
    }
}

template <class T>
void showcaseTT(TTTree<T>* twoThreeTree)
{
    int choice;
    bool done = false;
    while(!done)
    {
        std::cout << "===== Árbol 2-3 ===== " << std::endl;
        std::cout << "1) Mostrar ejemplo de funcionamiento" << std::endl;
        std::cout << "2) Insertar Dato" << std::endl;
        std::cout << "3) Borrar Dato" << std::endl;
        std::cout << "4) Buscar Dato" << std::endl;
        std::cout << "5) Imprimir ascendentemente" << std::endl;
        std::cout << "6) Imprimir descendentemente" << std::endl;
        std::cout << "7) Verificar si el árbol es 2-3" << std::endl;
        std::cout << "8) Salir" << std::endl;
        std::cout << "Elige una opción: ";
        while(!(std::cin >> choice)){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada inválida, intenta otra vez: ";
        }
        switch(choice)
        {
            case 1:{
                std::cout << "=======Inserción=======" << std::endl;
                std::cout << "Insertando 20" << std::endl;
                twoThreeTree->insert23(20);
                std::cout << "Insertando 5" << std::endl;
                twoThreeTree->insert23(5);
                std::cout << "Insertando 10" << std::endl;
                twoThreeTree->insert23(10);
                std::cout << "Insertando 1" << std::endl;
                twoThreeTree->insert23(1);
                std::cout << "Insertando 30" << std::endl;
                twoThreeTree->insert23(30);
                std::cout << "Insertando 33" << std::endl;
                twoThreeTree->insert23(33);
                std::cout << "Insertando 50" << std::endl;
                twoThreeTree->insert23(50);
                std::cout << "=======Borrado=======" << std::endl;
                std::cout << "Borrando 5" << std::endl;
                twoThreeTree->deleteNode(5);
                std::cout << "=======Búsqueda=======" << std::endl;
                twoThreeTree->searchForNode(20) ? std::cout << "Se encontró 20" << std::endl : std::cout << "No se encontró 20" << std::endl;
                twoThreeTree->searchForNode(100) ? std::cout << "Se encontró 100" << std::endl : std::cout << "No se encontró 100" << std::endl;
                std::cout << "=======Impresión ascendente=======" << std::endl;
                twoThreeTree->printAsc();
                std::cout << "=======Impresión descendente=======" << std::endl;
                twoThreeTree->printDesc();
                std::cout << "=======Verificación=======" << std::endl;
                twoThreeTree->isTT() ? std::cout << "Sí es 2-3!" << std::endl : std::cout << "No es 2-3" << std::endl;
                break;}
            case 2:{
                int val;
                std::cout << "Valor a insertar: ";
                while(!(std::cin >> val)){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Entrada inválida, intenta otra vez: ";
                }
                twoThreeTree->insert23(val);
                std::cout << "Valor insertado correctamente..." << std::endl;
                break;}
            case 3:{
                int val;
                std::cout << "Valor a borrar: ";
                while(!(std::cin >> val)){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Entrada inválida, intenta otra vez: ";
                }
                twoThreeTree->deleteNode(val);
                std::cout << "Valor borrado correctamente..." << std::endl;
                break;}
            case 4:{
                int val;
                std::cout << "Valor a buscar: ";
                while(!(std::cin >> val)){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Entrada inválida, intenta otra vez: ";
                }
                twoThreeTree->searchForNode(val) ? std::cout << "Valor encontrado!" << std::endl : std::cout << "Valor no encontrado" << std::endl;
                break;}
            case 5:{
                std::cout << "==============Árbol ascendente==============" << std::endl;
                twoThreeTree->printAsc();
                break;}
            case 6:{
                std::cout << "==============Árbol descendente==============" << std::endl;
                twoThreeTree->printDesc();
                break;}
            case 7:{
                twoThreeTree->isTT() ? std::cout << "Sí es 2-3!" << std::endl : std::cout << "No es 2-3" << std::endl;
                break;}
            case 8:{
                std::cout << "Adios!" << std::endl;
                done = true;
                break;
                }
            default:
                std::cout << "Opción inválida, elige otra" << std::endl;
                break;
        }
    }
}

template <class T>
void showcaseB(BTree<T>* bTree)
{
    int choice;
    bool done = false;
    while(!done)
    {
        std::cout << "===== Árbol B ===== " << std::endl;
        std::cout << "1) Mostrar ejemplo de funcionamiento" << std::endl;
        std::cout << "2) Insertar Dato" << std::endl;
        std::cout << "3) Borrar Dato" << std::endl;
        std::cout << "4) Buscar Dato" << std::endl;
        std::cout << "5) Imprimir ascendentemente" << std::endl;
        std::cout << "6) Imprimir descendentemente" << std::endl;
        std::cout << "7) Verificar si el árbol es AVL" << std::endl;
        std::cout << "8) Salir" << std::endl;
        std::cout << "Elige una opción: ";
        while(!(std::cin >> choice)){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada inválida, intenta otra vez: ";
        }
        switch(choice)
        {
            case 1:{
                std::cout << "=======Inserción=======" << std::endl;
                std::cout << "Insertando 35" << std::endl;
                bTree->Insert(35);
                std::cout << "Insertando 7" << std::endl;
                bTree->Insert(7);
                std::cout << "Insertando 10" << std::endl;
                bTree->Insert(10);
                std::cout << "Insertando 1" << std::endl;
                bTree->Insert(1);
                std::cout << "Insertando 57" << std::endl;
                bTree->Insert(57);
                std::cout << "Insertando 33" << std::endl;
                bTree->Insert(33);
                std::cout << "Insertando 68" << std::endl;
                bTree->Insert(68);
                std::cout << "=======Borrado=======" << std::endl;
                bTree->printNodes();
                std::cout << "Borrando 7" << std::endl;
                bTree->Delete(7);
                std::cout << "=======Búsqueda=======" << std::endl;
                bTree->searchForNode(35) ? std::cout << "Se encontró 35" << std::endl : std::cout << "No se encontró 35" << std::endl;
                bTree->searchForNode(100) ? std::cout << "Se encontró 100" << std::endl : std::cout << "No se encontró 100" << std::endl;
                std::cout << "=======Impresión ascendente=======" << std::endl;
                bTree->printAsc();
                std::cout << "=======Impresión descendente=======" << std::endl;
                bTree->printDesc();
                std::cout << "=======Verificación=======" << std::endl;
                bTree->isBTree() ? std::cout << "Sí es árbol B!" << std::endl : std::cout << "No es árbol B" << std::endl;
                //std::cout << bTree->getLevel() << std::endl;
                
                break;}
            case 2:{
                int val;
                std::cout << "Valor a insertar: ";
                while(!(std::cin >> val)){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Entrada inválida, intenta otra vez: ";
                }
                bTree->Insert(val);
                std::cout << "Valor insertado correctamente..." << std::endl;
                break;}
            case 3:{
                int val;
                std::cout << "Valor a borrar: ";
                while(!(std::cin >> val)){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Entrada inválida, intenta otra vez: ";
                }
                bTree->Delete(val);
                std::cout << "Valor borrado correctamente..." << std::endl;
                break;}
            case 4:{
                int val;
                std::cout << "Valor a buscar: ";
                while(!(std::cin >> val)){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Entrada inválida, intenta otra vez: ";
                }
                bTree->searchForNode(val) ? std::cout << "Valor encontrado!" << std::endl : std::cout << "Valor no encontrado" << std::endl;
                break;}
            case 5:{
                std::cout << "==============Árbol ascendente==============" << std::endl;
                bTree->printAsc();
                break;}
            case 6:{
                std::cout << "==============Árbol descendente==============" << std::endl;
                bTree->printDesc();
                break;}
            case 7:{
                //bTree->verificarArbol(bTree) ? std::cout << "Sí es árbol B!" << std::endl : std::cout << "No es árbol B" << std::endl;
                break;}
            case 8:{
                std::cout << "Adios!" << std::endl;
                done = true;
                break;}
            default:
                std::cout << "Opción inválida, elige otra" << std::endl;
                break;
        }
    }
}

#endif
