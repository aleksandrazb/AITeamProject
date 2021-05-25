#include "pch.h"

#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<process.h>
#include <thread>
#include <cmath>
#include <string>
#include <ostream>
#include <string.h>

using namespace std;

extern bool gra = true;
char mapa[25][25];
int pozycjaX = 1, pozycjaY = 1, ilosc_roslin = 0, ilosc_plonow = 0, ilosc_trupow = 0, paliwo = 0, konrolka = 0, h;
clock_t start, stop;
double czas;

//struktura do przekazywania danych
droga glowna;

//mapa roslin
roslina tab[25][25];

//tablica scierzek
sciezka scierzka[16];

sciezka sciezka_temp; //pomocnicze

droga oblicz(int x, int y) // nr drogi - obliczanie drogi  do pozycji x/y (drogi kolejno przez y=1;y=12;y=23)
{
	droga d;
	int i, j, dlugosc, droga_;
	int dlugosctemp = 0;

	i = abs(pozycjaX - x);
	j = abs(pozycjaY - y);

	d.x = x;
	d.y = y;

	if (x - pozycjaX > 1 && y - pozycjaY == 0)  // 0,1,2
	{
		dlugosctemp = dlugosctemp + abs(pozycjaY - 1);
		dlugosctemp = dlugosctemp + i;
		dlugosctemp = dlugosctemp + abs(1 - y);

		if (x == 2 || x == 5 || x == 8 || x == 11 || x == 14 || x == 17 || x == 20 || x == 23)
		{
			dlugosctemp = dlugosctemp - 1;
		}
		else
		{
			dlugosctemp = dlugosctemp + 1;
		}

		dlugosc = dlugosctemp;
		dlugosctemp = 0;
		droga_ = 0;

		dlugosctemp = dlugosctemp + abs(pozycjaY - 12);
		dlugosctemp = dlugosctemp + i;
		dlugosctemp = dlugosctemp + abs(12 - y);

		if (x == 2 || x == 5 || x == 8 || x == 11 || x == 14 || x == 17 || x == 20 || x == 23)
		{
			dlugosctemp = dlugosctemp - 1;
		}
		else
		{
			dlugosctemp = dlugosctemp + 1;
		}

		if (dlugosctemp < dlugosc)
		{
			dlugosc = dlugosctemp;
			droga_ = 1;
		}
		dlugosctemp = 0;

		dlugosctemp = dlugosctemp + abs(pozycjaY - 23);
		dlugosctemp = dlugosctemp + i;
		dlugosctemp = dlugosctemp + abs(23 - y);

		if (x == 2 || x == 5 || x == 8 || x == 11 || x == 14 || x == 17 || x == 20 || x == 23)
		{
			dlugosctemp = dlugosctemp - 1;
		}
		else
		{
			dlugosctemp = dlugosctemp + 1;
		}

		if (dlugosctemp < dlugosc)
		{
			dlugosc = dlugosctemp;
			droga_ = 2;
		}

		d._droga = droga_;
		d.dlugosc = dlugosc;

		return d;

	}
	if (x - pozycjaX > 1 && y - pozycjaY > 0) // 3,4,5
	{
		dlugosctemp = dlugosctemp + abs(pozycjaY - 1);
		dlugosctemp = dlugosctemp + i;
		dlugosctemp = dlugosctemp + abs(1 - y);


		if (x == 2 || x == 5 || x == 8 || x == 11 || x == 14 || x == 17 || x == 20 || x == 23)
		{
			dlugosctemp = dlugosctemp - 1;
		}
		else
		{
			dlugosctemp = dlugosctemp + 1;
		}

		dlugosc = dlugosctemp;
		dlugosctemp = 0;
		droga_ = 3;

		dlugosctemp = dlugosctemp + abs(pozycjaY - 12);
		dlugosctemp = dlugosctemp + i;
		dlugosctemp = dlugosctemp + abs(12 - y);


		if (x == 2 || x == 5 || x == 8 || x == 11 || x == 14 || x == 17 || x == 20 || x == 23)
		{
			dlugosctemp = dlugosctemp - 1;
		}
		else
		{
			dlugosctemp = dlugosctemp + 1;
		}

		if (dlugosctemp < dlugosc)
		{
			dlugosc = dlugosctemp;
			droga_ = 4;
		}
		dlugosctemp = 0;

		dlugosctemp = dlugosctemp + abs(pozycjaY - 23);
		dlugosctemp = dlugosctemp + i;
		dlugosctemp = dlugosctemp + abs(23 - y);


		if (x == 2 || x == 5 || x == 8 || x == 11 || x == 14 || x == 17 || x == 20 || x == 23)
		{
			dlugosctemp = dlugosctemp - 1;
		}
		else
		{
			dlugosctemp = dlugosctemp + 1;
		}

		if (dlugosctemp < dlugosc)
		{
			dlugosc = dlugosctemp;
			droga_ = 5;
		}

		d._droga = droga_;
		d.dlugosc = dlugosc;

		return d;

	}
	if (x - pozycjaX > 1 && y - pozycjaY < 0) // 6,7,8
	{
		dlugosctemp = dlugosctemp + abs(pozycjaY - 1);
		dlugosctemp = dlugosctemp + i;
		dlugosctemp = dlugosctemp + abs(1 - y);


		if (x == 2 || x == 5 || x == 8 || x == 11 || x == 14 || x == 17 || x == 20 || x == 23)
		{
			dlugosctemp = dlugosctemp - 1;
		}
		else
		{
			dlugosctemp = dlugosctemp + 1;
		}

		dlugosc = dlugosctemp;
		dlugosctemp = 0;
		droga_ = 6;

		dlugosctemp = dlugosctemp + abs(pozycjaY - 12);
		dlugosctemp = dlugosctemp + i;
		dlugosctemp = dlugosctemp + abs(12 - y);


		if (x == 2 || x == 5 || x == 8 || x == 11 || x == 14 || x == 17 || x == 20 || x == 23)
		{
			dlugosctemp = dlugosctemp - 1;
		}
		else
		{
			dlugosctemp = dlugosctemp + 1;
		}

		if (dlugosctemp < dlugosc)
		{
			dlugosc = dlugosctemp;
			droga_ = 7;
		}
		dlugosctemp = 0;

		dlugosctemp = dlugosctemp + abs(pozycjaY - 23);
		dlugosctemp = dlugosctemp + i;
		dlugosctemp = dlugosctemp + abs(23 - y);


		if (x == 2 || x == 5 || x == 8 || x == 11 || x == 14 || x == 17 || x == 20 || x == 23)
		{
			dlugosctemp = dlugosctemp - 1;
		}
		else
		{
			dlugosctemp = dlugosctemp + 1;
		}

		if (dlugosctemp < dlugosc)
		{
			dlugosc = dlugosctemp;
			droga_ = 8;
		}

		d._droga = droga_;
		d.dlugosc = dlugosc;

		return d;
	}

	if (x - pozycjaX == 0 && y - pozycjaY > 0) // 9,10 przez y=1 lub 12
	{
		dlugosctemp = dlugosctemp + 1;
		dlugosctemp = dlugosctemp + j;
		dlugosc = dlugosctemp;

		if (pozycjaY = 1)
		{
			droga_ = 9;
			d._droga = droga_;
			d.dlugosc = dlugosc;

			return d;
		}
		if (pozycjaY = 12)
		{
			droga_ = 10;
			d._droga = droga_;
			d.dlugosc = dlugosc;

			return d;
		}

	}
	if (x - pozycjaX == 0 && y - pozycjaY < 0) // 11,12 przez y=12 lub 23
	{
		dlugosctemp = dlugosctemp + 1;
		dlugosctemp = dlugosctemp + j;
		dlugosc = dlugosctemp;

		if (pozycjaY = 12)
		{
			droga_ = 11;
			d._droga = droga_;
			d.dlugosc = dlugosc;

			return d;
		}
		if (pozycjaY = 23)
		{
			droga_ = 12;

			d._droga = droga_;
			d.dlugosc = dlugosc;

			return d;
		}
	}

	if (x - pozycjaX < -1 && y - pozycjaY == 0) // 13,14,15
	{
		dlugosctemp = dlugosctemp + abs(pozycjaY - 1);
		dlugosctemp = dlugosctemp + i;
		dlugosctemp = dlugosctemp + abs(1 - y);

		if (x == 2 || x == 5 || x == 8 || x == 11 || x == 14 || x == 17 || x == 20 || x == 23)
		{
			dlugosctemp = dlugosctemp - 1;
		}
		else
		{
			dlugosctemp = dlugosctemp + 1;
		}

		dlugosc = dlugosctemp;
		dlugosctemp = 0;
		droga_ = 13;

		dlugosctemp = dlugosctemp + abs(pozycjaY - 12);
		dlugosctemp = dlugosctemp + i;
		dlugosctemp = dlugosctemp + abs(12 - y);

		if (x == 2 || x == 5 || x == 8 || x == 11 || x == 14 || x == 17 || x == 20 || x == 23)
		{
			dlugosctemp = dlugosctemp - 1;
		}
		else
		{
			dlugosctemp = dlugosctemp + 1;
		}

		if (dlugosctemp < dlugosc)
		{
			dlugosc = dlugosctemp;
			droga_ = 14;
		}
		dlugosctemp = 0;

		dlugosctemp = dlugosctemp + abs(pozycjaY - 23);
		dlugosctemp = dlugosctemp + i;
		dlugosctemp = dlugosctemp + abs(23 - y);

		if (x == 2 || x == 5 || x == 8 || x == 11 || x == 14 || x == 17 || x == 20 || x == 23)
		{
			dlugosctemp = dlugosctemp - 1;
		}
		else
		{
			dlugosctemp = dlugosctemp + 1;
		}

		if (dlugosctemp < dlugosc)
		{
			dlugosc = dlugosctemp;
			droga_ = 15;
		}

		d._droga = droga_;
		d.dlugosc = dlugosc;

		return d;
	}
	if (x - pozycjaX < -1 && y - pozycjaY>0) // 16,17,18
	{
		dlugosctemp = dlugosctemp + abs(pozycjaY - 1);
		dlugosctemp = dlugosctemp + i;
		dlugosctemp = dlugosctemp + abs(1 - y);


		if (x == 2 || x == 5 || x == 8 || x == 11 || x == 14 || x == 17 || x == 20 || x == 23)
		{
			dlugosctemp = dlugosctemp - 1;
		}
		else
		{
			dlugosctemp = dlugosctemp + 1;
		}

		dlugosc = dlugosctemp;
		dlugosctemp = 0;
		droga_ = 16;

		dlugosctemp = dlugosctemp + abs(pozycjaY - 12);
		dlugosctemp = dlugosctemp + i;
		dlugosctemp = dlugosctemp + abs(12 - y);

		if (x == 2 || x == 5 || x == 8 || x == 11 || x == 14 || x == 17 || x == 20 || x == 23)
		{
			dlugosctemp = dlugosctemp - 1;
		}
		else
		{
			dlugosctemp = dlugosctemp + 1;
		}

		if (dlugosctemp < dlugosc)
		{
			dlugosc = dlugosctemp;
			droga_ = 17;
		}
		dlugosctemp = 0;

		dlugosctemp = dlugosctemp + abs(pozycjaY - 23);
		dlugosctemp = dlugosctemp + i;
		dlugosctemp = dlugosctemp + abs(23 - y);


		if (x == 2 || x == 5 || x == 8 || x == 11 || x == 14 || x == 17 || x == 20 || x == 23)
		{
			dlugosctemp = dlugosctemp - 1;
		}
		else
		{
			dlugosctemp = dlugosctemp + 1;
		}

		if (dlugosctemp < dlugosc)
		{
			dlugosc = dlugosctemp;
			droga_ = 18;
		}

		d._droga = droga_;
		d.dlugosc = dlugosc;

		return d;
	}
	if (x - pozycjaX < -1 && y - pozycjaY < 0) // 19,20,21
	{
		dlugosctemp = dlugosctemp + abs(pozycjaY - 1);
		dlugosctemp = dlugosctemp + i;
		dlugosctemp = dlugosctemp + abs(1 - y);


		if (x == 2 || x == 5 || x == 8 || x == 11 || x == 14 || x == 17 || x == 20 || x == 23)
		{
			dlugosctemp = dlugosctemp - 1;
		}
		else
		{
			dlugosctemp = dlugosctemp + 1;
		}

		dlugosc = dlugosctemp;
		dlugosctemp = 0;
		droga_ = 19;

		dlugosctemp = dlugosctemp + abs(pozycjaY - 12);
		dlugosctemp = dlugosctemp + i;
		dlugosctemp = dlugosctemp + abs(12 - y);


		if (x == 2 || x == 5 || x == 8 || x == 11 || x == 14 || x == 17 || x == 20 || x == 23)
		{
			dlugosctemp = dlugosctemp - 1;
		}
		else
		{
			dlugosctemp = dlugosctemp + 1;
		}

		if (dlugosctemp < dlugosc)
		{
			dlugosc = dlugosctemp;
			droga_ = 20;
		}
		dlugosctemp = 0;

		dlugosctemp = dlugosctemp + abs(pozycjaY - 23);
		dlugosctemp = dlugosctemp + i;
		dlugosctemp = dlugosctemp + abs(23 - y);


		if (x == 2 || x == 5 || x == 8 || x == 11 || x == 14 || x == 17 || x == 20 || x == 23)
		{
			dlugosctemp = dlugosctemp - 1;
		}
		else
		{
			dlugosctemp = dlugosctemp + 1;
		}

		if (dlugosctemp < dlugosc)
		{
			dlugosc = dlugosctemp;
			droga_ = 21;
		}

		d._droga = droga_;
		d.dlugosc = dlugosc;

		return d;
	}

	if (i == 1 && y - pozycjaY > 0) // 22 brak przejscia w góre lub w dół
	{
		dlugosc = j;
		droga_ = 22;
		d._droga = droga_;
		d.dlugosc = dlugosc;

		return d;
	}
	if (i == 1 && y - pozycjaY < 0)  // 23 brak przejscia w góre lub w dół
	{
		d.dlugosc = j;
		d._droga = 23;

		return d;
	}
	if (i == 1 && y - pozycjaY == 0) //24 brak ruchu tylko podlanie
	{
		d.dlugosc = 0;
		d._droga = 24;
		return d;
	}
}

