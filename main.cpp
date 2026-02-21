#include <iostream>
#include <fstream>
#include "polinomio.h"
#include "operadores.h"

using namespace std;

void leerPolinomio(istream& archivo, tPolinomio& p, int num);
void sumarPolin(const tPolinomio& p1, const tPolinomio& p2);
void multiplicarPolin(const tPolinomio& p1, const tPolinomio& p2);

int main() {

	ifstream archivo1;
	ifstream archivo2;
	archivo1.open("polinomios1.txt");
	archivo2.open("polinomios3.txt");
	tPolinomio p1;
	tPolinomio p2;
	p1.inicia();
	p2.inicia();
	leerPolinomio(archivo1, p1, 1);
	leerPolinomio(archivo2, p2, 3);
	sumarPolin(p1, p2);
	multiplicarPolin(p1, p2);

	return 0;
}

void leerPolinomio(istream& archivo, tPolinomio& p, int num) {

	cout << "Cargando polinomio numero " << num << "...\n";

	int cont;
	archivo >> cont;
	tMonomio aux;
	bool carga = true;

	for (int i = 0; i < cont; i++) { // opcion de implementar un while para que salga del bucle en caso de error

		archivo >> aux;	
		if (not p.insertar(aux)) {

			// cout << "Bucle " << i << endl;
			carga = false;
		}
	}

	if (carga) {

		cout << "Polinomio cargado correctamente:" << endl;
		cout << p;
	}
	else {

		cout << "Error de carga en el polinomio." << endl;
		p.inicia();
	}

}
void sumarPolin(const tPolinomio& p1, const tPolinomio& p2) {

	if (p1.dameElem(0).esMonomioNulo() || p2.dameElem(0).esMonomioNulo()) {

		cout << "Error, uno de los dos polinomios no han sido cargados correctamente\n";
	}
	else {

		tPolinomio aux;
		aux = p1 + p2;
		cout << "La suma de los polinomios es: " << aux;
	}
}
void multiplicarPolin(const tPolinomio& p1, const tPolinomio& p2) {

	if (p1.dameElem(0).esMonomioNulo() || p2.dameElem(0).esMonomioNulo()) {

		cout << "Error, uno de los dos polinomios no han sido cargados correctamente\n";
	}
	else {

		tPolinomio aux;
		aux = p1 * p2;
		cout << "El producto de los polinomios es: " << aux;
	}
}