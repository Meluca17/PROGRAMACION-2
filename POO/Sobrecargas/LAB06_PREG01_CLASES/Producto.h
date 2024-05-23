

/* 
 * File:   Producto.h
 * Author: BlueCod (mell1)
 *
 * Created on 22 de mayo de 2024, 18:10
 */

using namespace std;

#ifndef PRODUCTO_H
#define PRODUCTO_H

class Producto {
private:
    char *codigo;
    char *descripcion;
    double precio;
    int stock;
    int clientes_servidos[100];
    int clientes_no_servidos[100];
    int cantidad_clientes_servidos;
    int cantidad_clientes_no_servidos;
public:
    Producto();
    Producto(const Producto& orig);
    virtual ~Producto();
    void SetCantidad_clientes_no_servidos(int cantidad_clientes_no_servidos);
    int GetCantidad_clientes_no_servidos() const;
    void SetCantidad_clientes_servidos(int cantidad_clientes_servidos);
    int GetCantidad_clientes_servidos() const;
//    void SetClientes_no_servidos(int[] clientes_no_servidos);
//    int[] GetClientes_no_servidos() const;
//    void SetClientes_servidos(int[] clientes_servidos);
//    int[] GetClientes_servidos() const;
    void SetStock(int stock);
    int GetStock() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetDescripcion(const char* ) ;
    void GetDescripcion(char *) const ;
    void SetCodigo(const char* ) ;
    void GetCodigo(char *) const ;
    //ADICIONALES
    void imprimeAtendidos(ofstream &) const;
    void imprimeNoAtendidos(ofstream &)const;
    bool operator+=(class Pedido &);
};

bool operator>>(ifstream &,class Producto &);
ofstream & operator<<(ofstream &, const class Producto & );

#endif /* PRODUCTO_H */

