//
//  RRBNode.h
//  Practica_1_Algoritmos
//
//  Created by alexis matuk on 9/6/15.
//  Copyright (c) 2015 alexis matuk. All rights reserved.
//

#ifndef Practica_1_Algoritmos_RBNode_h
#define Practica_1_Algoritmos_RBNode_h
#define BLACK "Black"
#define RED "Red"
#include <iostream>


template <class T>
class RBNode {
protected:
    RBNode<T> * parent = nullptr;
    RBNode<T> * left = nullptr;
    RBNode<T> * right = nullptr;
    std::string color = RED;
    T info;
    
public:
    
    RBNode() { }
    RBNode(const T & _info) : info (_info) { }
    RBNode(const RBNode<T> & );
    
    virtual ~RBNode();
    
    T getInfo() const { return info; }
    void setInfo(const T & value) { info = value; }
    
    RBNode<T> * getLeft() const { return left; }
    void setLeft(RBNode<T> * value) { left = value; }
    
    RBNode<T> * getRight() const { return right; }
    void setRight(RBNode<T> * value) { right = value; }
    
    RBNode<T> * getParent() const { return parent; }
    void setParent(RBNode<T> * value) { parent = value; }
    
    template <typename Tn>
    friend std::ostream & operator << (std::ostream & os, const RBNode<Tn>  & node);
};

template <class T>
RBNode<T>::RBNode(const RBNode<T> & other)
{
    info = other.info;
    left = other.left;
    right = other.right;
    parent = other.parent;
}

template <class T>
RBNode<T>::~RBNode()
{
    info.~T();
    left = right = parent = nullptr;
}


template <class T>
std::ostream & operator << (std::ostream & os, const RBNode<T>  & node)
{
    os << node.info;
    
    return os;
}


#endif
