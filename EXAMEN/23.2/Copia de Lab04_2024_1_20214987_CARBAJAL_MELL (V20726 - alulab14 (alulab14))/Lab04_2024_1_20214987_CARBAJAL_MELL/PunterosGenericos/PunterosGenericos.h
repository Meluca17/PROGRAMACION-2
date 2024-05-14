/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PunterosGenericos.h
 * Author: MELL ALESSANDRA CARBAJAL ROMAN 20214987
 *
 * Created on 26 de abril de 2024, 08:07 AM
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H
using namespace std; 

void cargaclientes(void *&clientes);
void *leeRegCli(ifstream &arch);
char *leeCadDelim(ifstream &arch,char delim); 
//preg2
void *leeRegLib(ifstream &arch);
void creareserva(void *&reserva);
//preg3
void cargareserva(void *clientes,void *&reserva); 
int buscarCliente(int dniLeid,void *clientes); 
int buscarLibro(char * codLibroLeid,void *reserva); 

void agregaPedDeCliente(void *&reservaLibro,void *cliente,int &cantPedPorLib,
                       int dniLeid); 
void agregaUnPed(void *pedidosReserLib,int cantPedPorLib,int dniLeid,char *nombreNuevo); 
#endif /* PUNTEROSGENERICOS_H */

