
/* 
 * File:   Vehiculo.cpp
 * Author: mell1
 * 
 * Created on 12 de junio de 2024, 10:14
 */
#include "Utils.h"
#include "Vehiculo.h"
using namespace std;

Vehiculo::Vehiculo() {
    ped = nullptr;
    placa = nullptr;
    actcarga = 0.0;
}

Vehiculo::~Vehiculo() {
}

void Vehiculo::SetActcarga(double actcarga) {
    this->actcarga = actcarga;
}

double Vehiculo::GetActcarga() const {
    return actcarga;
}

void Vehiculo::SetMaxcarga(double maxcarga) {
    this->maxcarga = maxcarga;
}

double Vehiculo::GetMaxcarga() const {
    return maxcarga;
}

void Vehiculo::SetPlaca(const char* placa) {
    if(this->placa!=nullptr) delete this->placa;
    this->placa = new char [strlen(placa)+1];
    strcpy(this->placa,placa);
}

void Vehiculo::GetPlaca(char*c) const {
    if(this->placa==nullptr) c[0]= 0;
    else strcpy(c,this->placa);
}

void Vehiculo::SetCliente(int cliente) {
    this->cliente = cliente;
}

int Vehiculo::GetCliente() const {
    return cliente;
}

void Vehiculo::lee(ifstream &arch){
    char c, buff[50];
    
    arch>>cliente>>c;
    arch.getline(buff,50,',');
    arch>>maxcarga>>c;
    
    SetPlaca(buff);
}

//*rec->unidad > *vehiculo
bool Vehiculo::operator >(const class Vehiculo &vel){
    return cliente > vel.GetCliente();
}

void Vehiculo::imprime(ofstream &arch){
    char buff[50];
    GetPlaca(buff);
    
    arch.precision(2);
    arch<<fixed;
    
    arch<<setw(10)<<" "<<left<<setw(20)<<"Codigo de cliente: "<<cliente<<endl;
    arch<<setw(10)<<" "<<left<<setw(20)<<"Placa: "<<buff<<endl;
    arch<<setw(10)<<" "<<left<<setw(20)<<"Carga maxima: "<<maxcarga<<endl;
    arch<<setw(10)<<" "<<left<<setw(20)<<"Carga actual: "<<actcarga<<endl;
    
}

void Vehiculo::imprimePedido(ofstream &arch){
    
    if(ped==nullptr){
        arch<<setw(10)<<" "<<left<<setw(20)<<"No hay pedidos para el cliente "<<endl;
    }
    else{
        arch<<setw(10)<<" "<<left<<setw(20)<<"Pedidos:"<<endl;
        class NPedido *rec=ped;
        while(rec){
            rec->imprimePedido(arch);
            rec = rec->sig;
        }
    }
}

// INSERTAR AL INICIO
void Vehiculo::push(class NPedido *dato){
    //es el nodo 
//    class NPedido *nuevo = new class NPedido;
//    nuevo = dato;
    if(espilavacia()){
        ped= dato;
    }
    else{
        dato->sig = ped;
        ped = dato;
    }
    actcarga+=dato->GetPeso();
    cout<<dato->peso<<endl;
}

double Vehiculo::pesoSobrante(){
    return maxcarga-actcarga;
}

bool Vehiculo::espilavacia(){
    if(ped==nullptr) return true;
    else return false;
}
