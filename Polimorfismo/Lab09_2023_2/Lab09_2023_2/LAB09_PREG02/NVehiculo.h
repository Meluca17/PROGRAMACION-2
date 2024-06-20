/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NVehiculo.h
 * Author: alulab14
 *
 * Created on 17 de noviembre de 2023, 08:02 AM
 */

#ifndef NVEHICULO_H
#define NVEHICULO_H

#include <fstream>
#include "NPedido.h"
using namespace std;

class NVehiculo {
public:
    NVehiculo();
    void leeDatos (ifstream &arch);
    void imprimeDatos (ofstream &arch);
    bool operator < (class NVehiculo);
    int GetCliente ();
    void leePedido(ifstream &arch, class NPedido &);
private:
    class Vehiculo *unidad;
};

#endif /* NVEHICULO_H */

