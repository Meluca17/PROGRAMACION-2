/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Camion.h
 * Author: alulab14
 *
 * Created on 17 de noviembre de 2023, 08:01 AM
 */

#ifndef CAMION_H
#define CAMION_H

#include "NPedido.h"
#include "Vehiculo.h"
#include <map>
#include <fstream>
#include <iomanip>
using namespace std;

class Camion : public Vehiculo{
public:
    void SetEjes(int ejes);
    int GetEjes() const;
    void SetLlantas(int llantas);
    int GetLlantas() const;
    void lee (ifstream &arch);
    void imprime (ofstream &arch);
    void cargadeposito (ifstream &arch, class NPedido &);
private:
    int ejes;
    int llantas;
    map<int, NPedido> mdeposito;
};

#endif /* CAMION_H */

