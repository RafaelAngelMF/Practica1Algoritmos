//
//  TTTree.h
//  Practica_1_Algoritmos
//
//  Created by alexis matuk on 9/6/15.
//  Copyright (c) 2015 alexis matuk. All rights reserved.
//

#ifndef Practica_1_Algoritmos_TTTree_h
#define Practica_1_Algoritmos_TTTree_h
#include "TTNode.h"
#include <iomanip>
#include <queue>
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

template <class T>
class TTTree {
    
protected:
    TTNode<T> * root = nullptr;
    std::vector<T> leafLevels;
    
public:
    TTTree() {}
    ~TTTree();
    
    bool empty();
    
    void clear();
    void clear(TTNode<T> * node);
    
    TTNode<T> * getRoot() const;
    void setRoot(const T element);
    void setRoot(TTNode<T> * node);
    bool isRoot(TTNode<T> * node);
    
    bool insert(TTNode<T> * parent, const T value);
    bool insert(TTNode<T> * parent, TTNode<T> * value);
    void insert(const T item);
    void insert(TTNode<T> * item);
    
    void insert23(T item);
    void insert23(TTNode<T> * item);
    void insert23(TTNode<T> * parent, TTNode<T> * item);
    
    void preOrder() const;
    void preOrder(TTNode<T> * node) const;
    
    void inOrder() const;
    void inOrder(TTNode<T> * node) const;
    
    void inverseInOrder() const;
    void inverseInOrder(TTNode<T> * node) const;
    
    void toInOrderArray(T * array, int arraySize);
    void toInOrderArray(TTNode<T> * node, T * array, int arraySize, int & i);
    
    void postOrder() const;
    void postOrder(TTNode<T> * node) const;
    
    void isLeaf() ;
    bool isLeaf(TTNode<T> * node) ;
    
    void ancestors(TTNode<T> * node) const;
    
    int getHeight() const;
    int getHeight(TTNode<T> * node) const ;
    
    int getDepth() const;
    int getDepth(TTNode<T> * node) const;
    
    int getLevel() const;
    int getLevel(TTNode<T> * node) const;
    
    int getBalanceFactor() const;
    int getBalanceFactor(TTNode<T> * node) const ;
    
    bool isAvl(TTNode<T> * node) const;
    
    void forceRoot(TTNode<T>* root);
    TTNode<T>* searchForNode(const T item, TTNode<T> * node);
    void insert23(TTNode<T> * parent, T item);
    void redistributeChildren(TTNode<T>* container, TTNode<T>* n1, TTNode<T>* n2);
    void print23(TTNode<T> * node, int level);
    void print23();
    void split(TTNode<T>* container);
    bool is2Node(TTNode<T>* node);
    bool is3Node(TTNode<T>* node);
    bool hasFreeChildren(TTNode<T>* node);
    bool isTT(TTNode<T>* node);
    void getLeafLevels(TTNode<T>* node);
    bool getNodeKeys(TTNode<T>* node);
    bool getNodeChildren(TTNode<T>* node);
    bool findNode(TTNode<T>*, T value);
    TTNode<T>* findNodeToDelete(TTNode<T>*, T value);
    bool deleteNode(TTNode<T>* node);
    bool deleteNode(T value);
    void fixTree(TTNode<T>* node);
    TTNode<T>* getInorderSuccesor(TTNode<T>* node);
    bool isTT ();
    void sort(T a[], int N);
};


template <class T>
void TTTree<T>::insert(const T item)
{
    this->insertOrder(item);
}

template <class T>
void TTTree<T>::insert(TTNode<T> * item)
{
    this->insertOrder(item);
}

template <class T>
TTTree<T>::~TTTree()
{
    clear();
}

template <class T>
bool TTTree<T>::empty()
{
    return root == nullptr;
}

template <class T>
void TTTree<T>::clear()
{
    clear(root);
}

template <class T>
void TTTree<T>::clear(TTNode<T> * node)
{
    if (node) {
        clear(node->getLeft());
        clear(node->getRight());
        delete node;
    }
}

template <class T>
TTNode<T> * TTTree<T>::getRoot() const
{
    return root;
}

