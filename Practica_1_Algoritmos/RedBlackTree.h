//
//  RedBlackTree.h
//  Practica_1_Algoritmos
//
//  Created by alexis matuk on 9/6/15.
//  Copyright (c) 2015 alexis matuk. All rights reserved.
//

#ifndef Practica_1_Algoritmos_RedBlackTree_h
#define Practica_1_Algoritmos_RedBlackTree_h
#include "RBNode.h"
#include <iomanip>

template <class T>
class RedBlackTree {
    
protected:
    RBNode<T> * root = nullptr;
    
public:
    RedBlackTree() {}
     ~RedBlackTree();
    
     bool empty();
    
     void clear();
     void clear(RBNode<T> * node);
    
     RBNode<T> * getRoot() const;
     void setRoot(const T element);
     void setRoot(RBNode<T> * node);
     bool isRoot(RBNode<T> * node);
    
    bool insert(RBNode<T> * parent, const T value);
    bool insert(RBNode<T> * parent, RBNode<T> * value);
    void insert(const T item);
    void insert(RBNode<T> * item);
    
     void insertOrder(T item);
     void insertOrder(RBNode<T> * item);
     void insertOrder(RBNode<T> * parent, RBNode<T> * item);
    
     void preOrder() const;
     void preOrder(RBNode<T> * node) const;
    
     void inOrder() const;
     void inOrder(RBNode<T> * node) const;
    
     void inverseInOrder() const;
     void inverseInOrder(RBNode<T> * node) const;
    
    void toInOrderArray(T * array, int arraySize);
    void toInOrderArray(RBNode<T> * node, T * array, int arraySize, int & i);
    
     void postOrder() const;
     void postOrder(RBNode<T> * node) const;
    
    void isLeaf() const;
    void isLeaf(RBNode<T> * node) const;
    
    void ancestors(RBNode<T> * node) const;
    
     int getHeight() const;
     int getHeight(RBNode<T> * node) const ;
    
     int getDepth() const;
     int getDepth(RBNode<T> * node) const;
    
     int getLevel() const;
     int getLevel(RBNode<T> * node) const;
    
     int getBalanceFactor() const;
     int getBalanceFactor(RBNode<T> * node) const ;
    
    void prettyPrint();
    void prettyPrint(RBNode<T>* node, int indent);
    bool isAvl(RBNode<T> * node) const;
    
};

template <class T>
void RedBlackTree<T>::prettyPrint()
{
    prettyPrint(root, 0);
}

