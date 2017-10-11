#include <iostream>
#include <cmath>
#include <fstream>
#include "rectangulo.h"

using namespace std;

// FIXME: Lee círculo en formato radio-centro, incluyendo '-' y leyendo "centro" con LeerPunto
bool Leer(istream& is, Rectangulo& r)
{
   char c;

   if(!Leer(is, r.inf_izq))
      is.clear(ios::failbit);
   else{
      is >> c;

      if(c != '-')
         is.clear(ios::failbit);
   }

   if(is.fail()){
      is.clear();
      is.ignore(1024, '\n');
      return 0;
   }
   else
      return 1;
}

// FIXME: Escribe círculo en formato radio-centro,  incluyendo '-' y escribiendo "centro" con EscribirPunto
void EscribirRectangulo(const Rectangulo& r)
{
   cout << '(' << r.inf_izq.x << ',' << r.inf_izq.y << ')' << '-' << '(' << r.sup_der.x << ',' << r.sup_der.y << ')';
}

bool Escribir(ostream& os, const Rectangulo& r){
   Escribir(os, r.inf_izq); os << '-'; Escribir(os, r.sup_der);
   return !os.fail();
}

// FIXME: Inicializa circulo c con centro y radio
void InicializarRectangulo (Rectangulo& r, const Punto& p1, const Punto& p2)
{
   r.inf_izq = p1;
   r.sup_der = p2;
}

Punto InferiorIzquierda (const Rectangulo& r){
   return r.inf_izq;
}

Punto SuperiorDerecha (const Rectangulo& r){
   return r.sup_der;
}

// FIXME: Devuelve el área del círculo c
double Area (const Rectangulo& r)
{
   Punto p_base, p_altura;
   p_base.x = r.sup_der.x;
   p_base.y = r.inf_izq.y;
   p_altura.x = r.inf_izq.x;
   p_altura.y = r.sup_der.y;

   double long_base = Distancia(r.inf_izq, p_base);
   double long_altura = Distancia(r.inf_izq, p_altura);

   return long_base * long_altura;
}

// FIXME: Devuelve si p está en el interior del círculo c (distancia al centro menor que el radio)
bool Interior (const Punto& p, const Rectangulo& r)
{
   return (p.x >= r.inf_izq.x && p.x <= r.sup_der.x) && (p.y >= r.inf_izq.y && p.y <= r.sup_der.y);
}

