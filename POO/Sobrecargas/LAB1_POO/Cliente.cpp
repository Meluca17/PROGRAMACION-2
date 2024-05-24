
/* 
 * File:   Cliente.cpp
 * Author: mell1
 * 
 * Created on 23 de mayo de 2024, 16:25
 */

#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std; 
#define MAX_LIB 30
#include "Cliente.h"

Cliente::Cliente() {
    //estoy en el const por defecto
    dni=0;  
    nombre = nullptr; 
    cantDeLibros = 0; 
    paagoTotal = 0.0; 
}

Cliente::Cliente(const Cliente& orig) {
}

Cliente::~Cliente() {
    //estoy en el destructor 
    if(nombre) delete nombre; 
}

void Cliente::SetPaagoTotal(double paagoTotal) {
    this->paagoTotal = paagoTotal;
}

double Cliente::GetPaagoTotal() const {
    return paagoTotal;
}

void Cliente::SetCantDeLibros(int cantDeLibros) {
    this->cantDeLibros = cantDeLibros;
}
int Cliente::GetCantDeLibros() const {
    return cantDeLibros;
}

/////////////////////////// CADENA /////////////////////////////////
void Cliente::SetNombre(const char* nombre) {
    //si ya existe un nombre lo deleteamos 
    if(this->nombre!=nullptr) delete this->nombre; 
    //declaramos el nuevo nombre 
    this->nombre = new char [strlen(nombre)+1]; 
    strcpy(this->nombre, nombre);
}

void Cliente::GetNombre(char *c) const {
    //si no existe el nombre retorna cad vacia 
    if(this->nombre==nullptr) c[0] = 0; 
    else strcpy(c,this->nombre); 
}

///////////////////////////////////////////////////////////////////////////

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}

///////////////////////// SOBRECARGAS ////////////////////////////////
//LECTURA DE UN LIBRO 
bool operator>>(ifstream &arch,class Cliente &c){
    //variables aux
    int dniC;
    char nomb[70];
    
    arch>>dniC;
    if(arch.eof()) return false;
    arch.get();
    arch.getline(nomb,70,'\n');

    
    //guardamos
    c.SetDni(dniC);
    c.SetNombre(nomb);
    
    return true;
}

ofstream& operator<<(ofstream &arch, const class Cliente &c){
    char buffNomb[70];
    int cantL;
    cantL = c.GetCantDeLibros();
    c.GetNombre(buffNomb);
    
    arch<<setprecision(2)<<fixed;
    arch<<left<<setw(10)<<c.GetDni()<<setw(70)<<buffNomb<<endl;
    arch<<"Libros entregados: "<<endl;
    arch<<setw(15)<<" "<<"Pedido No."<<setw(10)<<" "<<"CODIGO"<<setw(10)<<
            " "<<"Precio"<<endl;
    for(int i=0;i<cantL;i++){
        //imprecion de los libros entregados
    }
    arch<<"Total a pagar: "<<c.GetPaagoTotal()<<endl;
    arch<<"Libros no entregrados por falta de stock: "<<endl;
    arch<<setw(15)<<" "<<"Pedido No."<<setw(10)<<" "<<"CODIGO"<<endl;
    
    
    return arch;
}
    
//se le coloca CONST -> para usar los metodos 
void Cliente::imprimirLibrosNoEnt(ofstream &arch) const{
    char buffC[12];
    int numPed,k=0;
    
    for(int i=0; i<cantDeLibros; i++){
        if(librosSolicitados[i].IsAtendido()==false){
            numPed = librosSolicitados[i].GetNumeroDePedido();
            librosSolicitados[i].GetCodigoDelLibro(buffC);
            arch<<setw(17)<<" "<<setfill('0')<<setw(5)<<numPed<<
             setfill(' ')<<setw(13)<<" "<<setw(7)<<buffC<<endl;
            k++;
        }
    }
    if(k==0) arch<<" SE ENTREGARON TODOS LOS LIBROS"<<endl;
}

void Cliente::imprimirLibrosEnt(ofstream &arch) const{
    char buffC[12];
    int numPed,k=0;
    
    for(int i=0; i<cantDeLibros; i++){
        if(librosSolicitados[i].IsAtendido()==true){
            numPed = librosSolicitados[i].GetNumeroDePedido();
            librosSolicitados[i].GetCodigoDelLibro(buffC);
            arch<<setw(17)<<" "<<setfill('0')<<setw(5)<<numPed<<
             setfill(' ')<<setw(13)<<" "<<setw(7)<<buffC<<endl;
            k++;
        }
    }
    if(k==0) arch<<" NO SE ATENDIO NINGUN LIBRO "<<endl;
}

//Agrega LibroSolicitado a Cliente
//1.verifica si el arreglo esta lleno o no
bool Cliente::operator<<(class LibroSolicitado &pedido){
    bool atendido;
    int cant = GetCantDeLibros();
    int numPed;
    double prec;
    char buffC[14];
    
    pedido.GetCodigoDelLibro(buffC);
    numPed = pedido.GetNumeroDePedido();
    prec = pedido.GetPrecio();
    atendido = pedido.IsAtendido();
    
    if(cant< MAX_LIB){
        librosSolicitados[cant].SetCodigoDelLibro(buffC);
        librosSolicitados[cant].SetNumeroDePedido(numPed);
        librosSolicitados[cant].SetAtendido(atendido);
        librosSolicitados[cant].SetPrecio(prec);
        cantDeLibros++;
        return true;
    }
    //ya no se pueden añadir
    else{
        return false;
    }
}

void Cliente::operator++(){
    if(cantDeLibros>0){
        //calcula y asigna el pago total
        for(int i=0;i<cantDeLibros;i++){
            paagoTotal+=librosSolicitados[i].GetPrecio();
        }
    }
    else{
        return;
    }
}