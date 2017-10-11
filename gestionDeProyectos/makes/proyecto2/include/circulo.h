#ifndef _CIRCULO_H
#define _CIRCULO_H

#include "punto.h"

struct Circulo {
    Punto centro;
    double radio;
};

Circulo LeerCirculo();

bool Leer(istream& is, Circulo& c);

void EscribirCirculo(const Circulo& c);

bool Escribir(ostream& os, const Circulo& c);

void InicializarCirculo(Circulo& c, const Punto& centro, double radio);

Punto Centro (const Circulo& c);

double Radio (const Circulo& c);

double Area (const Circulo& c);

bool Interior (const Punto& p, const Circulo& c);

double Distancia (const Circulo& c1, const Circulo& c2);

#endif
