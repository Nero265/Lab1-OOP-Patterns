#pragma once
#ifndef _puz_h_
#define _puz_h_

#include "SadrzajPolja.h"

class Puz : public SadrzajPolja {

public:

	Puz();
	Puz(bool o);
	int ReakcijaNaMlaz(int jacina);

};

#endif // !_puz_h_
