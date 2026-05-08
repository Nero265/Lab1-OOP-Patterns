#pragma once
#ifndef _livada_h_
#define _livada_h_


#include "Ruza.h"
#include "SadrzajPolja.h";
#include "SemeRuze.h"
#include "Puz.h"
#include "JajascePuza.h"
#include "Trava.h"
#include "TrojanskaRuza.h"
#include "TrojanskiPuz.h"

class Livada {
	int n;
	SadrzajPolja*** matrica;
	bool rasejavanje;

	static Livada* instance;

	Livada(int n) {
		this->n = n;
		matrica = new SadrzajPolja * *[n];

		for (int i = 0; i < n; i++) {
			matrica[i] = new SadrzajPolja * [n];

			for (int j = 0; j < n; j++)
				matrica[i][j] = 0;
		}
	}

public:

	void Postavi(int i, int j, SadrzajPolja* sp);
	void Ispisi();


	int getN() const { return n; }
	static Livada* GetInstance() { return instance; }

	static void SetInstance(int n) {
		if (instance == nullptr) {
			instance = new Livada(n);
		}
	}

	SadrzajPolja* getPolje(int i, int j) { return matrica[i][j]; }

	bool proveriRasejavanje() { return rasejavanje; }
	void resetRasejavanje() { rasejavanje = false; }

	void ObradiMlaz(int x, int y, int jacina);

	void UnistiRuze(int i, int j);

	void PostaviRuze(int i, int j);

	void PostaviPuzaRand();

	void PostaviRuzeRand();

	bool Kraj();

	int brojBodova();

	~Livada();
};

#endif // !_livada_h_
