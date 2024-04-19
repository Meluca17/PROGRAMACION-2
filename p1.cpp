#include "Utils.h"
#include "funciones.h"
#define INCREMENTO 5
using namespace std;
enum libros{COD,TIT,AUT}; 
#define NOT_FOUND -1

char *leeCadDelim(ifstream &archLib,char delim){
    char aux_cad[100], *str; 
    
    archLib.getline(aux_cad,100,delim); 
    str = new char[strlen(aux_cad)+1];
    strcpy(str,aux_cad); 
    
    return str; 
}

//cod   nomb    autor   stock   precio
void lecturaDeLibros(const char*archName,char ***&libros,int **&stock){
    ifstream archLib(archName,ios::in); 
    //VARIABLES AUX -> TODO DINAMICO 
    char *cod, *nomb, *autor,c; 
    int cantStok; 
    double precio; 
    //VARIABLES PARA INCREMENTOS -> tmb inicializo orig
    int capacity = 0, numLib = 0; 
    libros = nullptr; 
    stock = nullptr; 
    
    while(true){
        cod = leeCadDelim(archLib,','); 
        if(archLib.eof()) break; 
        nomb = leeCadDelim(archLib,','); 
        autor = leeCadDelim(archLib,','); 
        archLib>>cantStok>>c>>precio>>c; 
        //cout << nomb<<endl;
        
        //CAPACITY = NUMDAT????
        if(capacity == numLib){
            reservaMemIncrementos(libros,stock,numLib,capacity); 
        }
        
        //ASIGNACION:
        asignarDatosDelLibro(libros[numLib-1],stock[numLib-1],cod,nomb,autor,cantStok);  
        //cout <<libros[numLib][0]<<endl; 
        //cout <<stock[numLib][0]<<endl; 
        numLib++; 
    }
}
void asignarDatosDelLibro(char **&libros,int *&stock,char *cod,char *nomb,
        char *autor,int cantStok){
    libros = new char*[3]{}; 
    libros[COD] = cod; 
    libros[TIT] = nomb; 
    libros[AUT] = autor; 
    
    stock = new int[2]{};
    stock[0] = cantStok;
    stock[1] = 0;
}


void reservaMemIncrementos(char ***&libros,int **&stock,int &numLib,int &capacity){
    //1. AUXILIARES DINAMICOS 
    char ***aux_libros; 
    int **aux_stock; 
    
    //2. AUMENTAR CAPACIDAD 
    capacity +=INCREMENTO; 
    
    //AL INICIO
    if(libros ==nullptr){ //se debe reservar en general:)))
        libros = new char **[capacity]{}; 
        stock = new int *[capacity]{}; 
        numLib = 1; //primer elemento 
    }
    else{ //YA HAY DATOSSS 
        aux_libros = new char **[capacity]{}; 
        aux_stock = new int*[capacity]{}; 
        for(int i=0; i<numLib; i++){
            aux_libros[i] = libros[i]; 
            aux_stock[i] = stock[i]; 
        }
        //los boto del salon
        delete libros; 
        delete stock; 
        //les digo q vuelvan a pasar pq ya hay espacio 
        libros = aux_libros; 
        stock = aux_stock; 
    }
}


void pruebaDeLecturaDeLibros(const char*archName,char ***libros,int **stock){
    ofstream arch(archName,ios::out); 
    
    char **aux_lib; 
    int cantLib, *aux_stock; 
    
    arch<<setw(60)<<"REPORTE INICIAL DE LIBROS"<<endl; 
    
    for(int i=0; libros[i]; i++){
     //  cout <<libros[i][0]<<endl;
        aux_lib = libros[i]; 
        aux_stock = stock[i]; 
        arch<<left <<setw(15)<<aux_lib[COD]<<setw(60)<<aux_lib[TIT]<<setw(60)<<aux_lib[AUT]
                <<setw(15)<<aux_stock[0]<<setw(15)<<aux_stock[1]<<endl; 
    }
}
