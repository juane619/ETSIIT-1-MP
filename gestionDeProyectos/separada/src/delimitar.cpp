#include <iostream>
#include <cmath> // sqrt, M_PI
#include "rectangulo.h"
using namespace std;

void Escribirr(const Rectangulo& r)
{
   cout << '(' << r.inf_izq.x << ',' << r.inf_izq.y << ')' << '-' << '(' << r.sup_der.x << ',' << r.sup_der.y << ')';
}

Rectangulo BoundingBox(istream& is){
   Rectangulo bound;
   Punto p1;

   Leer(is, p1);

   bound.inf_izq = p1;
   bound.sup_der = p1;

   if(!is.eof()){
      Punto p2;
      Leer(is, p2);

      do{
         if(p2.x >= p1.x){
            bound.sup_der.x = p2.x;
            if(p2.y < p1.y)
               bound.inf_izq.y = p2.y;
            else
               bound.sup_der.y = p2.y;
         }
         else{
            bound.inf_izq.x = p2.x;
            if(p2.y < p1.y)
               bound.inf_izq.y = p2.y;
            else
               bound.sup_der.y = p2.y;
         }

         p1 = p2;
      }while(Leer(is, p2));
   }
   return bound;
}



int main()
{
  Rectangulo bound;

  bound = BoundingBox(cin);

  cout << "El rectangulo que encierra a los puntos es: " ;
  Escribirr(bound);



  cout << endl;
}

/* Fin: circulomedio.cpp */
