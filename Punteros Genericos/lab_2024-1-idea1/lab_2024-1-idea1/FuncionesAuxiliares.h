/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: Josue
 *
 * Created on 25 de abril de 2024, 05:39 PM
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H
void lecturaDeLibros(void *&libros,const char* nombrArch);
void *leeLibros(ifstream &archLibros);
char *leeCadena(ifstream &arch);
void imprimeLibro(void *libros);
void imprimeLineas(ofstream &archRep,char car);
void imprimeInfoLibro(void *libro,ofstream &archRep);
void lecturaDeClientes(void *&clientes,const char *nombArch);
void *leeCliente(ifstream &archCliente);
void imprimeCliente(void *clientes,const char *nombArch);
void imprimeUnCliente(void *cliente,ofstream &archRep);
void completarPedidos(void *&clientes,void *libros,const char *nombArch);
int buscarCliente(void *clientes,int dni);
bool comparar(void *cliente,int dni);
int buscarLibro(char *codLibro,void *libros);
int compararLibros(void *libro,char *codLibro);
void agregarLibro(void *&cliente,void *libro,int numPedido,char *codLibro,int &cant);
void agregamosPedido(int numPedido,char *codLibro,char *nuevoTitulo,void *pedidos,int cant);
void recortaPedidos(void *&auxClientes,int cantPedidos);
void recortaBuffer(void *&pedidos,int cantPedidos);
void imprimeReporteFinal(void *clientes,const char*nombArch);
void imprimeInfoCompletaCliente(void *aux,ofstream &archRep);
void imprimePedidos(ofstream &archRep,void *auxCliente);
void imprimeUnPedido(ofstream &archRep,void *pedido);
#endif /* FUNCIONESAUXILIARES_H */

