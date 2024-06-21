

/* 
 * File:   Biblioteca.h
 * Author: BlueCod (mell1)
 *
 * Created on 20 de junio de 2024, 22:15
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include "ListaEstante.h"
#include "NLibro.h"

class Biblioteca {
private:
    class ListaEstante listaDobleEstantes;// LIST - vector de estantes 
public:
    Biblioteca();
    Biblioteca(const Biblioteca& orig);
    virtual ~Biblioteca();
    
    void carga();
    void llena();
    void baja();
    void muestra();
    bool asignaEstante(class NLibro &libroLeido);
};

#endif /* BIBLIOTECA_H */

