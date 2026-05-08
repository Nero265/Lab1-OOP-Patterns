#include "Trava.h"

Trava::Trava() : SadrzajPolja(0, false) {
	c = 't';
}

Trava::Trava(bool o) : SadrzajPolja(0, o) {
	c = 't';
}

int Trava::ReakcijaNaMlaz(int jacina) {
	if (!Otkriveno())
		PostaviOtkriveno(true);

	return 0;
}