template <class T>
void TTTree<T>::setRoot(const T element)
{
    TTNode<T> * node = new TTNode<T>(element);
    setRoot(node);
}

template <class T>
void TTTree<T>::setRoot(TTNode<T> * node)
{
    if (!empty()) {
        node->setLeft(root);
        root->setParent(node);
        root = node;
    }
    else {
        root = node;
    }
}

template <class T>
bool TTTree<T>::isRoot(TTNode<T> * node){
    return node == this->root;
}

template <class T>
void TTTree<T>::insert23(T item)
{
    //TTNode<T> * node = new TTNode<T>(item);
    insert23(this->root, item);
}

template <class T>
void TTTree<T>::insert23(TTNode<T> * item)
{
    insert23(this->root, item);
}

template <class T>
void TTTree<T>::forceRoot(TTNode<T>* node)
{
    root = node;
}

template <class T>
void TTTree<T>::redistributeChildren(TTNode<T>* container, TTNode<T>* n1, TTNode<T>* n2)
{
    n1->setLeft(container->getLeft());
    n1->setRight(container->getMiddle());
    n2->setLeft(container->getTempChild());
    n2->setRight(container->getRight());
    n1->getLeft()->setParent(n1);
    n1->getRight()->setParent(n1);
    n2->getLeft()->setParent(n2);
    n2->getRight()->setParent(n2);
}

template <class T>
void TTTree<T>::split(TTNode<T>* container)
{
    if(isRoot(container))
    {
        TTNode<T>* newRoot = new TTNode<T>(container->getTempMiddle());
        forceRoot(newRoot);
        TTNode<T>* n1 = new TTNode<T>(container->getLower());
        TTNode<T>* n2 = new TTNode<T>(container->getHigher());
        if(container->getTempChild()!=nullptr)
            redistributeChildren(container, n1, n2);
        newRoot->setLeft(n1);
        newRoot->setRight(n2);
        newRoot->getLeft()->setParent(newRoot);
        newRoot->getRight()->setParent(newRoot);
        delete container;
    }
    else if(container->getParent() != nullptr)
    {
        TTNode<T>* parent = container->getParent();
        if(parent->isFull())
        {
            parent->setMiddleValue(container->getTempMiddle());
            if(parent->getRight() == container)
            {
                TTNode<T>* n1 = new TTNode<T>(container->getLower());
                TTNode<T>* n2 = new TTNode<T>(container->getHigher());
                if(container->getTempChild()!=nullptr)
                    redistributeChildren(container, n1, n2);
                parent->setRight(n2);
                parent->setTempChild(n1);
                parent->getRight()->setParent(parent);
                parent->getTempChild()->setParent(parent);
                delete container;
            }
            else if(parent->getLeft() == container)
            {
                TTNode<T>* n1 = new TTNode<T>(container->getLower());
                TTNode<T>* n2 = new TTNode<T>(container->getHigher());
                if(container->getTempChild()!=nullptr)
                    redistributeChildren(container, n1, n2);
                parent->setLeft(n1);
                parent->setTempChild(parent->getMiddle());
                parent->setMiddle(n2);
                parent->getLeft()->setParent(parent);
                parent->getMiddle()->setParent(parent);
                parent->getTempChild()->setParent(parent);
                delete container;
                
            }
            else
            {
                TTNode<T>* n1 = new TTNode<T>(container->getLower());
                TTNode<T>* n2 = new TTNode<T>(container->getHigher());
                if(container->getTempChild()!=nullptr)
                    redistributeChildren(container, n1, n2);
                parent->setMiddle(n1);
                parent->setTempChild(n2);
                parent->getMiddle()->setParent(parent);
                parent->getTempChild()->setParent(parent);
                delete container;
            }
            split(parent);
        }
        else
        {
            parent->setValue(container->getTempMiddle());
            if(parent->getRight() == container)
            {
                TTNode<T>* n1 = new TTNode<T>(container->getLower());
                TTNode<T>* n2 = new TTNode<T>(container->getHigher());
                if(container->getTempChild()!=nullptr)
                    redistributeChildren(container, n1, n2);
                parent->setRight(n2);
                parent->setMiddle(n1);
                parent->getRight()->setParent(parent);
                parent->getMiddle()->setParent(parent);
                delete container;
            }
            else if(parent->getLeft() == container)
            {
                TTNode<T>* n1 = new TTNode<T>(container->getLower());
                TTNode<T>* n2 = new TTNode<T>(container->getHigher());
                if(container->getTempChild()!=nullptr)
                    redistributeChildren(container, n1, n2);
                parent->setLeft(n1);
                parent->setMiddle(n2);
                parent->getLeft()->setParent(parent);
                parent->getMiddle()->setParent(parent);
                delete container;
            }
            if(parent->has3Keys())
                split(parent);
        }
    }
}

