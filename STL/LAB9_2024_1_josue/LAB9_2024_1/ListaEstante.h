/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ListaEstante.h
 * Author: Josue
 *
 * Created on 21 de junio de 2024, 12:07 AM
 */

#ifndef LISTAESTANTE_H
#define LISTAESTANTE_H
#include <fstream>
using namespace std;
#include "NodoEstante.h"
#include "Nodo.h"
class ListaEstante {
public:
    ListaEstante();
    void leeEstantes(ifstream &arch);
    void leeLibros(ifstream &arch);
    void imprimeEstantes(ofstream &arch);
    void actualizaEstante();
private:
     void insertaEstante(char tipo, int num, double pesoMax);
    bool insertarLibros(class Nodo &libro);
    class NodoEstante *ini;
};

#endif /* LISTAESTANTE_H */

