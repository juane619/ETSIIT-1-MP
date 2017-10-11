#ifndef _RECTANGULO_H
#define _RECTANGULO_H

#include "punto.h"

using namespace std;

struct Rectangulo {
    Punto inf_izq;
    Punto sup_der;
};

bool Leer(istream& is, Rectangulo& r);

bool Escribir(const Rectangulo& r);

bool Escribir(ostream& os, const Rectangulo& r);

void InicializarRectangulo (Rectangulo& r, const Punto& p1, const Punto& p2);

Punto InferiorIzquierda (const Rectangulo& r);

Punto SuperiorDerecha (const Rectangulo& r);

double Area(const Rectangulo& r);

bool Interior (const Punto& p, const Rectangulo& r);

#endif
