/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vehiculo.h
 * Author: alulab14
 *
 * Created on 17 de noviembre de 2023, 08:01 AM
 */

#ifndef VEHICULO_H
#define VEHICULO_H

#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;

class Vehiculo {
public:
    Vehiculo();
//    Vehiculo(const Vehiculo& orig);
    virtual ~Vehiculo();
    void SetActcarga(double actcarga);
    double GetActcarga() const;
    void SetMaxcarga(double maxcarga);
    double GetMaxcarga() const;
    void SetPlaca(const char* placa);
    void GetPlaca(char* placa) const;
    void SetCliente(int cliente);
    int GetCliente() const;
    virtual void lee (ifstream &arch);
    virtual void imprime (ofstream &arch);
private:
    int cliente;
    char *placa;
    double maxcarga;
    double actcarga;
};

#endif /* VEHICULO_H */

