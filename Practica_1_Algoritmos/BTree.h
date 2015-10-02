#ifndef BTree_h
#define BTree_h

#include "BTreeNode.h"
#include <fstream>
#include <vector>

template <class T>
class BTree {
private:
    
    int currentID;
    int order;
    std::fstream data;
    void setData();
    std::vector<T> leafLevels;
    
public:
    
    BTree(int order);
    ~BTree();
    void Insert(T data);
    void Delete(T data);
    
    void printNodes();
    void print(BTreeNode<T> & node);
    void printAsc();
    void printDesc();
    void asc(BTreeNode<T> & node);
    void desc(BTreeNode<T> & node);
    
    void updateTotal(int number);
    int getRoot();
    void setRoot(int rootID);
    
    void deleteData(BTreeNode<T> & node,T data);
    void deleteLeaf(BTreeNode<T> & node,int);
    void deleteNoLeaf(BTreeNode<T> & parent,int);
    int getPredecesor(BTreeNode<T> & parent,int);
    int getNext(BTreeNode<T> & parent,int);
    void fill(BTreeNode<T> & parent,int);
    void borrowPredecesor(BTreeNode<T> & parent,int);
    void borrowNext(BTreeNode<T> & parent,int);
    void merge(BTreeNode<T> & parent,int);
    int findInfo(BTreeNode<T> & node,T);
    
    void insertData(BTreeNode<T> & node,T data);
    void splitNode(BTreeNode<T> & parentNode,int i,BTreeNode<T> & node);
    void save(BTreeNode<T> & node);
    BTreeNode<T> load(int loadKey);
    void find(T data);
    void loadNode(BTreeNode<T> *,int);
    int numberOfNodes();
    
    void searchForNode(BTreeNode<T> & node,T data, bool & found);
    bool searchForNode(T data);
    
    bool isBTree();
    void isBTree(BTreeNode<T> & node);
    int getLevel(BTreeNode<T> & node);
    int getLevel();
};

template <class T>
bool BTree<T>::searchForNode(T data)
{
    BTreeNode<T> root = load(getRoot());
    bool found = false;
    searchForNode(root, data, found);
    return found;
}

template <class T>
void BTree<T>:: searchForNode(BTreeNode<T> & node,T data, bool & found)
{
    int i = 0;
    while(i < node.filledKeys && data > node.info[i])
        i++;
    if (i < node.filledKeys && data == node.info[i])
    {
        found = true;
        return;
    }
    else if (node.leaf)
    {
        return;
    }
    else
    {
        for(int j = i; j<=node.filledKeys;j++)
        {
            node = load(node.children[j]);
            searchForNode(node, data, found);
        }
    }
}

template <class T>
BTree<T>::BTree(int order)
{
    this->order = order;
    currentID = 0;
    setData();
    BTreeNode<T> node(order);
    node.pointerKey = currentID;
    node.leaf = true;
    save(node);
    currentID++;
}

template <class T>
int BTree<T>::findInfo(BTreeNode<T> & node,T data)
{
    int i=0;
    while (i<node.filledKeys && node.info[i] < data)
        i++;
    return i;
}

template <class T>
void BTree<T>::Delete(T data)
{
    BTreeNode<T> root = load(getRoot());
    deleteData(root, data);
    if(root.filledKeys==0)
    {
        if(!root.leaf)
            setRoot(root.children[0]);
    }
}

template <class T>
void BTree<T>::deleteData(BTreeNode<T> & node,T data)
{
    int i = findInfo(node, data);
    if(i < node.filledKeys && node.info[i] == data)
    {
        if(node.leaf){
            deleteLeaf(node,i);
            save(node);
        }
        else
        {
            deleteNoLeaf(node,i);
            save(node);
        }
    }
    else{
        if(node.leaf){
            std::cout << "El dato " << data << " no existe en el arbol" << std::endl;
        }
        else
        {
            bool flag = ( (i==node.filledKeys)? true : false );
            BTreeNode<T> child = load(node.children[i]);
            T chancla = child.info[1];
            if(child.filledKeys < order)
                fill(node,i);
            if(flag && i > node.filledKeys)
            {
                child = load(node.children[i-1]);
                deleteData(child, data);
            }
            else
            {
                child = load(node.children[i]);
                chancla = child.info[2];
                deleteData(child,data);
            }
        }
    }
}

