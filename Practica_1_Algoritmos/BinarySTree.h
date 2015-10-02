#ifndef BinarySTree_h
#define BinarySTree_h

#include "BinaryTree.h"

template <class T>
class BinarySTree: public BinaryTree<T> 
{
public:
    BinarySTree();
    ~BinarySTree();
    
    BNode<T> * search(const T value) const;
    BNode<T> * search(const T value, BNode<T> * node) const;
    
     BNode<T> * insert(T value);
};

template <class T>
BinarySTree<T>::BinarySTree() : BinaryTree<T>() {}

template <class T>
BinarySTree<T>::~BinarySTree()
{
    
}

template <class T>
BNode<T> * BinarySTree<T>::search(const T value) const{
    return search(value, this->root);

}

template <class T>
BNode<T> * BinarySTree<T>::search(const T value, BNode<T> * node)const 
{
    if (node == nullptr)
    {
        return nullptr;
    }
    else {
        T nodeValue = node->getInfo();
        if (value == nodeValue)
        {
            return node;
        }
        else if (value < nodeValue)
        {
            return search(value, node->getLeft());
        }
        else {
            return search(value, node->getRight());
        }
    }
}

template <class T>
BNode<T> * BinarySTree<T>::insert(T value)
{
    BNode<T> * nodo = new BNode<T>(value);
    BNode<T> * padre;
    
    nodo->setRight(nullptr);
    nodo->setLeft(nullptr);
    
    padre = nodo->getParent();
    
    if(this->empty())
    {
        this->setRoot(nodo);
    }
    else
    {
        BNode<T> * actual = new BNode<T>();
        actual = this->getRoot();
        
        while (actual)
        {
            padre = actual;
            
            if(nodo->getInfo() >= actual->getInfo())
            {
                actual = actual->getRight();
            }
            else
            {
                actual = actual->getLeft();
            }
        }
        
        if(nodo->getInfo() >= padre->getInfo())
        {
            padre->setRight(nodo);
            nodo->setParent(padre);
        }
        else
        {
            padre->setLeft(nodo);
            nodo->setParent(padre);
        }
    }
    return nodo;
}


#endif /* BinarySTree_h */
