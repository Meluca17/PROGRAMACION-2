

/* 
 * File:   LibroSolicitado.h
 * Author: BlueCod (mell1)
 *
 * Created on 23 de mayo de 2024, 16:28
 */
using namespace std;
#include "Libro.h"

#ifndef LIBROSOLICITADO_H
#define LIBROSOLICITADO_H

class LibroSolicitado {
private:
    int numeroDePedido; 
    char *codigoDelLibro;
    double precio; 
    bool atendido;  //true ( se atendio ) , false (no se atendio ) 
public:
    LibroSolicitado();
    LibroSolicitado(const LibroSolicitado& orig);
    virtual ~LibroSolicitado();
    void SetAtendido(bool atendido);
    bool IsAtendido() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetNumeroDePedido(int numeroDePedido);
    int GetNumeroDePedido() const;
    //cadena
    void SetCodigoDelLibro(const char* codigoDelLibro);
    void  GetCodigoDelLibro(char *) const;
    //extras
    bool operator>>(class Libro *arrLib);
    int buscarLibro(char *codSol,class Libro *arrLib);
};

#endif /* LIBROSOLICITADO_H */

