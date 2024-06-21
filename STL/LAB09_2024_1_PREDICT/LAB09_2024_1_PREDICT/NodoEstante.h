/* 
 * File:   NodoEstante.h
 * Author: ramir
 *
 * Created on 21 de junio de 2024, 12:24 AM
 */

#ifndef NODOESTANTE_H
#define NODOESTANTE_H

#include "NodoEstante.h"
#include "Estante.h"
#include "Libro.h"

class NodoEstante {
public:
    NodoEstante();
    NodoEstante(const NodoEstante& orig);
    virtual ~NodoEstante();
    friend class ListaDoble;
private:
    Estante *pestante;
    NodoEstante *sig;
    NodoEstante *ant;
};

#endif /* NODOESTANTE_H */

