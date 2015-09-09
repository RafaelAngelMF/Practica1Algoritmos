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
#include <vector>

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
//        if(node == nullptr) return;
//        if(isLeaf(node))
//        {
//            if(is2Node(node))
//            {
//                std::cout << node->getLower() << " ";
//            }
//            else if(is3Node(node))
//            {
//                std::cout << node->getLower() << " " << node->getHigher();
//            }
//        }
//        else if(is2Node(node))
//        {
//            std::cout << node->getLower() << " ";
//            print23(node->getLeft(), lv);
//            print23(node->getRight(), lv);
//        }
//        else if(is3Node(node))
//        {
//            std::cout << "Level: " << lv++ << " ";
//            print23(node->getLeft(), lv);
//            std::cout << node->getLower() << " ";
//            std::cout << node->getHigher() << " ";
//            print23(node->getMiddle(), lv);
//            std::cout << node->getLower() << " ";
//            std::cout << node->getHigher() << " ";
//            print23(node->getRight(), lv);
//        }
    
}

template <class T>
bool TTTree<T>::isTT(TTNode<T>* node)
{
    getLeafLevels(root);
    T cmp = leafLevels[0];
    for(int i=1; i<leafLevels.size(); i++)
    {
        if(leafLevels[i] != cmp)
         return false;
    }
    return true;
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
        return getDepth(node->getParent()) + 1;
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
    return getDepth(node) +1;
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


#endif
