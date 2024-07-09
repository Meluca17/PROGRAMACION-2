

/* 
 * File:   Usuario.h
 * Author: BlueCod (mell1)
 *
 * Created on 7 de julio de 2024, 11:16 p. m.
 */

#ifndef USUARIO_H
#define USUARIO_H
#include "Utils.h"
using namespace std;

class Usuario {
private:
    int carne;
    char tipo;
    char *nombre;
public:
    Usuario();
//    Usuario(const Usuario& orig);
//    virtual ~Usuario();
    void SetNombre(const char* nombre);
    void GetNombre(char*c) const;
    void SetTipo(char tipo);
    char GetTipo() const;
    void SetCarne(int carne);
    int GetCarne() const;
    
    virtual void leer(ifstream &arch);
    virtual void getDatos(char &tipo,
        char *buffarea,char *buffNombre, int &anex, int &cel)=0;
    virtual void imprimir(ofstream &arch);
};

#endif /* USUARIO_H */

