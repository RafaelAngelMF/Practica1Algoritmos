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
    
    void print();
    
    void updateTotal(int cantidad);
    int getRoot();
    void setRoot(int rootID);
    
    void insertarDato(NodoArbolB<T> & nodo,T dato);
    void divideNodo(NodoArbolB<T> & nodoPadre,int i,NodoArbolB<T> & nodo);
    void save(NodoArbolB<T> & nodo);
    NodoArbolB<T> carga(int llaveDeCarga);
    void cargaNodo(NodoArbolB<T> *,int);
    int cantidadNodos(); // Checa cantidad de nodos
};

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
            if(dato > nodo.info[i])
                i++;
        }
        insertarDato(nodoHijo, dato);
    }
}

template <class T>
void ArbolB<T>::divideNodo(NodoArbolB<T> & nodoPadre,int i,NodoArbolB<T> & nodo){
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
void ArbolB<T>::print(){
    NodoArbolB<T> nodo(orden);
    for(int i = 0; i < currentID; i++){
        nodo = carga(i);
        nodo.print();
        cout << endl;
    }
    
}


template <class T>
void ArbolB<T>::setData(){
    //    int totalNodos = 0;
    int root = 0;
    data.open("/Users/javiercuriel/Documents/XCODE/Algoritmos/Arbol-B/Arbol-B/data.dat", ios::out|ios::in| ios::binary);
    data.seekp(0);
    //    data.write(reinterpret_cast<char*>(&totalNodos), sizeof(int));
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