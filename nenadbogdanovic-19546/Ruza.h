#pragma once
#ifndef _ruza_h_
#define _ruza_h_

#include "SadrzajPolja.h"

class Ruza : public SadrzajPolja {

public:

	Ruza();
	Ruza(bool o);
	int ReakcijaNaMlaz(int jacina);
};

#endif // !_ruza_h_
