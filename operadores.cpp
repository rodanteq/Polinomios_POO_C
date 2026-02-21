#include "operadores.h"

istream& operator>>(istream& input, tMonomio& mon) {

	int c;
	int g;
	input >> c >> g;

	mon.inicia(c, g);

	return input;
}
ostream& operator<<(ostream& out, const tPolinomio& pol) { // suponemos que el polinomio esta formado por al menos un monomio

	out << pol.dameElem(0).dameCoeficiente() << 'x' << pol.dameElem(0).dameGrado();

	for (int i = 1; i < pol.dameLongitud() - 1; i++) {

		// cout << "Ciclo " << i << endl;
		out << " + " << pol.dameElem(i).dameCoeficiente() << 'x' << pol.dameElem(i).dameGrado();
	}
	int i = pol.dameLongitud() - 1; // le damos el valor con el que ha acabado el bucle anterior

	// cout << "Valor de i: " << i << endl;

	if (pol.dameLongitud() > 1) {

		// cout << "Entrada\n";
		if (pol.dameElem(i).dameGrado() == 0) {

			out << " + " << pol.dameElem(i).dameCoeficiente();
		}
		else {

			out << " + " << pol.dameElem(i).dameCoeficiente() << 'x' << pol.dameElem(i).dameGrado();
		}
	}

	cout << endl;

	return out;
}