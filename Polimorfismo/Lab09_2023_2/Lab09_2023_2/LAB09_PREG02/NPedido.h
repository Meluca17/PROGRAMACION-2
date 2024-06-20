/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NPedido.h
 * Author: alulab14
 *
 * Created on 17 de noviembre de 2023, 08:01 AM
 */

#ifndef NPEDIDO_H
#define NPEDIDO_H

#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;

class NPedido {
public:
    NPedido();
    NPedido(const NPedido& orig);
    virtual ~NPedido();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(const char* cod);
    void GetCodigo(char* cod) const;
    void operator = (const class NPedido &ped);
    void leePedido(ifstream &arch);
    void imprimePedido (ofstream &arch);
private:
    char *codigo;
    int cantidad;
    double peso;
};

#endif /* NPEDIDO_H */

