

/* 
 * File:   ColaSol.h
 * Author: BlueCod (mell1)
 *
 * Created on 7 de julio de 2024, 11:42 p. m.
 */

#ifndef COLASOL_H
#define COLASOL_H
#include "NodoCola.h"
#include "NUsuario.h"
#include <vector>
using namespace std;

class ColaSol {
private:
    class NodoCola *inicola;
    class NodoCola *fincola;
    int n; //tamanho de cola
public:
    ColaSol();
   ColaSol(const ColaSol& orig);
//    virtual ~ColaSol();
    void setN(int n);
    int getN() const;
    void leeSolicitudes(ifstream &arch);
    void encolar(NodoCola *dato);
    NodoCola * desencolar();
    void desencola2(char *codLib,int &carne);
    bool esColaVacia();
    void imprimeDatos(ofstream &arch,vector < NUsuario> vusuarios);
    //void imprimeDatos(ofstream &arch);
    
    int buscarUsuario(int carnet,vector <NUsuario> vusuarios);
    void getDatosUsuario( class NUsuario &usu,char &tipo,
        char *buffarea,char *buffNombre,int &anex, int &cel);
};

#endif /* COLASOL_H */

