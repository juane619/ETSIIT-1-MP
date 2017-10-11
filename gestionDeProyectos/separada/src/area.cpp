#include <iostream>
#include <cmath> // sqrt, M_PI
#include "circulo.h"
using namespace std;

int main()
{
	Circulo c1;
	double area;

	cout << "Introduzca un circulo en formato radio-(x,y): ";
	c1= LeerCirculo();

	area = Area(c1);
	cout << "El area del circulo "; EscribirCirculo(c1);  cout << " es: " << area;
	cout<<endl;
}

/* Fin: circulomedio.cpp */
