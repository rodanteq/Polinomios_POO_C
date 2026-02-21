#include "monomio.h"

tMonomio::tMonomio() : grado(0) , coef(0) {}

void tMonomio::inicia(int c, int g) {

	coef = c;
	grado = g;
}
bool tMonomio::operator<(const tMonomio& m) const {

	return(grado < m.grado);
}
tMonomio tMonomio::operator+(const tMonomio& m2) const {

	tMonomio sol;
	sol.inicia(coef + m2.coef, grado);
	return sol;
}
tMonomio tMonomio::operator*(const tMonomio& m2) const {

	tMonomio sol;
	sol.inicia(coef * m2.coef, grado + m2.grado);
	return sol;
}
bool tMonomio::esMonomioNulo() const {

	return (coef == 0);
}
int tMonomio::dameGrado() const {

	return (grado);
}
int tMonomio::dameCoeficiente() const {

	return (coef);
}