droga znajdz() // wybranie najlepszej drogi do rosliny
{
	droga dozwrotu;
	droga zzrwotu;
	int i, j, k, l;
	zzrwotu._droga = 100;
	zzrwotu.dlugosc = 1000;
	dozwrotu.dlugosc = 10000;
	dozwrotu._droga = 100;
	droga zapis_drug[25][2];
	sciezka_temp.waga = 1000;

	for (i = 0; i < 16; i++) //zerowanie scieżki
	{
		scierzka[i].waga = 100;
		scierzka[i].ilosc_roslin_bez_nawozu = 0;
		scierzka[i].ilosc_roslin_bez_wody = 0;
	}

	for (k = 0; k < 16; k++)
	{
		for (i = 1; i <= 22; i = i + 3)
		{
			if (scierzka[k].numer == i && scierzka[k].poczatek == 2)
			{
				for (l = 2; l <= scierzka[k].koniec; l++)
				{
					if (tab[i + 1][l].rodzaj == 1 || tab[i - 1][l].rodzaj == 1)
					{
						if (tab[i + 1][l].stan == 2 || tab[i - 1][l].stan == 2)
						{
							scierzka[k].waga = scierzka[k].waga - 6;
							scierzka[k].ilosc_roslin_bez_wody = scierzka[k].ilosc_roslin_bez_wody + 1;
						}
						else if (tab[i + 1][l].stan == 3 || tab[i - 1][l].stan == 3)
						{
							scierzka[k].waga = scierzka[k].waga - 6;
							scierzka[k].ilosc_roslin_bez_nawozu = scierzka[k].ilosc_roslin_bez_nawozu + 1;
						}
						else if (tab[i + 1][l].stan == 4 || tab[i - 1][l].stan == 4)
						{
							scierzka[k].waga = scierzka[k].waga - 12;
							scierzka[k].ilosc_roslin_bez_wody = scierzka[k].ilosc_roslin_bez_wody + 1;
							scierzka[k].ilosc_roslin_bez_nawozu = scierzka[k].ilosc_roslin_bez_nawozu + 1;
						}

					}
					else if (tab[i + 1][l].rodzaj == 2 || tab[i - 1][l].rodzaj == 2)
					{
						if (tab[i + 1][l].stan == 2 || tab[i - 1][l].stan == 2)
						{
							scierzka[k].waga = scierzka[k].waga - 6;
							scierzka[k].ilosc_roslin_bez_wody = scierzka[k].ilosc_roslin_bez_wody + 1;
						}
						else if (tab[i + 1][l].stan == 3 || tab[i - 1][l].stan == 3)
						{
							scierzka[k].waga = scierzka[k].waga - 6;
							scierzka[k].ilosc_roslin_bez_nawozu = scierzka[k].ilosc_roslin_bez_nawozu + 1;
						}
						else if (tab[i + 1][l].stan == 4 || tab[i - 1][l].stan == 4)
						{
							scierzka[k].waga = scierzka[k].waga - 12;
							scierzka[k].ilosc_roslin_bez_wody = scierzka[k].ilosc_roslin_bez_wody + 1;
							scierzka[k].ilosc_roslin_bez_nawozu = scierzka[k].ilosc_roslin_bez_nawozu + 1;
						}
					}
					else if (tab[i + 1][l].rodzaj == 3 || tab[i - 1][l].rodzaj == 3)
					{
						if (tab[i + 1][l].stan == 2 || tab[i - 1][l].stan == 2)
						{
							scierzka[k].waga = scierzka[k].waga - 6;
							scierzka[k].ilosc_roslin_bez_wody = scierzka[k].ilosc_roslin_bez_wody + 1;
						}
						else if (tab[i + 1][l].stan == 3 || tab[i - 1][l].stan == 3)
						{
							scierzka[k].waga = scierzka[k].waga - 6;
							scierzka[k].ilosc_roslin_bez_nawozu = scierzka[k].ilosc_roslin_bez_nawozu + 1;
						}
						else if (tab[i + 1][l].stan == 4 || tab[i - 1][l].stan == 4)
						{
							scierzka[k].waga = scierzka[k].waga - 12;
							scierzka[k].ilosc_roslin_bez_wody = scierzka[k].ilosc_roslin_bez_wody + 1;
							scierzka[k].ilosc_roslin_bez_nawozu = scierzka[k].ilosc_roslin_bez_nawozu + 1;
						}
					}
					else
					{
						if (tab[i + 1][l].stan == 2 || tab[i - 1][l].stan == 2)
						{
							scierzka[k].waga = scierzka[k].waga - 6;
							scierzka[k].ilosc_roslin_bez_wody = scierzka[k].ilosc_roslin_bez_wody + 1;
						}
						else if (tab[i + 1][l].stan == 3 || tab[i - 1][l].stan == 3)
						{
							scierzka[k].waga = scierzka[k].waga - 6;
							scierzka[k].ilosc_roslin_bez_nawozu = scierzka[k].ilosc_roslin_bez_nawozu + 1;
						}
						else if (tab[i + 1][l].stan == 4 || tab[i - 1][l].stan == 4)
						{
							scierzka[k].waga = scierzka[k].waga - 12;
							scierzka[k].ilosc_roslin_bez_wody = scierzka[k].ilosc_roslin_bez_wody + 1;
							scierzka[k].ilosc_roslin_bez_nawozu = scierzka[k].ilosc_roslin_bez_nawozu + 1;
						}
					}
				}
			}
		}

		for (i = 1; i <= 22; i = i + 3)
		{
			if (scierzka[k].numer == i && scierzka[k].poczatek == 13)
			{
				for (l = 13; l < scierzka[k].koniec; l++)
				{
					if (tab[i + 1][l].rodzaj == 1 || tab[i - 1][l].rodzaj == 1)
					{
						if (tab[i + 1][l].stan == 2 || tab[i - 1][l].stan == 2)
						{
							scierzka[k].waga = scierzka[k].waga - 6;
							scierzka[k].ilosc_roslin_bez_wody = scierzka[k].ilosc_roslin_bez_wody + 1;
						}
						else if (tab[i + 1][l].stan == 3 || tab[i - 1][l].stan == 3)
						{
							scierzka[k].waga = scierzka[k].waga - 6;
							scierzka[k].ilosc_roslin_bez_nawozu = scierzka[k].ilosc_roslin_bez_nawozu + 1;
						}
						else if (tab[i + 1][l].stan == 4 || tab[i - 1][l].stan == 4)
						{
							scierzka[k].waga = scierzka[k].waga - 12;
							scierzka[k].ilosc_roslin_bez_wody = scierzka[k].ilosc_roslin_bez_wody + 1;
							scierzka[k].ilosc_roslin_bez_nawozu = scierzka[k].ilosc_roslin_bez_nawozu + 1;
						}

					}
					else if (tab[i + 1][l].rodzaj == 2 || tab[i - 1][l].rodzaj == 2)
					{
						if (tab[i + 1][l].stan == 2 || tab[i - 1][l].stan == 2)
						{
							scierzka[k].waga = scierzka[k].waga - 6;
							scierzka[k].ilosc_roslin_bez_wody = scierzka[k].ilosc_roslin_bez_wody + 1;
						}
						else if (tab[i + 1][l].stan == 3 || tab[i - 1][l].stan == 3)
						{
							scierzka[k].waga = scierzka[k].waga - 6;
							scierzka[k].ilosc_roslin_bez_nawozu = scierzka[k].ilosc_roslin_bez_nawozu + 1;
						}
						else if (tab[i + 1][l].stan == 4 || tab[i - 1][l].stan == 4)
						{
							scierzka[k].waga = scierzka[k].waga - 12;
							scierzka[k].ilosc_roslin_bez_wody = scierzka[k].ilosc_roslin_bez_wody + 1;
							scierzka[k].ilosc_roslin_bez_nawozu = scierzka[k].ilosc_roslin_bez_nawozu + 1;
						}
					}
					else if (tab[i + 1][l].rodzaj == 3 || tab[i - 1][l].rodzaj == 3)
					{
						if (tab[i + 1][l].stan == 2 || tab[i - 1][l].stan == 2)
						{
							scierzka[k].waga = scierzka[k].waga - 6;
							scierzka[k].ilosc_roslin_bez_wody = scierzka[k].ilosc_roslin_bez_wody + 1;
						}
						else if (tab[i + 1][l].stan == 3 || tab[i - 1][l].stan == 3)
						{
							scierzka[k].waga = scierzka[k].waga - 6;
							scierzka[k].ilosc_roslin_bez_nawozu = scierzka[k].ilosc_roslin_bez_nawozu + 1;
						}
						else if (tab[i + 1][l].stan == 4 || tab[i - 1][l].stan == 4)
						{
							scierzka[k].waga = scierzka[k].waga - 12;
							scierzka[k].ilosc_roslin_bez_wody = scierzka[k].ilosc_roslin_bez_wody + 1;
							scierzka[k].ilosc_roslin_bez_nawozu = scierzka[k].ilosc_roslin_bez_nawozu + 1;
						}
					}
					else
					{
						if (tab[i + 1][l].stan == 2 || tab[i - 1][l].stan == 2)
						{
							scierzka[k].waga = scierzka[k].waga - 6;
							scierzka[k].ilosc_roslin_bez_wody = scierzka[k].ilosc_roslin_bez_wody + 1;
						}
						else if (tab[i + 1][l].stan == 3 || tab[i - 1][l].stan == 3)
						{
							scierzka[k].waga = scierzka[k].waga - 6;
							scierzka[k].ilosc_roslin_bez_nawozu = scierzka[k].ilosc_roslin_bez_nawozu + 1;
						}
						else if (tab[i + 1][l].stan == 4 || tab[i - 1][l].stan == 4)
						{
							scierzka[k].waga = scierzka[k].waga - 12;
							scierzka[k].ilosc_roslin_bez_wody = scierzka[k].ilosc_roslin_bez_wody + 1;
							scierzka[k].ilosc_roslin_bez_nawozu = scierzka[k].ilosc_roslin_bez_nawozu + 1;
						}
					}
				}
			}
		}
	}

	for (k = 0; k < 16; k++)
	{
		if (scierzka[k].poczatek == 2)
		{
			scierzka[k].waga = scierzka[k].waga + (abs(pozycjaX - scierzka[k].numer) / 2);
		}
		else
		{
			scierzka[k].waga = scierzka[k].waga + (abs(pozycjaX - scierzka[k].numer) / 2);
		}

		if (pozycjaX == scierzka[k].numer && pozycjaY <= scierzka[k].koniec && pozycjaY >= scierzka[k].poczatek)
		{
			h = k;
		}
	}

	if (scierzka[h].waga < 100)
	{
		for (i = scierzka[h].poczatek; i <= scierzka[h].koniec; i++)
		{
			if (tab[pozycjaX + 1][i].stan == 2 || tab[pozycjaX + 1][i].stan == 3 || tab[pozycjaX + 1][i].stan == 4)
			{
				zzrwotu = oblicz(pozycjaX + 1, i);

				zapis_drug[i][0].dlugosc = zzrwotu.dlugosc;
				zapis_drug[i][0]._droga = zzrwotu._droga;
				zapis_drug[i][0].x = zzrwotu.x;
				zapis_drug[i][0].y = zzrwotu.y;
			}

			if (tab[pozycjaX - 1][i].stan == 2 || tab[pozycjaX - 1][i].stan == 3 || tab[pozycjaX - 1][i].stan == 4)
			{
				zzrwotu = oblicz(pozycjaX - 1, i);

				zapis_drug[i][1].dlugosc = zzrwotu.dlugosc;
				zapis_drug[i][1]._droga = zzrwotu._droga;
				zapis_drug[i][1].x = zzrwotu.x;
				zapis_drug[i][1].y = zzrwotu.y;
			}
		}

		for (i = scierzka[h].poczatek; i <= scierzka[h].koniec; i++)
		{
			if (tab[pozycjaX + 1][i].stan == 2 || tab[pozycjaX + 1][i].stan == 3 || tab[pozycjaX + 1][i].stan == 4)
			{
				if (dozwrotu.dlugosc > zapis_drug[i][0].dlugosc)
				{
					dozwrotu.dlugosc = zapis_drug[i][0].dlugosc;
					dozwrotu._droga = zapis_drug[i][0]._droga;
					dozwrotu.x = zapis_drug[i][0].x;
					dozwrotu.y = zapis_drug[i][0].y;
				}
			}
			if (tab[pozycjaX - 1][i].stan == 2 || tab[pozycjaX - 1][i].stan == 3 || tab[pozycjaX - 1][i].stan == 4)
			{
				if (dozwrotu.dlugosc > zapis_drug[i][1].dlugosc)
				{
					dozwrotu.dlugosc = zapis_drug[i][1].dlugosc;
					dozwrotu._droga = zapis_drug[i][1]._droga;
					dozwrotu.x = zapis_drug[i][1].x;
					dozwrotu.y = zapis_drug[i][1].y;
				}
			}
		}
	}
	else
	{
		for (k = 0; k < 16; k++)
		{
			if (scierzka[k].waga < sciezka_temp.waga)
			{
				sciezka_temp.waga = scierzka[k].waga;
				sciezka_temp.numer = scierzka[k].numer;
				sciezka_temp.poczatek = scierzka[k].poczatek;
				sciezka_temp.koniec = scierzka[k].koniec;
			}
		}

		for (i = sciezka_temp.poczatek; i <= sciezka_temp.koniec; i++)
		{
			if (tab[sciezka_temp.numer + 1][i].stan == 2 || tab[sciezka_temp.numer + 1][i].stan == 3 || tab[sciezka_temp.numer + 1][i].stan == 4)
			{
				zzrwotu = oblicz(sciezka_temp.numer + 1, i);

				zapis_drug[i][0].dlugosc = zzrwotu.dlugosc;
				zapis_drug[i][0]._droga = zzrwotu._droga;
				zapis_drug[i][0].x = zzrwotu.x;
				zapis_drug[i][0].y = zzrwotu.y;
			}
			if (tab[sciezka_temp.numer - 1][i].stan == 2 || tab[sciezka_temp.numer - 1][i].stan == 3 || tab[sciezka_temp.numer - 1][i].stan == 4)
			{
				zzrwotu = oblicz(sciezka_temp.numer - 1, i);

				zapis_drug[i][1].dlugosc = zzrwotu.dlugosc;
				zapis_drug[i][1]._droga = zzrwotu._droga;
				zapis_drug[i][1].x = zzrwotu.x;
				zapis_drug[i][1].y = zzrwotu.y;
			}
		}

		for (i = sciezka_temp.poczatek; i <= sciezka_temp.koniec; i++)
		{
			if (tab[sciezka_temp.numer + 1][i].stan == 2 || tab[sciezka_temp.numer + 1][i].stan == 3 || tab[sciezka_temp.numer + 1][i].stan == 4)
			{
				if (dozwrotu.dlugosc > zapis_drug[i][0].dlugosc)
				{
					dozwrotu.dlugosc = zapis_drug[i][0].dlugosc;
					dozwrotu._droga = zapis_drug[i][0]._droga;
					dozwrotu.x = zapis_drug[i][0].x;
					dozwrotu.y = zapis_drug[i][0].y;
				}
			}

			if (tab[sciezka_temp.numer - 1][i].stan == 2 || tab[sciezka_temp.numer - 1][i].stan == 3 || tab[sciezka_temp.numer - 1][i].stan == 4)
			{
				if (dozwrotu.dlugosc > zapis_drug[i][1].dlugosc)
				{
					dozwrotu.dlugosc = zapis_drug[i][1].dlugosc;
					dozwrotu._droga = zapis_drug[i][1]._droga;
					dozwrotu.x = zapis_drug[i][1].x;
					dozwrotu.y = zapis_drug[i][1].y;
				}
			}
		}
	}

	return dozwrotu;
}

