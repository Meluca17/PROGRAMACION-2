

/* 
 * File:   Libro.h
 * Author: BlueCod (mell1)
 *
 * Created on 20 de junio de 2024, 13:46
 */

#ifndef LIBRO_H
#define LIBRO_H
using namespace std;

class Libro {
private:
    char *nombre; 
    int paginas; 
    double peso; 
public:
    Libro();
    Libro(const Libro& orig);
    virtual ~Libro();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetPaginas(int paginas);
    int GetPaginas() const;
    void SetNombre(const char* nombre);
    void  GetNombre(char* c) const;
    
    virtual void lee(ifstream &arch);
    virtual void imprime(ofstream &arch);
    virtual void actualiza(int anho)=0;
    virtual void eliminar();
};

#endif /* LIBRO_H */