template <class T>
bool TTTree<T>:: is2Node(TTNode<T>* node)
{
    if((node->hasLower() && !node->hasHigher()) || (!node->hasLower() && node->hasHigher()))
        return true;
    else
        return false;
}

template <class T>
bool TTTree<T>:: is3Node(TTNode<T>* node)
{
    if(node->hasLower() && node->hasHigher())
        return true;
    else
        return false;
}

template <class T>
bool TTTree<T>::hasFreeChildren(TTNode<T>* node)
{
    if(node->getLeft() == nullptr || node->getMiddle() == nullptr || node->getRight() == nullptr)
        return true;
    else
        return false;
}

template <class T>
void TTTree<T>::insert23(TTNode<T> * parent, T item)
{
    TTNode<T>* container = new TTNode<T>();
    if(root == nullptr)
    {
        forceRoot(new TTNode<T>(item));
        return;
    }
    container = searchForNode(item, root);
    if(is2Node(container))
    {
        container->setValue(item);
        container->deleteTempMiddle();
    }
    else if(is3Node(container))
    {
        container->setMiddleValue(item);
        split(container);
    }
}

template <class T>
TTNode<T>* TTTree<T>::searchForNode(const T value, TTNode<T> * node)
{
    if(node == nullptr)
        return nullptr;
    if(isLeaf(node))
        return node;
    else if(is2Node(node))
    {
        if(value <= node->getLower())
            return searchForNode(value, node->getLeft());
        else
            return searchForNode(value, node->getRight());
    }
    else if(is3Node(node))
    {
        if(value <= node->getLower())
            return searchForNode(value, node->getLeft());
        else if(value > node->getHigher())
            return searchForNode(value, node->getRight());
        else
            return searchForNode(value, node->getMiddle());
    }
    return node;
}

template <class T>
void TTTree<T>::print23()
{
    print23(root, 0);
    std::cout << std::endl;
}

template <class T>
void TTTree<T>::print23(TTNode<T> * node, int lv)
{
    if(node == nullptr) return;
    if(isLeaf(node))
    {
        std::cout << "Level: " << lv++ << " ";
        if(is2Node(node))
        {
            std::cout << node->getLower() << " ";
        }
        else if(is3Node(node))
        {
            std::cout << node->getLower() << " " << node->getHigher();
        }
    }
    else if(is2Node(node))
    {
        std::cout << "Level: " << lv++ << " ";
        std::cout << node->getLower() << " ";
        print23(node->getLeft(), lv);
        print23(node->getRight(), lv);
    }
    else if(is3Node(node))
    {
        std::cout << "Level: " << lv++ << " ";
        std::cout << node->getLower() << " ";
        std::cout << node->getHigher() << " ";
        print23(node->getLeft(), lv);
        print23(node->getMiddle(), lv);
        print23(node->getRight(), lv);
    }
        if(node == nullptr) return;
        if(isLeaf(node))
        {
            if(is2Node(node))
            {
                std::cout << node->getLower() << " ";
            }
            else if(is3Node(node))
            {
                std::cout << node->getLower() << " " << node->getHigher();
            }
        }
        else if(is2Node(node))
        {
            std::cout << node->getLower() << " ";
            print23(node->getLeft(), lv);
            print23(node->getRight(), lv);
        }
        else if(is3Node(node))
        {
            std::cout << "Level: " << lv++ << " ";
            print23(node->getLeft(), lv);
            std::cout << node->getLower() << " ";
            std::cout << node->getHigher() << " ";
            print23(node->getMiddle(), lv);
            std::cout << node->getLower() << " ";
            std::cout << node->getHigher() << " ";
            print23(node->getRight(), lv);
        }
    
}

