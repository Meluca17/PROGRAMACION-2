#include <iostream>
#include "listaDoble.h"

using namespace std;

int main()
{
    ListaD L1;
    
    construir( L1);
    destruir( L1);
    construir( L1);
    //mostrar( L1);
    //mostrarReves( L1);
    insertarComienzo( L1, 1);
    //mostrar( L1);
    //mostrarReves( L1);
    insertarFinal( L1, 20);
    //mostrar( L1);
    //mostrarReves( L1);
    insertarFinal( L1, 40);
    //mostrar( L1);
    //mostrarReves( L1);
    insertarFinal( L1, 50);
    //mostrar( L1);
    //mostrarReves( L1);
    insertarFinal(L1, 60);
    mostrar( L1);
    //mostrarReves( L1);
    
    cout <<"ola"<<endl;
    insertarOrdenado(L1, 88);
    insertarOrdenado(L1, 22);
    mostrar( L1);
    
//    cout << ubicar(L1,45) << endl;
//    cout << ubicar(L1,15) << endl;
    
//    eliminar( L1, 60);
//    
//    eliminar(L1, 45);
//    mostrar(L1);
//    mostrarReves(L1);
//    
//    eliminar( L1, 99);
//    mostrar(L1);
//    mostrarReves(L1);
//    
//    eliminar( L1, 81);
//    mostrar(L1);
//    mostrarReves(L1);
//
//    destruir( L1);
//    mostrar(L1);
//    mostrarReves(L1);

    return 0;
}
