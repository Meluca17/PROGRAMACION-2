/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Flota.h
 * Author: Josue
 *
 * Created on July 2, 2024, 8:07 PM
 */

#ifndef FLOTA_H
#define FLOTA_H

#include<map> 
#include <fstream>
#include <string>
using namespace std;
#include "Vehiculo.h"
class Flota {
public:
    void cargar_vehiculos();
    void mostrar_vehiculos();
    void carga_pedidos();
    bool buscarVehiculo(string cod);
private:
    map <string,Vehiculo *>vehiculos;
    void reservaMemoria(class Vehiculo *&vehiculo,char tipo);
    void imprimeLinea(ofstream &arch,char car);
    
};

#endif /* FLOTA_H */

