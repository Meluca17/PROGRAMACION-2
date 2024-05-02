/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Utils.h"
#include "arreglos_genericos.h"
using namespace std;

char *leeCadDelim(ifstream &arch, char delim){
    char *str, buff[200];
    arch.getline(buff,200,delim);
    str = new char[strlen(buff)+1]{};
    strcpy(str,buff);
    
    return str;
}

//enum Registro{COD,NOMB,ROL,CAT,PUNT};
void *leeRegheroes(ifstream &arch){
    void **registro;
    int *cod = new int, codigo;
    char *nomb, *rol,c, *categoria;
    double *puntaje = new double;
    
    arch>>*cod;
    if(arch.eof()) return nullptr;
    arch.get();
    nomb = leeCadDelim(arch,',');
    rol = leeCadDelim(arch,',');
    categoria = leeCadDelim(arch,',');
    arch>>*puntaje;
   //cout <<categoria<<endl;
    
    registro = new void*[5]{};
    registro[COD] = cod;
    registro[NOMB] = nomb;
    registro[ROL] = rol;
    registro[CAT] = categoria;
    registro[PUNT] = puntaje;
    
    return registro;
}

void  llenar_arreglo_heroes(void *&arreglo_heroes,int &cantidad_total_heroes,const char *filename){
    ifstream arch(filename,ios::in);
    if(not arch.is_open()){
        cout <<"no se abrio el archivo"<<endl;
        exit(1);
    }
    
    void *registro, *buff[300];
    cantidad_total_heroes = 0;
    while(true){
        registro = leeRegheroes(arch);
        if(registro ==nullptr) break;
        
        buff[cantidad_total_heroes] = registro;
        cantidad_total_heroes++;
    }
    
    void **buffExacto = new void *[cantidad_total_heroes+1]{};
    for(int i=0;i<cantidad_total_heroes;i++){
        buffExacto[i]=buff[i]; 
//        void **campos = (void **)buffExacto[i];
//        char *cat = (char *)campos[CAT];
//        cout <<cat<<endl;
    }
    buffExacto[cantidad_total_heroes] = nullptr;
    arreglo_heroes = buffExacto;
}

//enum Registro{COD,NOMB,ROL,CAT,PUNT};
//ALFABETICAMENTE (A-Z) -> nomb
// DESCENDENTE PUNTAJE
int cmp_multicriterio_void(const void *a, const void *b){
    void **ai = (void **)a, **bi = (void **)b;
    
    void **regA = (void **)ai[0];
    void **regB = (void **)bi[0];
    
    double *puntajeA = (double *)regA[PUNT];
    char *nombA = (char *)regA[NOMB];
    
    double *puntajeB = (double *)regB[PUNT];
    char *nombB = (char *)regB[NOMB];
    
    //COMPARAMOS
    if(strcmp(nombA,nombB)==0){
        return *puntajeA - *puntajeB;
    }else{
        return strcmp(nombA,nombB);
    }
}