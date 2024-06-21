
/* 
 * File:   Biblioteca.cpp
 * Author: mell1
 * 
 * Created on 20 de junio de 2024, 22:15
 */
#include "Utils.h"
#include "Biblioteca.h"
#include "NLibro.h"
using namespace std;

Biblioteca::Biblioteca() {
    
}

Biblioteca::Biblioteca(const Biblioteca& orig) {
}

Biblioteca::~Biblioteca() {
}

// clase, id ,peso
void Biblioteca::carga(){
    ifstream arch("Estantes2.csv",ios::in);
    if(!arch.is_open()){
        cout<<"iipipip"<<endl;
        exit(1);
    }
    
    listaDobleEstantes.leeDatos(arch);
    
}

void Biblioteca::llena(){
    ifstream arch("Libros3.csv",ios::in);
    if(!arch.is_open()){
        cout<<"iipipip"<<endl;
        exit(1);
    }
    char tipo;
    class NLibro libroLeido;
    while(true){
        arch>>tipo;
        if(arch.eof())break;
        arch.get();
        libroLeido.asignaMemoria(tipo);
        libroLeido.leeLibro(arch);
        //asigna a un estante o lo descarta 
        if(not asignaEstante(libroLeido)){
            //se deletea el libro
            cout<<"debo eliminar gaa"<<endl;
            libroLeido.eliminar();
        }
    }
}

bool Biblioteca::asignaEstante(class NLibro &libroLeido){
    //recorremos la lista de estantes
    return listaDobleEstantes.meteLibroEstante(libroLeido);
}

void Biblioteca::baja(){
    listaDobleEstantes.actualizaLibrosEstante(2020);
}
   
void Biblioteca::muestra(){
    ofstream arch("Reporte.txt",ios::out);
    if(!arch.is_open()){
        cout<<"iipipip"<<endl;
        exit(1);
    }
    arch<<setw(10)<<" "<<"Estantes:"<<endl;
    for(int i=0; i<100;i++) arch<<"=";
    arch<<endl;
    listaDobleEstantes.muestraDatos(arch);
}