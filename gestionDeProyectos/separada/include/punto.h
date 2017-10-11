#ifndef _PUNTO_H
#define _PUNTO_H
using namespace std;

struct Punto {
    double x,y;
};

Punto LeerPunto();

bool Leer(istream& is, Punto& p);

void EscribirPunto (const Punto& p);

bool Escribir(ostream& os, const Punto& p);

void InicializarPunto (Punto &p, double cx, double cy);

double GetX (const Punto& p);

double GetY (const Punto& p);

double Distancia (const Punto& p1, const Punto& p2);

Punto PuntoMedio (const Punto& p1, const Punto& p2);

#endif
