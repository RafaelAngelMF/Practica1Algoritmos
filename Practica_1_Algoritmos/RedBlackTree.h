

#ifndef RedBlackTree_h
#define RedBlackTree_h

#include "BinarySTree.h"
#include <iomanip>

template<class T>
class RedBlackTree : public BinarySTree<T>
{
public:
    RedBlackTree();
    
    BNode<T> * grandparent(BNode<T> * nodo);
    BNode<T> * uncle(BNode<T> * nodo);
    BNode<T> * sibling(BNode<T> * nodo);
    
    BNode<T> * maximum_node(BNode<T> * nodo);
    
    void verifyProperties();
    void verifyProperty1(BNode<T> * nodo);
    void verifyProperty2(BNode<T> * nodo);
    void verifyProperty3(BNode<T> * nodo);
    void verifyProperty4(BNode<T> * root);
    void verifyProperty4Helper(BNode<T> * nodo, int contNegros, int& blackPath);
    
    std::string color(BNode<T> * nodo);
    
    void rotateLeft(BNode<T> * nodo);
    void rotateRight(BNode<T> * nodo);
    
    void RBinsert(T valor);
    void insertCase1(BNode<T> * nodo);
    void insertCase2(BNode<T> * nodo);
    void insertCase3(BNode<T> * nodo);
    void insertCase4(BNode<T> * nodo);
    void insertCase5(BNode<T> * nodo);
    
    void RBdelete(T valor);
    void deleteCase1(RedBlackTree * arbol, BNode<T> * nodo);
    void deleteCase2(RedBlackTree * arbol, BNode<T> * nodo);
    void deleteCase3(RedBlackTree * arbol, BNode<T> * nodo);
    void deleteCase4(RedBlackTree * arbol, BNode<T> * nodo);
    void deleteCase5(RedBlackTree * arbol, BNode<T> * nodo);
    void deleteCase6(RedBlackTree * arbol, BNode<T> * nodo);
    
    void prettyPrint(BNode<T>* p, int indent);
    
    void verificarArbol();
};

template<class T>
RedBlackTree<T>::RedBlackTree() : BinarySTree<T>() {}

template<class T>
BNode<T> * RedBlackTree<T>::grandparent(BNode<T> * nodo)
{
    if(nodo != nullptr && nodo->getParent() != nullptr)
        return nodo->getParent()->getParent();
    else
        return nullptr;
}

template<class T>
BNode<T> * RedBlackTree<T>::uncle(BNode<T> * nodo)
{
    BNode<T> * abuelo = grandparent(nodo);
    
    if(abuelo == nullptr)
        return nullptr;
    else if(nodo->getParent() == abuelo->getLeft())
        return abuelo->getRight();
    else
        return abuelo->getLeft();
}

template<class T>
BNode<T> * RedBlackTree<T>::sibling(BNode<T> * nodo)
{
    if(nodo != nullptr && nodo->getParent() != nullptr)
    {
        if(nodo == nodo->getParent()->getLeft())
            return nodo->getParent()->getRight();
        else
            return nodo->getParent()->getLeft();
    }
    else
        return nullptr;
}

template<class T>
BNode<T> * RedBlackTree<T>::maximum_node(BNode<T> * nodo)
{
    while (nodo->getRight() != nullptr)
    {
        nodo = nodo->getRight();
    }
    return nodo;
}

template<class T>
void RedBlackTree<T>::verifyProperties()
{
    verifyProperty1(this->getRoot());
    verifyProperty2(this->getRoot());
    verifyProperty3(this->getRoot());
    verifyProperty4(this->getRoot());
}

template<class T>
void RedBlackTree<T>::verifyProperty1(BNode<T> * nodo)
{
    if(nodo == nullptr)
        return;

    verifyProperty1(nodo->getLeft());
    verifyProperty1(nodo->getRight());
}

template<class T>
void RedBlackTree<T>::verifyProperty2(BNode<T> * nodo)
{
    
}

