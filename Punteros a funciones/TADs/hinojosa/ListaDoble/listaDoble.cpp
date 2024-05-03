//en otras listas era necesario crear funciones para recorrer la lista y posicionarnos u
//una ubicaicon anterior, en cambio aqui no
#include "listaDoble.h"

void construir( ListaD &Ld )
{
    // se crea la lista vacia
    Ld.cabeza = NULL;
    Ld.longitud = 0;
}

bool esListaVacia( ListaD Ld )
{
    return Ld.cabeza == NULL;
    // return Ld.longitud == 0;
}

Nodo* crearNodo( Nodo *a, Elemento e, Nodo *s )
{
    Nodo *p;
    p = new Nodo; // se crea un nodo y su direccion se almacena en p
    p->ant = a;
    p->elem = e;
    p->sig = s;
    return p; // devuelve la dirección donde se ha creado el nodo
}

int obtenerLongitud( ListaD Ld )
{
    return Ld.longitud;
}

void insertarComienzo( ListaD &Ld, Elemento e )
{
    Nodo *p, *q;
    p = crearNodo( NULL, e, Ld.cabeza );
    if ( !esListaVacia(Ld) )
    {
        q = Ld.cabeza;
        q->ant = p;
    }
    Ld.cabeza = p;
    Ld.longitud++;
}

void mostrar( ListaD Ld )
{
    Nodo *p;
    if ( esListaVacia(Ld) )
        cout << "La lista esta vacia" << endl;
    else
    {
        p = Ld.cabeza;
        while ( p != NULL )
        {
            cout << p->elem << " ";
            p = p->sig;
        }
        cout << endl;
    }
}

Nodo* ubicarUltimo( ListaD Ld )
{
    Nodo *pU;
    int i;
    if( esListaVacia(Ld) )
        return NULL;
    else
    {
        pU = Ld.cabeza;
        for(i=1; i<=Ld.longitud-1; i++)
            pU = pU->sig;
        return pU; // devuelve la direccion el ultimo nodo
    }
}

void mostrarReves( ListaD Ld )
{
    Nodo *p;
    int i;
    p = ubicarUltimo( Ld);
    if ( p == NULL ) //llegue al primer elemento
        cout << "La lista esta vacia" << endl;
    else
    {
        for(i=1;i<=Ld.longitud; i++)
        {
            cout << p->elem << " ";
            p = p->ant;
        }
        cout << endl;
    }
}

void insertarFinal( ListaD &Ld, Elemento e )
{
    Nodo *p, *pU;
    p = crearNodo( NULL , e , NULL);
    pU = ubicarUltimo( Ld );
    if ( pU != NULL )
    {
        pU->sig = p;
        p->ant = pU;
    }
    else
        Ld.cabeza = p;
    Ld.longitud++;
}

//busca un determinado valor
Nodo* ubicar( ListaD Ld, Elemento e )
{
    Nodo *p;
    int i;
    if ( esListaVacia(Ld) )
        return NULL;  
    else
    { //si la lista no esta vacia
        p = Ld.cabeza;
        for(i=1;i<=Ld.longitud;i++) //recorre todos los nodos. El for controla los elementos de la lista
            if ( p->elem == e )
                return p; //devuelve la direccion del nodo que lo encontró
            else
                p = p->sig; //sigue buscando en el siguiente nodo
        return NULL;        
    }
}

void eliminar( ListaD &Ld, Elemento e)
{
    Nodo *p, *q, *a;
    if ( esListaVacia(Ld) )
        cout << "No es posible eliminar en una lista vacia" << endl;
    else
    {
        p = ubicar( Ld, e );
        if ( p == NULL ) // el dato no esta
            cout << "No es posible eliminar un dato inexistente" << endl;
        else
        {   //cuando el dato sí está
            if ( p->ant == NULL ) // es el primer nodo
            {
                Ld.cabeza = p->sig;
                if ( p->sig != NULL )
                {
                    q = p->sig;
                    q->ant = NULL;
                }
            }
            else // no es el primer nodo
            {
                a = p->ant;
                if ( p->sig != NULL ) // no es el ultimo
                {
                    q = p->sig;
                    a->sig = p->sig;
                    q->ant = p->ant;
                }
                else // es el ultimo nodo
                    a->sig = NULL;
            }
            delete p;
            Ld.longitud--;
        }
    }
}

void destruir( ListaD &Ld )
{
    Nodo *p,*q;
    int i;
    if ( !esListaVacia( Ld ) )
    {
        p = Ld.cabeza;
        for( i=1; i<=Ld.longitud; i++)
        {
            q = p->sig;
            delete p;
            p = q;
        }
        Ld.cabeza = NULL;
        Ld.longitud = 0;
    }
}

//void insertarOrdenado(ListaD& Ld, Elemento e) {
//    Nodo* nuevoNodo = crearNodo(nullptr, e, nullptr);
//
//    if (esListaVacia(Ld) || e < Ld.cabeza->elem) {
//        nuevoNodo->sig = Ld.cabeza;
//        Ld.cabeza = nuevoNodo;
//        if (nuevoNodo->sig) {
//            nuevoNodo->sig->ant = nuevoNodo;
//        }
//        Ld.longitud++;
//        return;
//    }
//
//    Nodo* actual = Ld.cabeza;
//
//    while (actual->sig && actual->sig->elem <= e) {
//        actual = actual->sig;
//    }
//
//    nuevoNodo->sig = actual->sig;
//    actual->sig = nuevoNodo;
//
//    if (nuevoNodo->sig) {
//        nuevoNodo->sig->ant = nuevoNodo;
//    }
//
//    Ld.longitud++;
//}

void insertarOrdenado(ListaD &Ld, int e) {
    Nodo* nuevoNodo = crearNodo(nullptr, e, nullptr);

    // Si la lista está vacía o el valor es menor que el primer nodo
    if (esListaVacia(Ld) || e < Ld.cabeza->elem) {
        nuevoNodo->sig = Ld.cabeza;
        if (!esListaVacia(Ld)) {
            Ld.cabeza->ant = nuevoNodo;
        }
        Ld.cabeza = nuevoNodo;
        Ld.longitud++;
        return;
    }

    Nodo* actual = Ld.cabeza;

    // Avanzar hasta encontrar el lugar adecuado para insertar el valor
    while (actual->sig != nullptr && actual->sig->elem < e) {
        actual = actual->sig;
    }

    nuevoNodo->sig = actual->sig;
    if (actual->sig != nullptr) {
        actual->sig->ant = nuevoNodo;
    }
    actual->sig = nuevoNodo;
    nuevoNodo->ant = actual;
    Ld.longitud++;
}