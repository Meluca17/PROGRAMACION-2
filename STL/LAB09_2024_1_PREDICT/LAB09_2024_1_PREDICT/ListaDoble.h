/* 
 * File:   ListaDoble.h
 * Author: ramir
 *
 * Created on 21 de junio de 2024, 12:25 AM
 */

#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include "NodoEstante.h"


class ListaDoble {
public:
    ListaDoble();
    ListaDoble(const ListaDoble& orig);
    virtual ~ListaDoble();
    void creaLista(ifstream &);
    void llenaLibros(ifstream &);
    void actualizaVigencia();
    void imprimeEstantes(ofstream &);
private:
    NodoEstante *lini;
    NodoEstante *lfin;
    void insertar(class NodoEstante*);
    void insertarLibro(class NodoLibro);
};

#endif /* LISTADOBLE_H */

