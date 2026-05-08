#pragma once
#ifndef _trojanskipuz_h_
#define _trojanskipuz_h_

#include "SadrzajPolja.h"

class TrojanskiPuz : public SadrzajPolja {

public:

	TrojanskiPuz()  : SadrzajPolja(0, true) {
		c = 'P';
	}

	int ReakcijaNaMlaz(int jacina) {
		return 0;
	}
};

#endif // !_trojanskipuz_h_
