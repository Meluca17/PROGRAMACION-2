
/* 
 * File:   Libro.cpp
 * Author: mell1
 * 
 * Created on 23 de mayo de 2024, 16:29
 */
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std; 
#include "Libro.h"

Libro::Libro() {
    //CONSTRUCTOR POR DEFECTO 
    autor = nullptr;
    codigo = nullptr;
    titulo = nullptr;
    precio = 0.0; 
    stock = 0; 
}

Libro::Libro(const Libro& orig) {
}

Libro::~Libro() {
    if(autor ) delete autor;
    if(codigo ) delete codigo;
    if(titulo ) delete titulo;    
}

void Libro::SetPrecio(double precio) {
    this->precio = precio;
}

double Libro::GetPrecio() const {
    return precio;
}

void Libro::SetStock(int stock) {
    this->stock = stock;
}

int Libro::GetStock() const {
    return stock;
}

///////////////////////// CADENAS ////////////////////////////////

void Libro::SetAutor(const char* autor) {
    //si ya existe un nombre lo deleteamos 
    if(this->autor!=nullptr) delete this->autor; 
    //declaramos el nuevo nombre 
    this->autor = new char [strlen(autor)+1]; 
    strcpy(this->autor, autor); 
}

void Libro::GetAutor(char *c) const {
    //si no existe el nombre retorna cad vacia 
    if(this->autor==nullptr) c[0] = 0; 
    else strcpy(c,this->autor); 
}

void Libro::SetTitulo(const char* titulo) {
   //si ya existe un nombre lo deleteamos 
    if(this->titulo!=nullptr) delete this->titulo; 
    //declaramos el nuevo nombre 
    this->titulo = new char [strlen(titulo)+1]; 
    strcpy(this->titulo, titulo); 
}

void Libro::GetTitulo(char *c) const {
    //si no existe el nombre retorna cad vacia 
    if(this->titulo==nullptr) c[0] = 0; 
    else strcpy(c,this->titulo); 
}

void Libro::SetCodigo(const char* codigo) {
    //si ya existe un nombre lo deleteamos 
    if(this->codigo!=nullptr) delete this->codigo; 
    //declaramos el nuevo nombre 
    this->codigo = new char [strlen(codigo)+1]; 
    strcpy(this->codigo, codigo);
}

void Libro::GetCodigo(char *c) const {
    //si no existe el nombre retorna cad vacia 
    if(this->codigo==nullptr) c[0] = 0; 
    else strcpy(c,this->codigo); 
}

///////////////////////// SOBRECARGAS ////////////////////////////////
//LECTURA DE UN LIBRO 
bool operator>>(ifstream &arch,class Libro &l){
    //variables aux
    char cod[12], aut[70],tit[70],c;
    int stockL;
    double precio;
    
    arch.getline(cod,12,',');
    if(arch.eof()) return false;
    arch.getline(aut,70,',');
    arch.getline(tit,70,',');
    arch>>stockL>>c>>precio;
    
    //guardamos
    l.SetStock(stockL);
    l.SetPrecio(precio);
    l.SetAutor(aut);
    l.SetCodigo(cod);
    l.SetTitulo(tit);
    
    return true;
}

ofstream& operator<<(ofstream &arch, const class Libro &l){
    char buffCod[13], tit[70],aut[70];
    l.GetCodigo(buffCod);
    l.GetTitulo(tit);
    l.GetAutor(aut);
    
    arch<<setprecision(2)<<fixed;
    arch<<left<<setw(15)<<buffCod<<setw(70)<<tit<<setw(70)<<aut
            <<right<<setw(3)<<l.GetStock()<<setw(7)<<" "<<setw(8)
            <<l.GetPrecio()<<endl;
    
    return arch;
}




//LIBROS 
// cod tit aut stock    prec

//te quiero <3 uwu