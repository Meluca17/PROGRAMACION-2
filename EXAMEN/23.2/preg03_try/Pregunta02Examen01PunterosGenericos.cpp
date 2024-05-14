/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <fstream>
using namespace std;
#include "Pregunta02Examen01PunterosGenericos.h"
#define INCREMENTO 5
void cargaProductos(void *&productos,const char *nombArch){
    ifstream arch (nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: no se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    productos=nullptr;
    void *datos;
    int numDat=0,capacidad=0;
    while(true){
        datos=leeRegistroProductos(arch);
        if(arch.eof())break;
        if(numDat==capacidad){
            aumentarEspacios(productos,numDat,capacidad);
        }
        asignarDatos(productos,datos,numDat-1);
        numDat++;
    }
    qsort(productos,numDat-1,sizeof(void *),compara);
}

int compara(const void *a,const void *b){
    void **ai=(void **)a,**bi=(void **)b;
    void **regA=(void **)(*ai),**regB=(void **)(*bi);
    void **regAA=(void **)(regA[0]),**regBB=(void **)(regB[0]);
    char *codA=(char *)regAA[0],*codB=(char *)regBB[0];
    return strcmp(codA,codB);
}

void asignarDatos(void *&productos,void *datos,int pos){
    void **aux=(void **)productos;
    void **registro=new void*[2];
    registro[0]=datos;
    registro[1]=nullptr;
    aux[pos]=registro;
}
void aumentarEspacios(void *&productos,int &numDat,int &capacidad){
    capacidad+=5;
    void **aux;
    if(productos==nullptr){
        aux=new void*[capacidad]{};
        productos=aux;
        numDat=1;
    }
    else{
        aux=new void*[capacidad]{};
        void **auxProductos=(void **)productos;
        for(int i=0;i<numDat;i++){
            aux[i]=auxProductos[i];
        }
        delete auxProductos;
        productos=aux;
    }
}
void *leeRegistroProductos(ifstream &arch){
    char *codigo,*descripcion;
    double *precio=new double;
    int *stock=new int;
    codigo=leerCadenaExacta(arch,',');
    if(arch.eof())return nullptr;
    descripcion=leerCadenaExacta(arch,',');
    arch>>*precio;
    arch.get();
    arch>>*stock>>ws;
    void **datos=new void *[4];
    datos[0]=codigo;
    datos[1]=descripcion;
    datos[2]=precio;
    datos[3]=stock;
    return datos;
}
char *leerCadenaExacta(ifstream &arch, char limitador){
    char cadena[60],*nuevaCadena;
    arch.getline(cadena,60,limitador);
    if(arch.eof())return nullptr;
    nuevaCadena=new char[strlen(cadena)+1];
    strcpy(nuevaCadena,cadena);
    return nuevaCadena;
}
void pruebaDeCargaDeProductos(void *productos){
    ofstream archRep("ReporteProductos.txt",ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: no se pudo abrir el archivo ReporteProductos.txt"<<endl;
        exit(1);
    }
    archRep<<setw(50)<<" "<<"REPORTE DE PRODUCTOS"<<endl;
    imprimeLinea2(archRep,'=');
    archRep<<setw(3)<<" "<<"CODIGO"<<setw(10)<<" "<<"DESCRIPCION"<<
            setw(46)<<" "<<"PRECIO"<<setw(5)<<" "<<"STOCK"<<endl;
    archRep<<fixed;
    archRep.precision(2);
    imprimeLinea2(archRep,'-');
    void **auxProducto=(void **)productos;
    for(int i=0;auxProducto[i];i++){
        imprimirProducto(auxProducto[i],archRep);
    }
}

void imprimirProducto(void *producto,ofstream &archRep){
    void **registros=(void **)producto;
    void **datos=(void **)registros[0];
    char *cod=(char *)datos[0],*descripcion=(char *)datos[1];
    double *precio=(double *)datos[2];
    int *stock=(int *)datos[3];
    archRep<<setw(2)<<" "<<setw(7)<<cod<<setw(5)<<" "<<setw(60)<<left<<descripcion<<
            right<<setw(8)<<*precio<<setw(5)<<" "<<setw(3)<<*stock<<endl;
}

void imprimeLinea2(ofstream &arch,char lineas){
    for(int i=0;i<200;i++)arch.put(lineas);
    arch<<endl;
}