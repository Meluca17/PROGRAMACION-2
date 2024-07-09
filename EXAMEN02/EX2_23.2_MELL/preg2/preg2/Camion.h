/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Camion.h
 * Author: Josue
 *
 * Created on July 2, 2024, 7:57 PM
 */

#ifndef CAMION_H
#define CAMION_H

#include <fstream>
#include <vector>
using namespace std;
#include "Vehiculo.h"
#include "Pedido.h"
class Camion:public Vehiculo {
public:
    void SetLlantas(int llantas);
    int GetLlantas() const;
    void SetEjes(int ejes);
    int GetEjes() const;
    void lee (ifstream &arch);
    void imprime(ofstream &arch);
    void insertar (class Pedido &ped);
private:
    int ejes;
    int llantas;
    vector <Pedido> depositos;//max 5
};

#endif /* CAMION_H */

