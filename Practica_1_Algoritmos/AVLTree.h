#ifndef AVLTree_h
#define AVLTree_h

#include "BinarySTree.h"

template <class T>
class AVLTree : public BinarySTree<T>{
    
public:
    AVLTree(){}
    ~AVLTree();
    
    void LL(BNode<T> * node);
    void RR(BNode<T> * node);
    void LR(BNode<T> * node);
    void RL(BNode<T> * node);
    bool isAvl(BNode<T> * node);
    bool isAvl();
    BNode<T> * insert(BNode<T> * parent, BNode<T> * node);
    BNode<T> * insert(T value);
    void remove(T value);
    
    BNode<T> * getMaxMin(BNode<T> * node) const;
    BNode<T> * getMaxMin() const;
    
};

template <class T>
AVLTree<T>::~AVLTree()
{
    
}

template <class T>
bool AVLTree<T>::isAvl()
{
    return isAvl(this->getRoot());
}

template <class T>
bool AVLTree<T>::isAvl(BNode<T> * node)
{
    if (node)
    {
        if (abs(this->balanceFactor(node)) > 1 )
        {
            return false;
        }
        return  isAvl(node->getRight()) && isAvl(node->getLeft());
    }
    else
    {
        return true;
    }
}

template <class T>
void AVLTree<T>::RR(BNode<T> * pivot)
{
    BNode<T> * temp = pivot->getLeft();
    
    
    if(pivot->getParent() && pivot->getInfo() <= pivot->getParent()->getInfo() )
	{
        pivot->getParent()->setLeft(temp);
    }
	else if (pivot->getParent())
	{
        pivot->getParent()->setRight(temp);
    }
	else
	{
        this->setRoot(temp);
    }
    
    temp->setParent(pivot->getParent());
    pivot->setParent(temp);
    pivot->setLeft(temp->getRight());
    temp->setRight(pivot);
    
    if(pivot->getLeft())
	{
        pivot->getLeft()->setParent(pivot);
	}
}

template <class T>
void AVLTree<T>::LL(BNode<T> * pivot)
{
    BNode<T> * temp = pivot->getRight();
    
    if(pivot->getParent() && pivot->getInfo() <= pivot->getParent()->getInfo() )
	{
        pivot->getParent()->setLeft(temp);
    }
	else if (pivot->getParent())
	{
        pivot->getParent()->setRight(temp);
    }
	else
	{
        this->setRoot(temp);
    }
    
    temp->setParent(pivot->getParent());
    pivot->setParent(temp);
    pivot->setRight(temp->getLeft());
    temp->setLeft(pivot);
    
    if(pivot->getRight())
	{
        pivot->getRight()->setParent(pivot);
	}
}

template <class T>
void AVLTree<T>::LR(BNode<T> * pivot)
{
   BNode<T> * temp = pivot->getRight();
   LL(pivot);
   RR(temp->getParent());
}

template <class T>
void AVLTree<T>::RL(BNode<T> * pivot)
{
    BNode<T> * temp = pivot->getLeft();
    RR(pivot);
    LL(temp->getParent());
}

template <class T>
BNode<T> * AVLTree<T>::insert(BNode<T> * parent, BNode<T> * node)
{
	if (this->empty())
	{
		this->setRoot(node);
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
		else if(node->getInfo() > parent->getInfo())
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
		else 
		{
			return nullptr;
		}

		if(this->balanceFactor(parent->getParent()) == -2 && this->balanceFactor(parent->getParent()->getLeft())== -1)
		{
			RR(parent->getParent());
		}
		if(this->balanceFactor(parent->getParent()) == -2 && this->balanceFactor(parent->getParent()->getLeft())== 1)
		{
			LR(parent);
		}
		if(this->balanceFactor(parent->getParent()) == 2 && this->balanceFactor(parent->getParent()->getRight())== 1)
		{
			LL(parent->getParent());
		}
		if(this->balanceFactor(parent->getParent()) == 2 && this->balanceFactor(parent->getParent()->getRight())== -1)
		{
			RL(parent);
		}
	}
    return node;
}


template <class T>
BNode<T> * AVLTree<T>::insert(T value)
{
    BNode<T> * node = new BNode<T>(value);
    return insert(this->root, node);
}

template <class T>
void AVLTree<T>::remove(T value)
{
    BNode<T> * node = this->search(value);
    
    if(node)
	{
        BNode<T> * parent = node->getParent();
        BNode<T> * newnode = getMaxMin(node);
        
        if(newnode)
		{
            newnode->setRight(node->getRight());
            if(newnode->getRight())
			{
                newnode->getRight()->setParent(newnode);
			}
            newnode->getParent()->setRight(newnode->getLeft());
            newnode->setParent(node->getParent());
			
            if(node->getLeft() == newnode)
			{
                if(!newnode->getLeft())
				{
                    newnode->setLeft(nullptr);
				}
            }
            else
			{
                newnode->setLeft(node->getLeft());
            }
        }
        
        if(!node->getParent())
		{
            BinaryTree<T>::setRoot(newnode);
        }
		else if(node->getInfo() <= node->getParent()->getInfo())
		{
            node->getParent()->setLeft(newnode);
        } 
		else
		{
            node->getParent()->setRight(newnode);
        }

        delete node;
        
        if(this->balanceFactor(parent) == -2 && this->balanceFactor(parent->getLeft()) == -1)
		{
            RR(parent);
        }
        if(this->balanceFactor(parent) == -2 && this->balanceFactor(parent->getLeft())== 1)
		{
            LR(parent->getLeft());
        }
        if(this->balanceFactor(parent) == 2 && this->balanceFactor(parent->getRight())== 1)
		{
            LL(parent);
        }
        if( (this->balanceFactor(parent) == 2 && this->balanceFactor(parent->getRight())== -1))
		{
            RL(parent->getRight());
        }
        parent =  parent->getParent();
        

        if(this->balanceFactor(newnode) == -2 && this->balanceFactor(newnode->getLeft()) == -1)
		{
            RR(newnode);
        }
        if(this->balanceFactor(newnode) == -2 && this->balanceFactor(newnode->getLeft())== 1)
		{
            LR(newnode->getLeft());
        }
        if(this->balanceFactor(newnode) == 2 && this->balanceFactor(newnode->getRight())== 1)
		{
            LL(newnode);
        }
        if(this->balanceFactor(newnode) == 2 && this->balanceFactor(newnode->getRight())== -1)
		{
            RL(newnode->getRight());
        }
    }
}

template <class T>
BNode<T> * AVLTree<T>::getMaxMin() const
{
    return getMaxMin(this->root);
}


template <class T>
BNode<T> * AVLTree<T>::getMaxMin(BNode<T> * node) const
{
    if (node)
    {
        BNode<T> * workingNode = node->getLeft();
        if(workingNode)
		{
            while (workingNode->getRight() != nullptr)
            {
                workingNode = workingNode->getRight();
            }
            return workingNode;
        }
        return nullptr;
    } 
	else
	{
        return nullptr;
    }
}

#endif /* AVLTree_h */