//Completa el delete cuando el nodo esta vacio por borrar la raiz, redistribuir valores o mergear nodos.
//Si n es interno tiene un hijo
template <class T>
void TTTree<T>::fixTree(TTNode<T>* node)
{
    if(isRoot(node))
    {
        forceRoot(node->getMiddle());
        delete node;
    }
    else
    {
        bool threeKeys = false;
        TTNode<T>* parent = node->getParent();//let p be the parent of n
        //=====IF SOME SIBLING OF N HAS 2 ITEMS====
        if(is2Node(parent))
        {
            TTNode<T>* sibling = new TTNode<T>();
            if(parent->getRight() == node)//soy derecho
                sibling = parent->getLeft();
            else//soy izquierdo
                sibling = parent->getRight();
            if(parent->getRight() == node)
            {
                //soy hijo derecho
                //======YA ENTRO A ESTE CASO======
                if(is3Node(parent->getLeft()))
                {
                    threeKeys = true;
                    T siblingLower = sibling->getLower();
                    T siblingHigher = sibling->getHigher();
                    T parentVal = parent->getLower();
                    T keys[3] = {siblingLower,siblingHigher,parentVal};
                    sort(keys,3);
                    T low = keys[0];
                    T mid = keys[1];
                    T high = keys[2];
                    
                    //if some sibling of n has 2 items
                    //Distribute items among n, the sibling and p
                    node->setValue(high);
                    parent->deleteAllKeys();
                    parent->setValue(mid);
                    sibling->deleteAllKeys();
                    sibling->setValue(low);
                    
                    //======YA ENTRO A ESTE CASO======
                    if(!isLeaf(node))
                    {
                        //MOVE THE APPROPRIATE CHILD FROM SIBLING TO N
                        node->setRight(node->getMiddle());
                        node->setMiddle(nullptr);
                        node->setLeft(sibling->getRight());
                        node->getLeft()->setParent(node);
                        sibling->setRight(sibling->getMiddle());
                        sibling->setMiddle(nullptr);
                    }
                }
            }
            else
            {
                //soy hijo izquierdo
                //======YA ENTRO A ESTE CASO======
                if(is3Node(parent->getRight()))
                {
                    threeKeys = true;
                    T siblingLower = sibling->getLower();
                    T siblingHigher = sibling->getHigher();
                    T parentVal = parent->getLower();
                    T keys[3] = {siblingLower,siblingHigher,parentVal};
                    sort(keys,3);
                    T low = keys[0];
                    T mid = keys[1];
                    T high = keys[2];
                    //if some sibling of n has 2 items
                    //Distribute items among n, the sibling and p
                    node->setValue(low);
                    parent->deleteAllKeys();
                    parent->setValue(mid);
                    sibling->deleteAllKeys();
                    sibling->setValue(high);
                    
                    //======YA ENTRO A ESTE CASO======
                    if(!isLeaf(node))
                    {
                        //MOVE THE APPROPRIATE CHILD FROM SIBLING TO N
                        node->setLeft(node->getMiddle());
                        node->setMiddle(nullptr);
                        node->setRight(sibling->getLeft());
                        node->getRight()->setParent(node);
                        sibling->setLeft(sibling->getMiddle());
                        sibling->setMiddle(nullptr);//TENEMOS QUE HACER QUE LA REFERNCIA SIEMPRE SE QUEDE EN MEDIO
                    }
                }
            }
        }
        else if(is3Node(parent))//======NO HA ENTRADO A NINGUN SUBCASO======
        {
            TTNode<T>* sibling = new TTNode<T>();
            if(parent->getRight() == node)
            {
                //======ME ESTOY PASANDO DE AMIGO, NO ME LA CREO======
                if(is3Node(parent->getMiddle()))
                {
                    threeKeys = true;
                    //mi sibling es el del medio
                    sibling = parent->getMiddle();
                    node->setValue(parent->getHigher());
                    parent->setHigher(sibling->getHigher());
                    sibling->deleteHigher();
                    if(!isLeaf(node))
                    {
                        //======YA ENTRO A ESTE CASO======
                        //MOVE THE APPROPRIATE CHILD FROM SIBLING TO N
                        node->setRight(node->getMiddle());
                        node->setLeft(sibling->getRight());
                        node->getLeft()->setParent(node);
                        sibling->setRight(sibling->getMiddle());
                        sibling->setMiddle(nullptr);
                    }
                    //if some sibling of n has 2 items
                    //Distribute items among n, the sibling and p
                }
            }
            else if(parent->getMiddle() == node)
            {
                //======YA ENTRO A ESTE CASO======
                if(is3Node(parent->getLeft()))
                {
                    threeKeys = true;
                    //mi sibling es el izquierdo
                    sibling = parent->getLeft();
                    node->setValue(parent->getLower());
                    parent->setLower(sibling->getHigher());
                    sibling->deleteHigher();
                    if(!isLeaf(node))
                    {
                        //======YA ENTRO A ESTE CASO======
                        //MOVE THE APPROPRIATE CHILD FROM SIBLING TO N
                        node->setRight(node->getMiddle());
                        node->setLeft(sibling->getRight());
                        node->getLeft()->setParent(node);
                        sibling->setRight(sibling->getMiddle());
                        sibling->setMiddle(nullptr);
                    }
                    //if some sibling of n has 2 items
                    //Distribute items among n, the sibling and p
                }
            }
            else
            {
                //======YA ENTRO A ESTE CASO======
                if(is3Node(parent->getMiddle()))
                {
                    threeKeys = true;
                        //======YA ENTRO A ESTE CASO======
                        //mi sibling es el medio
                        sibling = parent->getMiddle();
                        node->setValue(parent->getLower());
                        parent->setLower(sibling->getLower());
                        sibling->swapHigherToLower();
                        if(!isLeaf(node))
                        {
                            //MOVE THE APPROPRIATE CHILD FROM SIBLING TO N
                            node->setLeft(node->getMiddle());
                            node->setRight(sibling->getLeft());
                            node->getRight()->setParent(node);
                            sibling->setLeft(sibling->getMiddle());
                            sibling->setMiddle(nullptr);
                        }
                    //if some sibling of n has 2 items
                    //Distribute items among n, the sibling and p
                }
            }
        }
        if(!threeKeys)//IF THERE ARE NO SIBLINGS WITH 3 ITEMS, MERGE THE NODE
        {
            TTNode<T>* sibling = new TTNode<T>();
            //CHOOSE ADJACENT SIBLING
            if(is2Node(parent))
            {
                if(parent->getRight() == node)//soy derecho
                {
                    //======YA ENTRO A ESTE CASO======
                    sibling = parent->getLeft();
                    sibling->setValue(parent->getLower());//bring item down
                    if(!isLeaf(node))
                    {
                        //======YA ENTRO A ESTE CASO======
                        //move n's child to s
                        sibling->setMiddle(sibling->getRight());
                        sibling->setRight(node->getMiddle());//TENEMOS QUE HACER QUE LA REFERNCIA SIEMPRE SE QUEDE EN MEDIO
                    }
                    parent->setMiddle(sibling);
                    parent->getMiddle()->setParent(parent);
                    parent->setLeft(nullptr);
                    parent->setRight(nullptr);
                    parent->deleteAllKeys();
                    delete node;
                }
                else//soy izquierdo
                {
                    //======YA ENTRO A ESTE CASO======
                    sibling = parent->getRight();
                    sibling->setValue(parent->getLower());
                    if(!isLeaf(node))
                    {
                        //======YA ENTRO A ESTE CASO======
                        //move n's child to s
                        sibling->setMiddle(sibling->getLeft());
                        sibling->setLeft(node->getMiddle());//TENEMOS QUE HACER QUE LA REFERNCIA SIEMPRE SE QUEDE EN MEDIO
                        sibling->getLeft()->setParent(sibling);
                    }
                    parent->setMiddle(sibling);
                    parent->getMiddle()->setParent(parent);
                    parent->setLeft(nullptr);
                    parent->setRight(nullptr);
                    parent->deleteAllKeys();
                    delete node;
                }
            }
            else if(is3Node(parent))//======YA ENTRO A TODOS LOS SUBCASOS  ======
            {
                //choose adjacent sibling of n
                //======YA ENTRO A ESTE CASO======
                if(parent->getRight() == node)//soy derecho
                {
                    sibling = parent->getMiddle();//agarro en medio
                    sibling->setValue(parent->getHigher());
                    if(!isLeaf(node))
                    {
                        //======YA ENTRO A ESTE CASO======
                        //move n's child to s
                        sibling->setMiddle(sibling->getRight());
                        sibling->setRight(node->getMiddle());//TENEMOS QUE HACER QUE LA REFERNCIA SIEMPRE SE QUEDE EN MEDIO
                        sibling->getRight()->setParent(sibling);
                    }
                    parent->setRight(sibling);
                    parent->getRight()->setParent(parent);
                    parent->setMiddle(nullptr);
                    parent->deleteHigher();
                    delete node;
                }
                //======YA ENTRO A ESTE CASO======
                else if(parent->getMiddle() == node)//soy medio
                {
                    sibling = parent->getLeft();//agarro a la izquierda
                    sibling->setValue(parent->getLower());
                    if(!isLeaf(node))
                    {
                        //======YA ENTRO A ESTE CASO======
                        //move n's child to s
                        sibling->setMiddle(sibling->getRight());
                        sibling->setRight(node->getMiddle());//TENEMOS QUE HACER QUE LA REFERNCIA SIEMPRE SE QUEDE EN MEDIO
                        sibling->getRight()->setParent(sibling);
                    }
                    parent->setLeft(sibling);
                    parent->getLeft()->setParent(parent);
                    parent->setMiddle(nullptr);
                    parent->deleteLower();
                    parent->swapHigherToLower();
                    delete node;
                }
                else//soy izquierdo
                {
                    //======YA ENTRO A ESTE CASO======
                    sibling = parent->getMiddle();//agarro en medio
                    sibling->setValue(parent->getLower());
                    if(!isLeaf(node))
                    {
                        //======YA ENTRO A ESTE CASO======
                        //move n's child to s
                        sibling->setMiddle(sibling->getLeft());
                        sibling->setLeft(node->getMiddle());//TENEMOS QUE HACER QUE LA REFERNCIA SIEMPRE SE QUEDE EN MEDIO
                        sibling->getLeft()->setParent(sibling);
                    }
                    parent->setLeft(sibling);
                    parent->getLeft()->setParent(parent);
                    parent->setMiddle(nullptr);
                    parent->deleteLower();
                    parent->swapHigherToLower();
                    delete node;
                }
            }
            //REMOVE NODE N
            if(parent->hasNoKeys())
            {
                sibling->setParent(parent);
                fixTree(parent);
            }
        }
    }
}

