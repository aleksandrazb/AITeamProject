#pragma once
#ifndef PCH_H
#define PCH_H

#include <string>
#include <string.h>
#include <ctime>
extern bool gra;
//ofstream zapis; //deklaracja pliku dla drzewka

typedef
struct droga
{
	int _droga;
	int x;
	int y;
	int dlugosc;
}droga;

//definicja struktury sciezki przekazywanie danych do drzewa decyzyjnego

typedef
struct sciezka
{
	int numer;  //nummer pozycji x 1,4,7,10,13,16,19,22
	int ilosc_roslin_bez_wody;
	int ilosc_roslin_bez_nawozu;
	int waga;
	int poczatek;
	int koniec;
}sciezka;



//definicja struktury rosliny
typedef
struct roslina
{
	int stan;
	double woda;
	double nawoz;
	double zycie;
	double sadzonka;
	int waga;
	int rodzaj;
	int x;
	int y;
	int wod;
	int naw;
	std::string lisc;
	std::string kwiat;
	std::string kolor;
}roslina;

extern char mapa[25][25];
extern int pozycjaX, pozycjaY, ilosc_roslin, ilosc_plonow, ilosc_trupow, paliwo, konrolka, h;
extern clock_t start, stop;
extern double czas;

//struktura do przekazywania danych
extern droga glowna;

//mapa roslin
extern roslina tab[25][25];

//tablica scierzek
extern sciezka scierzka[16];

extern sciezka sciezka_temp; //pomocnicze

droga oblicz(int x, int y);
droga znajdz();
void idz();
void ustaw_stan();
void updateMapa();
void Odswiez(void* data);
void Chodz(void* data);
void ShowConsoleCursor(bool showFlag);
void dzialanie(char klikniecie);

#endif _PCH_H

