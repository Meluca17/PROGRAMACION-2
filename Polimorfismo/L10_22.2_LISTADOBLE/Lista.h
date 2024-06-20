

/* 
 * File:   Lista.h
 * Author: BlueCod (mell1)
 *
 * Created on 11 de junio de 2024, 0:42
 */

#ifndef LISTA_H
#define LISTA_H
using namespace std; 

class Lista {
private:
    class Nodo *lini;
    class Nodo *lfin;
    
    void imprimeRec(class Nodo *rec,ofstream &arch); 
public:
    Lista();
    virtual ~Lista();
    void leeDatos(const char *filename);
    void asignaMemoria(int cod, class Pedido *&ped); 
    void insertarOrd(class Pedido *&dato);
    void imprimeDatos(const char *filename); 
    void imprimirIterativo(ofstream &arch); 
    void actualizaDatos(const char *filename);
    void actualizaClientes(int dniLeid,int fecha);
};

#endif /* LISTA_H */

