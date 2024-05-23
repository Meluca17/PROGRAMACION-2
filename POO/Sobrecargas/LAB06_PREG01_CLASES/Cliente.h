

/* 
 * File:   Cliente.h
 * Author: BlueCod (mell1)
 *
 * Created on 22 de mayo de 2024, 18:08
 */


#include <fstream>
using namespace std; 
#include "ProductoEntregado.h"
#include "Pedido.h"

#ifndef CLIENTE_H
#define CLIENTE_H


class Cliente {
private:
    int dni;
    char *nombre;
    int telefono;
    class ProductoEntregado productos_entregados[100];
    int cantidad_productos_entregados;
    double monto_total;
public:
    Cliente();
    //Cliente(const Cliente& orig);
    virtual ~Cliente();
    void SetMonto_total(double monto_total);
    double GetMonto_total() const;
    void SetCantidad_productos_entregados(int cantidad_productos_entregados);
    int GetCantidad_productos_entregados() const;
    //void SetProductos_entregados(ProductoEntregado[] productos_entregados);
    //class ProductoEntregado &GetProducto_entregado(int i) const;
    void SetTelefono(int telefono);
    int GetTelefono() const;
    void SetNombre(const char* cad);
    void  GetNombre(char *) const;
    void SetDni(int dni);
    int GetDni() const;
    void imprimirProductos(ofstream &) const; 
    //SOBRECARGAS
    void operator+=(class Pedido &);
};
//ARCHIVO DE TEXTO 
bool operator>>(ifstream &, class Cliente &);
ofstream & operator<<(ofstream &, const class Cliente & );

#endif /* CLIENTE_H */

