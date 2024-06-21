

/* 
 * File:   ListaEstante.h
 * Author: BlueCod (mell1)
 *
 * Created on 20 de junio de 2024, 22:44
 */

#ifndef LISTAESTANTE_H
#define LISTAESTANTE_H
using namespace std;

class ListaEstante {
private:
    class NodoEstante *lini;
    class NodoEstante *lfin;
public:
    ListaEstante();
    ListaEstante(const ListaEstante& orig);
    virtual ~ListaEstante();
    
    void leeDatos(ifstream &arch);
    void insertaOrden(class Estante *&dato);
    void muestraDatos(ofstream &arch);
    bool meteLibroEstante(class NLibro &lib);
    void actualizaLibrosEstante(int);
};

#endif /* LISTAESTANTE_H */

