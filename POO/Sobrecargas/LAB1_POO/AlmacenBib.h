

/* 
 * File:   AlmacenBib.h
 * Author: BlueCod (mell1)
 *
 * Created on 23 de mayo de 2024, 22:57
 */
#include "Cliente.h"
#include "Libro.h"

#ifndef ALMACENBIB_H
#define ALMACENBIB_H

class AlmacenBib {
private:
    class Cliente arreglo_clientes[100];
    int cantidad_clientes;
    class Libro arreglo_libros[300];
    int cantidad_libros;
public:
    AlmacenBib();
    AlmacenBib(const AlmacenBib& orig);
    virtual ~AlmacenBib();
    void SetCantidad_libros(int cantidad_libros);
    int GetCantidad_libros() const;
    void SetCantidad_clientes(int cantidad_clientes);
    int GetCantidad_clientes() const;
    //funciones
    void cargar_clientes() ; 
    void cargar_libros() ; 
    void cargar_pedidos() ; 
    int buscarCliente(int );
    void mostrar_datos();
    void imprimeLinea(ofstream &,int n, char c);
};

#endif /* ALMACENBIB_H */

