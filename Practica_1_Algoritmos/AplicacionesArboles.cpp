//
//  AplicacionesArboles.cpp
//  Practica_1_Algoritmos
//
//  Created by alexis matuk on 10/1/15.
//  Copyright (c) 2015 alexis matuk. All rights reserved.
//

#include <iostream>
#include "Showcases.h"

int main(int argc, const char * argv[])
{
    TTTree<int> * twoThreeTree = new TTTree<int>();
    RedBlackTree<int> * redBlackTree = new RedBlackTree<int>();
    AVLTree<int> * avlTree = new AVLTree<int>();
    std::cout << "========== Aplicaciones de árboles B, AVL, 2-3 y RojiNegro ==========" << std::endl;
    int choice;
    bool done = false;
    while(!done)
    {
        std::cout << "1) Árbol AVL" << std::endl;
        std::cout << "2) Árbol RojiNegro" << std::endl;
        std::cout << "3) Árbol 2-3" << std::endl;
        std::cout << "4) Árbol B" << std::endl;
        std::cout << "5) Salir" << std::endl;
        std::cout << "Elige una opción: ";
        while(!(std::cin >> choice)){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada inválida, intenta otra vez: ";
        }
        switch(choice)
        {
            case 1:{
                showcaseAVL(avlTree);
                break;}
            case 2:{
                showcaseRedBlack(redBlackTree);
                break;}
            case 3:{
                showcaseTT(twoThreeTree);
                break;}
            case 4:{
                int order;
                std::cout << "Escoge el orden el árbol" << std::endl;
                while(!(std::cin >> order)){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Entrada inválida, intenta otra vez: ";
                }
                BTree<int> * bTree = new BTree<int>(order);
                showcaseB(bTree);
                break;}
            case 5:{
                std::cout << "Adios!" << std::endl;
                done = true;
                break;}
            default:
                std::cout << "Opción inválida, elige otra" << std::endl;
                break;
        }
    }
}