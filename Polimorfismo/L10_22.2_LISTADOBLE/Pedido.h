

/* 
 * File:   Pedido.h
 * Author: BlueCod (mell1)
 *
 * Created on 11 de junio de 2024, 0:29
 */

#ifndef PEDIDO_H
#define PEDIDO_H
#include "Utils.h"
using namespace std; 

class Pedido {
private:
    int codigo;
    char *nombre;
    int cantidad;
    int dni;
    int fecha;
    double total; //monto del pedido
public:
    Pedido();
    virtual ~Pedido();
    void SetTotal(double total);
    double GetTotal() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetDni(int dni);
    int GetDni() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetNombre(const char* nombre);
    void GetNombre(char*c) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    //
    virtual void lee(ifstream &arch); 
    bool operator >(const class Pedido &); 
    virtual void imprime(ofstream &arch);
    virtual void actualizaMonto()=0;
};

#endif /* PEDIDO_H */

