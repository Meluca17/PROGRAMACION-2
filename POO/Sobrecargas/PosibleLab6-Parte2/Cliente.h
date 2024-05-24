/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Cliente.h
 * Author: julia
 *
 * Created on 23 de mayo de 2024, 11:58
 */

#ifndef CLIENTE_H
#define CLIENTE_H
#include "LibroSolicitado.h"
class Cliente {
public:
    Cliente();
    virtual ~Cliente();
    void SetPagoTotal(double pagoTotal);
    double GetPagoTotal() const;
    void SetCantDeLibros(int cantDeLibros);
    int GetCantDeLibros() const;
    void SetNombre(const char* nombre);
    void GetNombre(char *) const;
    void SetDni(int dni);
    int GetDni() const;
    bool operator <<(const LibroSolicitado &);
    void operator ++();
    void imprimirPedidos(ofstream &arch);
private:
    int dni;
    char *nombre;
    LibroSolicitado librosSolicitados[30];
    int cantDeLibros;
    double pagoTotal;
};

bool operator >>(ifstream &,Cliente &);
void operator <<(ofstream &,Cliente &);

#endif /* CLIENTE_H */

