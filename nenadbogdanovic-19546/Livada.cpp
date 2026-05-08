#include "Livada.h"

#include <iostream>	
#include <cstdlib>
using namespace std;

Livada* Livada::instance = nullptr;

Livada::~Livada() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			delete matrica[i][j];
		}
	}

	for (int i = 0; i < n; i++)
		delete[] matrica[i];

	delete[] matrica;
	matrica = nullptr;
}

void Livada::Postavi(int i, int j, SadrzajPolja* sp) {
	this->matrica[i][j] = sp;
}

void Livada::Ispisi() {
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrica[i][j]) {
				if (matrica[i][j]->Otkriveno())
					cout << matrica[i][j]->Karakter() << " ";
				else
					cout << "X ";
			}
		}
		cout << endl;
	}
}

bool Livada::Kraj() {
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			auto* polje = matrica[i][j];
			if (!polje->Otkriveno() && polje->Karakter() == 's')
				return false;
			if (!polje->Otkriveno() && polje->Karakter() == 'j')
				return false;
		}
	}
	return true;
}

int Livada::brojBodova() {
	int rez = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			auto* polje = matrica[i][j];
			
			if (polje->Karakter() == 'r')
				rez++;
		}
	}
	return rez;
}

void Livada::UnistiRuze(int i, int j) {
	Postavi(i, j, new Puz(true));
	for (int x = -1; x <= 1; x++) {
		for (int y = -1; y <= 1; y++) {

			if (x == 0 && y == 0) continue;

			int ni = i + x;
			int nj = j + y;

			if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
				auto* sused = matrica[ni][nj];
				if (sused->Karakter() == 'r') {
					if (sused->Otkriveno())
						Postavi(ni, nj, new Trava(true));
					else
						Postavi(ni, nj, new Trava(false));
				}
			}
		}
	}
}

void Livada::PostaviRuze(int i, int j) {
	auto* polje = matrica[i][j];
	for (int x = -1; x <= 1; x++) {
		for (int y = -1; y <= 1; y++) {

			if (x == 0 && y == 0) continue;

			int ni = i + x;
			int nj = j + y;

			if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
				auto* sused = matrica[ni][nj];
				if (sused->Karakter() == 't') {
					if (sused->Otkriveno())
						Postavi(ni, nj, new SemeRuze(polje->Kolicina(), true));
					else
						Postavi(ni, nj, new SemeRuze(polje->Kolicina(), false));
				}
			}
		}
	}
	Postavi(i, j, new Trava(true));
	rasejavanje = true;
}

void Livada::PostaviPuzaRand() {
	
	int broj = 0;

	while(broj < 3) {
		int x = rand() % n;
		int y = rand() % n;

		auto* polje = matrica[x][y];
		if (polje && polje->Karakter() != 'p') {
			UnistiRuze(x, y);
			broj++;
		}
	}
	rasejavanje = true;
}

void Livada::PostaviRuzeRand() {
	int broj = 0;

	while (broj < 3) {
		int x = rand() % n;
		int y = rand() % n;

		auto* polje = matrica[x][y];
		if (polje && polje->Karakter() != 'r') {
			Postavi(x, y, new Ruza(true));
			broj++;
		}
	}
	rasejavanje = true;
}

void Livada::ObradiMlaz(int i, int j, int jacina) {

	auto* polje = matrica[i][j];
	int reakcija = polje->ReakcijaNaMlaz(jacina);

	if (reakcija== 2) {

		if (polje->Karakter() == 's')
			Postavi(i, j, new Ruza(true));
		
		if (polje->Karakter() == 'j')
		{
			UnistiRuze(i, j);
		}
	}
	
	if (reakcija == 3 && polje->Karakter() == 's') {
		PostaviRuze(i, j);
	}

	if (reakcija == 3 && polje->Karakter() == 'j') {
		
		Postavi(i, j, new TrojanskiPuz());
		PostaviPuzaRand();
	}

	if (reakcija == 4) {
		Postavi(i, j, new TrojanskaRuza());
	}
}