/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Flota.cpp
 * Author: alulab14
 * 
 * Created on 17 de noviembre de 2023, 08:03 AM
 */

#include "Flota.h"

//Flota::Flota() {
//}
//
//Flota::Flota(const Flota& orig) {
//}
//
//Flota::~Flota() {
//}

void Flota::cargaflota() {
    ifstream arch ("Vehiculos.csv",ios::in);
    if (not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo vehículos"<<endl;
        exit(1);
    }
    while (true){
        class NVehiculo vehiculo;
        vehiculo.leeDatos (arch);
        if (arch.eof()) break;
        vflota.push_back(vehiculo);
    }
    sort(vflota.begin(), vflota.end());
}

void Flota::cargapedidos() {
    ifstream arch ("Pedidos3.csv",ios::in);
    if (not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo vehículos"<<endl;
        exit(1);
    }
    int cli, pos;
    while (true){
        arch>> cli;
        if (arch.eof()) break;
        arch.get();
        pos = buscarCliente(cli);
        if (pos != -1){
            class NPedido ped;
            vflota[pos].leePedido(arch, ped);
        }
    }
}

int Flota::buscarCliente(int cli) {
    for (int i=0; i< vflota.size();i++)
        if (vflota[i].GetCliente() == cli) return i;
    return -1;
}

void Flota::muestracarga() {
    ofstream arch ("ReporteFlota.txt",ios::out);
    if (not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo vehículos"<<endl;
        exit(1);
    }
    arch << setprecision(2)<<fixed;
    arch << setw(15)<<""<<"REPORTE DE FLOTA"<<endl;
    imprimeLinea(arch);
    for (NVehiculo vehiculo: vflota)
        vehiculo.imprimeDatos(arch);
}

void Flota::imprimeLinea(ofstream &arch) {
    for (int i=0;i<40;i++) arch << '=';
    arch << endl;
}

