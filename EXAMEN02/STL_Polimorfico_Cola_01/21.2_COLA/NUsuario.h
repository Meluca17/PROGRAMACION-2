

/* 
 * File:   NUsuario.h
 * Author: BlueCod (mell1)
 *
 * Created on 7 de julio de 2024, 11:25 p. m.
 */

#ifndef NUSUARIO_H
#define NUSUARIO_H

#include "Usuario.h"
using namespace std;

class NUsuario:public Usuario {
private:
    class Usuario *pusuario; //puntero a la clase 
public:
    NUsuario();
    NUsuario(const NUsuario& orig);
    virtual ~NUsuario();
    int getCarneUsuario();
    
    void leerUsuario(ifstream &arch);
    void getDatosUsuario(char &tipo,
        char *buffarea,char *buffNombre, int &anex, int &cel);
    void getDatos(char &tipo,
        char *buffarea,char *buffNombre,  int &anex, int &cel){};
    void imprimirUsuario(ofstream &arch);
    void imprimir(ofstream &arch){};
};

#endif /* NUSUARIO_H */

