#ifndef __binaryTree__BTreeNode__
#define __binaryTree__BTreeNode__

template <class T>
class BTreeNode {
public:
    int pointerKey = NULL;
    int filledKeys = 0;
    int parent = NULL;
    bool leaf = false;
    T *info;
    int *children;
    
    
    
    BTreeNode(int);
    BTreeNode(int,int,std::fstream &);
    virtual ~BTreeNode();
    
    bool checkFull(int);
    
    
    void printInfo();
    void print(int);
    
};

template <class T>
void BTreeNode<T>::printInfo()
{
    for(int i = 0; i < filledKeys;i++)
    {
        std::cout << info[i] << " ";
    }
}




template <class T>
bool BTreeNode<T>::checkFull(int orden)
{
    return filledKeys==orden*2-1;
}


template <class T>
BTreeNode<T>::BTreeNode(int orden)
{
    info = new T[2*orden-1];
    children = new int[2*orden+1];
}

template <class T>
void BTreeNode<T>::print(int orden)
{
    std::cout << "Nodo: ";
    std::cout << pointerKey << std::endl;
    std::cout << "Padre: ";
    std::cout << parent << std::endl;
    
    std::cout << "Info: ";
    printInfo();
    std::cout << std::endl;
    if(!leaf){
        std::cout << "Hijos: ";
        for(int i = 0; i < filledKeys+1;i++)
        {
            std::cout << children[i] << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Leaf" << std::endl;
    }
    
    std::cout << std::endl;
}



template <class T>
BTreeNode<T>::~BTreeNode(){
}


#endif /* defined(__binaryTree__BTreeNode__) */