template <class T>
bool TTTree<T>::deleteNode(T value)
{
    TTNode<T>* node = new TTNode<T>();
    node = findNodeToDelete(root, value);
    if(node)
    {
        TTNode<T>* leafNode = new TTNode<T>();
        if(!isLeaf(node))
        {
            //Swap node with the inorder succesor, which will be in a leaf :)
            leafNode = getInorderSuccesor(node);
            T swapVal = leafNode->getLower();
            node->setLower(swapVal);
        }
        //El delete siempre empieza con una hoja?
        leafNode->deleteLower();
        if(leafNode->hasNoKeys())
        {
            fixTree(leafNode);
        }
        return true;
    }
    else
        return false;
}

template <class T>
TTNode<T>* TTTree<T>::getInorderSuccesor(TTNode<T>* node)
{
    if (node)
    {
        TTNode<T> * workingNode = node->getLeft();
        if(workingNode){
            while (workingNode->getRight() != nullptr)
            {
                workingNode = workingNode->getRight();
            }
            return workingNode;
        }
        return nullptr;
        
    } else{
        return nullptr;
    }
}

template <class T>
TTNode<T>* TTTree<T>::findNodeToDelete(TTNode<T>* node, T value)
{
    if(node == nullptr)
        return nullptr;
    if(isLeaf(node))
    {
        if(is2Node(node))
        {
            if(node->getLower() == value)
            {
                return node;
            }
        }
        else if(is3Node(node))
        {
            if(node->getLower() == value || node->getHigher() == value)
            {
                return node;
            }
        }
        return nullptr;
    }
    else if(is2Node(node))
    {
        if(value == node->getLower())
        {
            return node;
        }
        
        if(value < node->getLower())
            return findNodeToDelete(node->getLeft(), value);
        else
            return findNodeToDelete( node->getRight(), value);
    }
    else if(is3Node(node))
    {
        if(node->getLower() == value || node->getHigher() == value)
        {
            return node;
        }
        if(value < node->getLower())
            return findNodeToDelete(node->getLeft(), value);
        else if(value > node->getHigher())
            return findNodeToDelete(node->getRight(), value);
        else
            return findNodeToDelete(node->getMiddle(), value);
    }
    return nullptr;
}

