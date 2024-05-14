/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "FuncionesAuxiliares.h"
#define INCREMENTOS 5
enum libros{COD,TIT,AUT,STO,PRE};

void leerLibros(void *&libros,const char *nombArch){
    ifstream archLibro(nombArch,ios::in);
    if(not archLibro.is_open()){
        cout<<"ERROR: Archivo libros"<<endl;
        exit(1);
    }
    void *buffLibros[400]{},*dato;
    int cant=0;
    while(true){
        dato=leeRegistro(archLibro);
        if(archLibro.eof())break;
        buffLibros[cant]=dato;
        cant++;
    }
    
    void **nuevoBuff=new void*[cant+2]{};
    for(int i=0;i<cant;i++){
        nuevoBuff[i]=buffLibros[i];
    }
    libros=nuevoBuff;
}
void *leeRegistro(ifstream &archLibro){
    char *codigo,*titulo,*autor,car;
    int *stock;
    double *precio;
    void **datos;
    codigo=leeCadenaExacta(archLibro,',');
    if(archLibro.eof())return nullptr;
    datos=new void*[5];
    stock=new int;
    precio=new double;
    titulo=leeCadenaExacta(archLibro,',');
    autor=leeCadenaExacta(archLibro,',');
    archLibro>>*stock>>car>>*precio;
//    archLibro>>ws;
    archLibro.get();
    datos[COD]=codigo;
    datos[TIT]=titulo;
    datos[AUT]=autor;
    datos[STO]=stock;
    datos[PRE]=precio;
 
    
    return datos;
    
}
char *leeCadenaExacta(ifstream &arch,char limitador){
    char *nuevaCad,cadena[60];
    arch.getline(cadena,60,limitador);
    if(arch.eof())return nullptr;
    nuevaCad=new char [strlen(cadena)+1];
    strcpy(nuevaCad,cadena);
    return nuevaCad;
}

void reporteLibros(void *libros,const char *nombArch){
    ofstream archRep(nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: Archivo de reporte de libros"<<endl;
        exit(1);
    }
    archRep<<fixed;
    archRep.precision(2);
    void **auxLibros=(void **)libros;
    for(int i=0;auxLibros[i];i++){
        imprimirLibros(auxLibros[i],archRep);
    }
}
void imprimirLibros(void *auxLibro,ofstream &archRep){
    void **libro=(void **)auxLibro;
    char *codigo=(char *)libro[COD],*titulo=(char *)libro[TIT],*autor=(char *)libro[AUT];
    int *stock=(int *)libro[STO];
    double *precio=(double *)libro[PRE];
    archRep<<setw(7)<<codigo<<setw(5)<<" "<<left<<setw(60)<<titulo<<setw(50)<<autor<<
            right<<setw(5)<<*stock<<setw(10)<<" "<<setw(10)<<*precio<<endl;
}

void leePunteroMultiple(char ***&librosMult,int *&stock,double *&precio,
        void *libros){
    void **auxLibros=(void **)libros;
    int capacidad=0,cantidad=0;
    
    librosMult=nullptr;
    stock=nullptr;
    precio=nullptr;
    for(int i=0;auxLibros[i];i++){
        if(cantidad==capacidad)aumentarEspacios(librosMult,stock,precio,cantidad,capacidad);
        colocarDatos(auxLibros[i],librosMult[cantidad-1],stock[cantidad-1],precio[cantidad-1]);
        cantidad++;
    }
    
}

void colocarDatos(void *datosLibro,char **&librosMult,int &stock,double &precio){
    void **libro=(void **)datosLibro;
    char *codigo=(char *)libro[COD],*titulo=(char *)libro[TIT],*autor=(char *)libro[AUT],
            *nuevoCod,*nuevoTitulo,*nuevoAutor;
    int *stockIni=(int *)libro[STO],stockNuevo;
    double *precioIni=(double *)libro[PRE],precioNuevo;
    nuevoCod=new char[strlen(codigo)+1];
    nuevoTitulo=new char[strlen(titulo)+1];
    nuevoAutor=new char[strlen(autor)+1];
    strcpy(nuevoCod,codigo);
    strcpy(nuevoTitulo,titulo);
    strcpy(nuevoAutor,autor);
    stockNuevo=(*stockIni);
    precioNuevo=(*precioIni);
    stock=stockNuevo;
    precio=precioNuevo;
    librosMult=new char *[3];
    librosMult[0]=nuevoCod;
    librosMult[1]=nuevoTitulo;
    librosMult[2]=nuevoAutor;
}

void aumentarEspacios(char ***&librosMult,int *&stock,double *&precio,int &cantidad,int &capacidad){
    capacidad+=INCREMENTOS;
    if(librosMult==nullptr){
        librosMult=new char **[capacidad]{};
        precio=new double [capacidad]{};
        stock=new int [capacidad]{};
        cantidad=1;
    }
    else{
        char ***auxLibros=new char **[capacidad]{};
        int *auxStock=new int [capacidad]{};
        double *auxPrecio=new double [capacidad]{};
        for(int i=0;i<cantidad;i++){
            auxLibros[i]=librosMult[i];
            auxPrecio[i]=precio[i];
            auxStock[i]=stock[i];
        }
        delete librosMult;
        delete stock;
        delete precio;
        librosMult=auxLibros;
        stock=auxStock;
        precio=auxPrecio;
    }
}

void reporteDePunteros(char ***librosMult,int *stock,double *precio,const char *nombArch){
    ofstream archRep(nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: Archivo de reporte de libros"<<endl;
        exit(1);
    }
    archRep<<fixed;
    archRep.precision(2);
    archRep<<"REPORTE DE LIBROS PUNTEROS"<<endl;
    char **auxLibro;
    for(int i=0;librosMult[i];i++){
        auxLibro=librosMult[i];
        archRep<<setw(7)<<auxLibro[0]<<setw(5)<<" "<<left<<setw(60)<<auxLibro[1]<<setw(50)<<auxLibro[2]<<
            right<<setw(5)<<stock[i]<<setw(10)<<" "<<setw(10)<<precio[i]<<endl;
    }
}