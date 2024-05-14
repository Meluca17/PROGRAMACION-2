/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: Josue
 *
 * Created on 13 de mayo de 2024, 11:35 PM
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void leerLibros(void *&libros,const char *nombArch);
char *leeCadenaExacta(ifstream &arch,char limitador);
void *leeRegistro(ifstream &archLibro);
void reporteLibros(void *libros,const char *nombArch);
void imprimirLibros(void *auxLibro,ofstream &archRep);
void leePunteroMultiple(char ***&librosMult,int *&stock,double *&precio,
        void *libros);
void aumentarEspacios(char ***&librosMult,int *&stock,double *&precio,int &cantidad,int &capacidad);
void colocarDatos(void *datosLibro,char **&librosMult,int &stock,double &precio);

void reporteDePunteros(char ***librosMult,int *stock,double *precio,const char *nombArch);
#endif /* FUNCIONESAUXILIARES_H */

