#include <iostream>
#include <cmath>
#include <circulo.h>
using namespace std;

// FIXME: Lee círculo en formato radio-centro, incluyendo '-' y leyendo "centro" con LeerPunto
Circulo LeerCirculo()
{
   Circulo circulo;
   cin >> circulo.radio;
   cin.ignore();
   circulo.centro = LeerPunto();

   return circulo;
}

bool Leer(istream& is, Circulo& c){
   char car;

   is >> c.radio >> car;
   if(car != '-')
      is.clear(ios::failbit);
   else{
      if(!Leer(is, c.centro))
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
void EscribirCirculo(const Circulo& c)
{
   cout << c.radio << "-(" << c.centro.x << "," << c.centro.y << ")";
}

bool Escribir(ostream& os, const Circulo& c){
   os << c.radio << '-'; Escribir(os, c.centro);
   return !os.fail();
}

// FIXME: Inicializa circulo c con centro y radio
void InicializarCirculo (Circulo& c, const Punto& centro, double radio)
{
   c.radio = radio;
   c.centro = centro;
}

// FIXME: Devuelve del centro de c
Punto Centro (const Circulo& c)
{
   return c.centro;
}

// FIXME: Devuelve el radio de c
double Radio (const Circulo& c)
{
   return c.radio;
}

// FIXME: Devuelve el área del círculo c
double Area (const Circulo& c)
{
   return c.radio * c.radio * M_PI;
}

// FIXME: Devuelve si p está en el interior del círculo c (distancia al centro menor que el radio)
bool Interior (const Punto& p, const Circulo& c)
{
   return c.radio >= Distancia(p, Centro(c));
}

// FIXME: Devuelve la distancia de c1 a c2 (distancia entre los centros restándole los radios)
double Distancia (const Circulo& c1, const Circulo& c2)
{
   return Distancia(Centro(c1), Centro(c2)) - Radio(c1) - Radio(c2);
}
