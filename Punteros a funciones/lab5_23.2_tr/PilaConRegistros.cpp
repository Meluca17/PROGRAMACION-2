/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include "Utils.h"
#include "PilaConRegistros.h"
using namespace std;
//enum Registro{COD,DNI,CANT,PESO};

char *leeCadDelim(ifstream &arch,char delim){
    char *str, buff[100];
    arch.getline(buff,100,delim);
    str = new char[strlen(buff)+1]{};
    strcpy(str,buff);
    return str;
}

void* leeregistro(ifstream &arch){
    char *cod,c;
    int *dni = new int, *cant = new int;
    double *peso= new double;
    
    cod = leeCadDelim(arch,',');
    if(arch.eof()) return nullptr;
    arch>>*dni;
    arch.get();
    arch>>*cant>>c>>*peso;
    arch.get(); //salto de linea
    
    void **registro = new void *[4]{};
    registro[COD] = cod;
    registro[DNI] = dni;
    registro[CANT] = cant;
    registro[PESO] = peso;
    
    return registro;
}

    
double calcularregistro(void *reg){
    //tenemos que sacar el peso del registro
    
    //ACCEDO A CAMPOS
    void **camposReg = (void **)reg;
    double *peso = (double *)camposReg[PESO];
    return *peso;
}


int cmpregistro(const void *a, const void *b){
    void **ai = (void **)a, **bi=(void **)b;
     //accedemos a los campos
     void **regA = (void **)(ai[0]), **regB=(void **)(*bi);
     
     double *pesoA = (double *)regA[PES], *pesoB = (double *)regB[PES];
     
     return *pesoB - *pesoA;
}

void imprimeregistro(void *dato, ofstream &arch){
    void **camposdat =(void **)dato;
    char *cod = (char *)camposdat[COD];
    int *cant = (int *)camposdat[CANT];
    double *peso = (double *)camposdat[PESO];
    
    arch<<right<<setw(20)<<cod<<setw(10)<<*cant<<setw(10)<<*peso<<endl;
}
