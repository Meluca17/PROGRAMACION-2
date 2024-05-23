

/* 
 * File:   Pedido.h
 * Author: BlueCod (mell1)
 *
 * Created on 22 de mayo de 2024, 18:12
 */

using namespace std;

#ifndef PEDIDO_H
#define PEDIDO_H

class Pedido {
private:
    char *codigo;
    int dni_cliente;
    double precio_producto;
public:
    Pedido();
    Pedido(const Pedido& orig);
    virtual ~Pedido();
    void SetPrecio_producto(double precio_producto);
    double GetPrecio_producto() const;
    void SetDni_cliente(int dni_cliente);
    int GetDni_cliente() const;
    void SetCodigo(const char*);
    void GetCodigo(char *) const;
};

bool operator>>(ifstream &,class Pedido &);

#endif /* PEDIDO_H */

