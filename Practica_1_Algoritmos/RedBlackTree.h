

#ifndef ProblemaPractico1_RedBlackTree_h
#define ProblemaPractico1_RedBlackTree_h

#include "BinarySTree.h"
#include <assert.h>
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
    
    void verifyProperties(RedBlackTree * arbol);
    void verifyProperty1(BNode<T> * nodo);
    void verifyProperty2(BNode<T> * nodo);
    void verifyProperty3(BNode<T> * nodo);
    void verifyProperty4(BNode<T> * root);
    void verifyProperty4Helper(BNode<T> * nodo, int contNegros, int& blackPath);
    
    std::string color(BNode<T> * nodo);
    
    void rotateLeft(RedBlackTree * arbol, BNode<T> * nodo);
    void rotateRight(RedBlackTree * arbol, BNode<T> * nodo);
    
    void RBinsert(T valor);
    void insertCase1(RedBlackTree * arbol, BNode<T> * nodo);
    void insertCase2(RedBlackTree * arbol, BNode<T> * nodo);
    void insertCase3(RedBlackTree * arbol, BNode<T> * nodo);
    void insertCase4(RedBlackTree * arbol, BNode<T> * nodo);
    void insertCase5(RedBlackTree * arbol, BNode<T> * nodo);
    
    void RBdelete(T valor);
    void deleteCase1(RedBlackTree * arbol, BNode<T> * nodo);
    void deleteCase2(RedBlackTree * arbol, BNode<T> * nodo);
    void deleteCase3(RedBlackTree * arbol, BNode<T> * nodo);
    void deleteCase4(RedBlackTree * arbol, BNode<T> * nodo);
    void deleteCase5(RedBlackTree * arbol, BNode<T> * nodo);
    void deleteCase6(RedBlackTree * arbol, BNode<T> * nodo);
    
    void prettyPrint(BNode<T>* p, int indent);
    
    void verificarArbol(RedBlackTree<T> * arbol);
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
    assert (nodo != nullptr);
    while (nodo->getRight() != nullptr)
    {
        nodo = nodo->getRight();
    }
    return nodo;
}

template<class T>
void RedBlackTree<T>::verifyProperties(RedBlackTree * arbol)
{
    verifyProperty1(arbol->getRoot());
    verifyProperty2(arbol->getRoot());
    verifyProperty3(arbol->getRoot());
    verifyProperty4(arbol->getRoot());
}

template<class T>
void RedBlackTree<T>::verifyProperty1(BNode<T> * nodo)
{
    if(nodo == nullptr)
        return;
    
    assert(nodo->getColor() == "negro" || nodo->getColor() == "rojo");
    
    verifyProperty1(nodo->getLeft());
    verifyProperty1(nodo->getRight());
}

template<class T>
void RedBlackTree<T>::verifyProperty2(BNode<T> * nodo)
{
    assert(color(nodo) == "negro");
}

