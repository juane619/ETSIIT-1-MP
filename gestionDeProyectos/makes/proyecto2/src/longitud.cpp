#include <iostream>
#include <cmath> // sqrt, M_PI
#include <fstream>
#include "punto.h"
using namespace std;

double Longitud(istream& is){
   double longitud = 0;
   Punto p1, p2;

   do{
      //cout << "LEctura del primer punto: ";
   }while(!Leer(is, p1));

   do{
      //cout << "LEctura del segundo punto: ";
   }while(!Leer(is, p2));

   do{
      longitud += Distancia(p1,p2);
      p1 = p2;
   }while(Leer(is, p2));

   return longitud;
}

int main(int argc, char* argv[])
{
    double longitud;

   if(argc==1)
      longitud = Longitud(cin);
   else{
      ifstream f(argv[1]);

      if(!f){
         cerr << "Error: no se abre " << argv[1] << endl;
         return 1;
      }

      longitud = Longitud(f);

      cout << "La longitud de los puntos introducidos es: " << longitud;
      cout << endl;
   }
}

