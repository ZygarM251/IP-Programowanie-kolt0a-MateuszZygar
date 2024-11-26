#include "Wybor.h"
#include <iostream>
#include <cassert>
#include "zbior.h"


#ifdef Kol_1



void testKonstruktorKopiujacyRozdzielaZasoby()
{
	cout << "Test Rozdzielania zasobow przez konstruktor kopujacy" << endl;
	Zbior oryginal(10, 0.0, 100.0);

	Zbior kopia = oryginal;

	for (size_t i = 0; i < oryginal.liczbaElementow(); i++)
	{
		if (oryginal.getElement()[i] == kopia.getElement()[i] && oryginal.liczbaElementow() == kopia.liczbaElementow())
		{
			cout << "OK" << endl;
		}
		else
		{
			cout << "FAIL" << endl;
		}

	}
}


void testOperatorPrzenoszacyPrzypisujeZasoby()
{
	cout << "Test Przypisania zasobu poprzez operator =" << endl;
	Zbior oryginal(10, 0.0, 100.0);

	Zbior przenoszenie = move(oryginal);

	for (size_t i = 0; i < oryginal.liczbaElementow(); i++)
	{
		if (przenoszenie.liczbaElementow() != oryginal.liczbaElementow())
		{
			cout << "OK" << endl;
		}
		else if (przenoszenie.getElement()[i] != oryginal.getElement()[i])
		{
			cout << "OK" << endl;
		}
		else
		{
			cout << "Fail!" << endl;
		}


	}
}

	void sprawdzPrawidloweZasoby(vector<Zbior>&zbiory)
	{
		CzyPrawidlowyZasob predykat;
		int prawidloweZasoby = 0;

		for (const auto& zbior : zbiory)
		{
			if (predykat(zbior))
			{
				prawidloweZasoby++;
			}
		}

		cout << "Liczba instancji Zbioru z prawidlowym zasobem: " << prawidloweZasoby << endl;
	}



	int main()
	{
		testKonstruktorKopiujacyRozdzielaZasoby();
		testOperatorPrzenoszacyPrzypisujeZasoby();

		Zbior zbr1(10, 0.0, 100.0), zbr2(10, 0.0, 100.0), zbr3(10, 0.0, 100.0), zbr4(0, 0.0, 0.0);
		Zbiory zbior;

		zbior.dodajZbior(zbr1);
		zbior.dodajZbior(zbr2);
		zbior.dodajZbior(zbr3);
		zbior.dodajZbior(zbr4);

		/ sprawdzPrawidloweZasoby(zbior);

	}

#endif