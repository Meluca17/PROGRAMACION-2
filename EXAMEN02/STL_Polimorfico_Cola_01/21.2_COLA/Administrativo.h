

/* 
 * File:   Administrativo.h
 * Author: BlueCod (mell1)
 *
 * Created on 7 de julio de 2024, 11:19 p. m.
 */

#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H
#include "Usuario.h"
using namespace std;

class Administrativo: public Usuario {
private:
    char *area; // area a la cual pertence el administrativo
public:
    Administrativo();
//    Administrativo(const Administrativo& orig);
//    virtual ~Administrativo();
    void SetArea(const char* area);
    void GetArea(char*c) const;
    void leer(ifstream &arch);
    void getDatos(char &tipo,
        char *buffarea,char *buffNombre,  int &anex, int &cel);
    void imprimir(ofstream &arch);
};

#endif /* ADMINISTRATIVO_H */

