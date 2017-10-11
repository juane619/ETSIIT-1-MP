#include <iostream>
#include <cmath> // sqrt, M_PI
#include <fstream>
#include "punto.h"
using namespace std;

double Longitud(istream& is){
   double longitud = 0;
   Punto p1, p2;

   //do{
      //cout << "LEctura del primer punto: ";
      Leer(is, p1);
   //}while(!Leer(is, p1));

   //do{
      //cout << "LEctura del segundo punto: ";
      Leer(is, p2);
   //}while(!Leer(is, p2));

   do{
      longitud += Distancia(p1,p2);
      p1 = p2;
   }while(Leer(is, p2));

   return longitud;
}

int main()
{
    double longitud;

    longitud = Longitud(cin);

    cout << "La longitud de los puntos introducidos es: " << longitud;

    cout << endl;
}

/* Fin: circulomedio.cpp */