template<class T>
void RedBlackTree<T>::verifyProperty3(BNode<T> * nodo)
{
    if (nodo == nullptr)
        return;
    verifyProperty3(nodo->getLeft());
    verifyProperty3(nodo->getRight());
}

template <class T>
void RedBlackTree<T>::verifyProperty4(BNode<T> * root)
{
    
    int blackPath = -1;
    std::string mensaje="";
    
    return verifyProperty4Helper(root, 0, blackPath);
}

template <class T>
void RedBlackTree<T>::verifyProperty4Helper(BNode<T> * nodo, int contNegros, int& blackPath)
{
    std::string color;
    if (nodo != nullptr)
    {
        color = nodo->getColor();
    }
    else
    {
        color = "";
    }
    
    if (color == "negro")
    {
        contNegros++;
    }
    if (nodo == nullptr)
    {
        if (blackPath == -1)
        {
            blackPath = contNegros;
        }
        else
        {
            if (contNegros != blackPath)
            {
                std::cout << "No es RedBlackTree" << std::endl;
            }
        }
        return;
    }
    verifyProperty4Helper(nodo->getLeft(),  contNegros, blackPath);
    verifyProperty4Helper(nodo->getRight(), contNegros, blackPath);
    
    return;
}

template<class T>
std::string RedBlackTree<T>::color(BNode<T> * nodo)
{
    if(nodo == nullptr)
        return "negro";
    else
        return nodo->getColor();
}

template<class T>
void RedBlackTree<T>::rotateLeft(BNode<T> * nodeL)
{
    BNode<T> *nodeR;
    
    if(nodeL->getRight() == nullptr)
    {
        return;
    }
    
    nodeR = nodeL->getRight();
    
    if(nodeR->getLeft() != nullptr)
    {
        nodeR->getLeft()->setParent(nodeL);
        nodeL->setRight(nodeR->getLeft());
    }
    
    nodeR->setParent(nodeL->getParent());
    
    if(nodeL->getParent() == nullptr)
    {
        this->setRoot(nodeR);
    }
    else if(nodeL == nodeL->getParent()->getLeft())
    {
        nodeL->getParent()->setLeft(nodeR);
    }
    else{
        
        nodeL->getParent()->setRight(nodeR);
    }
    
    nodeL->setRight(nodeR->getLeft());
    nodeR->setLeft(nodeL);
    nodeL->setParent(nodeR);
}

template<class T>
void RedBlackTree<T>::rotateRight(BNode<T> * nodeR)
{
    BNode<T> *nodeL;
    
    if(nodeR->getLeft() == nullptr)
    {
        return;
    }
    
    nodeL = nodeR->getLeft();
    
    if(nodeL->getRight() != nullptr)
    {
        nodeL->getRight()->setParent(nodeR);
        nodeR->setLeft(nodeL->getRight());
    }
    
    nodeL->setParent(nodeR->getParent());
    
    if(nodeR->getParent() == nullptr)
    {
        this->setRoot(nodeL);
    }
    else if(nodeR == nodeR->getParent()->getLeft())
    {
        nodeR->getParent()->setLeft(nodeL);
    }
    else
    {
        nodeR->getParent()->setRight(nodeL);
    }
    
    nodeR->setLeft(nodeL->getRight());
    nodeL->setRight(nodeR);
    nodeR->setParent(nodeL);
}

