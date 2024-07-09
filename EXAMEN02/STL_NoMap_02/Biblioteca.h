

/* 
 * File:   Biblioteca.h
 * Author: BlueCod (mell1)
 *
 * Created on 8 de julio de 2024, 5:15 p. m.
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "Libro.h"
#include "RegistroUsuario.h"

class Biblioteca {
private:
    list <Libro> libros;
    vector <RegistroUsuario> usuarios;
public:
    Biblioteca();
//    Biblioteca(const Biblioteca& orig);
//    virtual ~Biblioteca();
    //
    void leeLibros(const char *filename);
    void imprimeLibros(const char *filename);
    void leeUsuarios(const char *filename);
    void imprimeUsuarios(const char *filename);
    void leerPrestamos(const char *filename);
    void actualizaLibros(char *libPres);
    void imprimirSuspendidos(const char *filename,int dia,int mes,int anho);
};

#endif /* BIBLIOTECA_H */

