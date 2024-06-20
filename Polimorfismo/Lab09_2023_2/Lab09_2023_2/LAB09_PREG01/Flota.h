/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Flota.h
 * Author: alulab14
 *
 * Created on 17 de noviembre de 2023, 08:03 AM
 */

#ifndef FLOTA_H
#define FLOTA_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include "NVehiculo.h"
#include <vector>
using namespace std;

class Flota {
public:
//    Flota();
//    Flota(const Flota& orig);
//    virtual ~Flota();
    void cargaflota();
    void muestracarga();
    void imprimeLinea(ofstream &);
private:
    vector <NVehiculo> vflota;
};

#endif /* FLOTA_H */

