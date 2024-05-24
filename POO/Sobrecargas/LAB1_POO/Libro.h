

/* 
 * File:   Libro.h
 * Author: BlueCod (mell1)
 *
 * Created on 23 de mayo de 2024, 16:29
 */

#ifndef LIBRO_H
#define LIBRO_H

class Libro {
private:
    char *codigo;
    char *titulo;
    char *autor;
    int stock;
    double precio; 
public:
    Libro();
    Libro(const Libro& orig);
    virtual ~Libro();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetStock(int stock);
    int GetStock() const;
    //cadenas
    void SetAutor(const char* autor);
    void  GetAutor(char *) const;
    void SetTitulo(const char* titulo);
    void GetTitulo(char *) const;
    void SetCodigo(const char* codigo);
    void  GetCodigo(char *) const;
    //extras
    
};

bool operator>>(ifstream &,class Libro &); 
ofstream& operator<<(ofstream &arch, const class Libro &l);

#endif /* LIBRO_H */

