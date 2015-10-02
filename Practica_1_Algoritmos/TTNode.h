//
//  TTNode.h
//  Practica_1_Algoritmos
//
//  Created by alexis matuk on 9/6/15.
//  Copyright (c) 2015 alexis matuk. All rights reserved.
//

#ifndef Practica_1_Algoritmos_TTNode_h
#define Practica_1_Algoritmos_TTNode_h

template <class T>
class TTNode{
    bool hasSmall = false;
    bool hasHigh = false;
    bool full = false;
    T* smaller = nullptr;
    T* higher = nullptr;
    T* tempMiddle = nullptr;
    TTNode<T>* parent = nullptr;
    TTNode<T>* leftChild = nullptr;
    TTNode<T>* middleChild = nullptr;
    TTNode<T>* rightChild = nullptr;
    TTNode<T>* tempChild = nullptr;
public:
    TTNode<T>():leftChild(nullptr),middleChild(nullptr),rightChild(nullptr),parent(nullptr),smaller(nullptr),higher(nullptr),tempMiddle(nullptr),tempChild(nullptr){}
    TTNode(T _smaller){
        smaller = new T(_smaller);
        hasSmall = true;
    }
    virtual ~TTNode(){
        leftChild = middleChild = rightChild = parent = tempChild = nullptr;
        smaller = higher = nullptr;
    }
    
    TTNode<T>* getTempChild()
    {
        return tempChild;
    }
    
    void setTempChild(TTNode<T>* node)
    {
        tempChild = node;
    }
    
    T getTempMiddle()
    {
        return *tempMiddle;
    }
    
    void deleteTempMiddle()
    {
        if(tempMiddle)
        {
            tempMiddle = nullptr;
        }
    }
    
    void setTempMiddle(T _value)
    {
        if(tempMiddle == nullptr)
        {
            tempMiddle = new T(_value);
        }
        else
        {
            *tempMiddle = _value;
        }
    }
    
    bool hasTempMiddle()
    {
        if(tempMiddle)
            return true;
        else
            return false;
    }
    
    void setLower(T _value)
    {
        if(smaller!=nullptr)
        {
            *smaller = _value;
        }
        else
        {
            smaller = new T(_value);
        }
    }
    
    void setHigher(T _value)
    {
        if(higher!=nullptr)
        {
            *higher = _value;
        }
        else
        {
            higher = new T(_value);
        }
    }
    
    T getLower()
    {
        return *smaller;
    }
    
    T getHigher()
    {
        return *higher;
    }
    
    bool isFull()
    {
        //        if(higher != nullptr && smaller != nullptr)
        //            return true;
        //        return false;
        if(higher && smaller)
            return true;
        return false;
    }
    
    bool has3Keys()
    {
        return higher && smaller && tempMiddle;
    }
    
    void setValue(T _value)
    {
        //std::cout << "Parsing " << _value << std::endl;
        //std::cout << "entrando a setValue" << std::endl;
        if(!smaller)
        {
            //std::cout << "creando smaller" << std::endl;
            smaller = new T(_value);
            //std::cout << "valor actual de smaller " << *smaller << std::endl;
        }
        else
        {
            //std::cout << "ya hay smaller, que es "<< *smaller << std::endl;
            if(_value >= *smaller)
            {
                //std::cout << "El valor es mayor a smaller" << std::endl;
                if(!higher)
                {
                    //std::cout << "creando higher" << std::endl;
                    higher = new T(_value);
                }
            }
            else if(_value < *smaller)
            {
                //std::cout << "Value es menor a smaller, swapeando" << std::endl;
                higher = new T(*smaller);
                *smaller = _value;
            }
        }
    }
    
    void deleteAllKeys()
    {
        if(smaller)
            smaller = nullptr;
        if(higher)
            higher = nullptr;
    }
    
    void setMiddleValue(T _value)
    {
        if(higher && smaller)
        {
            if(!tempMiddle)
            {
                tempMiddle = new T(_value);
                if(_value < *smaller)
                {
                    *tempMiddle = *smaller;
                    *smaller = _value;
                }
                else if(_value >= *smaller && _value <= *higher)
                {
                    *tempMiddle = _value;
                }
                else
                {
                    *tempMiddle = *higher;
                    *higher = _value;
                }
            }
            else
            {
                if(_value < *smaller)
                {
                    *tempMiddle = *smaller;
                    *smaller = _value;
                }
                else if(_value >= *smaller && _value <= *higher)
                {
                    *tempMiddle = _value;
                }
                else
                {
                    *tempMiddle = *higher;
                    *higher = _value;
                }
            }
        }
    }
    
    void deleteHigher()
    {
        if(higher)
        {
            higher = nullptr;
        }
    }
    
    void deleteLower()
    {
        if(smaller)
            smaller = nullptr;
    }
    
    void swapHigherToLower()
    {
        if(!smaller)
            smaller = new T(*higher);
        else
            *smaller = *higher;
        higher = nullptr;
    }
    
    
    bool hasLower(){
        if(smaller==nullptr)
            return false;
        else
            return true;
    }
    bool hasHigher(){
        if(higher==nullptr)
            return false;
        else
            return true;
    }
    
    bool hasNoKeys()
    {
        return !smaller && !higher;
    }
    
    TTNode<T> * getLeft() const { return leftChild; }
    void setLeft(TTNode<T> * value) { leftChild = value; }
    
    TTNode<T> * getRight() const { return rightChild; }
    void setRight(TTNode<T> * value) { rightChild = value; }
    
    TTNode<T> * getMiddle() const { return middleChild; }
    void setMiddle(TTNode<T> * value) { middleChild = value; }
    
    TTNode<T> * getParent() const { return parent; }
    void setParent(TTNode<T> * value) { parent = value; }
};


#endif
