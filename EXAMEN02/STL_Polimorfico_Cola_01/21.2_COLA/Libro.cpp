
/* 
 * File:   Libro.cpp
 * Author: mell1
 * 
 * Created on 7 de julio de 2024, 11:09 p. m.
 */
#include "Utils.h"
using namespace std;
#include "Libro.h"

Libro::Libro() {
    autor = nullptr;
    codigo = nullptr;
    titulo = nullptr;
    stock = 0;
}
Libro::Libro(const Libro& orig) {
    autor = nullptr;
    codigo = nullptr;
    titulo = nullptr;
    (*this) = orig;
}

void Libro::operator =(const class Libro &lib){
    anho = lib.anho;
    cantidad = lib.cantidad; 
    precio = lib.precio;
    stock = lib.stock;
    //usamos el metodo set que le brinda memoria propia 
    SetCodigo(lib.codigo);
    SetAutor(lib.autor);
    SetTitulo(lib.titulo);
}

//Libro::~Libro() {
//}
void Libro::SetPrecio(double precio) {
    this->precio = precio;
}

double Libro::GetPrecio() const {
    return precio;
}

void Libro::SetAnho(int anho) {
    this->anho = anho;
}

int Libro::GetAnho() const {
    return anho;
}

void Libro::SetStock(int stock) {
    this->stock = stock;
}

int Libro::GetStock() const {
    return stock;
}

void Libro::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Libro::GetCantidad() const {
    return cantidad;
}


void Libro::SetAutor(const char* autor) {
    if(this->autor!=nullptr) delete this->autor;
    //espacio de mem y copiar 
    this->autor = new char [strlen(autor)+1];
    strcpy(this->autor,autor);
}


void  Libro::GetAutor(char* c) const {
    if(this->autor==nullptr) c[0] = 0;
    else strcpy(c,this->autor);
}

void Libro::SetTitulo(const char* titulo) {
    if(this->titulo!=nullptr) delete this->titulo;
    //espacio de mem y copiar 
    this->titulo = new char [strlen(titulo)+1];
    strcpy(this->titulo,titulo);
}

void Libro::GetTitulo(char*c) const {
    if(this->titulo==nullptr) c[0] = 0;
    else strcpy(c,this->titulo);
}

void Libro::SetCodigo(const char* codigo) {
    if(this->codigo!=nullptr) delete this->codigo;
    //espacio de mem y copiar 
    this->codigo = new char [strlen(codigo)+1];
    strcpy(this->codigo,codigo);
}

void Libro::GetCodigo(char*c) const {
   if(this->codigo==nullptr) c[0] = 0;
    else strcpy(c,this->codigo);
}

////////////////////////// OTROS METODOS //////////////////////////////////
bool Libro::leeDatos(ifstream &arch){
    char buffC[100]{},buffT[200]{},buffA[100]{},c;
    
    arch.getline(buffC,100,',');
    if(arch.eof()) return false; 
    arch.getline(buffT,200,',');
    arch.getline(buffA,100,',');
    arch>>anho>>c>>cantidad>>c>>precio;
    arch.get(); //salto de lin

    SetAutor(buffA);
    SetCodigo(buffC);
    SetTitulo(buffT);
    SetStock(cantidad); //inicializado en cantidad 
    //cout<<cantidad<<endl;
    return true;
}

void Libro::imprimeDatos(ofstream &arch){
     char buffC[100]{},buffT[200]{},buffA[100]{},c;
     GetAutor(buffA);
     GetCodigo(buffC);
     GetTitulo(buffT);
     
      arch.precision(2);
    arch << fixed;
     arch << setw(10) << left << buffC
         << setw(50) << left << buffT
         << setw(50) << left << buffA
         << setw(6) << right << anho
         << setw(15) << right << stock
         << setw(10) << right << cantidad
         << setw(10) << right << precio
         << endl; // Asegúrate de agregar un salto de línea al final
 }