/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Vehiculo.h
 * Author: Josue
 *
 * Created on July 2, 2024, 7:55 PM
 */

#ifndef VEHICULO_H
#define VEHICULO_H
#include <string>
#include <fstream>
using namespace std;
#include "Pedido.h"
class Vehiculo {
public:
    Vehiculo();
    Vehiculo(const Vehiculo& orig);
    void SetCarga_actual(double carga_actual);
    double GetCarga_actual() const;
    void SetCarga_maxima(double carga_maxima);
    double GetCarga_maxima() const;
    void SetPlaca(string placa);
    string GetPlaca() const;
    void SetDni(int dni);
    int GetDni() const;
    void operator = (const class Vehiculo &veh);
    virtual void lee (ifstream &arch);
    virtual void imprime(ofstream &arch);
    virtual void insertar (class Pedido &ped);
private:
    int dni;
    string placa;
    double carga_maxima;
    double carga_actual;
};

#endif /* VEHICULO_H */