void idz() // alg||ytmy chodzenia trakt||a dla zadanej drogi
{
	int x, y, droga, i, j;

	glowna = znajdz();
	x = glowna.x;
	y = glowna.y;
	droga = glowna._droga;

	Sleep(100);

	if (droga == 100) //stój w miejscu
	{
		while (konrolka != 0);
		konrolka = 1;
		keybd_event(VkKeyScan('t'), 0, 0, 0);
		keybd_event(VkKeyScan('t'), 0, KEYEVENTF_KEYUP, 0);
		Sleep(50);
	}

	if (droga == 9 || droga == 10 || droga == 11 || droga == 12)
	{
		if (pozycjaX == 2 || pozycjaX == 5 || pozycjaX == 8 || pozycjaX == 11 || pozycjaX == 14 || pozycjaX == 17 || pozycjaX == 20 || pozycjaX == 23)
		{
			while (konrolka != 0);
			konrolka = 1;
			keybd_event(VkKeyScan('w'), 0, 0, 0);
			keybd_event(VkKeyScan('w'), 0, KEYEVENTF_KEYUP, 0);
			Sleep(50);
		}
		else
		{
			while (konrolka != 0);
			konrolka = 1;
			keybd_event(VkKeyScan('s'), 0, 0, 0);
			keybd_event(VkKeyScan('s'), 0, KEYEVENTF_KEYUP, 0);
			Sleep(50);
		}
		if (droga == 9)
		{
			i = abs(pozycjaY - y);
			for (j = 0; j < i; j++)
			{
				while (konrolka != 0);
				konrolka = 1;
				keybd_event(VkKeyScan('d'), 0, 0, 0);
				keybd_event(VkKeyScan('d'), 0, KEYEVENTF_KEYUP, 0);
				Sleep(50);
			}
		}
		if (droga == 10)
		{
			i = abs(pozycjaY - y);
			for (j = 0; j < i; j++)
			{
				while (konrolka != 0);
				konrolka = 1;
				keybd_event(VkKeyScan('d'), 0, 0, 0);
				keybd_event(VkKeyScan('d'), 0, KEYEVENTF_KEYUP, 0);
				Sleep(50);
			}
		}
		if (droga == 11)
		{
			i = abs(pozycjaY - y);
			for (j = 0; j < i; j++)
			{
				while (konrolka != 0);
				konrolka = 1;
				keybd_event(VkKeyScan('a'), 0, 0, 0);
				keybd_event(VkKeyScan('a'), 0, KEYEVENTF_KEYUP, 0);
				Sleep(50);
			}
		}
		if (droga == 12)
		{
			i = abs(pozycjaY - y);
			for (j = 0; j < i; j++)
			{
				while (konrolka != 0);
				konrolka = 1;
				keybd_event(VkKeyScan('a'), 0, 0, 0);
				keybd_event(VkKeyScan('a'), 0, KEYEVENTF_KEYUP, 0);
				Sleep(50);
			}
		}

		if (pozycjaX - x > 0)
		{
			while (konrolka != 0);
			konrolka = 1;
			keybd_event(VkKeyScan('p'), 0, 0, 0);
			keybd_event(VkKeyScan('p'), 0, KEYEVENTF_KEYUP, 0);
			while (konrolka != 0);
			konrolka = 1;
			keybd_event(VkKeyScan('o'), 0, 0, 0);
			keybd_event(VkKeyScan('o'), 0, KEYEVENTF_KEYUP, 0);
			while (konrolka != 0);
			konrolka = 1;
			keybd_event(VkKeyScan('t'), 0, 0, 0);
			keybd_event(VkKeyScan('t'), 0, KEYEVENTF_KEYUP, 0);
			Sleep(50);
		}
		else
		{
			while (konrolka != 0);
			konrolka = 1;
			keybd_event(VkKeyScan('l'), 0, 0, 0);
			keybd_event(VkKeyScan('l'), 0, KEYEVENTF_KEYUP, 0);
			while (konrolka != 0);
			konrolka = 1;
			keybd_event(VkKeyScan('k'), 0, 0, 0);
			keybd_event(VkKeyScan('k'), 0, KEYEVENTF_KEYUP, 0);
			while (konrolka != 0);
			konrolka = 1;
			keybd_event(VkKeyScan('t'), 0, 0, 0);
			keybd_event(VkKeyScan('t'), 0, KEYEVENTF_KEYUP, 0);
			Sleep(50);

		}
	}
	if (droga == 0 || droga == 1 || droga == 2 || droga == 13 || droga == 14 || droga == 15)
	{
		if (droga == 0 || droga == 13)
		{
			i = abs(pozycjaY - 1);
			for (j = i; j > 0; j--)
			{
				while (konrolka != 0);
				konrolka = 1;
				keybd_event(VkKeyScan('a'), 0, 0, 0);
				keybd_event(VkKeyScan('a'), 0, KEYEVENTF_KEYUP, 0);
				Sleep(50);
			}

			if (x == 2 || x == 5 || x == 8 || x == 11 || x == 14 || x == 17 || x == 20 || x == 23)
			{
				if (droga == 0)
				{
					i = abs(pozycjaX - x);
					for (j = i; j > 1; j--)
					{
						while (konrolka != 0);
						konrolka = 1;
						keybd_event(VkKeyScan('s'), 0, 0, 0);
						keybd_event(VkKeyScan('s'), 0, KEYEVENTF_KEYUP, 0);
						Sleep(50);
					}
				}
				else
				{
					i = abs(pozycjaX - x);
					for (j = i; j >= 0; j--)
					{
						while (konrolka != 0);
						konrolka = 1;
						keybd_event(VkKeyScan('w'), 0, 0, 0);
						keybd_event(VkKeyScan('w'), 0, KEYEVENTF_KEYUP, 0);
						Sleep(50);
					}
				}
			}
			else
			{
				if (droga == 0)
				{
					i = abs(pozycjaX - x);
					for (j = i; j >= 0; j--)
					{
						while (konrolka != 0);
						konrolka = 1;
						keybd_event(VkKeyScan('s'), 0, 0, 0);
						keybd_event(VkKeyScan('s'), 0, KEYEVENTF_KEYUP, 0);
						Sleep(50);
					}
				}
				else
				{
					i = abs(pozycjaX - x);
					for (j = i; j > 1; j--)
					{
						while (konrolka != 0);
						konrolka = 1;
						keybd_event(VkKeyScan('w'), 0, 0, 0);
						keybd_event(VkKeyScan('w'), 0, KEYEVENTF_KEYUP, 0);
						Sleep(50);
					}
				}
			}

			for (j = 1; j < y; j++)
			{
				while (konrolka != 0);
				konrolka = 1;
				keybd_event(VkKeyScan('d'), 0, 0, 0);
				keybd_event(VkKeyScan('d'), 0, KEYEVENTF_KEYUP, 0);
				Sleep(50);
			}

		}
		else if (droga == 1 || droga == 14)
		{
			i = abs(pozycjaY - 12);
			if (pozycjaY < 12)
			{
				for (j = i; j > 0; j--)
				{
					while (konrolka != 0);
					konrolka = 1;
					keybd_event(VkKeyScan('d'), 0, 0, 0);
					keybd_event(VkKeyScan('d'), 0, KEYEVENTF_KEYUP, 0);
					Sleep(50);
				}
			}
			else
			{
				for (j = i; j > 0; j--)
				{
					while (konrolka != 0);
					konrolka = 1;
					keybd_event(VkKeyScan('a'), 0, 0, 0);
					keybd_event(VkKeyScan('a'), 0, KEYEVENTF_KEYUP, 0);
					Sleep(50);
				}
			}

			if (x == 2 || x == 5 || x == 8 || x == 11 || x == 14 || x == 17 || x == 20 || x == 23)
			{
				if (droga == 1)
				{
					i = abs(pozycjaX - x);
					for (j = i; j > 1; j--)
					{
						while (konrolka != 0);
						konrolka = 1;
						keybd_event(VkKeyScan('s'), 0, 0, 0);
						keybd_event(VkKeyScan('s'), 0, KEYEVENTF_KEYUP, 0);
						Sleep(50);
					}
				}
				else
				{
					i = abs(pozycjaX - x);
					for (j = i; j >= 0; j--)
					{
						while (konrolka != 0);
						konrolka = 1;
						keybd_event(VkKeyScan('w'), 0, 0, 0);
						keybd_event(VkKeyScan('w'), 0, KEYEVENTF_KEYUP, 0);
						Sleep(50);
					}
				}
			}
			else
			{
				if (droga == 1)
				{
					i = abs(pozycjaX - x);
					for (j = i; j >= 0; j--)
					{
						while (konrolka != 0);
						konrolka = 1;
						keybd_event(VkKeyScan('s'), 0, 0, 0);
						keybd_event(VkKeyScan('s'), 0, KEYEVENTF_KEYUP, 0);
						Sleep(50);
					}
				}
				else
				{
					i = abs(pozycjaX - x);
					for (j = i; j > 1; j--)
					{
						while (konrolka != 0);
						konrolka = 1;
						keybd_event(VkKeyScan('w'), 0, 0, 0);
						keybd_event(VkKeyScan('w'), 0, KEYEVENTF_KEYUP, 0);
						Sleep(50);
					}
				}
			}

			if (12 < y)
			{
				for (j = 12; j < y; j++)
				{
					while (konrolka != 0);
					konrolka = 1;
					keybd_event(VkKeyScan('d'), 0, 0, 0);
					keybd_event(VkKeyScan('d'), 0, KEYEVENTF_KEYUP, 0);
					Sleep(50);
				}
			}
			else
			{
				for (j = 12; j > y; j--)
				{
					while (konrolka != 0);
					konrolka = 1;
					keybd_event(VkKeyScan('a'), 0, 0, 0);
					keybd_event(VkKeyScan('a'), 0, KEYEVENTF_KEYUP, 0);
					Sleep(50);
				}
			}
		}
		else
		{
			i = abs(pozycjaY - 23);
			for (j = i; j > 0; j--)
			{
				while (konrolka != 0);
				konrolka = 1;
				keybd_event(VkKeyScan('d'), 0, 0, 0);
				keybd_event(VkKeyScan('d'), 0, KEYEVENTF_KEYUP, 0);
				Sleep(50);
			}

			if (x == 2 || x == 5 || x == 8 || x == 11 || x == 14 || x == 17 || x == 20 || x == 23)
			{
				if (droga == 2)
				{
					i = abs(pozycjaX - x);
					for (j = i; j > 1; j--)
					{
						while (konrolka != 0);
						konrolka = 1;
						keybd_event(VkKeyScan('s'), 0, 0, 0);
						keybd_event(VkKeyScan('s'), 0, KEYEVENTF_KEYUP, 0);
						Sleep(50);
					}
				}
				else
				{
					i = abs(pozycjaX - x);
					for (j = i; j >= 0; j--)
					{
						while (konrolka != 0);
						konrolka = 1;
						keybd_event(VkKeyScan('w'), 0, 0, 0);
						keybd_event(VkKeyScan('w'), 0, KEYEVENTF_KEYUP, 0);
						Sleep(50);
					}
				}
			}
			else
			{
				if (droga == 2)
				{
					i = abs(pozycjaX - x);
					for (j = i; j >= 0; j--)
					{
						while (konrolka != 0);
						konrolka = 1;
						keybd_event(VkKeyScan('s'), 0, 0, 0);
						keybd_event(VkKeyScan('s'), 0, KEYEVENTF_KEYUP, 0);
						Sleep(50);
					}
				}
				else
				{
					i = abs(pozycjaX - x);
					for (j = i; j > 1; j--)
					{
						while (konrolka != 0);
						konrolka = 1;
						keybd_event(VkKeyScan('w'), 0, 0, 0);
						keybd_event(VkKeyScan('w'), 0, KEYEVENTF_KEYUP, 0);
						Sleep(50);
					}
				}
			}


			for (j = 23; j > y; j--)
			{
				while (konrolka != 0);
				konrolka = 1;
				keybd_event(VkKeyScan('a'), 0, 0, 0);
				keybd_event(VkKeyScan('a'), 0, KEYEVENTF_KEYUP, 0);
				Sleep(50);
			}
		}

		if (pozycjaX - x > 0)
		{
			while (konrolka != 0);
			konrolka = 1;
			keybd_event(VkKeyScan('p'), 0, 0, 0);
			keybd_event(VkKeyScan('p'), 0, KEYEVENTF_KEYUP, 0);
			while (konrolka != 0);
			konrolka = 1;
			keybd_event(VkKeyScan('o'), 0, 0, 0);
			keybd_event(VkKeyScan('o'), 0, KEYEVENTF_KEYUP, 0);
			while (konrolka != 0);
			konrolka = 1;
			keybd_event(VkKeyScan('t'), 0, 0, 0);
			keybd_event(VkKeyScan('t'), 0, KEYEVENTF_KEYUP, 0);
			Sleep(50);
		}
		else
		{
			while (konrolka != 0);
			konrolka = 1;
			keybd_event(VkKeyScan('l'), 0, 0, 0);
			keybd_event(VkKeyScan('l'), 0, KEYEVENTF_KEYUP, 0);
			while (konrolka != 0);
			konrolka = 1;
			keybd_event(VkKeyScan('k'), 0, 0, 0);
			keybd_event(VkKeyScan('k'), 0, KEYEVENTF_KEYUP, 0);
			while (konrolka != 0);
			konrolka = 1;
			keybd_event(VkKeyScan('t'), 0, 0, 0);
			keybd_event(VkKeyScan('t'), 0, KEYEVENTF_KEYUP, 0);
			Sleep(50);
		}
	}
	if (droga == 3 || droga == 4 || droga == 5 || droga == 6 || droga == 7 || droga == 8)
	{
		if (droga == 3 || droga == 6)
		{
			if (pozycjaX == 2 || pozycjaX == 5 || pozycjaX == 8 || pozycjaX == 11 || pozycjaX == 14 || pozycjaX == 17 || pozycjaX == 20 || pozycjaX == 23)
			{
				while (konrolka != 0);
				konrolka = 1;
				keybd_event(VkKeyScan('s'), 0, 0, 0);
				keybd_event(VkKeyScan('s'), 0, KEYEVENTF_KEYUP, 0);
				Sleep(50);
				while (konrolka != 0);
				konrolka = 1;
				keybd_event(VkKeyScan('s'), 0, 0, 0);
				keybd_event(VkKeyScan('s'), 0, KEYEVENTF_KEYUP, 0);
				Sleep(50);
			}
			else if (pozycjaX == 3 || pozycjaX == 6 || pozycjaX == 9 || pozycjaX == 12 || pozycjaX == 15 || pozycjaX == 18 || pozycjaX == 21 || pozycjaX == 24)
			{
				while (konrolka != 0);
				konrolka = 1;
				keybd_event(VkKeyScan('s'), 0, 0, 0);
				keybd_event(VkKeyScan('s'), 0, KEYEVENTF_KEYUP, 0);
				Sleep(50);
			}

			if (pozycjaY != 1)
			{
				i = abs(pozycjaY - 1);
				for (j = 0; j < i; j++)
				{
					while (konrolka != 0);
					konrolka = 1;
					keybd_event(VkKeyScan('a'), 0, 0, 0);
					keybd_event(VkKeyScan('a'), 0, KEYEVENTF_KEYUP, 0);
					Sleep(50);
				}
			}
			if (x == 2 || x == 5 || x == 8 || x == 11 || x == 14 || x == 17 || x == 20 || x == 23)
			{
				i = abs(pozycjaX - x);
				i = i - 1;
				for (j = 0; j < i; j++)
				{
					while (konrolka != 0);
					konrolka = 1;
					keybd_event(VkKeyScan('s'), 0, 0, 0);
					keybd_event(VkKeyScan('s'), 0, KEYEVENTF_KEYUP, 0);
					Sleep(50);
				}
			}
			else
			{
				i = abs(pozycjaX - x);
				i = i + 1;
				for (j = 0; j < i; j++)
				{
					while (konrolka != 0);
					konrolka = 1;
					keybd_event(VkKeyScan('s'), 0, 0, 0);
					keybd_event(VkKeyScan('s'), 0, KEYEVENTF_KEYUP, 0);
					Sleep(50);
				}
			}

			i = abs(pozycjaY - y);
			for (j = 0; j < i; j++)
			{
				while (konrolka != 0);
				konrolka = 1;
				keybd_event(VkKeyScan('d'), 0, 0, 0);
				keybd_event(VkKeyScan('d'), 0, KEYEVENTF_KEYUP, 0);
				Sleep(50);
			}

		}

		if (droga == 4 || droga == 7)
		{
			if (pozycjaX == 2 || pozycjaX == 5 || pozycjaX == 8 || pozycjaX == 11 || pozycjaX == 14 || pozycjaX == 17 || pozycjaX == 20 || pozycjaX == 23)
			{
				while (konrolka != 0);
				konrolka = 1;
				keybd_event(VkKeyScan('s'), 0, 0, 0);
				keybd_event(VkKeyScan('s'), 0, KEYEVENTF_KEYUP, 0);
				Sleep(50);
				while (konrolka != 0);
				konrolka = 1;
				keybd_event(VkKeyScan('s'), 0, 0, 0);
				keybd_event(VkKeyScan('s'), 0, KEYEVENTF_KEYUP, 0);
				Sleep(50);
			}
			else if (pozycjaX == 3 || pozycjaX == 6 || pozycjaX == 9 || pozycjaX == 12 || pozycjaX == 15 || pozycjaX == 18 || pozycjaX == 21 || pozycjaX == 24)
			{
				while (konrolka != 0);
				konrolka = 1;
				keybd_event(VkKeyScan('s'), 0, 0, 0);
				keybd_event(VkKeyScan('s'), 0, KEYEVENTF_KEYUP, 0);
				Sleep(50);
			}

			if (pozycjaY != 12)
			{
				i = abs(pozycjaY - 12);
				if (pozycjaY < 12)
				{
					for (j = 0; j < i; j++)
					{
						while (konrolka != 0);
						konrolka = 1;
						keybd_event(VkKeyScan('d'), 0, 0, 0);
						keybd_event(VkKeyScan('d'), 0, KEYEVENTF_KEYUP, 0);
						Sleep(50);
					}
				}
				else
				{
					for (j = 0; j < i; j++)
					{
						while (konrolka != 0);
						konrolka = 1;
						keybd_event(VkKeyScan('a'), 0, 0, 0);
						keybd_event(VkKeyScan('a'), 0, KEYEVENTF_KEYUP, 0);
						Sleep(50);
					}
				}

			}
			if (x == 2 || x == 5 || x == 8 || x == 11 || x == 14 || x == 17 || x == 20 || x == 23)
			{
				i = abs(pozycjaX - x);
				i = i - 1;
				for (j = 0; j < i; j++)
				{
					while (konrolka != 0);
					konrolka = 1;
					keybd_event(VkKeyScan('s'), 0, 0, 0);
					keybd_event(VkKeyScan('s'), 0, KEYEVENTF_KEYUP, 0);
					Sleep(50);
				}
			}
			else
			{
				i = abs(pozycjaX - x);
				i = i + 1;
				for (j = 0; j < i; j++)
				{
					while (konrolka != 0);
					konrolka = 1;
					keybd_event(VkKeyScan('s'), 0, 0, 0);
					keybd_event(VkKeyScan('s'), 0, KEYEVENTF_KEYUP, 0);
					Sleep(50);
				}
			}


			i = abs(pozycjaY - y);
			if (y < 12)
			{
				for (j = 0; j < i; j++)
				{
					while (konrolka != 0);
					konrolka = 1;
					keybd_event(VkKeyScan('a'), 0, 0, 0);
					keybd_event(VkKeyScan('a'), 0, KEYEVENTF_KEYUP, 0);
					Sleep(50);
				}
			}
			else
			{
				for (j = 0; j < i; j++)
				{
					while (konrolka != 0);
					konrolka = 1;
					keybd_event(VkKeyScan('d'), 0, 0, 0);
					keybd_event(VkKeyScan('d'), 0, KEYEVENTF_KEYUP, 0);
					Sleep(50);
				}
			}
		}

		if (droga == 5 || droga == 8)
		{
			if (pozycjaX == 2 || pozycjaX == 5 || pozycjaX == 8 || pozycjaX == 11 || pozycjaX == 14 || pozycjaX == 17 || pozycjaX == 20 || pozycjaX == 23)
			{
				while (konrolka != 0);
				konrolka = 1;
				keybd_event(VkKeyScan('s'), 0, 0, 0);
				keybd_event(VkKeyScan('s'), 0, KEYEVENTF_KEYUP, 0);
				Sleep(50);
				while (konrolka != 0);
				konrolka = 1;
				keybd_event(VkKeyScan('s'), 0, 0, 0);
				keybd_event(VkKeyScan('s'), 0, KEYEVENTF_KEYUP, 0);
				Sleep(50);
			}
			else if (pozycjaX == 3 || pozycjaX == 6 || pozycjaX == 9 || pozycjaX == 12 || pozycjaX == 15 || pozycjaX == 18 || pozycjaX == 21 || pozycjaX == 24)
			{
				while (konrolka != 0);
				konrolka = 1;
				keybd_event(VkKeyScan('s'), 0, 0, 0);
				keybd_event(VkKeyScan('s'), 0, KEYEVENTF_KEYUP, 0);
				Sleep(50);
			}

			if (pozycjaY != 23)
			{
				i = abs(pozycjaY - 23);
				for (j = 0; j < i; j++)
				{
					while (konrolka != 0);
					konrolka = 1;
					keybd_event(VkKeyScan('d'), 0, 0, 0);
					keybd_event(VkKeyScan('d'), 0, KEYEVENTF_KEYUP, 0);
					Sleep(50);
				}
			}

			if (x == 2 || x == 5 || x == 8 || x == 11 || x == 14 || x == 17 || x == 20 || x == 23)
			{
				i = abs(pozycjaX - x);
				i = i - 1;
				for (j = 0; j < i; j++)
				{
					while (konrolka != 0);
					konrolka = 1;
					keybd_event(VkKeyScan('s'), 0, 0, 0);
					keybd_event(VkKeyScan('s'), 0, KEYEVENTF_KEYUP, 0);
					Sleep(50);
				}
			}
			else
			{
				i = abs(pozycjaX - x);
				i = i + 1;
				for (j = 0; j < i; j++)
				{
					while (konrolka != 0);
					konrolka = 1;
					keybd_event(VkKeyScan('s'), 0, 0, 0);
					keybd_event(VkKeyScan('s'), 0, KEYEVENTF_KEYUP, 0);
					Sleep(50);
				}
			}


			i = abs(pozycjaY - y);
			for (j = 0; j < i; j++)
			{
				while (konrolka != 0);
				konrolka = 1;
				keybd_event(VkKeyScan('a'), 0, 0, 0);
				keybd_event(VkKeyScan('a'), 0, KEYEVENTF_KEYUP, 0);
				Sleep(50);
			}

		}

		if (pozycjaX - x > 0)
		{
			while (konrolka != 0);
			konrolka = 1;
			keybd_event(VkKeyScan('p'), 0, 0, 0);
			keybd_event(VkKeyScan('p'), 0, KEYEVENTF_KEYUP, 0);
			while (konrolka != 0);
			konrolka = 1;
			keybd_event(VkKeyScan('o'), 0, 0, 0);
			keybd_event(VkKeyScan('o'), 0, KEYEVENTF_KEYUP, 0);
			while (konrolka != 0);
			konrolka = 1;
			keybd_event(VkKeyScan('t'), 0, 0, 0);
			keybd_event(VkKeyScan('t'), 0, KEYEVENTF_KEYUP, 0);
			Sleep(50);
		}
		else
		{
			while (konrolka != 0);
			konrolka = 1;
			keybd_event(VkKeyScan('l'), 0, 0, 0);
			keybd_event(VkKeyScan('l'), 0, KEYEVENTF_KEYUP, 0);
			while (konrolka != 0);
			konrolka = 1;
			keybd_event(VkKeyScan('k'), 0, 0, 0);
			keybd_event(VkKeyScan('k'), 0, KEYEVENTF_KEYUP, 0);
			while (konrolka != 0);
			konrolka = 1;
			keybd_event(VkKeyScan('t'), 0, 0, 0);
			keybd_event(VkKeyScan('t'), 0, KEYEVENTF_KEYUP, 0);
			Sleep(50);
		}
	}
	if (droga == 16 || droga == 17 || droga == 18 || droga == 19 || droga == 20 || droga == 21)
	{
		if (droga == 16 || droga == 19)
		{
			if (pozycjaX == 2 || pozycjaX == 5 || pozycjaX == 8 || pozycjaX == 11 || pozycjaX == 14 || pozycjaX == 17 || pozycjaX == 20 || pozycjaX == 23)
			{
				while (konrolka != 0);
				konrolka = 1;
				keybd_event(VkKeyScan('w'), 0, 0, 0);
				keybd_event(VkKeyScan('w'), 0, KEYEVENTF_KEYUP, 0);
				Sleep(50);
			}
			else if (pozycjaX == 3 || pozycjaX == 6 || pozycjaX == 9 || pozycjaX == 12 || pozycjaX == 15 || pozycjaX == 18 || pozycjaX == 21 || pozycjaX == 24)
			{
				while (konrolka != 0);
				konrolka = 1;
				keybd_event(VkKeyScan('w'), 0, 0, 0);
				keybd_event(VkKeyScan('w'), 0, KEYEVENTF_KEYUP, 0);
				Sleep(50);
				while (konrolka != 0);
				konrolka = 1;
				keybd_event(VkKeyScan('w'), 0, 0, 0);
				keybd_event(VkKeyScan('w'), 0, KEYEVENTF_KEYUP, 0);
				Sleep(50);
			}

			if (pozycjaY != 1)
			{
				i = abs(pozycjaY - 1);
				for (j = 0; j < i; j++)
				{
					while (konrolka != 0);
					konrolka = 1;
					keybd_event(VkKeyScan('a'), 0, 0, 0);
					keybd_event(VkKeyScan('a'), 0, KEYEVENTF_KEYUP, 0);
					Sleep(50);
				}
			}
			if (x == 2 || x == 5 || x == 8 || x == 11 || x == 14 || x == 17 || x == 20 || x == 23)
			{
				i = abs(pozycjaX - x);
				i = i + 1;
				for (j = 0; j < i; j++)
				{
					while (konrolka != 0);
					konrolka = 1;
					keybd_event(VkKeyScan('w'), 0, 0, 0);
					keybd_event(VkKeyScan('w'), 0, KEYEVENTF_KEYUP, 0);
					Sleep(50);
				}
			}
			else
			{
				i = abs(pozycjaX - x);
				i = i - 1;
				for (j = 0; j < i; j++)
				{
					while (konrolka != 0);
					konrolka = 1;
					keybd_event(VkKeyScan('w'), 0, 0, 0);
					keybd_event(VkKeyScan('w'), 0, KEYEVENTF_KEYUP, 0);
					Sleep(50);
				}
			}


			i = abs(pozycjaY - y);
			for (j = 0; j < i; j++)
			{
				while (konrolka != 0);
				konrolka = 1;
				keybd_event(VkKeyScan('d'), 0, 0, 0);
				keybd_event(VkKeyScan('d'), 0, KEYEVENTF_KEYUP, 0);
				Sleep(50);
			}

		}

		if (droga == 17 || droga == 20)
		{
			if (pozycjaX == 2 || pozycjaX == 5 || pozycjaX == 8 || pozycjaX == 11 || pozycjaX == 14 || pozycjaX == 17 || pozycjaX == 20 || pozycjaX == 23)
			{
				while (konrolka != 0);
				konrolka = 1;
				keybd_event(VkKeyScan('w'), 0, 0, 0);
				keybd_event(VkKeyScan('w'), 0, KEYEVENTF_KEYUP, 0);
				Sleep(50);
			}
			else if (pozycjaX == 3 || pozycjaX == 6 || pozycjaX == 9 || pozycjaX == 12 || pozycjaX == 15 || pozycjaX == 18 || pozycjaX == 21 || pozycjaX == 24)
			{
				while (konrolka != 0);
				konrolka = 1;
				keybd_event(VkKeyScan('w'), 0, 0, 0);
				keybd_event(VkKeyScan('w'), 0, KEYEVENTF_KEYUP, 0);
				Sleep(50);
				while (konrolka != 0);
				konrolka = 1;
				keybd_event(VkKeyScan('w'), 0, 0, 0);
				keybd_event(VkKeyScan('w'), 0, KEYEVENTF_KEYUP, 0);
				Sleep(50);
			}

			if (pozycjaY != 12)
			{
				i = abs(pozycjaY - 12);

				if (pozycjaY < 12)
				{
					for (j = 0; j < i; j++)
					{
						while (konrolka != 0);
						konrolka = 1;
						keybd_event(VkKeyScan('d'), 0, 0, 0);
						keybd_event(VkKeyScan('d'), 0, KEYEVENTF_KEYUP, 0);
						Sleep(50);
					}
				}
				else
				{
					for (j = 0; j < i; j++)
					{
						while (konrolka != 0);
						konrolka = 1;
						keybd_event(VkKeyScan('a'), 0, 0, 0);
						keybd_event(VkKeyScan('a'), 0, KEYEVENTF_KEYUP, 0);
						Sleep(50);
					}
				}

			}
			if (x == 2 || x == 5 || x == 8 || x == 11 || x == 14 || x == 17 || x == 20 || x == 23)
			{
				i = abs(pozycjaX - x);
				i = i + 1;
				for (j = 0; j < i; j++)
				{
					while (konrolka != 0);
					konrolka = 1;
					keybd_event(VkKeyScan('w'), 0, 0, 0);
					keybd_event(VkKeyScan('w'), 0, KEYEVENTF_KEYUP, 0);
					Sleep(50);
				}
			}
			else
			{
				i = abs(pozycjaX - x);
				i = i - 1;
				for (j = 0; j < i; j++)
				{
					while (konrolka != 0);
					konrolka = 1;
					keybd_event(VkKeyScan('w'), 0, 0, 0);
					keybd_event(VkKeyScan('w'), 0, KEYEVENTF_KEYUP, 0);
					Sleep(50);
				}
			}


			i = abs(pozycjaY - y);
			if (y < 12)
			{
				for (j = 0; j < i; j++)
				{
					while (konrolka != 0);
					konrolka = 1;
					keybd_event(VkKeyScan('a'), 0, 0, 0);
					keybd_event(VkKeyScan('a'), 0, KEYEVENTF_KEYUP, 0);
					Sleep(50);
				}
			}
			else
			{
				for (j = 0; j < i; j++)
				{
					while (konrolka != 0);
					konrolka = 1;
					keybd_event(VkKeyScan('d'), 0, 0, 0);
					keybd_event(VkKeyScan('d'), 0, KEYEVENTF_KEYUP, 0);
					Sleep(50);
				}
			}

		}

		if (droga == 18 || droga == 21)
		{
			if (pozycjaX == 2 || pozycjaX == 5 || pozycjaX == 8 || pozycjaX == 11 || pozycjaX == 14 || pozycjaX == 17 || pozycjaX == 20 || pozycjaX == 23)
			{
				while (konrolka != 0);
				konrolka = 1;
				keybd_event(VkKeyScan('w'), 0, 0, 0);
				keybd_event(VkKeyScan('w'), 0, KEYEVENTF_KEYUP, 0);
				Sleep(50);
			}
			else if (pozycjaX == 3 || pozycjaX == 6 || pozycjaX == 9 || pozycjaX == 12 || pozycjaX == 15 || pozycjaX == 18 || pozycjaX == 21 || pozycjaX == 24)
			{
				while (konrolka != 0);
				konrolka = 1;
				keybd_event(VkKeyScan('w'), 0, 0, 0);
				keybd_event(VkKeyScan('w'), 0, KEYEVENTF_KEYUP, 0);
				Sleep(50);
				while (konrolka != 0);
				konrolka = 1;
				keybd_event(VkKeyScan('w'), 0, 0, 0);
				keybd_event(VkKeyScan('w'), 0, KEYEVENTF_KEYUP, 0);
				Sleep(50);
			}

			if (pozycjaY != 23)
			{
				i = abs(pozycjaY - 23);
				for (j = 0; j < i; j++)
				{
					while (konrolka != 0);
					konrolka = 1;
					keybd_event(VkKeyScan('d'), 0, 0, 0);
					keybd_event(VkKeyScan('d'), 0, KEYEVENTF_KEYUP, 0);
					Sleep(50);
				}
			}
			if (x == 2 || x == 5 || x == 8 || x == 11 || x == 14 || x == 17 || x == 20 || x == 23)
			{
				i = abs(pozycjaX - x);
				i = i + 1;
				for (j = 0; j < i; j++)
				{
					while (konrolka != 0);
					konrolka = 1;
					keybd_event(VkKeyScan('w'), 0, 0, 0);
					keybd_event(VkKeyScan('w'), 0, KEYEVENTF_KEYUP, 0);
					Sleep(50);
				}
			}
			else
			{
				i = abs(pozycjaX - x);
				i = i - 1;
				for (j = 0; j < i; j++)
				{
					while (konrolka != 0);
					konrolka = 1;
					keybd_event(VkKeyScan('w'), 0, 0, 0);
					keybd_event(VkKeyScan('w'), 0, KEYEVENTF_KEYUP, 0);
					Sleep(50);
				}
			}


			i = abs(pozycjaY - y);
			for (j = 0; j < i; j++)
			{
				while (konrolka != 0);
				konrolka = 1;
				keybd_event(VkKeyScan('a'), 0, 0, 0);
				keybd_event(VkKeyScan('a'), 0, KEYEVENTF_KEYUP, 0);
				Sleep(50);
			}
		}

		if (pozycjaX - x > 0)
		{
			while (konrolka != 0);
			konrolka = 1;
			keybd_event(VkKeyScan('p'), 0, 0, 0);
			keybd_event(VkKeyScan('p'), 0, KEYEVENTF_KEYUP, 0);
			while (konrolka != 0);
			konrolka = 1;
			keybd_event(VkKeyScan('o'), 0, 0, 0);
			keybd_event(VkKeyScan('o'), 0, KEYEVENTF_KEYUP, 0);
			while (konrolka != 0);
			konrolka = 1;
			keybd_event(VkKeyScan('t'), 0, 0, 0);
			keybd_event(VkKeyScan('t'), 0, KEYEVENTF_KEYUP, 0);
			Sleep(50);
		}
		else
		{
			while (konrolka != 0);
			konrolka = 1;
			keybd_event(VkKeyScan('l'), 0, 0, 0);
			keybd_event(VkKeyScan('l'), 0, KEYEVENTF_KEYUP, 0);
			while (konrolka != 0);
			konrolka = 1;
			keybd_event(VkKeyScan('k'), 0, 0, 0);
			keybd_event(VkKeyScan('k'), 0, KEYEVENTF_KEYUP, 0);
			while (konrolka != 0);
			konrolka = 1;
			keybd_event(VkKeyScan('t'), 0, 0, 0);
			keybd_event(VkKeyScan('t'), 0, KEYEVENTF_KEYUP, 0);
			Sleep(50);
		}

	}
	if (droga == 22 || droga == 23)
	{
		if (droga == 22)
		{
			i = abs(pozycjaY - y);
			for (i; i > 0; i--)
			{
				while (konrolka != 0);
				konrolka = 1;
				keybd_event(VkKeyScan('d'), 0, 0, 0);
				keybd_event(VkKeyScan('d'), 0, KEYEVENTF_KEYUP, 0);
				Sleep(50);
			}
		}
		else
		{
			i = abs(pozycjaY - y);
			for (i; i > 0; i--)
			{
				while (konrolka != 0);
				konrolka = 1;
				keybd_event(VkKeyScan('a'), 0, 0, 0);
				keybd_event(VkKeyScan('a'), 0, KEYEVENTF_KEYUP, 0);
				Sleep(50);
			}

		}
		if (pozycjaX - x > 0)
		{
			while (konrolka != 0);
			konrolka = 1;
			keybd_event(VkKeyScan('p'), 0, 0, 0);
			keybd_event(VkKeyScan('p'), 0, KEYEVENTF_KEYUP, 0);
			while (konrolka != 0);
			konrolka = 1;
			keybd_event(VkKeyScan('o'), 0, 0, 0);
			keybd_event(VkKeyScan('o'), 0, KEYEVENTF_KEYUP, 0);
			while (konrolka != 0);
			konrolka = 1;
			keybd_event(VkKeyScan('t'), 0, 0, 0);
			keybd_event(VkKeyScan('t'), 0, KEYEVENTF_KEYUP, 0);
			Sleep(50);
		}
		else
		{
			while (konrolka != 0);
			konrolka = 1;
			keybd_event(VkKeyScan('l'), 0, 0, 0);
			keybd_event(VkKeyScan('l'), 0, KEYEVENTF_KEYUP, 0);
			while (konrolka != 0);
			konrolka = 1;
			keybd_event(VkKeyScan('k'), 0, 0, 0);
			keybd_event(VkKeyScan('k'), 0, KEYEVENTF_KEYUP, 0);
			while (konrolka != 0);
			konrolka = 1;
			keybd_event(VkKeyScan('t'), 0, 0, 0);
			keybd_event(VkKeyScan('t'), 0, KEYEVENTF_KEYUP, 0);
			Sleep(50);
		}
	}
	if (droga == 24)
	{
		if (pozycjaX - x > 0)
		{
			while (konrolka != 0);
			konrolka = 1;
			keybd_event(VkKeyScan('p'), 0, 0, 0);
			keybd_event(VkKeyScan('p'), 0, KEYEVENTF_KEYUP, 0);
			while (konrolka != 0);
			konrolka = 1;
			keybd_event(VkKeyScan('o'), 0, 0, 0);
			keybd_event(VkKeyScan('o'), 0, KEYEVENTF_KEYUP, 0);
			while (konrolka != 0);
			konrolka = 1;
			keybd_event(VkKeyScan('t'), 0, 0, 0);
			keybd_event(VkKeyScan('t'), 0, KEYEVENTF_KEYUP, 0);
			Sleep(50);
		}
		else
		{
			while (konrolka != 0);
			konrolka = 1;
			keybd_event(VkKeyScan('l'), 0, 0, 0);
			keybd_event(VkKeyScan('l'), 0, KEYEVENTF_KEYUP, 0);
			while (konrolka != 0);
			konrolka = 1;
			keybd_event(VkKeyScan('k'), 0, 0, 0);
			keybd_event(VkKeyScan('k'), 0, KEYEVENTF_KEYUP, 0);
			while (konrolka != 0);
			konrolka = 1;
			keybd_event(VkKeyScan('t'), 0, 0, 0);
			keybd_event(VkKeyScan('t'), 0, KEYEVENTF_KEYUP, 0);
			Sleep(50);
		}
	}
}

