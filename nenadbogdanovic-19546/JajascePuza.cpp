#include "JajascePuza.h"

JajascePuza::JajascePuza() : SadrzajPolja(1, false) {
	c = 'j';
}

int JajascePuza::ReakcijaNaMlaz(int jacina) {
	if (!Otkriveno()) {
		PostaviOtkriveno(true);

		int zbir = kolicina + jacina;

		return zbir;
	}
}