template<class T>
void RedBlackTree<T>::verifyProperty3(BNode<T> * nodo)
{
    if (nodo == nullptr)
        return;
    
    if (color(nodo) == "rojo")
    {
        assert(color(nodo->getLeft()) == "negro");
        assert(color(nodo->getRight()) == "negro");
        assert(color(nodo->getParent()) == "negro");
    }
    
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
    
    
    if (nodo != nullptr) {
        color = nodo->getColor();
    }
    else{
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
void RedBlackTree<T>::rotateLeft(RedBlackTree * arbol, BNode<T> * node_x)
{
    BNode<T> *node_y;
    
    if(node_x->getRight() == NULL){
        return;
    }
    
    node_y = node_x->getRight();
    
    if(node_y->getLeft() != NULL){
        node_y->getLeft()->setParent(node_x);
        node_x->setRight(node_y->getLeft());
    }
    
    node_y->setParent(node_x->getParent());
    
    if(node_x->getParent() == NULL){
        this->setRoot(node_y);
    }else if(node_x == node_x->getParent()->getLeft()){
        node_x->getParent()->setLeft(node_y);
    }else{
        node_x->getParent()->setRight(node_y);
    }
    
    node_x->setRight(node_y->getLeft());
    node_y->setLeft(node_x);
    node_x->setParent(node_y);
}

template<class T>
void RedBlackTree<T>::rotateRight(RedBlackTree * arbol, BNode<T> * node_y)
{
    BNode<T> *node_x;
    
    if(node_y->getLeft() == NULL){
        return;
    }
    
    node_x = node_y->getLeft();
    
    if(node_x->getRight() != NULL){
        node_x->getRight()->setParent(node_y);
        node_y->setLeft(node_x->getRight());
    }
    
    node_x->setParent(node_y->getParent());
    
    if(node_y->getParent() == NULL){
        this->setRoot(node_x);
    }else if(node_y == node_y->getParent()->getLeft()){
        node_y->getParent()->setLeft(node_x);
    }else{
        node_y->getParent()->setRight(node_x);
    }
    
    node_y->setLeft(node_x->getRight());
    node_x->setRight(node_y);
    node_y->setParent(node_x);
}

template<class T>
void RedBlackTree<T>::RBinsert(T valor)
{
    BNode<T> * nodo = this->insert(valor);//De arbolbinbusq
    nodo->setColor("rojo");
    insertCase1(this, nodo);
    verifyProperties(this);
    
}

template<class T>
void RedBlackTree<T>::insertCase1(RedBlackTree * arbol, BNode<T> * nodo)
{
    if(nodo->getParent() == nullptr)
        nodo->setColor("negro");
    else
        insertCase2(this, nodo);
}

template<class T>
void RedBlackTree<T>::insertCase2(RedBlackTree * arbol, BNode<T> * nodo)
{
    if(nodo->getParent()->getColor() == "negro")
        return;
    else
        insertCase3(this, nodo);
}

template<class T>
void RedBlackTree<T>::insertCase3(RedBlackTree * arbol, BNode<T> * nodo)
{
    if(color(uncle(nodo)) == "rojo")
    {
        nodo->getParent()->setColor("negro");
        uncle(nodo)->setColor("negro");
        grandparent(nodo)->setColor("rojo");
        insertCase1(arbol, grandparent(nodo));
    }
    else
    {
        insertCase4(arbol, nodo);
    }
}

template<class T>
void RedBlackTree<T>::insertCase4(RedBlackTree * arbol, BNode<T> * nodo)
{
    if(nodo == nodo->getParent()->getRight() && nodo->getParent() == grandparent(nodo)->getLeft())
    {
        rotateLeft(arbol, nodo->getParent());
        nodo = nodo->getLeft();
    }
    else if(nodo == nodo->getParent()->getLeft() && nodo->getParent() == grandparent(nodo)->getRight())
    {
        rotateRight(arbol, nodo->getParent());
        nodo = nodo->getRight();
    }
    insertCase5(arbol, nodo);
}

template<class T>
void RedBlackTree<T>::insertCase5(RedBlackTree * arbol, BNode<T> * nodo)
{
    nodo->getParent()->setColor("negro");
    grandparent(nodo)->setColor("rojo");
    if (nodo == nodo->getParent()->getLeft() && nodo->getParent() == grandparent(nodo)->getLeft())
    {
        rotateRight(arbol, grandparent(nodo));
    }
    else
    {
        assert(nodo == nodo->getParent()->getRight() && nodo->getParent() == grandparent(nodo)->getRight());
        rotateLeft(arbol, grandparent(nodo));
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
    assert(nodo->getLeft() == NULL || nodo->getRight() == nullptr);
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
    verifyProperties(this);
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
            rotateLeft(this, nodo->getParent());
        else
            rotateRight(this, nodo->getParent());
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
        rotateRight(this, sibling(nodo));
    }
    else if (nodo == nodo->getParent()->getRight() && color(sibling(nodo)) == "negro" &&
             color(sibling(nodo)->getRight()) == "rojo" && color(sibling(nodo)->getLeft()) == "negro")
    {
        sibling(nodo)->setColor("rojo");
        sibling(nodo)->getRight()->setColor("negro");
        rotateLeft(this, sibling(nodo));
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
        assert(color(sibling(nodo)->getRight()) == "rojo");
        sibling(nodo)->getRight()->setColor("negro");
        rotateLeft(this, nodo->getParent());
    }
    else
    {
        assert(color(sibling(nodo)->getLeft()) == "rojo");
        sibling(nodo)->getLeft()->setColor("negro");
        rotateRight(this, nodo->getParent());
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
void RedBlackTree<T>::verificarArbol(RedBlackTree<T> * arbol)
{
    verifyProperties(arbol);
    std::cout << "Sí es RojiNegro" << std::endl;
}

#endif
