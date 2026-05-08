#include "PoljeFactory.h"
#include "Livada.h"
#include "Igrac.h"
#include <fstream>

#include <iostream>
using namespace std;


void Ucitaj(ifstream& f, Livada* livada) {
	char c;
	for (int i = 0; i < livada->getN(); i++) {
		for (int j = 0; j < livada->getN(); j++) {
			f >> c;
			livada->Postavi(i, j, PoljeFactory::ucitajPolje(c));
		}
	}
}

int main() {

	ifstream f("fajl.txt");
	int n;
	f >> n;
	Livada::SetInstance(n);
	Livada* l = Livada::GetInstance();

	Ucitaj(f, l);

	cout << "Nakon ucitavanja" << endl;
	l->Ispisi();

	Igrac igrac(l);

	while (!l->Kraj()) {
		igrac.Pucaj();
	}

	cout << endl << "------------------------------------------------------" << endl;
	
	int poeni = l->brojBodova();
	cout << "Igrac je osvojio " << poeni << " poena, a to se vidi i iz livade";

	return 0;
}