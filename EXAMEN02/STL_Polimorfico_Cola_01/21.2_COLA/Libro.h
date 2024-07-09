

/* 
 * File:   Libro.h
 * Author: BlueCod (mell1)
 *
 * Created on 7 de julio de 2024, 11:09 p. m.
 */

#ifndef LIBRO_H
#define LIBRO_H
using namespace std;

class Libro {
private:
    char *codigo;
    char *titulo;
    char *autor;
    int cantidad;
    int stock;
    int anho;
    double precio;
    
public:
    Libro();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetAnho(int anho);
    int GetAnho() const;
    void SetStock(int stock);
    int GetStock() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetAutor(const char* autor);
    void GetAutor(char*c) const;
    void SetTitulo(const char* titulo);
    void GetTitulo(char *c) const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char*c) const;
    Libro(const Libro& orig);
//    virtual ~Libro();
    bool leeDatos(ifstream &arch);
    void imprimeDatos(ofstream &arch);
    void operator =(const class Libro &lib);
};

#endif /* LIBRO_H */

