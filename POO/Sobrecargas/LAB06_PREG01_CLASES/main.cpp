
/* 
 * File:   main.cpp
 * Author: BlueCod (mell1)
 *
 * Created on 22 de mayo de 2024, 18:06
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Cliente.h"
#include "Producto.h"
#include "Pedido.h"
#include "Almacen.h"

int main(int argc, char** argv) {
//    ifstream arch("PruebaCliente.txt",ios::in);
//    ifstream archProd("Productos.csv",ios::in);
//    ifstream archPed("Pedidos.csv",ios::in);
//    ofstream archRep("RepPrueba.txt",ios::out);
//    //ofstream archRep2("RepP2.txt",ios::out);
//    
//    class Cliente c1,c2;
//    class Producto p1,p2;
//    class Pedido ped1,ped2;
//    
//    arch>>c1;
//    archRep<<c1;
//    
//    archProd>>p1;
//    archRep<<p1;
//    
//    archPed>>ped1;
//    archPed>>ped2; 
//    
//    
//    //añade un pedido a un PRODUCTO 
//    archRep<<" AÑADIENDO PEDIDOS "<<endl;
//    p1+=ped1; 
//    archRep<<p1;
//    archRep<<endl; 
//    //añade un pedido a UN CLIENTE
//    c1+=ped1; 
//    archRep<<c1;
    
    Almacen almacen; 
    
    almacen.cargar_clientes(); 
    almacen.cargar_productos(); 
    almacen.cargar_pedidos(); 
    almacen.mostrar_datos(); 
    
    
    return 0;
}

//CLIENTES
// dni  nonbre  telefono

//PRODUCTOS
// cod   desc   precio  stockFinal

//PEDIDOS
//  codProdPedido  dni 