#pragma once
#ifndef _sadrzajpolja_h_
#define _sadrzajpolja_h_

class SadrzajPolja {

protected:

	char c; //oznaka biljke ili zivotinje
	int kolicina; //semena ili jajasca
	bool otkriveno;

public:

	SadrzajPolja();
	virtual ~SadrzajPolja() { }
	SadrzajPolja(int x, bool o);

	virtual int ReakcijaNaMlaz(int jacina) = 0;

	int Kolicina() { return kolicina; }
	char Karakter() { return c; }
	bool Otkriveno() { return otkriveno; }

	void PostaviOtkriveno(bool o) { otkriveno = o; }
	void PostaviKolicinu(int k) {
		kolicina = k;
	}
};

#endif // !_sadrzajpolja_h_
