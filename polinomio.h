#pragma once
#include "monomio.h"
#include <fstream>

using namespace std;
const int MAX_GRADO = 20;
class tPolinomio {
private:
	int cont;
	tMonomio monomios[MAX_GRADO];
	// declara metodos privados si es necesario
public:
	tPolinomio();
	void inicia();
	bool insertar(const tMonomio& m);
	tPolinomio operator+(const tPolinomio& p2) const;
	int dameLongitud() const;
	tMonomio dameElem(int i) const;
	tPolinomio operator*(const tPolinomio& p2) const;
};