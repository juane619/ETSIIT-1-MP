#include <iostream>
#include <cstdlib> // rand, atoi
#include <ctime> // time
// FIXME 1: Crear módulo util_celdas y añadir la cabecera aquí
#include "util_celdas.h"
using namespace std;

// FIXME 2: Crear funciones BuscarMaximo y OrdenarSeleccion
// FIXME 3: Función Mezcla que mezcla dos listas ordenadas en una nueva, dejando las dos originales vacías
// FIXME 4: Función MergeSort para ordenar una lista


int main(int argc, char* argv[])
{
   
srand(time(0)); // Inicializamos generador de números
  
  int n=100, max=100;
      
      Celda* lista1= 0;
      Celda* lista2= 0; // Listas vacías

      for (int i=0; i<n; ++i) {
         // Añadimos un elemento al principio de lista1 y otro a lista2
         Add(lista1, Uniforme(1,max));
         Add(lista2, Uniforme(1,max));
      }
      
      cout << "Lista1: ";
      Listar(lista1);
      //cout << "Maximo lista 1:" << (*BuscarMaximo(lista1))->dato;
      cout << "Lista2: ";
      Listar(lista2);
      
      // FIXME 2: Llamar a ordenar las dos listas y listarlas ordenadas
     	//OrdenaSeleccion(lista1);
   	//OrdenaSeleccion(lista2);
      
     // cout << "Lista1 ordenada: ";
      //Listar(lista1);
  		//cout << "Lista2 ordenada por seleccion: ";
   	//Listar(lista2);
      
      // FIXME 4: Ordenar la primera lista con MergeSort
		lista1= Mergesort(lista1);
		cout << "Lista1 ordenada por mergesort: ";
      Listar(lista1);
      
      OrdenarEspecial(lista2);
		cout << "Lista2 ordenada especial: ";
      Listar(lista2);
  		
      // FIXME 3: Llamar a mezclar las dos listas y guardar el resultado en la lista1
      Mezcla(lista1, lista2);
		cout << "Lista mezcla: ";
		Listar(lista1);
      
      Liberar(lista1);
      Liberar(lista2);
   }  

