#pragma once
#ifndef _trava_h_
#define _trava_h_

#include "SadrzajPolja.h"

class Trava : public SadrzajPolja {


public :

	Trava();
	Trava(bool o);
	int ReakcijaNaMlaz(int jacina);
};

#endif // !_trava_h_
