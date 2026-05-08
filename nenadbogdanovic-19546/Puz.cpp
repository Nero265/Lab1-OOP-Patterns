#include "Puz.h"

Puz::Puz() : SadrzajPolja(0, false) {
	c = 'p';
}

Puz::Puz(bool o) : SadrzajPolja(0, o) {
	c = 'p';
	PostaviOtkriveno(o);
}

int Puz::ReakcijaNaMlaz(int jacina) {
	if (!Otkriveno())
		PostaviOtkriveno(true);

	return 0;
}