void ustaw_stan() // stan dla roslin przed updatemapa
{
	int i, j;

	for (i = 2; i <= 23; i++)
	{
		for (j = 2; j < 23; j++)
		{
			if (i != 4 && i != 7 && i != 10 && i != 13 && i != 16 && i != 19 && i != 22 && j != 12)
			{

				if (tab[i][j].stan == 5)
				{
					if (czas - tab[i][j].sadzonka > 0)
					{
						tab[i][j].stan = 1;
						tab[i][j].zycie = czas;
						tab[i][j].woda = czas;
						tab[i][j].nawoz = czas;
						mapa[i][j] = 'R';
					}
				}
				if (tab[i][j].rodzaj == 1)
				{
					if ((czas - tab[i][j].woda > 60 || czas - tab[i][j].nawoz > 60) && (tab[i][j].stan != 5 && tab[i][j].stan != 6))
					{
						tab[i][j].stan = 0;
						mapa[i][j] = 'X';
					}

					if (tab[i][j].stan != 0 && tab[i][j].stan != 5)
					{

						if (tab[i][j].stan == 1 && czas - tab[i][j].zycie > 60)
						{
							tab[i][j].stan = 6;
							mapa[i][j] = 'G';
						}

						if (tab[i][j].stan != 4 && tab[i][j].stan != 6)
						{

							if ((czas - tab[i][j].woda) > 20)
							{
								if (tab[i][j].stan != 3)
								{
									tab[i][j].stan = 2;
								}
								else
								{
									tab[i][j].stan = 4;
								}

							}
							if ((czas - tab[i][j].nawoz) > 30)
							{
								if (tab[i][j].stan != 2)
								{
									tab[i][j].stan = 3;
								}
								else
								{
									tab[i][j].stan = 4;
								}

							}
						}
					}
				}
				else if (tab[i][j].rodzaj == 2)
				{
					if ((czas - tab[i][j].woda > 60 || czas - tab[i][j].nawoz > 60) && (tab[i][j].stan != 5 && tab[i][j].stan != 6))
					{
						tab[i][j].stan = 0;
						mapa[i][j] = 'X';
					}

					if (tab[i][j].stan != 0 && tab[i][j].stan != 5)
					{

						if (tab[i][j].stan == 1 && czas - tab[i][j].zycie > 70)
						{
							tab[i][j].stan = 6;
							mapa[i][j] = 'G';
						}

						if (tab[i][j].stan != 4 && tab[i][j].stan != 6)
						{

							if ((czas - tab[i][j].woda) > 30)
							{
								if (tab[i][j].stan != 3)
								{
									tab[i][j].stan = 2;
								}
								else
								{
									tab[i][j].stan = 4;
								}

							}
							if ((czas - tab[i][j].nawoz) > 35)
							{
								if (tab[i][j].stan != 2)
								{
									tab[i][j].stan = 3;
								}
								else
								{
									tab[i][j].stan = 4;
								}

							}
						}
					}

				}
				else if (tab[i][j].rodzaj == 3)
				{
					if ((czas - tab[i][j].woda > 60 || czas - tab[i][j].nawoz > 80) && (tab[i][j].stan != 5 && tab[i][j].stan != 6))
					{
						tab[i][j].stan = 0;
						mapa[i][j] = 'X';
					}

					if (tab[i][j].stan != 0 && tab[i][j].stan != 5)
					{

						if (tab[i][j].stan == 1 && czas - tab[i][j].zycie > 90)
						{
							tab[i][j].stan = 6;
							mapa[i][j] = 'G';
						}

						if (tab[i][j].stan != 4 && tab[i][j].stan != 6)
						{

							if ((czas - tab[i][j].woda) > 25)
							{
								if (tab[i][j].stan != 3)
								{
									tab[i][j].stan = 2;
								}
								else
								{
									tab[i][j].stan = 4;
								}

							}
							if ((czas - tab[i][j].nawoz) > 50)
							{
								if (tab[i][j].stan != 2)
								{
									tab[i][j].stan = 3;
								}
								else
								{
									tab[i][j].stan = 4;
								}

							}
						}
					}

				}
				else
				{
					if ((czas - tab[i][j].woda > 100 || czas - tab[i][j].nawoz > 120) && (tab[i][j].stan != 5 && tab[i][j].stan != 6))
					{
						tab[i][j].stan = 0;
						mapa[i][j] = 'X';
					}

					if (tab[i][j].stan != 0 && tab[i][j].stan != 5)
					{

						if (tab[i][j].stan == 1 && czas - tab[i][j].zycie > 180)
						{
							tab[i][j].stan = 6;
							mapa[i][j] = 'G';
						}

						if (tab[i][j].stan != 4 && tab[i][j].stan != 6)
						{

							if ((czas - tab[i][j].woda) > 45)
							{
								if (tab[i][j].stan != 3)
								{
									tab[i][j].stan = 2;
								}
								else
								{
									tab[i][j].stan = 4;
								}

							}
							if ((czas - tab[i][j].nawoz) > 70)
							{
								if (tab[i][j].stan != 2)
								{
									tab[i][j].stan = 3;
								}
								else
								{
									tab[i][j].stan = 4;
								}

							}
						}
					}

				}
			}
		}
	}
}

