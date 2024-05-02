/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include "Utils.h"
#include "ListaConEnteros.h"
#include "FlotaGenerica.h"
using namespace std;
//enum Pila{CIM, PES};
//enum Nodo{SIG,DAT};

// UNA FLOTA ES UN ARREGLO DE VOIDS
//CADA VOID APUNTA A UNA PILA
// UNA PILA REPRESENTA UN CAMION
//CADA NODO ES UN PEDIDO 
void cargacamiones(void *&flota,int numcamiones,int pesomaximo,void *(*leenumero)(ifstream &),
        double (*calculanumero)(void *),const char *filename){
    ifstream arch(filename, ios::in);
    
    //2. LECTURA DE CAMIONES
    cargaCamExacto(flota,numcamiones);
    
    void *dato, **camion;
    void **camionActual = (void **)flota; //al incio de la flota
    int numCam = 1,posCamion =0;
    double*pesoAcumulado;
    double peso,pesoTotal;
    while(true){
        dato = leenumero(arch);
        if(dato ==nullptr) break;
        
        peso = calculanumero(dato);
        camion = (void **)camionActual[posCamion];
        pesoAcumulado = (double *)camion[PES]; 
        pesoTotal =  *pesoAcumulado + peso; //peso total 
                
        if(pesoTotal>=pesomaximo){ //se incrementa la posicion en el arr de pila
            posCamion++;
            if(posCamion>=numcamiones) break;
        }
        //cout <<posCamion << " "<<peso<<endl;
        push(camionActual[posCamion],dato,peso);
    }
}
//enum Pila{CIM, PES};
//enum Nodo{SIG,DAT};
void push(void *&camionActual,void *dato,double peso){
    void **camion= (void **)camionActual;
    //creamos los noditos que seran los paquetes :))
    void **nuevoNodo = new void *[2]{};
    
    //INSERTAMOS AL INICIO
    nuevoNodo[DAT] = dato;
    nuevoNodo[SIG] = camion[CIM];
    camion[CIM] = nuevoNodo;
    
    //ACUMULAMOS EL PESO DE LA PILA (CAMION)
    double *pesoAcumulado = (double *)camion[PES];
    (*pesoAcumulado) += peso;
}
void cargaCamExacto(void *&flota,int numcamiones){
    void **flotaExacta = new void *[numcamiones]{};
    for(int i=0;i<numcamiones;i++){
        cargaFlotaExacta(flotaExacta[i]);
    }
    flota = flotaExacta;
}

void cargaFlotaExacta(void *&camion){
    //ACCEDER A LOS CAMPOS DEL ARREGLO FLOTA Y LOS INICIALIZA :))
    void **pilaCamion = new void *[2]{};
    
    double *pesoIni = new double;
    *pesoIni = 0;
    pilaCamion[CIM] = nullptr;
    pilaCamion[PES] = pesoIni;
    
    camion=pilaCamion;
}

void muestracamiones(void *flota,int numcamiones,void (*imprimenumero)(void *, ofstream&arch), const char *filename){
    ofstream arch(filename,ios::out);
    void **arrFlota = (void **)flota;
    
    arch.precision(2);
    arch<<fixed;
    for(int i=0; i<numcamiones;i++){
        arch<<"Camion "<<i+1<<setw(10)<<" ";
        imprimeCamiones(arrFlota[i],arch,imprimenumero);
    }
}

void imprimeCamiones(void *camion,ofstream &arch,void (*imprimenumero)(void *, ofstream&arch)){
    void **pilaCamion = (void **)camion;
    double *pesoCam = (double *)pilaCamion[PES];
    
    arch<<"Peso: "<<setw(8)<<(double)*pesoCam<<endl;
    if(pilaVacia(pilaCamion[CIM])){
        cout<<" El camion esta vacio"<<endl;
    }else{
        void **aux = (void**)pilaCamion[CIM];
        while(aux){
            imprimenumero(aux[DAT],arch);
             aux = (void **)aux[SIG];
        }
    }
}

bool pilaVacia(void *cima){
    if(cima == nullptr) return true;
    else return false;
}