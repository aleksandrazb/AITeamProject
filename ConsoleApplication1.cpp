#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include <thread>
#include <cmath>
#include <string>
#include <string.h>
#include <winnt.h>
#include "pch.h"
#include<wtypes.h>
#include<WTypesbase.h>
#include<process.h>
#include<conio.h>
using namespace std;

int main()
{
	/*wyłączenie_kursora*/ShowConsoleCursor(false);
	int i, j, k = 0, q = 1, w = 2, e = 11;  //q,w,e - zmienne do ustawienia scieżki;
	int tab_temp[7];

	//szkielet mapy//////////////////////
	for (i = 0; i < 25; i++)
	{
		mapa[0][i] = '#';
		mapa[i][0] = '#';
		mapa[24][i] = '#';
		mapa[i][24] = '#';
	}
	for (i = 1; i < 24; i++)
	{
		for (j = 1; j < 24; j++)
		{
			mapa[i][j] = '.';
		}
	}

	for (i = 0; i <= 7; i++) // losowanie rodzaju rosliny dla drogi
	{
		tab_temp[i] = rand() % 4;
	}

	for (i = 0; i < 16; i++) //numer scieżki
	{
		scierzka[i].numer = q;
		scierzka[i].poczatek = w;
		scierzka[i].koniec = e;

		if (w == 2)
		{
			w = 13;
			e = 22;
		}
		else
		{
			w = 2;
			e = 11;
		}

		if (i % 2 != 0 && i != 0)
		{
			q = q + 3;
		}
	}


	for (i = 2; i <= 23; i++)
	{
		for (j = 2; j < 23; j++)
		{
			if (i != 4 && i != 7 && i != 10 && i != 13 && i != 16 && i != 19 && i != 22 && j != 12)
			{
				mapa[i][j] = 'S';
				tab[i][j].x = i;
				tab[i][j].y = j;
				tab[i][j].stan = 5;
				tab[i][j].woda = 0;
				tab[i][j].nawoz = 0;
				tab[i][j].zycie = 0;
				tab[i][j].sadzonka = rand() % 240;
				if (i == 2)
				{
					tab[i][j].rodzaj = tab_temp[0];
				}
				if (i == 3 or i == 5)
				{
					tab[i][j].rodzaj = tab_temp[1];
				}
				if (i == 6 or i == 8)
				{
					tab[i][j].rodzaj = tab_temp[2];
				}
				if (i == 9 or i == 11)
				{
					tab[i][j].rodzaj = tab_temp[3];
				}
				if (i == 12 or i == 14)
				{
					tab[i][j].rodzaj = tab_temp[4];
				}
				if (i == 15 or i == 17)
				{
					tab[i][j].rodzaj = tab_temp[5];
				}
				if (i == 18 or i == 20)
				{
					tab[i][j].rodzaj = tab_temp[6];
				}
				if (i == 21 or i == 23)
				{
					tab[i][j].rodzaj = tab_temp[7];
				}
				k++; //spr
			}
		}
	}

	for (i = 2; i <= 23; i++)
	{
		for (j = 2; j < 23; j++)
		{
			if (i != 4 && i != 7 && i != 10 && i != 13 && i != 16 && i != 19 && i != 22 && j != 12)
			{
				if (tab[i][j].rodzaj == 1)
				{
					tab[i][j].kolor = "zielony";
					tab[i][j].kwiat = "koszyczki";
					tab[i][j].lisc = "maly";
				}
				else if (tab[i][j].rodzaj == 2)
				{
					tab[i][j].kolor = "czerwony";
					tab[i][j].kwiat = "kielich";
					tab[i][j].lisc = "sredni";
				}
				else if (tab[i][j].rodzaj == 3)
				{
					tab[i][j].kolor = "zolty";
					tab[i][j].kwiat = "dzwoneczki";
					tab[i][j].lisc = "sredni";
				}
				else
				{
					tab[i][j].kolor = "zielony";
					tab[i][j].kwiat = "kielich";
					tab[i][j].lisc = "duze";
				}
			}
		}
	}


	mapa[1][1] = 'T';
	/*pierwsze_wyświetlenie_mapy_na_konsoli*/updateMapa();

	/////////////////////////////////////


	//////gra///////////////////////////////////////////////////////////////////////

	start = clock();

	
	/*rozpoczecie watku chodzenia */HANDLE watekidz = (HANDLE)_beginthread(&Chodz, 0, 0);
	/*rozpoczęcie_wątku_odśwież*/HANDLE watekOdswiez = (HANDLE)_beginthread(&Odswiez, 0, 0);
	
	char akcja;
	do
	{
		do
		{
			akcja = _getch();

			if (akcja == 'w' || akcja == 's' || akcja == 'a' || akcja == 'd' || akcja == 'p' || akcja != 'o' || akcja != 'k' || akcja != 'l')
			{
				dzialanie(akcja);
			}

			konrolka = 0;
		} while (akcja != 't');

		if (ilosc_plonow >= 250 or ilosc_trupow >= 50 or paliwo >= 4000)
		{
			gra = false;
		}
	} while (gra != false);
	////////////////////////////////////////////////////////////////////////////////


	return 0;
}


