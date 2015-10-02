#ifndef __binaryTree__NodoArbolB__
#define __binaryTree__NodoArbolB__

using namespace std;
template <class T>
class NodoArbolB {
public:
    int llave = NULL;
    int espaciosUsados = 0;
    int padre = NULL;
    bool leaf = false;
    T *info;
    int *hijos;
    
    NodoArbolB(int);
    NodoArbolB(int,int,fstream &);
    virtual ~NodoArbolB();
    
    bool checkFull(int);
    
    void printInfo();
    void print(int,bool);
    
};

template <class T>
void NodoArbolB<T>::printInfo(){
    for(int i = 0; i < espaciosUsados;i++){
        cout << info[i] << " ";
    }
}


template <class T>
bool NodoArbolB<T>::checkFull(int orden){
    return espaciosUsados==orden*2-1;
}


template <class T>
NodoArbolB<T>::NodoArbolB(int orden){
    info = new T[2*orden-1];
    hijos = new int[2*orden+1];
}

template <class T>
void NodoArbolB<T>::print(int orden,bool root){
    cout << "Nodo: ";
    cout << llave << endl;
    if(root)
        cout << "Root" << endl;
    else{
        cout << "Padre: ";
        cout << padre << endl;
    }
    cout << "Info: ";
    printInfo();
    cout << endl;
    if(!leaf){
        cout << "Hijos: ";
        for(int i = 0; i < espaciosUsados+1;i++){
            cout << hijos[i] << " ";
        }
        cout << endl;
    }
    else{
        cout << "Leaf" << endl;
    }
    
    cout << endl;
}



template <class T>
NodoArbolB<T>::~NodoArbolB(){
}


#endif /* defined(__binaryTree__NodoArbolB__) */