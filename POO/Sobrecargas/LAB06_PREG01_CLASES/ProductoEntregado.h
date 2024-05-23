

/* 
 * File:   ProductoEntregado.h
 * Author: BlueCod (mell1)
 *
 * Created on 22 de mayo de 2024, 18:07
 */

#ifndef PRODUCTOENTREGADO_H
#define PRODUCTOENTREGADO_H

class ProductoEntregado {
private:
    char *codigo;
    double precio;
public:
    ProductoEntregado();
    ProductoEntregado(const ProductoEntregado& orig);
    virtual ~ProductoEntregado();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char *) const;
};

#endif /* PRODUCTOENTREGADO_H */