template <class T>
void BTree<T>::deleteLeaf(BTreeNode<T> & node,int i)
{
    for (int j = i+1; j < node.filledKeys; j++)
        node.info[j-1] = node.info[j];
    node.filledKeys--;
}

template <class T>
void BTree<T>::deleteNoLeaf(BTreeNode<T> & parent,int i)
{
    T data = parent.info[i];
    BTreeNode<T> child = load(parent.children[i]);
    BTreeNode<T> childHermano = load(parent.children[i+1]);
    if(child.filledKeys >= order)
    {
        T antes = getPredecesor(parent,i);
        parent.info[i] = antes;
        deleteData(child, antes);
    }
    else if(childHermano.filledKeys >= order)
    {
        T siguiente = getNext(parent,i);
        parent.info[i] = siguiente;
        deleteData(childHermano, siguiente);
    }
    else
    {
        merge(parent,i);
        child = load(child.pointerKey);
        deleteData(child,data);
    }
}


template <class T>
int BTree<T>::getPredecesor(BTreeNode<T> & parent,int i)
{
    BTreeNode<T> child = load(parent.children[i]);
    while(!child.leaf)
        child = load(child.children[child.filledKeys]);
    return child.info[child.filledKeys-1];
}


template <class T>
int BTree<T>::getNext(BTreeNode<T> & parent, int i)
{
    BTreeNode<T> child = load(parent.children[i+1]);
    while(!child.leaf)
        child = load(child.children[0]);
    return child.info[0];
}

template <class T>
void BTree<T>::fill(BTreeNode<T> & node,int i)
{
    BTreeNode<T> child = load(node.children[i-1]);
    BTreeNode<T> childHermano = load(node.children[i+1]);
    if(i != 0 && child.filledKeys >= order)
        borrowPredecesor(node,i);
    else if(i != node.filledKeys && childHermano.filledKeys >= order)
        borrowNext(node,i);
    else
    {
        if(i != node.filledKeys)
            merge(node,i);
        else
            merge(node,i-1);
    }
    
}

template <class T>
void BTree<T>::borrowPredecesor(BTreeNode<T> & parent,int i)
{
    BTreeNode<T> child = load(parent.children[i]);
    BTreeNode<T> childHermano = load(parent.children[i-1]);
    
    for(int j = child.filledKeys; j>= 0;j--)
        child.info[j+1] = child.info[j];
    if(!child.leaf){
        for(int j = child.filledKeys; j>=0; j--)
            child.children[j+1] = child.children[j];
    }
    child.info[0] = parent.info[i-1];

    if(!parent.leaf)
        child.children[0] = childHermano.children[childHermano.filledKeys];
    
    parent.info[i-1] = childHermano.info[childHermano.filledKeys-1];
    
    child.filledKeys++;
    childHermano.filledKeys--;
    
    save(parent);
    save(child);
    save(childHermano);
}

template <class T>
void BTree<T>::borrowNext(BTreeNode<T> & parent,int i)
{
    BTreeNode<T> child = load(parent.children[i]);
    BTreeNode<T> childHermano = load(parent.children[i+1]);
    
    child.info[child.filledKeys] = parent.info[i];
    
    if(!child.leaf)
        child.children[child.filledKeys+1] = childHermano.children[0];
    
    
    parent.info[i] = childHermano.info[0];
    
    for(int j = 1 ; j < childHermano.filledKeys;j++)
        childHermano.info[j-1] = childHermano.info[j];
    
    if(!childHermano.leaf)
    {
        for(int j = 1; j <= childHermano.filledKeys; j++)
            childHermano.children[j-1] = childHermano.children[j];
    }
    
    
    child.filledKeys++;
    childHermano.filledKeys--;
    
    save(parent);
    save(child);
    save(childHermano);
    
}

