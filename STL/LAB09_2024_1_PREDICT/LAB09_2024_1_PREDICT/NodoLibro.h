/* 
 * File:   NodoLibro.h
 * Author: ramir
 *
 * Created on 21 de junio de 2024, 12:18 AM
 */

#ifndef NODOLIBRO_H
#define NODOLIBRO_H

#include "Libro.h"

class NodoLibro {
public:
    NodoLibro();
    NodoLibro(const NodoLibro& orig);
    virtual ~NodoLibro();
    void leerLibros(ifstream &);
    void SetNull();
    double GetPeso() const;
    void actualizaVigencia();
    void imprimeLibro(ofstream &);
private:
    Libro *ptr_libro;
};

#endif /* NODOLIBRO_H */

