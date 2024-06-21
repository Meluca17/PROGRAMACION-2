/* 
 * File:   Libro.h
 * Author: ramir
 *
 * Created on 21 de junio de 2024, 12:12 AM
 */

#ifndef LIBRO_H
#define LIBRO_H

class Libro {
public:
    Libro();
    Libro(const Libro& orig);
    virtual ~Libro();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetPaginas(int paginas);
    int GetPaginas() const;
    void SetNombre(char *cad);
    void GetNombre(char *cad) const;
    virtual void lee(ifstream &);
    virtual void actualiza()=0;
    virtual void imprime(ofstream &);
private:
    char *nombre;
    int paginas;
    double peso;
};

#endif /* LIBRO_H */