template <class T>
void BTree<T>::merge(BTreeNode<T> & parent, int i)
{
    BTreeNode<T> child = load(parent.children[i]);
    BTreeNode<T> childHermano = load(parent.children[i+1]);
    child.info[order-1] = parent.info[i];
    
    for (int j=0; j<childHermano.filledKeys; j++)
        child.info[j+order] = childHermano.info[j];
    
    
    if (!child.leaf)
    {
        for(int j=0; j<=childHermano.filledKeys; j++)
            child.children[j+order] = childHermano.children[j];
    }
    
    
    for (int j=i+1; j<parent.filledKeys; j++)
        parent.info[j-1] = parent.info[j];
    
    
    for (int j=i+2; j<=parent.filledKeys; j++)
        parent.children[j-1] = parent.children[j];
    
    child.filledKeys += childHermano.filledKeys+1;
    parent.filledKeys--;
    
    save(parent);
    save(child);
    save(childHermano);
    
}

template <class T>
void BTree<T>::find(T data)
{
    BTreeNode<T> root = load(getRoot());
    buscarDato(root, data);
}


template <class T>
void BTree<T>::Insert(T data)
{
    BTreeNode<T> root = load(getRoot());
    if(root.checkFull(order))
    {
        BTreeNode<T> parentNode(order);
        parentNode.pointerKey = currentID;
        setRoot(currentID);
        parentNode.leaf = false;
        parentNode.filledKeys = 0;
        parentNode.children[0] = root.pointerKey;
        parentNode.parent = parentNode.pointerKey;
        currentID++;
        splitNode(parentNode, 0, root);
        insertData(parentNode, data);
    }
    else
    {
        insertData(root, data);
        
    }
}

template <class T>
void BTree<T>::insertData(BTreeNode<T> & node,T data)
{
    int i = node.filledKeys-1;
    if(node.leaf)
    {
        while (i >= 0 && data < node.info[i])
        {
            node.info[i+1] = node.info[i];
            i--;
        }
        node.info[i+1] = data;
        node.filledKeys++;
        save(node);
        
    }
    else
    {
        while (i >= 0 && data < node.info[i])
        {
            i--;
        }
        i ++;
        BTreeNode<T> nodeHijo = load(node.children[i]);
        if(nodeHijo.checkFull(order))
        {
            splitNode(node, i, nodeHijo);
            if(data > node.info[i])
            {
                i++;
                nodeHijo = load(node.children[i]);
            }
        }
        insertData(nodeHijo, data);
    }
}

template <class T>
void BTree<T>::splitNode(BTreeNode<T> & parentNode,int i,BTreeNode<T> & node)
{
    node.parent = parentNode.pointerKey;
    BTreeNode<T> siblingNode(order);
    siblingNode.pointerKey = currentID;
    siblingNode.parent = parentNode.pointerKey;
    currentID++;
    siblingNode.leaf = node.leaf;
    int div = order-1;
    siblingNode.filledKeys = div;
    
    for(int j = 0; j < div; j++)
    {
        siblingNode.info[j] = node.info[j+order];
    }
    if (!node.leaf){
        for(int j = 0; j < div+1; j++)
        {
            siblingNode.children[j] = node.children[j+order];
        }
    }
    node.filledKeys = div;
    
    for (int j = parentNode.filledKeys+1; j >= i+1;j--)
    {
        parentNode.children[j+1] = parentNode.children[j];
    }
    
    parentNode.children[i+1] = siblingNode.pointerKey;
    
    for (int j = parentNode.filledKeys; j >= i; j--)
    {
        parentNode.info[j] = parentNode.info[j-1];
    }
    
    parentNode.info[i] = node.info[order-1];
    parentNode.filledKeys++;
    
    save(node);
    save(parentNode);
    save(siblingNode);
}

template <class T>
void BTree<T>::printNodes()
{
    BTreeNode<T> root = load(getRoot());
    print(root);
    std::cout << std::endl;
}

template <class T>
void BTree<T>::printAsc()
{
    BTreeNode<T> root = load(getRoot());
    asc(root);
    std::cout << std::endl;
}

template <class T>
void BTree<T>::printDesc()
{
    BTreeNode<T> root = load(getRoot());
    desc(root);
    std::cout << std::endl;
}

template <class T>
void BTree<T>::print(BTreeNode<T> & node)
{
    BTreeNode<T> child(order);
    if(node.leaf)
        node.print(order);
    else{
        node.print(order);
        for(int i = 0; i<= node.filledKeys; i++)
        {
            child = load(node.children[i]);
            print(child);
        }
    }
}

