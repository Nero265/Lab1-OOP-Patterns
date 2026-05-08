#include "Igrac.h"

void Igrac::Pucaj() {

	int n = livada->getN();

	int i = rand() % n;
	int j = rand() % n;

	int mlaz = 1 + rand() % 2;

	livada->ObradiMlaz(i, j, mlaz);

	if (livada->proveriRasejavanje()) {
		ProveriRasejavanje(i, j);
	}

	livada->resetRasejavanje();
	livada->Ispisi();
}

void Igrac::ProveriRasejavanje(int x, int y) {
	for (int i = 0; i < livada->getN(); i++) {
		for (int j = 0; j < livada->getN(); j++) {
			if (i == x && j == y) continue;
			if (livada->getPolje(i, j)->Otkriveno() && (livada->getPolje(i, j)->Karakter() == 's' || livada->getPolje(i, j)->Karakter() == 'j') )
				Pucaj(i, j);
		}
	}
}

void Igrac::Pucaj(int i, int j) {
	int m = 1 + rand() % 2;
	livada->ObradiMlaz(i, j, m);
}