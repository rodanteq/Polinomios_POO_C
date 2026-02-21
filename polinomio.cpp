#include "polinomio.h"

// #include <iostream>

tPolinomio::tPolinomio() : cont(0) {}
void tPolinomio::inicia() {

	monomios[0].inicia(0, 0);
	cont = 0;
}
bool tPolinomio::insertar(const tMonomio& m) {

	if ((cont != 0 && monomios[cont - 1].dameGrado() <= m.dameGrado())) {
		
		// cout << "Error\n";
		// cout << "Grado anterior: " << monomios[cont - 1].dameGrado() << "\nNuevo grado: " << m.dameGrado() << endl;
		return false;
	}
	else {

		// cout << "Bien\n";
		monomios[cont] = m; // suponemos que: cont < MAX
		cont++;
		return true;
	}
}
tPolinomio tPolinomio::operator+(const tPolinomio& p2) const {

	tPolinomio sol;
	int i = 0, j = 0; // i indice de this y j indice de p2

	while (i < cont || j < p2.cont) {

		if ((i < cont && j < p2.cont && p2.monomios[j] < monomios[i]) || j >= p2.cont) { // comprobamos que ambos esten dentro del rango y luego la condicion de desigualdad, o en otro caso que el contador j haya llegado al limite.

			// cout << "Caso1\n";
			sol.insertar(monomios[i]);
			i++;
		}
		else if ((i < cont && j < p2.cont && monomios[i] < p2.monomios[j]) || i >= cont) { // comprobamos que ambos esten dentro del rango y luego la condicion de desigualdad, o en otro caso que el contador i haya llegado al limite.

			// cout << "Caso2\n";
			sol.insertar(p2.monomios[j]);
			j++;
		}
		else {

			// cout << "Caso3\n";
			sol.insertar(p2.monomios[j] + monomios[i]);
			if (sol.monomios[cont - 1].esMonomioNulo()) sol.cont--;
			i++; 
			j++;
		}
	}
	return sol;
}
int tPolinomio::dameLongitud() const {

	return (cont);
}
tMonomio tPolinomio::dameElem(int i) const { // suponemos que esta dentro del rango.

	return (monomios[i]);
}
tPolinomio tPolinomio::operator*(const tPolinomio& p2) const {

	tPolinomio sol, aux;
	for (int i = 0; i < cont; i++) {
		for (int j = 0; j < p2.cont; j++) {
			aux.insertar(monomios[i] * p2.monomios[j]);
		}
		sol = sol + aux;
		aux.inicia();
	}
	return sol;
	
}