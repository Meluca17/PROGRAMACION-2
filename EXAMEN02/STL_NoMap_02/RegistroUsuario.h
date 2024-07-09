

/* 
 * File:   RegistroUsuario.h
 * Author: BlueCod (mell1)
 *
 * Created on 8 de julio de 2024, 5:11 p. m.
 */

#ifndef REGISTROUSUARIO_H
#define REGISTROUSUARIO_H

#include "RegistroPrestamo.h"
#include "Usuario.h"
#include "Utils.h"
using namespace std;

class RegistroUsuario {
private:
    class Usuario usuario;
    list <RegistroPrestamo> prestamos;
public:
    RegistroUsuario();
    RegistroUsuario(const RegistroUsuario& orig);
    //virtual ~RegistroUsuario();
    
    bool leeDatos(ifstream &arch);
    void imprimeDatos(ofstream &arch) const;
    bool anhadePrestamo(const class RegistroPrestamo &regPrest);
    bool tieneLibrosAtrasados(int fechaProceso) const ;
    void imprimeUsuario(ofstream &arch) const;
};

#endif /* REGISTROUSUARIO_H */