template<class T>
void RedBlackTree<T>::RBinsert(T valor)
{
    BNode<T> * nodo = this->insert(valor);
    nodo->setColor("rojo");
    if(nodo->getParent() == nullptr)
        nodo->setColor("negro");
    else
    {
        if(nodo->getParent()->getColor() == "negro")
            return;
        else
        {
            if(color(uncle(nodo)) == "rojo")
            {
                nodo->getParent()->setColor("negro");
                uncle(nodo)->setColor("negro");
                grandparent(nodo)->setColor("rojo");
                insertCase1(grandparent(nodo));
            }
            else
            {
                if(nodo == nodo->getParent()->getRight() && nodo->getParent() == grandparent(nodo)->getLeft())
                {
                    rotateLeft(nodo->getParent());
                    nodo = nodo->getLeft();
                }
                else if(nodo == nodo->getParent()->getLeft() && nodo->getParent() == grandparent(nodo)->getRight())
                {
                    rotateRight(nodo->getParent());
                    nodo = nodo->getRight();
                }
                nodo->getParent()->setColor("negro");
                grandparent(nodo)->setColor("rojo");
                if (nodo == nodo->getParent()->getLeft() && nodo->getParent() == grandparent(nodo)->getLeft())
                {
                    rotateRight(grandparent(nodo));
                }
                else
                {
                    rotateLeft(grandparent(nodo));
                }
            }
        }
    }
    verifyProperties();
}

template<class T>
void RedBlackTree<T>::insertCase1(BNode<T> * nodo)
{
    if(nodo->getParent() == nullptr)
        nodo->setColor("negro");
    else
        insertCase2(nodo);
}

template<class T>
void RedBlackTree<T>::insertCase2(BNode<T> * nodo)
{
    if(nodo->getParent()->getColor() == "negro")
        return;
    else
        insertCase3(nodo);
}

template<class T>
void RedBlackTree<T>::insertCase3(BNode<T> * nodo)
{
    if(color(uncle(nodo)) == "rojo")
    {
        nodo->getParent()->setColor("negro");
        uncle(nodo)->setColor("negro");
        grandparent(nodo)->setColor("rojo");
        insertCase1(grandparent(nodo));
    }
    else
    {
        insertCase4(nodo);
    }
}

template<class T>
void RedBlackTree<T>::insertCase4(BNode<T> * nodo)
{
    if(nodo == nodo->getParent()->getRight() && nodo->getParent() == grandparent(nodo)->getLeft())
    {
        rotateLeft(nodo->getParent());
        nodo = nodo->getLeft();
    }
    else if(nodo == nodo->getParent()->getLeft() && nodo->getParent() == grandparent(nodo)->getRight())
    {
        rotateRight(nodo->getParent());
        nodo = nodo->getRight();
    }
    insertCase5(nodo);
}

template<class T>
void RedBlackTree<T>::insertCase5(BNode<T> * nodo)
{
    nodo->getParent()->setColor("negro");
    grandparent(nodo)->setColor("rojo");
    if (nodo == nodo->getParent()->getLeft() && nodo->getParent() == grandparent(nodo)->getLeft())
    {
        rotateRight(grandparent(nodo));
    }
    else
    {
        rotateLeft(grandparent(nodo));
    }
}

template <class T>
void RedBlackTree<T>::RBdelete(T valor)
{
    BNode<T> * hijo;
    BNode<T> * nodo;
    nodo = this->search(valor);
    if (nodo == nullptr)
        return;
    
    if (nodo->getLeft() != nullptr && nodo->getRight() != nullptr)
    {
        BNode<T> * pred = maximum_node(nodo->getLeft());
        nodo->setInfo(pred->getInfo());
        nodo = pred;
    }
    hijo = nodo->getRight() == nullptr ? nodo->getLeft()  : nodo->getRight();
    if (color(nodo) == "negro")
    {
        nodo->getColor() = color(hijo);
        deleteCase1(this, nodo);
    }
    
    
    if (nodo->getParent() == nullptr)
    {
        this->setRoot(hijo);
    }
    else
    {
        if (nodo == nodo->getParent()->getLeft())
            nodo->getParent()->setLeft(hijo);
        else
            nodo->getParent()->setRight(hijo);
    }
    if (hijo != nullptr)
    {
        hijo->setParent(nodo->getParent());
    }
    delete nodo;
    verifyProperties();
}

