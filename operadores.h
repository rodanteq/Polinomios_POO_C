#pragma once
#include <fstream>
#include <iostream>
#include "polinomio.h"
using namespace std;
istream& operator>>(istream& input, tMonomio& mon);
ostream& operator<<(ostream& out, const tPolinomio& pol);