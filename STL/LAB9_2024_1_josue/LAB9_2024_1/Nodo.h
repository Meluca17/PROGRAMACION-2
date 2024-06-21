/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Nodo.h
 * Author: Josue
 *
 * Created on 21 de junio de 2024, 12:00 AM
 */

#ifndef NODO_H
#define NODO_H

using namespace std;
#include "Libro.h"

class Nodo {
public:
    Nodo();
    Nodo(const Nodo& orig);
    virtual ~Nodo();
    void leeDato(ifstream &,char );
    void setNull();
    double getPeso();
    void imprimeLibro(ofstream &arch);
    void actualiza();
private:
    class Libro *plibro;
 
};

#endif /* NODO_H */

