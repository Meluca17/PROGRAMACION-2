
/* 
 * File:   NLibro.cpp
 * Author: mell1
 * 
 * Created on 20 de junio de 2024, 23:01
 */
#include "Utils.h"
#include "NLibro.h"
#include "Enciclopedia.h"
#include "Revista.h"
#include "Novela.h"
using namespace std;

NLibro::NLibro() {
    unidad = nullptr;
}

NLibro::NLibro(const NLibro& orig) {
    unidad = nullptr;
    *this = orig;
}

NLibro::~NLibro() {
}

void NLibro::asignaMemoria(char tipo){
    if(tipo=='N') unidad = new class Novela;
    if(tipo=='E') unidad = new class Enciclopedia;
    if(tipo=='R') unidad = new class Revista;
}

void NLibro::leeLibro(ifstream &arch){
    unidad->lee(arch);
}

double NLibro::GetPesoLibro(){
    return unidad->GetPeso();
}

void NLibro::imprimeLibro(ofstream &arch){
    unidad->imprime(arch);
}
void NLibro::actualizaLibro(int anho){
    unidad->actualiza(anho);
}

void NLibro::eliminar(){
    unidad->eliminar();
}