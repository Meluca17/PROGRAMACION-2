/* 
 * File:   Biblioteca.h
 * Author: ramir
 *
 * Created on 21 de junio de 2024, 12:28 AM
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "ListaDoble.h"

class Biblioteca {
public:
    Biblioteca();
    Biblioteca(const Biblioteca& orig);
    virtual ~Biblioteca();
    void carga();
    void llena();
    void baja();
    void muestra();
private:
    ListaDoble LDEstantes;
    void imprimirLinea(ofstream &,char);
};

#endif /* BIBLIOTECA_H */

