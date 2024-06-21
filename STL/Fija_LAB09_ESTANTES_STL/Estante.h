

/* 
 * File:   Estante.h
 * Author: BlueCod (mell1)
 *
 * Created on 20 de junio de 2024, 21:57
 */

#ifndef ESTANTE_H
#define ESTANTE_H
#include "Utils.h"
#include "NLibro.h"
#include <vector>
using namespace std;

class Estante {
private:
    char clase; // h , v
    int id; // identificador
    double capacidad; //peso maximo 
    vector<class NLibro>vlibro;//lista-VECTOR de libros 
public:
    Estante();
    Estante(const Estante& orig);
    virtual ~Estante();
    void SetCapacidad(double capacidad);
    double GetCapacidad() const;
    void SetId(int id);
    int GetId() const;
    void SetClase(char clase);
    char GetClase() const;
    
    void lee(ifstream &arch);
    void imprimeEstante(ofstream&arch);
    double GetEspacioSobrante();
    void agregaLibro(class NLibro &lib);
    void imprimeLibros(ofstream&arch);
    void actualizaLibros(int );
};

#endif /* ESTANTE_H */

