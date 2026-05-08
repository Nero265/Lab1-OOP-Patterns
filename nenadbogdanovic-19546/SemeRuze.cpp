#include "SemeRuze.h"
#include "Ruza.h"
#include "Trava.h"

SemeRuze::SemeRuze() : SadrzajPolja() {
	kolicina = Random();
	otkriveno = false;
	c = 's';
}

SemeRuze::SemeRuze(int kolicina, bool o) : SadrzajPolja(kolicina, o)
{
	c = 's';
}

int SemeRuze::ReakcijaNaMlaz(int jacina) {
	if (!Otkriveno())
	{
		PostaviOtkriveno(true);

		int zbir = kolicina + jacina;

		return zbir;
	}
}