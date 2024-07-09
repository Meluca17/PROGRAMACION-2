

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
    int prestados;
public:
    Libro();
    Libro(const Libro& orig);
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
    void SetPrestados(int prestados);
    int GetPrestados() const;
    //
    void leerDatos(ifstream &arch);
    void imprimeDatos(ofstream &arch) const;
    bool operator < (const class Libro &);
    void operator = (const class Libro &);
    
};

#endif /* LIBRO_H */

