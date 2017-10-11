#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <cstdlib> // rand, atoi
#include <ctime> // time
using namespace std;

struct Celda {
  int dato;
  Celda* sig;
};

// Genera un valor del intervalo [minimo,maximo]
int Uniforme(int minimo, int maximo);


// FIXME 1: Añadir un elemento a una lista. Se añade como primer elemento
void Add(Celda*& l, int e);


// FIXME 2: Liberar todas las celdas de una lista y dejarla a cero
void Liberar(Celda*& lista);


// FIXME 3: Listar los elementos de una lista entre llaves y separados por comas
void Listar(Celda* lista);


// FIXME 4: Crear función Size para calcular el número de elemento de la lista
int Size(Celda* lista);


// FIXME 5: Crear una función Buscar que devuelva la celda donde está un dato. Puntero nulo si no está.

Celda* BuscarCelda(Celda* lista, int v);

// FIXME 6: Crear una función BuscarPuntero que devuelve un puntero a puntero.
Celda** BuscarPuntero(Celda*& lista, int v);

// FIXME 7: Recibe un puntero a celda, la desengancha, y la devuelve como resultado
Celda* Descolgar(Celda**& cx);
    
void EliminarDato(Celda *&lista, int v);

//Buscar maximo
Celda** BuscarMaximo(Celda*& lista);

//Ordenar SELECCION
void OrdenaSeleccion(Celda*& lista);

//MEZCLA
//A�adir celda al final
void AddFinal(Celda*& lista, Celda* add, Celda*& final);

Celda* Mezcla(Celda*& l1, Celda*& l2);

//MERGESORT
Celda* Mergesort(Celda*& lista);

//ORDENA ESPECIAL
void OrdenarEspecial(Celda*& l);

#endif // UTIL_H