template <class T>
void BTree<T>::asc(BTreeNode<T> & node)
{
    BTreeNode<T> child(order);
    int i;
    for(i = 0; i < node.filledKeys; i++)
    {
        if(!node.leaf)
        {
            child = load(node.children[i]);
            asc(child);
        }
        std::cout << " " << node.info[i];
    }
    if(node.leaf == false)
    {
        child = load(node.children[i]);
        asc(child);
    }
}

template <class T>
void BTree<T>::desc(BTreeNode<T> & node)
{
    BTreeNode<T> child(order);
    int i;
    for(i = node.filledKeys; i > 0; i--)
    {
        if(!node.leaf)
        {
            child = load(node.children[i]);
            desc(child);
        }
        std::cout << " " << node.info[i-1];
    }
    if(node.leaf == false)
    {
        child = load(node.children[i]);
        desc(child);
    }
}

template <class T>
void BTree<T>::setData()
{
    int root = 0;
    try
    {
        if (std::ifstream("./data.dat"))
        {
            std::cout << "Se encontró el archivo... Abriendo " << std::endl;
            data.open("./data.dat", std::ios::out|std::ios::in| std::ios::binary);
        } else
        {
            std::cout << "No se encontró el archivo... Creando uno nuevo" << std::endl;
            data.open("./data.dat", std::ios::out | std::ios::binary);
            data.close();
            data.open("./data.dat", std::ios::out|std::ios::in| std::ios::binary);
        }
        if(data.fail())
            throw 1;
    }
    catch (int e)
    {
        std::cerr << "Hubo un error al abrir los datas... Exception " << e << " caught" << std::endl;
    }
    data.seekp(0);
    data.write(reinterpret_cast<char*>(&root), sizeof(int));
}

template <class T>
int BTree<T>::getRoot()
{
    int root;
    data.seekg(0);
    data.read(reinterpret_cast<char*>(&root), sizeof(int));
    return root;
}

template <class T>
void BTree<T>::setRoot(int rootID)
{
    data.seekp(0);
    data.write(reinterpret_cast<char*>(&rootID), sizeof(int));
}

template <class T>
int BTree<T>::numberOfNodes()
{
    int totalNodos;
    data.seekg(0);
    data.read(reinterpret_cast<char*>(&totalNodos), sizeof(int));
    return totalNodos;
}


template <class T>
void BTree<T>::updateTotal(int number)
{
    int total;
    data.seekg(0);
    data.read(reinterpret_cast<char*>(&total), sizeof(int));
    total += number;
    data.seekp(0);
    data.write(reinterpret_cast<char*>(&total), sizeof(int));
}


template <class T>
void BTree<T>::save(BTreeNode<T> & node)
{
    data.seekp(sizeof(int)+node.pointerKey*sizeof(BTreeNode<T>));
    data.write(reinterpret_cast<char*>(&node), sizeof(BTreeNode<T>));
}

template <class T>
BTreeNode<T>  BTree<T>::load(int loadKey)
{
    BTreeNode<T> node(order);
    data.seekg(sizeof(int)+loadKey*sizeof(BTreeNode<T>));
    data.read(reinterpret_cast<char*>(&node), sizeof(BTreeNode<T>));
    return node;
    
}

template <class T>
int BTree<T>::getLevel()
{
    BTreeNode<T> node = load(getRoot());
    return getLevel(node);
}

template <class T>
int BTree<T>::getLevel(BTreeNode<T> & node)
{
    int level = 0;
    while (node.parent != node.pointerKey) {
        level++;
        node = load(node.parent);
    }
    return level;
}

template <class T>
bool BTree<T>::isBTree()
{
    BTreeNode<T> root = load(getRoot());
    isBTree(root);
    leafLevels.clear();
    T cmp = leafLevels[0];
    bool leafs = true;
    for(int i=1; i<leafLevels.size(); i++)
    {
        if(leafLevels[i] != cmp)
            leafs = false;
    }
    return leafs;
}

template <class T>
void BTree<T>::isBTree(BTreeNode<T> & node)
{
    if (node.leaf)
    {
        leafLevels.push_back(getLevel(node));
    }
    else
    {
        for(int j = 0; j<=node.filledKeys;j++)
        {
            node = load(node.children[j]);
            isBTree(node);
        }
    }
}

template <class T>
BTree<T>::~BTree()
{
    data.close();
}

#endif