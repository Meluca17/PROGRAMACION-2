/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Pedido.h
 * Author: Josue
 *
 * Created on July 2, 2024, 7:50 PM
 */

#ifndef PEDIDO_H
#define PEDIDO_H
#include <fstream> 
#include <string>
using namespace std;

class Pedido {
public:
    Pedido();
    Pedido(const Pedido& orig);
    void SetPeso(double peso);
    double GetPeso() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(string codigo);
    string GetCodigo() const;
    void operator = (const class Pedido &ped);
    void leePedido(ifstream &arch);
    void imprime(ofstream &arch);
private:
    string codigo;
    int cantidad;
    double peso;
};

#endif /* PEDIDO_H */

