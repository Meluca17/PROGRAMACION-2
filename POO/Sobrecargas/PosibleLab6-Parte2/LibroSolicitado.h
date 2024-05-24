/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   LibroSolicitado.h
 * Author: julia
 *
 * Created on 23 de mayo de 2024, 11:42
 */

#ifndef LIBROSOLICITADO_H
#define LIBROSOLICITADO_H
#include "Libro.h"
class LibroSolicitado {
public:
    LibroSolicitado();
    LibroSolicitado(int,const char*,double,bool);
    virtual ~LibroSolicitado();
    void SetAtendido(bool atendido);
    bool IsAtendido() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigoDelLibro(const char *cod);
    void GetCodigoDelLibro(char *cod) const;
    void SetNumeroDelPedido(int numeroDelPedido);
    int GetNumeroDelPedido() const;
    void operator =(const LibroSolicitado &);
    bool operator >>(Libro *libros);
private:
    int numeroDelPedido;
    char *codigoDelLibro;
    double precio;
    bool atendido;
};

#endif /* LIBROSOLICITADO_H */

