/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: julia
 *
 * Created on 23 de mayo de 2024, 16:17
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void cargarLibros(ifstream &archLibros,Libro *arrLibros);
void cargarClientes(ifstream &archClientes,Cliente *arrClientes);
void cargarPedidos(ifstream &arch,Libro *arrLibros,Cliente *arrClientes);
void cargarLibrosSolicitados(ifstream &arch,int numPed,int dni,Libro *arrLibros,Cliente *arrClientes);
int buscarPosicionCliente(int dni,Cliente *arrClientes);
void imprimirLibros(ofstream &archLibrosOf,Libro *arrLibros);
void imprimirClientes(ofstream &archClientesOf,Cliente *arrClientes);

#endif /* FUNCIONES_H */

