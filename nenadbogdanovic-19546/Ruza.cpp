#include "Ruza.h"

Ruza::Ruza() 
	: SadrzajPolja(0, false) {
	c = 'r';
}

int Ruza::ReakcijaNaMlaz(int jacina) {
	if (!Otkriveno())
		PostaviOtkriveno(true);

	return 0;
}

Ruza::Ruza(bool o)
	: SadrzajPolja(0, o) {
	c = 'r';
}