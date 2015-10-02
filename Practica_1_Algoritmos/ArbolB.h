#ifndef __binaryTree__ArbolB__
#define __binaryTree__ArbolB__

#include "NodoArbolB.h"

#include <fstream>

template <class T>
class ArbolB {
private:
    
    int currentID;
    int orden;
    fstream data;
    
    void setData();
public:
    
    ArbolB(int orden);
    ~ArbolB();
    void Insertar(T dato);
    void Borrar(T dato);

    
    void updateTotal(int cantidad);
    int getRoot();
    void setRoot(int rootID);
    
    void insertarDato(NodoArbolB<T> & nodo,T dato);
    void divideNodo(NodoArbolB<T> & nodoPadre,int i,NodoArbolB<T> & nodo);
    void save(NodoArbolB<T> & nodo);
    NodoArbolB<T> carga(int llaveDeCarga);
    void cargaNodo(NodoArbolB<T> *,int);
    int cantidadNodos(); // Checa cantidad de nodos
    void searchForNode(NodoArbolB<T> & node,T data, bool & found);
    bool searchForNode(T dato);
    void print(NodoArbolB<T> & node);
    void print();
};

template <class T>
bool ArbolB<T>::searchForNode(T dato)
{
    NodoArbolB<T> root = carga(getRoot());
    bool found = false;
    searchForNode(root, dato, found);
    return found;
}

template <class T>
void ArbolB<T>:: searchForNode(NodoArbolB<T> & nodo,T dato, bool & found)
{
    int i = 0;
    while(i < nodo.espaciosUsados && dato > nodo.info[i])
        i++;
    if (i < nodo.espaciosUsados && dato == nodo.info[i])
    {
        found = true;
        return;
    }
    else if (nodo.leaf)
    {
        return;
    }
    else
    {
        for(int j = i; j<=nodo.espaciosUsados;j++)
        {
            nodo = carga(nodo.hijos[j]);
            searchForNode(nodo, dato, found);
        }
    }
}

template <class T>
ArbolB<T>::ArbolB(int orden){
    this->orden = orden;
    currentID = 0;
    setData();
    NodoArbolB<T> nodo(orden);
    nodo.llave = currentID;
    nodo.leaf = true;
    save(nodo);
    currentID++;
}



template <class T>
void ArbolB<T>::Insertar(T dato){
    NodoArbolB<T> root = carga(getRoot());
    if(root.checkFull(orden)){
        NodoArbolB<T> nodoPadre(orden);
        nodoPadre.llave = currentID;
        setRoot(currentID);
        nodoPadre.leaf = false;
        nodoPadre.espaciosUsados = 0;
        nodoPadre.hijos[0] = root.llave;
        nodoPadre.padre = nodoPadre.llave;
        currentID++;
        divideNodo(nodoPadre, 0, root);
        insertarDato(nodoPadre, dato);
    }
    else{
        insertarDato(root, dato);
        
    }
}

template <class T>
void ArbolB<T>::insertarDato(NodoArbolB<T> & nodo,T dato){
    int i = nodo.espaciosUsados-1;
    if(nodo.leaf){
        while (i >= 0 && dato < nodo.info[i]){
            nodo.info[i+1] = nodo.info[i];
            i--;
        }
        nodo.info[i+1] = dato;
        nodo.espaciosUsados++;
        save(nodo);
        
    }
    else{
        while (i >= 0 && dato < nodo.info[i]){
            i--;
        }
        i ++;
        NodoArbolB<T> nodoHijo = carga(nodo.hijos[i]);
        if(nodoHijo.checkFull(orden)){
            divideNodo(nodo, i, nodoHijo);
            if(dato > nodo.info[i]){
                i++;
                nodoHijo = carga(nodo.hijos[i]);
            }
        }
        insertarDato(nodoHijo, dato);
    }
}

