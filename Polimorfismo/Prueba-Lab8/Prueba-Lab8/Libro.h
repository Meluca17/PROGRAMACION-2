/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Libro.h
 * Author: Josue
 *
 * Created on 14 de junio de 2024, 01:43 AM
 */

#ifndef LIBRO_H
#define LIBRO_H

class Libro {
public:
    Libro();
    Libro(const Libro& orig);
    virtual ~Libro();
    void SetVolumen(double volumen);
    double GetVolumen() const;
    void SetAlto(int alto);
    int GetAlto() const;
    void SetAncho(int ancho);
    int GetAncho() const;
    void SetNombre(const char* cad);
    void GetNombre(char* cad) const;
    void SetCodigo(const char* cad);
    void GetCodigo(char* cad) const;
private:
    char *codigo;
    char *nombre;
    int ancho;
    int alto;
    double volumen;
};

#endif /* LIBRO_H */

