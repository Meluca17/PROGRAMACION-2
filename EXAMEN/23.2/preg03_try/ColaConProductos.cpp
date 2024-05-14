/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "ColaGenerica.h"
#include "ColaConProductos.h"

#define NO_ENCONTRO -1
enum producto {COD,DES,PRE,STOCK};
enum pedido {FECHA,DNI,CANTIDAD};
//OJO: no todas las estructuras son void 
void procesarPedidos(int **fechaCli,char **codigoPedido,void *productos){
    int posPed; 
    crearColaProductos(productos); 
    void **castProd = (void **)productos; 
    //recorro la estructura CODPROD de los pedidos 
    for(int i=0; fechaCli[i]; i++){
        char *codigo = codigoPedido[i]; 
        posPed = buscarPedido(codigo,productos); 
        
        if(posPed!=NO_ENCONTRO){
            agregarPedido(fechaCli,castProd[posPed]);   //void * -> castProd[posPed];
        }
//        void **producto = (void **)castProd[posPed]; 
//        int *stock = (int *)producto[3]; //stock del producto pedido 
//        
//        int *pedidoSol = fechaCli[i]; 
//        int cantPedida = pedidoSol[2]; 
//        if(*stock >cantPedida){
//            //SE PUEDE ATENDER -> ENCOLAMOS :))) 
            
        }
    }
}



int buscarPedido(char *codigoBus,void *productos){
    void **castProd = (void **)productos; 
    //recorre toda la estructura de productos
    for(int i=0; castProd[i]; i++){
        void **producto = (void **)castProd[i]; 
        void **detalles = (void **)producto[0]; 
        char *codigo = (char *)detalles[0]; 
        
        if(strcmp(codigo,codigoBus)==0) return i;
    }
    return NO_ENCONTRO; 
}
void crearColaProductos(void *productos){
    void **castProductos = (void **)productos;
    void **producto; 
    for(int i=0; castProductos[i]; i++){
        producto = (void **)castProductos[i];
        generacola(producto[1]);
    }
}