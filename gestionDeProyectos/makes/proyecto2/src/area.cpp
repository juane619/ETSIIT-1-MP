#include <iostream>
#include <cmath> // sqrt, M_PI
#include "circulo.h"
using namespace std;

int main()
{
	Circulo c1;
	double area;

   do{
      cout << "Introduzca un circulo en formato radio-(x,y): ";
   }while(!Leer(cin, c1));


	area = Area(c1);

	cout << "El area del circulo "; Escribir(cout, c1); cout << " es: " << area << endl;
}

