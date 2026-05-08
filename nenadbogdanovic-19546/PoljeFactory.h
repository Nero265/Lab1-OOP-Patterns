#pragma once
#ifndef _poljefactory_h_
#define _poljefactory_h_

#include "SadrzajPolja.h"
#include "SemeRuze.h"
#include "Ruza.h"
#include "Puz.h"
#include "JajascePuza.h"
#include "Trava.h"
#include "TrojanskaRuza.h"
#include "TrojanskiPuz.h"

class PoljeFactory {

public :

	static SadrzajPolja* ucitajPolje(char c)
	{
		switch (c)
		{
		case 't':
			return new Trava();
			break;
		case 'r':
			return new Ruza();
			break;
		case 's':
			return new SemeRuze();
			break;
		case 'p':
			return new Puz();
			break;
		case 'j':
			return new JajascePuza();
			break;
		case 'R':
			return new TrojanskaRuza();
			break;
		case 'P':
			return new TrojanskiPuz();
			break;

		}
		
	}
};

#endif // !_poljefactory_h_