template <class T>
void RedBlackTree<T>::deleteCase1(RedBlackTree * arbol, BNode<T> * nodo)
{
    if(nodo->getParent() == nullptr)
        return;
    else
        deleteCase2(this, nodo);
}

template <class T>
void RedBlackTree<T>::deleteCase2(RedBlackTree * arbol, BNode<T> * nodo)
{
    if (color(sibling(nodo)) == "rojo")
    {
        nodo->getParent()->setColor("rojo");
        sibling(nodo)->setColor("negro");
        if (nodo == nodo->getParent()->getLeft())
            rotateLeft(nodo->getParent());
        else
            rotateRight(nodo->getParent());
    }
    deleteCase3(this, nodo);
}

template <class T>
void RedBlackTree<T>::deleteCase3(RedBlackTree * arbol, BNode<T> * nodo)
{
    if (color(nodo->getParent()) == "negro" && color(sibling(nodo)) == "negro" &&
        color(sibling(nodo)->getLeft()) == "negro" && color(sibling(nodo)->getRight()) == "negro")
    {
        sibling(nodo)->setColor("rojo");
        deleteCase1(this, nodo->getParent());
    }
    else
        deleteCase4(this, nodo);
}

template <class T>
void RedBlackTree<T>::deleteCase4(RedBlackTree * arbol, BNode<T> * nodo)
{
    if (color(nodo->getParent()) == "rojo" && color(sibling(nodo)) == "negro" &&
        color(sibling(nodo)->getLeft()) == "negro" && color(sibling(nodo)->getRight()) == "negro")
    {
        sibling(nodo)->setColor("rojo");
        nodo->getParent()->setColor("negro");
    }
    else
        deleteCase5(this, nodo);
}

template<class T>
void RedBlackTree<T>::deleteCase5(RedBlackTree * arbol, BNode<T> * nodo)
{
    if (nodo == nodo->getParent()->getLeft() && color(sibling(nodo)) == "negro" &&
        color(sibling(nodo)->getLeft()) == "rojo" && color(sibling(nodo)->getRight()) == "negro")
    {
        sibling(nodo)->setColor("rojo");
        sibling(nodo)->getLeft()->setColor("negro");
        rotateRight(sibling(nodo));
    }
    else if (nodo == nodo->getParent()->getRight() && color(sibling(nodo)) == "negro" &&
             color(sibling(nodo)->getRight()) == "rojo" && color(sibling(nodo)->getLeft()) == "negro")
    {
        sibling(nodo)->setColor("rojo");
        sibling(nodo)->getRight()->setColor("negro");
        rotateLeft(sibling(nodo));
    }
    deleteCase6(this, nodo);
}

template<class T>
void RedBlackTree<T>::deleteCase6(RedBlackTree * arbol, BNode<T> * nodo)
{
    sibling(nodo)->setColor(color(nodo->getParent()));
    nodo->getParent()->setColor("negro");
    if (nodo == nodo->getParent()->getLeft())
    {
        sibling(nodo)->getRight()->setColor("negro");
        rotateLeft(nodo->getParent());
    }
    else
    {
        sibling(nodo)->getLeft()->setColor("negro");
        rotateRight(nodo->getParent());
    }
}

template <class T>
void RedBlackTree<T>::prettyPrint(BNode<T>* p, int indent)
{
    if (p != nullptr) {
        if (p->getRight()) {
            prettyPrint(p->getRight(), indent + 4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        if (p->getRight()) std::cout << " /\n" << std::setw(indent) << ' ';
        std::cout << p->getInfo() << "|" << p->getColor() << "\n ";
        if (p->getLeft()) {
            std::cout << std::setw(indent) << ' ' << " \\\n";
            prettyPrint(p->getLeft(), indent + 4);
        }
    }
}

template<class T>
void RedBlackTree<T>::verificarArbol()
{
    verifyProperties();
    std::cout << "Sí es RojiNegro" << std::endl;
}

#endif
