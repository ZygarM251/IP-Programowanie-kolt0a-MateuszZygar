#include "zbior.h"
#include <new>
#include <random>
#include <cassert>
using namespace std;

void Zbior::alokuj(int n)
{
	assert(n > 0);
	m_elementy = new(std::nothrow) double[n] {};
	m_liczbaElementow = n;

}

void Zbior::zwolnij()
{
	delete[] m_elementy;
}

Zbior::Zbior(size_t liczElem, double dGran, double gGran)
{
	alokuj(liczElem);
	std::uniform_real_distribution<double> zakres(dGran, gGran);
	std::random_device generator;
	for (int elem = 0; elem < liczElem; elem++)
		m_elementy[elem] = zakres(generator);
}

//Konstruktor Kopiuj¹cy
Zbior::Zbior(const Zbior& zbr) 
	:m_liczbaElementow(zbr.m_liczbaElementow),
	m_dolnaGranica(zbr.m_dolnaGranica),
	m_gornaGranica(zbr.m_gornaGranica)
{
	alokuj(m_liczbaElementow);
	for (size_t i = 0; i < m_liczbaElementow; i++)
	{
		m_elementy[i] = zbr.m_elementy[i];
	}
}

//Przenosz¹cy operator =
Zbior& Zbior::operator=(Zbior&& zbr)noexcept 
{
	if (this!= &zbr)
	{
		zwolnij();
		m_liczbaElementow = zbr.m_liczbaElementow;
		m_elementy = zbr.m_elementy;
		m_dolnaGranica = zbr.m_dolnaGranica;
		m_gornaGranica = zbr.m_gornaGranica;
		zbr.m_elementy = nullptr;
		zbr.m_liczbaElementow = 0;
	}
	return *this;
}


void Zbiory::dodajZbior(const Zbior& zbior)
{
	zbiory.push_back(zbior);
}

void Zbiory::usunZbior(size_t zbr)
{
	if (zbr<zbiory.size())
	{
		zbiory.erase(zbiory.begin() + zbr);
	}
}