void updateMapa()
{
	ustaw_stan();
	COORD cur = { 0, 0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
	ilosc_roslin = 0;
	ilosc_plonow = 0;
	ilosc_trupow = 0;
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			if (mapa[i][j] == 'R' && tab[i][j].stan == 1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);//jest_ok
				cout << mapa[i][j];
				ilosc_roslin++;
			}
			else if (mapa[i][j] == 'R' && tab[i][j].stan == 2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x06A);//potrzebuje_wody
				cout << mapa[i][j];
				ilosc_roslin++;
			}
			else if (mapa[i][j] == 'R' && tab[i][j].stan == 3)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xE);//potrzebuje_nawozu
				cout << mapa[i][j];
				ilosc_roslin++;
			}
			else if (mapa[i][j] == 'R' && tab[i][j].stan == 4)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 366);//potrzebuje_wody_i_nawozu
				cout << mapa[i][j];
				ilosc_roslin++;
			}
			else if (mapa[i][j] == 'S' && tab[i][j].stan == 5)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00F);//sadzonka
				cout << mapa[i][j];
			}
			else if (mapa[i][j] == 'G' && tab[i][j].stan == 6)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				cout << mapa[i][j];
				ilosc_plonow++;
			}
			else if (mapa[i][j] == 'X' && tab[i][j].stan == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xC);//roślina_jest_martwa
				cout << mapa[i][j];
				ilosc_trupow++;
			}
			else if (mapa[i][j] == 'T')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 70);//traktor
				cout << mapa[i][j];
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);//pole+płot
				cout << mapa[i][j];
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		cout << '\n';
	}
	stop = clock();
	czas = (stop - start) / (double)CLOCKS_PER_SEC;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00F);
	cout << (int)czas << '\n' << ilosc_roslin << (char)" roslin" << '\n' << ilosc_trupow << (char)" martwych roslin" << '\n' << ilosc_plonow << (char)" planow" << '\n' << paliwo << (char)" zuzyte paliwo ";
	cout << glowna._droga << ' ' << h << ' ' << scierzka[0].waga << ' ' << scierzka[1].waga << ' ' << scierzka[2].waga << ' ' << scierzka[3].waga << ' ' << scierzka[4].waga << ' ' << scierzka[5].waga << ' ' << scierzka[6].waga << ' ' << scierzka[7].waga << ' ' << scierzka[8].waga << ' ' << scierzka[9].waga << ' ' << scierzka[10].waga << ' ' << scierzka[11].waga << ' ' << scierzka[12].waga << ' ' << scierzka[13].waga << ' ' << scierzka[14].waga << ' ' << scierzka[15].waga << ' ' << sciezka_temp.numer << ' ' << sciezka_temp.waga;
}
////////////////////////////////////////////////////////////////////////////////

