

#include "Utils.h"
#include "BibliotecaListaGenerica.h"
using namespace std; 
enum Reg{DATO,SIG};

void crearLista(ifstream &arch,void *&lista, 
        void* (*lee)(ifstream &), int (*comp)(const void*, const void*)){
    
    void *dato; 
    lista = nullptr; //INICIALIZACION 
    
    while(true){
        dato = lee(arch);
        if(dato ==nullptr) break; 
        insertaLista(lista,dato,comp); 
    }
}

void insertaLista(void *&lista,void * dato, int (*comp)(const void*, const void*)){
    void **p = (void **)lista;
    void **ant = nullptr; 
    void **nuevo; 
    
    nuevo = new void*[2]; //UN NODITO JEJE
    nuevo[DATO] = dato; 
    
    //recorrer con p para encontrar donde insertar nuestro dato :))))
    while(p!=nullptr){
        if(comp(p[DATO],dato)>0) break; //cuando nuestro dato que queremos insertar es mayor 
        ant = p; 
        p = (void **)p[SIG]; 
    }
    nuevo[SIG] = p; 
    
    if(ant ==nullptr) lista = nuevo; //si apuntamos al inicio 
    else ant[SIG] = nuevo; 
    
}

void imprimirLista(void*lista, void (*imprime)(void *)){
    void **listaCampos = (void **)lista; //para ACCEDER a los nodidos (mini arreglos) de la lista 
    
    while(listaCampos){
        imprime(listaCampos[DATO]); 
        listaCampos = (void **)(listaCampos[SIG]); 
    }
}










