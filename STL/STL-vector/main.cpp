
/* 
 * File:   main.cpp
 * Author: BlueCod (mell1)
 *
 * Created on 19 de junio de 2024, 12:26
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm> 
using namespace std;
/*
 * 
 */
int main(int argc, char** argv) {
    //  tipoDato nombre
    //vector<int> vInt;
    vector<int> vInt = {23,55,12,83,112,53,99}; //al definirlo asi, asigna capIni = 5
    //vector<int> vInt(10); // crea 10 elem y cap, y asigma 0 a todos
    //vector<int> vInt(10,33); // inicializa 10 elementos en 33, cap=10
    
//    cout <<"Numero de elementos: "<<vInt.size()<<endl; //size -> cant elem
//    cout <<"Capacidad inicial  : "<<vInt.capacity()<<endl<<endl;
//    
    vInt.push_back(23); //asigna un elemento -> 5 x2 -> capFinal = 10
    vInt.push_back(56);
    vInt.push_back(20);
    vInt.push_back(83);
    vInt.push_back(112); //aca se llena cap=10
    vInt.push_back(1111); // capFinal = 10 x 2 = 20
    cout <<"Numero de elementos: "<<vInt.size()<<endl;
    cout <<"Capacidad          : "<<vInt.capacity()<<endl<<endl;
    
    //IMPRESION, se tiene la sobrecarga de []
    cout<<"Elementos del vector:";
    for(int i=0; i<vInt.size();i++){
        cout<<setw(5)<<vInt[i];
    }
    cout<<endl<<endl; 
    
//    vInt.shrink_to_fit(); //elimina la capacidad extra 
//    cout <<"Numero de elementos: "<<vInt.size()<<endl;
//    cout <<"Capacidad Final    : "<<vInt.capacity()<<endl<<endl;
//    
    
    int dato;
    dato = vInt.front();
    cout<< "Dato Front = "<<dato<<endl; // no lo elimina del vector
    dato = vInt.back();
    cout<< "Dato Back = "<<dato<<endl<<endl; // no lo elimina del vector
    
    //*********************** ITERADORES *****************************
    //                  apunta al inicio            apunta al final
    cout<<"Elementos con iterador:     ";
    for(vector<int>::iterator it=vInt.begin(); it!= vInt.end(); it++){
        cout <<setw(5)<<*it;
    }
    cout<<endl<<endl;
    
    vector<int>::iterator itt = vInt.begin(); //apunta al inicio
    itt+=3;//movemos 3 posiciones
    vInt.erase(itt);
    cout<<"Borra elem en la posicion 3:";
    for(vector<int>::iterator it=vInt.begin(); it!= vInt.end(); it++){
        cout <<setw(5)<<*it;
    }
    cout<<endl<<endl;
    
    vInt.insert(itt,777);
    cout<<"Inserta elem en la posicion 3:";
    for(vector<int>::iterator it=vInt.begin(); it!= vInt.end(); it++){
        cout <<setw(5)<<*it;
    }
    cout<<endl<<endl;
    
    sort(vInt.begin(), vInt.end());
    cout<<"Vector ordenado              :";
    for(vector<int>::iterator it=vInt.begin(); it!= vInt.end(); it++){
        cout <<setw(5)<<*it;
    }
    cout<<endl<<endl;
    
    
    
    
    return 0;
}

