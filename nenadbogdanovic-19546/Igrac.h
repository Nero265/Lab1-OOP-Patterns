#pragma once
#ifndef _igrac_h_
#define _igrac_h_

#include "Livada.h"

class Igrac {

	Livada* livada;

public:

	Igrac(Livada* l) : livada(l) {}

	void Pucaj();

	void ProveriRasejavanje(int x, int y);

	void Pucaj(int i, int j);
};

#endif // !_igrac_h_