//wątek_odświeżający_konsolę_co_1ms/////////////////////////////
void Odswiez(void* data)
{
	//printf("_beginthread %d \n", GetCurrentThreadId());
	do
	{
		updateMapa();
	} while (gra != FALSE);
	_endthread();
}
/////////////////////////////////////////////////////////////////

void Chodz(void* data)
{
	do
	{
		idz();
	} while (gra != FALSE);
	_endthread();
}

//widoczność_kursora/////////////////////////////////
void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}
/////////////////////////////////////////////////////


//działania_traktora///////////////////////////////////
void dzialanie(char klikniecie)
{
	//....................W
	if (klikniecie == 'w')
	{
		if (mapa[pozycjaX - 1][pozycjaY] == '.')
		{
			mapa[pozycjaX][pozycjaY] = '.';
			pozycjaX = pozycjaX - 1;
			mapa[pozycjaX][pozycjaY] = 'T';
			paliwo = paliwo + 1;
		}
	}

	//....................S
	if (klikniecie == 's')
	{
		if (mapa[pozycjaX + 1][pozycjaY] == '.')
		{
			mapa[pozycjaX][pozycjaY] = '.';
			pozycjaX = pozycjaX + 1;
			mapa[pozycjaX][pozycjaY] = 'T';
			paliwo = paliwo + 1;
		}
	}

	//....................A
	if (klikniecie == 'a')
	{
		if (mapa[pozycjaX][pozycjaY - 1] == '.')
		{
			mapa[pozycjaX][pozycjaY] = '.';
			pozycjaY = pozycjaY - 1;
			mapa[pozycjaX][pozycjaY] = 'T';
			paliwo = paliwo + 1;

		}
	}

	//....................D
	if (klikniecie == 'd')
	{
		if (mapa[pozycjaX][pozycjaY + 1] == '.')
		{
			mapa[pozycjaX][pozycjaY] = '.';
			pozycjaY = pozycjaY + 1;
			mapa[pozycjaX][pozycjaY] = 'T';
			paliwo = paliwo + 1;

		}
	}

	//....................P
	if (klikniecie == 'p')
	{
		if (mapa[pozycjaX - 1][pozycjaY] == 'R' && (tab[pozycjaX - 1][pozycjaY].stan == 2 || tab[pozycjaX - 1][pozycjaY].stan == 4))
		{
			if (tab[pozycjaX - 1][pozycjaY].stan == 2)
			{
				tab[pozycjaX - 1][pozycjaY].stan = 1;
				tab[pozycjaX - 1][pozycjaY].woda = czas;
			}

			if (tab[pozycjaX - 1][pozycjaY].stan == 4)
			{
				tab[pozycjaX - 1][pozycjaY].stan = 3;
				tab[pozycjaX - 1][pozycjaY].woda = czas;
			}
		}
	}
	if (klikniecie == 'l')
	{
		if (tab[pozycjaX + 1][pozycjaY].stan == 2 || tab[pozycjaX + 1][pozycjaY].stan == 4)
		{
			if (tab[pozycjaX + 1][pozycjaY].stan == 2)
			{
				tab[pozycjaX + 1][pozycjaY].stan = 1;
				tab[pozycjaX + 1][pozycjaY].woda = czas;
			}
			if (tab[pozycjaX + 1][pozycjaY].stan == 4)
			{
				tab[pozycjaX + 1][pozycjaY].stan = 3;
				tab[pozycjaX + 1][pozycjaY].woda = czas;
			}
		}
	}
	if (klikniecie == 'o')
	{
		if (tab[pozycjaX - 1][pozycjaY].stan == 3 || tab[pozycjaX - 1][pozycjaY].stan == 4)
		{
			if (tab[pozycjaX - 1][pozycjaY].stan == 3)
			{
				tab[pozycjaX - 1][pozycjaY].stan = 1;
				tab[pozycjaX - 1][pozycjaY].nawoz = czas;
			}

			if (tab[pozycjaX - 1][pozycjaY].stan == 4)
			{
				tab[pozycjaX - 1][pozycjaY].stan = 2;
				tab[pozycjaX - 1][pozycjaY].nawoz = czas;
			}
		}
	}
	if (klikniecie == 'k')
	{
		if (tab[pozycjaX + 1][pozycjaY].stan == 3 || tab[pozycjaX + 1][pozycjaY].stan == 4)
		{
			if (tab[pozycjaX + 1][pozycjaY].stan == 3)
			{
				tab[pozycjaX + 1][pozycjaY].stan = 1;
				tab[pozycjaX + 1][pozycjaY].nawoz = czas;
			}
			if (tab[pozycjaX + 1][pozycjaY].stan == 4)
			{
				tab[pozycjaX + 1][pozycjaY].stan = 2;
				tab[pozycjaX + 1][pozycjaY].nawoz = czas;
			}
		}
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////
