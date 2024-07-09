/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Furgon.h
 * Author: Josue
 *
 * Created on July 2, 2024, 8:04 PM
 */

#ifndef FURGON_H
#define FURGON_H
#include <fstream>
#include <list>
using namespace std;
#include "Vehiculo.h"
#include "Pedido.h"

class Furgon:public Vehiculo {
public:
    void SetPuertas(int puertas);
    int GetPuertas() const;
    void SetFilas(int filas);
    int GetFilas() const;
    void lee (ifstream &arch);
    void imprime(ofstream &arch);
    void insertar (class Pedido &ped);
private:
    int filas;
    int puertas;
    list <Pedido>depositos;
};

#endif /* FURGON_H */

