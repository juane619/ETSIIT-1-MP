/**
  * @file central.cpp
  * @brief Calcula círculo con centro en medio de dos círculos y radio la mitad de la distancia
  * @author Agarrido
  * @warning Módulo no definitivo (creado para ser modificado)
  *
  * Un ejemplo de ejecución es:
  *   Introduzca un circulo en formato radio-(x,y): 3-(0,0)
  *   Introduzca otro circulo: 4-(5,0)
  *   El círculo que pasa por los dos centros es: 2.5-(2.5,0)
  */

#include <iostream>
#include <cmath> // sqrt, M_PI
#include "circulo.h"
using namespace std;

int main()
{
  Circulo c1,c2, res;

   do{
      do{
         cout << "Introduzca un circulo en formato radio-(x,y): ";
      }while(!Leer(cin, c1));

      do{
         cout << "Introduzca otro circulo en formato radio-(x,y): ";
      }while(!Leer(cin, c2));
   }while (Distancia(Centro(c1),Centro(c2))==0);

  InicializarCirculo(res,PuntoMedio(Centro(c1),Centro(c2)),Distancia(Centro(c1),Centro(c2))/2);

  cout << "El círculo que pasa por los dos centros es: "; Escribir(cout, res);
  cout<<endl;

}

/* Fin: circulomedio.cpp */