template <class T>
void RedBlackTree<T>::prettyPrint(RBNode<T>* p, int indent)
{
    if(p != NULL) {
        if(p->getRight()) {
            prettyPrint(p->getRight(), indent+4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        if (p->getRight()) std::cout<<" /\n" << std::setw(indent) << ' ';
        std::cout<< p->getInfo() << "\n ";
        if(p->getLeft()) {
            std::cout << std::setw(indent) << ' ' <<" \\\n";
            prettyPrint(p->getLeft(), indent+4);
        }
    }
}

template <class T>
void RedBlackTree<T>::insert(const T item)
{
    this->insertOrder(item);
}

template <class T>
void RedBlackTree<T>::insert(RBNode<T> * item)
{
    this->insertOrder(item);
}

template <class T>
RedBlackTree<T>::~RedBlackTree()
{
    clear();
}

template <class T>
bool RedBlackTree<T>::empty()
{
    return root == nullptr;
}

template <class T>
void RedBlackTree<T>::clear()
{
    clear(root);
}

template <class T>
void RedBlackTree<T>::clear(RBNode<T> * node)
{
    if (node) {
        clear(node->getLeft());
        clear(node->getRight());
        
        delete node;
    }
}

template <class T>
RBNode<T> * RedBlackTree<T>::getRoot() const
{
    return root;
}

template <class T>
void RedBlackTree<T>::setRoot(const T element)
{
    RBNode<T> * node = new RBNode<T>(element);
    setRoot(node);
}

template <class T>
void RedBlackTree<T>::setRoot(RBNode<T> * node)
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
bool RedBlackTree<T>::isRoot(RBNode<T> * node){
    return node == this->root;
}

template <class T>
void RedBlackTree<T>::insertOrder(T item)
{
    RBNode<T> * node = new RBNode<T>(item);
    insertOrder(this->root, node);
}

template <class T>
void RedBlackTree<T>::insertOrder(RBNode<T> * item)
{
    insertOrder(this->root, item);
}

template <class T>
void RedBlackTree<T>::insertOrder(RBNode<T> * parent, RBNode<T> * item)
{
    if (empty())
    {
        setRoot(item);
    }
    else
    {
        if(item->getInfo() < parent->getInfo())
        {
            
            if (parent->getLeft() == nullptr)
            {
                parent->setLeft(item);
                item->setParent(parent);
            }
            else
            {
                insertOrder(parent->getLeft(), item);
            }
        }
        else
        {
            if (parent->getRight() == nullptr)
            {
                parent->setRight(item);
                item->setParent(parent);
            }
            else
            {
                insertOrder(parent->getRight(), item);
            }
        }
    }
    
}

template <class T>
bool RedBlackTree<T>::insert(RBNode<T> * parent, const T value)
{
    RBNode<T> * node = new RBNode<T>(value);
    bool inserted = insert(parent, node);
    
    if (!inserted) delete node;
    
    return inserted;
}

template <class T>
bool RedBlackTree<T>::insert(RBNode<T> * parent, RBNode<T> * value)
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
void RedBlackTree<T>::preOrder() const
{
    preOrder(root);
}

template <class T>
void RedBlackTree<T>::preOrder(RBNode<T> * node) const
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
void RedBlackTree<T>::inOrder() const
{
    inOrder(root);
}

template <class T>
void RedBlackTree<T>::inOrder(RBNode<T> * node) const
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
void RedBlackTree<T>::inverseInOrder() const
{
    inverseInOrder(root);
}

template <class T>
void RedBlackTree<T>::inverseInOrder(RBNode<T> * node) const
{
    if (node)
    {
        inverseInOrder(node->getRight());
        std::cout << *node << std::endl;
        inverseInOrder(node->getLeft());
    }
}

// REQUIRES: arraySize is size of array.
// MODIFIES: array.
// EFFECTS: Returns the array representation of the tree in inorder.
template <class T>
void RedBlackTree<T>::toInOrderArray(T * array, int arraySize)
{
    int i = 0;
    toInOrderArray(root, array, arraySize, i);
}

// REQUIRES: arraySize is the size of the array.
// MODIFIES: array.
// EFFECTS: Adds the tree's elements to array in inorder.
template <class T>
void RedBlackTree<T>::toInOrderArray(RBNode<T> * node, T * array,int arraySize, int & i)
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
void RedBlackTree<T>::postOrder() const
{
    postOrder(root);
}

template <class T>
void RedBlackTree<T>::postOrder(RBNode<T> * node) const
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
void RedBlackTree<T>::isLeaf() const
{
    isLeaf(root);
}

template <class T>
void RedBlackTree<T>::isLeaf(RBNode<T> * node) const
{
    if (node) {
        if (!node->getLeft() && !node->getRight()) {
            std::cout << *node << std::endl;
        }
        else {
            isLeaf(node->getLeft());
            isLeaf(node->getRight());
        }
    }
}

template <class T>
void RedBlackTree<T>::ancestors(RBNode<T> * node) const
{
    if (node) {
        std::cout << *node << " -> ";
        ancestors(node->getParent());
    }
}

template <class T>
int RedBlackTree<T>::getHeight() const
{
    return getHeight(root);
}

template <class T>
int RedBlackTree<T>::getHeight(RBNode<T> * node) const
{
    if (!node) return -1;
    return 1 + std::max(getHeight(node->getLeft()), getHeight(node->getRight()));
}

template <class T>
int RedBlackTree<T>::getDepth() const
{
    return getDepth(root);
}

template <class T>
int RedBlackTree<T>::getDepth(RBNode<T> * node) const
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
int RedBlackTree<T>::getLevel() const
{
    return getLevel(root);
}

template <class T>
int RedBlackTree<T>::getLevel(RBNode<T> * node) const
{
    return getDepth(node) +1;
}

template <class T>
int RedBlackTree<T>::getBalanceFactor() const
{
    return getBalanceFactor(root);
}

template <class T>
int RedBlackTree<T>::getBalanceFactor(RBNode<T> * node) const
{
    return getHeight(node->getRight()) - getHeight(node->getLeft());
}

template <class T>
bool RedBlackTree<T>::isAvl(RBNode<T> * node) const
{
    static bool avl=false;
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
