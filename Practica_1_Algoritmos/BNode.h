//
//  BNode.h
//  Practica_1_Algoritmos
//
//  Created by alexis matuk on 9/5/15.
//  Copyright (c) 2015 alexis matuk. All rights reserved.
//

#ifndef Practica_1_Algoritmos_BNode_h
#define Practica_1_Algoritmos_BNode_h

#include <iostream>


template <class T>
class BNode {
protected:
    BNode<T> * parent = nullptr;
    BNode<T> * left = nullptr;
    BNode<T> * right = nullptr;
    
    T info;
    
public:
    
    BNode() { }
    BNode(const T & _info) : info (_info) { }
    BNode(const BNode<T> & );
    
    virtual ~BNode();
    
    T getInfo() const { return info; }
    void setInfo(const T & value) { info = value; }
    
     BNode<T> * getLeft() const { return left; }
     void setLeft(BNode<T> * value) { left = value; }
    
     BNode<T> * getRight() const { return right; }
     void setRight(BNode<T> * value) { right = value; }
    
     BNode<T> * getParent() const { return parent; }
     void setParent(BNode<T> * value) { parent = value; }
    
    template <typename Tn>
    friend std::ostream & operator << (std::ostream & os, const BNode<Tn>  & node);
};

template <class T>
BNode<T>::BNode(const BNode<T> & other)
{
    info = other.info;
    left = other.left;
    right = other.right;
    parent = other.parent;
}

template <class T>
BNode<T>::~BNode()
{
    info.~T();
    left = right = parent = nullptr;
}


template <class T>
std::ostream & operator << (std::ostream & os, const BNode<T>  & node)
{
    os << node.info;
    
    return os;
}



#endif