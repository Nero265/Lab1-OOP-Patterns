#pragma once
#ifndef _trojanskaruzaa_h_
#define _trojanskaruza_h_

#include "SadrzajPolja.h"

class TrojanskaRuza : public SadrzajPolja {

public:
	TrojanskaRuza() : SadrzajPolja(0, true) {
		c = 'R';
	}

	int ReakcijaNaMlaz(int jacina) {
		return 0;
	}
};

#endif // !_trojanskaruzaa_h_
