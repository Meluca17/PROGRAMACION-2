/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Furgon.h
 * Author: alulab14
 *
 * Created on 17 de noviembre de 2023, 08:02 AM
 */

#ifndef FURGON_H
#define FURGON_H

#include "NPedido.h"
#include "Vehiculo.h"
#include <list>
#include <fstream>
#include <iomanip>
using namespace std;

class Furgon: public Vehiculo{
public:
    void SetPuertas(int puertas);
    int GetPuertas() const;
    void SetFilas(int filas);
    int GetFilas() const;
    void lee (ifstream &arch);
    void imprime (ofstream &arch);
private:
    int filas;
    int puertas;
    list<NPedido> pdeposito; // tiene comportamiento de pila
};

#endif /* FURGON_H */

