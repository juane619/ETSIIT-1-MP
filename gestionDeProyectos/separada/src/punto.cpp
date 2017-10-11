#include <cmath>
#include <iostream>
//#include <fstream>
#include "punto.h"
using namespace std;

// FIXME: Lee un punto en el formato (x,y), incluyendo la lectura de '(' ',' y ')'
Punto LeerPunto()
{
   Punto punto;

	cin.ignore();
	cin >> punto.x;
	cin.ignore();
	cin >> punto.y;
	cin.ignore();

   return punto;
}

bool Leer(istream& is, Punto& p){
   char c;
   is >> c;
   if(c != '(')
      is.clear(ios::failbit);
   else{
      is >> p.x >> c;
      if(c!=',')
         is.clear(ios::failbit);
      else{
         is >> p.y >> c;
         if(c!=')')
            is.clear(ios::failbit);
      }
   }
   return !is.fail();
}

// FIXME: Escribe un punto en formato (x,y), incluyendo la escritura de '(' ',' y ')'
void EscribirPunto (const Punto& p)
{
   cout << "(" << p.x << "," << p.y << ")";
}

bool Escribir(ostream& os, const Punto& p){
   os << '(' << p.x << ',' << p.y << ')';
   return !os.fail();
}

// FIXME: Inicializa un punto con dos valores cx cy
void InicializarPunto (Punto &p, double cx, double cy)
{
   p.x = cx;
   p.y = cy;
}

// FIXME: Devuelve la coordenada X del punto p
double GetX (const Punto& p)
{
   return p.x;
}

// FIXME: Devuelve la coordenada Y del punto p
double GetY (const Punto& p)
{
   return p.y;
}

// FIXME: Devuelve la distancia euclídea entre p1 y p2
double Distancia (const Punto& p1, const Punto& p2)
{
   return sqrt((p2.x - p1.x)*(p2.x - p1.x)+(p2.y-p1.y)*(p2.y-p1.y));
}

// FIXME: Devuelve el punto que está entre p1 y p2 (más cercano a igual distancia de p1 y p2)
Punto PuntoMedio (const Punto& p1, const Punto& p2)
{
   Punto punto;

   double x = (p1.x+p2.x)/2;
   double y = (p1.y+p2.y)/2;

   InicializarPunto(punto, x, y);

   return punto;
}
