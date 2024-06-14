

/* 
 * File:   NPedido.h
 * Author: BlueCod (mell1)
 *
 * Created on 12 de junio de 2024, 10:13
 */

#ifndef NPEDIDO_H
#define NPEDIDO_H
#include "Vehiculo.h"
#include "NPedido.h"
using namespace std;

class NPedido {
private:
    char *codigo;
    int cantidad; 
    double peso; 
    class NPedido *sig; 
public:
    NPedido();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char *c) const;
    
    friend class Vehiculo;
    void lee(ifstream &arch);
    void imprimePedido(ofstream &arch);
};

#endif /* NPEDIDO_H */

