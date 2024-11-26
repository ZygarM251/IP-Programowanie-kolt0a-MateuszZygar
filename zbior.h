#pragma once
#include <vector>

using namespace std;

class Zbior
{
	size_t m_liczbaElementow = 0;
	double* m_elementy = nullptr;
	double m_dolnaGranica = 0;
	double m_gornaGranica = 0;
	void alokuj(int);
	void zwolnij();
public:
	Zbior(size_t liczElem, double dGran, double gGran);
	~Zbior() {}

	Zbior(const Zbior& zbr);
	Zbior& operator=(Zbior&& zbr)noexcept;

	//Dodanie mozliwosci odczytu liczby Elementow oraz eleentow ze zbioru
	//S¹ one potrzebne do testu jednostkowego przy sprawdzaniu orygina³u i kopi 
	//Oraz przenioszenia
	size_t liczbaElementow()const { return m_liczbaElementow; }
	double* getElement()const { return m_elementy; }


};

class Zbiory 
{

	vector<Zbior> zbiory;

public:

	void dodajZbior(const Zbior& zbior);
	void usunZbior(size_t zbr);
};


class CzyPrawidlowyZasob 
{
public:
	bool operator()(const Zbior& zbior) const
	{
		return zbior.getElement() != nullptr && zbior.liczbaElementow() > 0;
	}
};