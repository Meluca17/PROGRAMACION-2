/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Estante.h
 * Author: Josue
 *
 * Created on 21 de junio de 2024, 12:01 AM
 */

#ifndef ESTANTE_H
#define ESTANTE_H
#include <vector>
#include <fstream>
using namespace std;
#include "Nodo.h"
class Estante {
public:
    Estante();
    
    void SetCapacidad(double capacidad);
    double GetCapacidad() const;
    void SetId(int id);
    int GetId() const;
    void SetClase(char clase);
    char GetClase() const;
    void agregaDatos(char tipo, int numero, double peso);
    double getSobrante();
    void insertaLibro(class Nodo &libro);
    void imprimeEstante(ofstream &arch);
    void actualizaLibros();
private:
    char clase;
    int id;
    double capacidad;
   
    vector <class Nodo>nLibros;
};

#endif /* ESTANTE_H */

