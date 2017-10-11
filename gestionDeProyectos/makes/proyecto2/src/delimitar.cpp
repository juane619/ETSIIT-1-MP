#include <iostream>
#include <cmath> // sqrt, M_PI
#include <fstream>
#include "rectangulo.h"
using namespace std;

Rectangulo BoundingBox(istream& is){
   Rectangulo bound;
   Punto p1;

   Leer(is,p1);

   bound.inf_izq = p1;
   bound.sup_der = p1;

   if(!is.eof() && !is.fail()){
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


int main(int argc, char* argv[])
{
   Rectangulo bound;

   if(argc==1)
      bound = BoundingBox(cin);
   else{
      ifstream f(argv[1]);

      if(!f){
         cerr << "Error: no se abre " << argv[1] << endl;
         return 1;
      }
      bound = BoundingBox(f);
   }

  cout << "El rectangulo que encierra a los puntos es: " ;
  Escribir(cout, bound);
  cout << endl;
}