template <class T>
bool TTTree<T>::findNode(TTNode<T>* node, T value)
{
    if(node == nullptr)
        return false;
    if(isLeaf(node))
    {
        if(is2Node(node))
        {
            if(node->getLower() == value)
            {
                return true;
            }
        }
        else if(is3Node(node))
        {
            if(node->getLower() == value || node->getHigher() == value)
            {
                return true;
            }
        }
        return false;
    }
    else if(is2Node(node))
    {
        if(value == node->getLower())
        {
            return true;
        }
        
        if(value < node->getLower())
            return findNode(node->getLeft(), value);
        else
            return findNode( node->getRight(), value);
    }
    else if(is3Node(node))
    {
        if(node->getLower() == value || node->getHigher() == value)
        {
            return true;
        }
        if(value < node->getLower())
            return findNode(node->getLeft(), value);
        else if(value > node->getHigher())
            return findNode(node->getRight(), value);
        else
            return findNode(node->getMiddle(), value);
    }
    return false;
}

template <class T>
bool TTTree<T>::isTT()
{
    return isTT(root);
}

template <class T>
bool TTTree<T>::isTT(TTNode<T>* node)
{
    leafLevels.clear();
    getLeafLevels(root);
    T cmp = leafLevels[0];
    bool leafs = true;
    for(int i=1; i<leafLevels.size(); i++)
    {
        if(leafLevels[i] != cmp)
            leafs = false;
    }
    return leafs;
}

