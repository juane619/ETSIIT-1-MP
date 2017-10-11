#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;


int main()
{
	char frase;
	int i = 0;
	frase = cin.get();
	
	while(frase != 'z'){
		
		cout << frase << "";
		frase = cin.get();
		i++;
	}
}
