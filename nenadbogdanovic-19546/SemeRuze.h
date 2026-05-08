#pragma once
#ifndef _semeruze_h_
#define _semeruze_h_

#include "SadrzajPolja.h"
#include "cstdlib"

class SemeRuze : public SadrzajPolja {

public:

	SemeRuze();
	SemeRuze(int kolicina, bool o);

	int ReakcijaNaMlaz(int jacina);

	int Random() {
		return 1 + rand() % 2;
	}
};


#endif // !_semeruze_h_