template <class T>
void TTTree<T>::getLeafLevels(TTNode<T>* node)
{
    if(node == nullptr) return;
    if(isLeaf(node))
    {
        leafLevels.push_back(getLevel(node));
    }
    else if(is2Node(node))
    {
        getLeafLevels(node->getLeft());
        getLeafLevels(node->getRight());
    }
    else if(is3Node(node))
    {
        getLeafLevels(node->getLeft());
        getLeafLevels(node->getMiddle());
        getLeafLevels(node->getRight());
    }
}

template <class T>
bool TTTree<T>::insert(TTNode<T> * parent, const T value)
{
    TTNode<T> * node = new TTNode<T>(value);
    bool inserted = insert(parent, node);
    
    if (!inserted) delete node;
    
    return inserted;
}

template <class T>
bool TTTree<T>::insert(TTNode<T> * parent, TTNode<T> * value)
{
    bool inserted = false;
    
    if (empty() || !parent) {
        setRoot(value);
        inserted = true;
    }
    else {
        if (!parent->getLeft()) {
            parent->setLeft(value);
            value->setParent(parent);
            inserted = true;
        }
        else if (!parent->getRight()) {
            parent->setRight(value);
            value->setParent(parent);
            inserted = true;
        }
    }
    
    return inserted;
}

template <class T>
void TTTree<T>::preOrder() const
{
    preOrder(root);
}

template <class T>
void TTTree<T>::preOrder(TTNode<T> * node) const
{
    if (node) {
        /* Procesar el nodo */
        std::cout << *node << std::endl;
        
        /* Invocar a los hijos */
        preOrder(node->getLeft());
        preOrder(node->getRight());
        
    }
}

template <class T>
void TTTree<T>::inOrder() const
{
    inOrder(root);
}

template <class T>
void TTTree<T>::inOrder(TTNode<T> * node) const
{
    if (node) {
        
        /* Invocar al hijo izquierdo */
        inOrder(node->getLeft());
        
        /* Procesar el nodo */
        std::cout << *node << std::endl;
        
        /* Invocar al hijo derecho */
        inOrder(node->getRight());
    }
}

