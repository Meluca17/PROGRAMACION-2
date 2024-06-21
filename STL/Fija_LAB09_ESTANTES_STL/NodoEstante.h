

/* 
 * File:   NodoEstante.h
 * Author: BlueCod (mell1)
 *
 * Created on 20 de junio de 2024, 22:45
 */

#ifndef NODOESTANTE_H
#define NODOESTANTE_H
#include "Estante.h"

class NodoEstante {
private:
    class NodoEstante *sig;
    class NodoEstante *ant;
    class Estante *pEstante;
public:
    NodoEstante();
//    NodoEstante(const NodoEstante& orig);
//    virtual ~NodoEstante();
    
    friend class ListaEstante;
};

#endif /* NODOESTANTE_H */