template <class T>
void ArbolB<T>::divideNodo(NodoArbolB<T> & nodoPadre,int i,NodoArbolB<T> & nodo){
    nodo.padre = nodoPadre.llave;
    NodoArbolB<T> nodoHermano(orden);
    nodoHermano.llave = currentID;
    nodoHermano.padre = nodoPadre.llave;
    currentID++;
    nodoHermano.leaf = nodo.leaf;
    int div = orden-1;
    nodoHermano.espaciosUsados = div;
    
    for(int j = 0; j < div; j++){
        nodoHermano.info[j] = nodo.info[j+orden];
    }
    if (!nodo.leaf){
        for(int j = 0; j < div+1; j++){
            nodoHermano.hijos[j] = nodo.hijos[j+orden];
        }
    }
    nodo.espaciosUsados = div;
    
    for (int j = nodoPadre.espaciosUsados+1; j >= i+1;j--){
        nodoPadre.hijos[j+1] = nodoPadre.hijos[j];
    }
    
    nodoPadre.hijos[i+1] = nodoHermano.llave;
    
    for (int j = nodoPadre.espaciosUsados; j >= i; j--){
        nodoPadre.info[j] = nodoPadre.info[j-1];
    }
    
    nodoPadre.info[i] = nodo.info[orden-1];
    nodoPadre.espaciosUsados++;
    
    save(nodo);
    save(nodoPadre);
    save(nodoHermano);
}


template <class T>
void ArbolB<T>:: print(NodoArbolB<T> & nodo)
{
    NodoArbolB<T> hijo(orden);
    int i = 0;
    while(i < nodo.espaciosUsados)
    {
        std::cout << "| " << nodo.info[i] << " |";
        i++;
    }
    std::cout << std::endl;
    if(!nodo.leaf)
    {
        for(int j = 0; j<=nodo.espaciosUsados;j++)
        {
            hijo = carga(nodo.hijos[j]);
            print(hijo);
        }
    }
    else
        return;
}

template <class T>
void ArbolB<T>::print()
{
   NodoArbolB<T> root = carga(getRoot());
    print(root);
}

template <class T>
void ArbolB<T>::setData(){
    int root = 0;
    try
    {
        if (ifstream("./data.dat")) {
            std::cout << "Se encontró el archivo... Abriendo " << std::endl;
            data.open("./data.dat", ios::out|ios::in| ios::binary);
        } else {
            std::cout << "No se encontró el archivo... Creando uno nuevo" << std::endl;
            data.open("./data.dat", ios::out | ios::binary);
            data.close();
            data.open("./data.dat", ios::out|ios::in| ios::binary);
        }
        if(data.fail())
            throw 1;
    }
    catch (int e)
    {
        std::cerr << "Hubo un error al abrir los datos... Exception " << e << " caught" << std::endl;
    }
    data.seekp(0);
    data.write(reinterpret_cast<char*>(&root), sizeof(int));
}

template <class T>
int ArbolB<T>::getRoot(){
    int root;
    data.seekg(0);
    data.read(reinterpret_cast<char*>(&root), sizeof(int));
    return root;
}

template <class T>
void ArbolB<T>::setRoot(int rootID){
    data.seekp(0);
    data.write(reinterpret_cast<char*>(&rootID), sizeof(int));
}

template <class T>
int ArbolB<T>::cantidadNodos(){
    int totalNodos;
    data.seekg(0);
    data.read(reinterpret_cast<char*>(&totalNodos), sizeof(int));
    return totalNodos;
}


template <class T>
void ArbolB<T>::updateTotal(int cantidad){
    int total;
    data.seekg(0);
    data.read(reinterpret_cast<char*>(&total), sizeof(int));
    total += cantidad;
    data.seekp(0);
    data.write(reinterpret_cast<char*>(&total), sizeof(int));
}


template <class T>
void ArbolB<T>::save(NodoArbolB<T> & nodo){
    data.seekp(sizeof(int)+nodo.llave*sizeof(NodoArbolB<T>));
    data.write(reinterpret_cast<char*>(&nodo), sizeof(NodoArbolB<T>));
}

template <class T>
NodoArbolB<T>  ArbolB<T>::carga(int llaveDeCarga){
    NodoArbolB<T> nodo(orden);
    data.seekg(sizeof(int)+llaveDeCarga*sizeof(NodoArbolB<T>));
    data.read(reinterpret_cast<char*>(&nodo), sizeof(NodoArbolB<T>));
    return nodo;
    
}


template <class T>
ArbolB<T>::~ArbolB(){
    data.close();
}

#endif /* defined(__binaryTree__ArbolB__) */