template <class T>
void TTTree<T>::inverseInOrder() const
{
    inverseInOrder(root);
}

template <class T>
void TTTree<T>::inverseInOrder(TTNode<T> * node) const
{
    if (node)
    {
        inverseInOrder(node->getRight());
        std::cout << *node << std::endl;
        inverseInOrder(node->getLeft());
    }
}

template <class T>
void TTTree<T>::toInOrderArray(T * array, int arraySize)
{
    int i = 0;
    toInOrderArray(root, array, arraySize, i);
}

template <class T>
void TTTree<T>::toInOrderArray(TTNode<T> * node, T * array,int arraySize, int & i)
{
    if (node)
    {
        toInOrderArray(node->getLeft(), array, arraySize, i);
        array[i] = node->getInfo();
        i++;
        toInOrderArray(node->getRight(), array, arraySize, i);
    }
}

template <class T>
void TTTree<T>::postOrder() const
{
    postOrder(root);
}

template <class T>
void TTTree<T>::postOrder(TTNode<T> * node) const
{
    if (node) {
        /* Invocar a los hijos */
        postOrder(node->getLeft());
        postOrder(node->getRight());
        
        /* Procesar el nodo */
        std::cout << *node << std::endl;
    }
}

template <class T>
void TTTree<T>::isLeaf()
{
    isLeaf(root);
}

template <class T>
bool TTTree<T>::isLeaf(TTNode<T> * node)
{
    if(node->getLeft() == nullptr && node->getMiddle() == nullptr && node->getRight() == nullptr)
        return true;
    else
        return false;
}

template <class T>
void TTTree<T>::ancestors(TTNode<T> * node) const
{
    if (node) {
        std::cout << *node << " -> ";
        ancestors(node->getParent());
    }
}

template <class T>
int TTTree<T>::getHeight() const
{
    return getHeight(root);
}

template <class T>
int TTTree<T>::getHeight(TTNode<T> * node) const
{
    if (!node) return -1;
    return 1 + std::max(getHeight(node->getLeft()), getHeight(node->getRight()));
}

template <class T>
int TTTree<T>::getDepth() const
{
    return getDepth(root);
}

template <class T>
int TTTree<T>::getDepth(TTNode<T> * node) const
{
    if (node == nullptr)
    {
        return 0;
    }
    else
    {
        return getDepth(node->getParent())+1;
    }
}

template <class T>
int TTTree<T>::getLevel() const
{
    return getLevel(root);
}

template <class T>
int TTTree<T>::getLevel(TTNode<T> * node) const
{
//    return getDepth(node) +1;
    int level = 0;
    while (node != nullptr && node->getParent() != nullptr) {
        level++;
        node = node->getParent();
    }
    return level;
}

template <class T>
int TTTree<T>::getBalanceFactor() const
{
    return getBalanceFactor(root);
}

template <class T>
int TTTree<T>::getBalanceFactor(TTNode<T> * node) const
{
    return getHeight(node->getRight()) - getHeight(node->getLeft());
}

template <class T>
bool TTTree<T>::isAvl(TTNode<T> * node) const
{
    bool avl;
    if(node && avl)
    {
        int factor = getBalanceFactor(node);
        if (factor <= 1 && factor >= -1)
        {
            isAvl(node->getLeft());
            isAvl(node->getRight());
        }
        else
        {
            avl = false;
        }
    }
    return avl;
}

template <class T>
void TTTree<T>::sort(T a[], int N)
{
        int i, j, flag = 1;    // set flag to 1 to start first pass
        int temp;             // holding variable
        int numLength = N;
        for(i = 1; (i <= numLength) && flag; i++)
        {
            flag = 0;
            for (j=0; j < (numLength -1); j++)
            {
                if (a[j+1] < a[j])      // ascending order simply changes to <
                {
                    temp = a[j];             // swap elements
                    a[j] = a[j+1];
                    a[j+1] = temp;
                    flag = 1;               // indicates that a swap occurred.
                }
            }
        }
        return;   //arrays are passed to functions by address; nothing is returned
}


#endif
