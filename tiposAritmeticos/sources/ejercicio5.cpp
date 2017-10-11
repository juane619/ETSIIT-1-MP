#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	cout << setw(10) << left  << "Nombre" << setw(12) << left  << "Apellidos" << setw(4) << right  << "Edad" << setw(7) << right  << "Estado" << endl;
	cout << setw(10) << left  << "Javier" << setw(12) << left  << "Moreno" << setw(4) << right  << 20 << setw(7) << right  << "S" << endl;
	cout << setw(10) << left  << "Juan" << setw(12) << left  << "Espejo" << setw(4) << right  << 8 << setw(7) << right  << "S" << endl;
	cout << setw(10) << left  << "Antonio" << setw(12) << left  << "Caballero" << setw(4) << right  << 53 << setw(7) << right  << "C" << endl;
	cout << setw(10) << left  << "Jose" << setw(12) << left  << "Cano" << setw(4) << right  << 27 << setw(7) << right  << "C" << endl;
	cout << setw(10) << left  << endl;
	cout << setw(10) << left  << 123.456 << 26.467872 << 876.3876 << endl;
	cout << setw(10) << left  << 17.26734 << 0.22 << 18972.1 << endl;
	cout << setw(10) << left  << 456.5 << 2897.0 << 2832.3 << endl;
}
/*
int main()
{
int x;
cout << "Dame un número: ";
cin >> x;
cout << "Decimal : " << dec << x << endl;
cout << "Octal : " << oct << x << endl;
cout << "Hexadecimal: " << hex << x << endl;
cout << dec;
cout << "8 posiciones : " << setw(8) << x << endl;
cout << "8 posiciones (just dcha): " << setw(8) << right << x << endl;
cout << "8 posiciones (just izda): " << setw(8) << left << x << endl;
double y;
cout << "Dame otro número: ";
cin >> y;
cout << "Con 2 decimales: " << fixed << setprecision(2) << y << endl;
cout << "Con 6 decimales: " << fixed << setprecision(6) << y << endl;
}*/
