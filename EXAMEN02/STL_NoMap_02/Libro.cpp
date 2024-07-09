
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
    cantidad = 0;
}
Libro::Libro(const Libro& orig) {
    autor = nullptr;
    codigo = nullptr;
    titulo = nullptr;
    (*this) = orig;
}


void Libro::operator = (const class Libro &lib){
    anho = lib.anho;
    stock = lib.stock;
    precio = lib.precio;
    //metodo set que brinda memoria propia
    SetAutor(lib.autor);
    SetCodigo(lib.codigo);
    SetTitulo(lib.titulo);
}


bool Libro::operator < (const class Libro &lib){
    char buff[100];
    lib.GetCodigo(buff);
    return strcmp(codigo,buff)<0;
}
//Libro::~Libro() {
//}
void Libro::SetPrestados(int prestados) {
    this->prestados = prestados;
}

int Libro::GetPrestados() const {
    return prestados;
}

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
void Libro::leerDatos(ifstream &arch){
    char buff1[100], buff2[100], buff3[100],c;
    
    arch.getline(buff1,100,',');
    if(arch.eof()) return;
    arch.getline(buff2,100,',');
    arch.getline(buff3,100,',');
    arch>>anho>>c>>stock>>c>>precio;
    arch.get();
    
    SetCodigo(buff1);
    SetTitulo(buff2);
    SetAutor(buff3);
}

void Libro::imprimeDatos(ofstream &arch) const {
    arch.precision(2);
    arch<<fixed;
    
    char buff1[100],buff2[100],buff3[100];
    GetCodigo(buff1);
    GetTitulo(buff2);
    GetAutor(buff3);
    
    arch<<left<<setw(15)<<buff1<<setw(60)<<buff2<<setw(60)
            <<buff3<<setw(5)<<" "<<right<<anho<<setw(5)<<" "<<right<<stock
            <<setw(5)<<" "<<right<<precio<<endl;
}