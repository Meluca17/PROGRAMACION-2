/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Libro.h
 * Author: julia
 *
 * Created on 23 de mayo de 2024, 11:52
 */

#ifndef LIBRO_H
#define LIBRO_H

class Libro {
public:
    Libro();
    virtual ~Libro();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetStock(int stock);
    int GetStock() const;
    void SetAutor(const char* aut);
    void GetAutor(char *aut) const;
    void SetTitulo(const char* titulo);
    void GetTitulo(char *tit) const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char *) const;
private:
    char *codigo;
    char *titulo;
    char *autor;
    int stock;
    double precio;
};

bool operator >>(ifstream &,Libro &);
int buscarLibro(char *codigoDelLibro,Libro *libros);
void operator <<(ofstream &,Libro &);
#endif /* LIBRO_H */

