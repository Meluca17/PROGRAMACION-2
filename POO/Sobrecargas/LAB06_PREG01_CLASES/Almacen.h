

/* 
 * File:   Almacen.h
 * Author: BlueCod (mell1)
 *
 * Created on 22 de mayo de 2024, 18:13
 */

#include "Cliente.h"
#include "Producto.h"

#ifndef ALMACEN_H
#define ALMACEN_H

class Almacen {
private:
    class Cliente arreglo_clientes[200];
    int cantidad_clientes;
    class Producto arreglo_productos[200];
    int cantidad_productos;
public:
    Almacen();
    Almacen(const Almacen& orig);
    virtual ~Almacen();
    void SetCantidad_productos(int cantidad_productos);
    int GetCantidad_productos() const;
    void SetCantidad_clientes(int cantidad_clientes);
    int GetCantidad_clientes() const;
    //funciones 
    void cargar_clientes() ; 
    void cargar_productos() ; 
    void cargar_pedidos() ; 
    void mostrar_datos(); 
    int buscarCliente(int );
    int buscarProducto(const char *);
    void imprimelinea(char, ofstream &); 
};

#endif /* ALMACEN_H */

