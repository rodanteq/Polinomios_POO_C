#pragma once
class tMonomio {
private:
	int grado;
	int coef;
public:
	tMonomio();
	void inicia(int c, int g);
	bool operator<(const tMonomio& m) const;
	tMonomio operator+(const tMonomio& m2) const;
	tMonomio operator*(const tMonomio& m2) const;
	bool esMonomioNulo() const;
	int dameGrado() const;
	int dameCoeficiente() const;
};