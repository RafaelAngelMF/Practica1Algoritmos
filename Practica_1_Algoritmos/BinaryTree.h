#ifndef BinaryTree_BinaryTree_h
#define BinaryTree_BinaryTree_h

#include "BNode.h"
#include <iomanip>
#include <iostream>


template <class T>
class BinaryTree 
{
protected:
    BNode<T> * root = nullptr;
    
public:
    BinaryTree() {}
    virtual ~BinaryTree();
    
    bool empty();
    
    void clear();
    void clear(BNode<T> * node);
    
    BNode<T> * getRoot() const;
    void setRoot(BNode<T> * node);
    
    
    virtual BNode<T> * insert(T value);
    virtual BNode<T> * insert(BNode<T> * parent, BNode<T> * node);
    
    
    void preOrder() const;
    void preOrder(BNode<T> * node) const;
    
    
    void inOrder() const;
    void inOrder(BNode<T> * node) const;
    void reverseInOrder() const;
    void reverseInOrder(BNode<T> * node) const;
    
    
    void postOrder() const;
    void postOrder(BNode<T> * node) const;
    
    void isLeaf() const;
    void isLeaf(BNode<T> * node) const;
    
    void ancestors(BNode<T> * node) const;
    
    int getHeight() const;
    int getHeight(BNode<T> * node) const ;
    
    int getDepth() const;
    int getDepth(BNode<T> * node) const;
    
    int getLevel() const;
    int getLevel(BNode<T> * node) const;
    
    int balanceFactor() const;
    int balanceFactor(BNode<T> * node) const ;
    
    void prettyPrint(BNode<T> * p, int indent);
    
};


template <class T>
BinaryTree<T>::~BinaryTree()
{
    clear();
}

template <class T>
bool BinaryTree<T>::empty()
{
    return root == nullptr;
}

template <class T>
void BinaryTree<T>::clear()
{
    clear(root);
}

template <class T>
void BinaryTree<T>::clear(BNode<T> * node)
{
    if (node) {
        clear(node->getLeft());
        clear(node->getRight());
        
        delete node;
    }
}

template <class T>
BNode<T> * BinaryTree<T>::getRoot() const
{
    return root;
}

template <class T>
void BinaryTree<T>::setRoot(BNode<T> * node)
{
    root = node;
}




template <class T>
BNode<T> * BinaryTree<T>::insert(T value){
    BNode<T> * node = new BNode<T>(value);
    return insert(this->root, node);
}

template <class T>
BNode<T> * BinaryTree<T>::insert(BNode<T> * parent, BNode<T> * node){
    if (empty())
    {
        setRoot(node);
    }
    else
    {
        if(node->getInfo() < parent->getInfo())
        {
            
            if (parent->getLeft() == nullptr)
            {
                parent->setLeft(node);
                node->setParent(parent);

            }
            else
            {
                insert(parent->getLeft(), node);
            }
        }
        else
        {
            if (parent->getRight() == nullptr)
            {
                parent->setRight(node);
                node->setParent(parent);

            }
            else
            {
                insert(parent->getRight(), node);
            }
        }
    }
    return node;
}



template <class T>
void BinaryTree<T>::preOrder() const
{
    preOrder(root);
}

template <class T>
void BinaryTree<T>::preOrder(BNode<T> * node) const
{
    if (node) 
	{
        std::cout << *node << std::endl;
        
        preOrder(node->getLeft());
        preOrder(node->getRight());
        
    }
}

template <class T>
void BinaryTree<T>::inOrder() const
{
    inOrder(root);
}

template <class T>
void BinaryTree<T>::inOrder(BNode<T> * node) const
{
    if (node) 
	{
        inOrder(node->getLeft());
        std::cout << *node << std::endl;
        inOrder(node->getRight());
    }
}

template <class T>
void BinaryTree<T>::reverseInOrder() const
{
    reverseInOrder(root);
    
}
template <class T>
void BinaryTree<T>::reverseInOrder(BNode<T> * node) const
{    
	if (node) 
	{
		reverseInOrder(node->getRight());
		std::cout << *node << std::endl;
		reverseInOrder(node->getLeft());
	}
}

template <class T>
void BinaryTree<T>::postOrder() const
{
    postOrder(root);
}

template <class T>
void BinaryTree<T>::postOrder(BNode<T> * node) const
{
    if (node) 
	{
        postOrder(node->getLeft());
        postOrder(node->getRight());

        std::cout << *node << std::endl;
    }
}

template <class T>
void BinaryTree<T>::isLeaf() const
{
    isLeaf(root);
}

template <class T>
void BinaryTree<T>::isLeaf(BNode<T> * node) const
{
    if (node) {
        if (!node->getLeft() && !node->getRight()) 
		{
            std::cout << *node << std::endl;
        }
        else 
		{
            isLeaf(node->getLeft());
            isLeaf(node->getRight());
        }
    }
}

template <class T>
void BinaryTree<T>::ancestors(BNode<T> * node) const
{
    if (node) 
	{
        std::cout << *node << " -> ";
        ancestors(node->getParent());
    }
}

template <class T>
int BinaryTree<T>::getHeight() const
{
    return getHeight(root);
}

template <class T>
int BinaryTree<T>::getHeight(BNode<T> * node) const
{
    if (!node) return -1;
    return 1 + std::max(getHeight(node->getLeft()), getHeight(node->getRight()));
}

template <class T>
int BinaryTree<T>::getLevel() const
{
    return getLevel(root);
}

template <class T>
int BinaryTree<T>::getLevel(BNode<T> * node) const
{
    if (node == nullptr)
    {
        return 0;
    }
    else
    {
        return getLevel(node->getParent()) + 1;
    }
}

template <class T>
int BinaryTree<T>::getDepth() const
{
    return getDepth(root);
}

template <class T>
int BinaryTree<T>::getDepth(BNode<T> * node) const
{
    return getLevel(node) - 1;
}

template <class T>
int BinaryTree<T>::balanceFactor() const
{
    return balanceFactor(root);
}

template <class T>
int BinaryTree<T>::balanceFactor(BNode<T> * node) const
{
    if (node)
    {
        return getHeight(node->getRight()) - getHeight(node->getLeft());
    }
    return 0;
}

template <class T>
void BinaryTree<T>::prettyPrint(BNode<T>* p, int indent)
{
	if(p != NULL) 
	{
		if(p->getRight()) 
		{
			prettyPrint(p->getRight(), indent+4);
		}
		if (indent) 
		{
			std::cout << std::setw(indent) << ' ';
		}
		if (p->getRight()) std::cout<<" /\n" << std::setw(indent) << ' ';
		std::cout<< p->getInfo() << "\n ";
		if(p->getLeft()) 
		{
			std::cout << std::setw(indent) << ' ' <<" \\\n";
			prettyPrint(p->getLeft(), indent+4);
		}
	}
}

#endif
