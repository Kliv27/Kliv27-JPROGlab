/*
PLAN REALIZACJI PROJEKTU
Niewykonane:
	Sprawdzi�, czy system("cls"); dzia�a pod Linuxem
	�wiat tych automat�w kom�rkowych ma by� niesko�czony. Zastanowi� si�, czy doda� torus.
	pami�taj: d0 musi zasze wynosi� 0, aby pusta przestrze� nie ulega�a samowype�nieniu.
	Do przyjmowania polece� od u�ytkownika w trakcie dzia�ania programu wsz�dzie u�ywaj getch() z conio.h
	Linux - https://linux.die.net/man/3/sleep / Windows - sleep() windows.h, ifdef itp. 
	Warunkowo zdefiniuj dzielnik, je�li funkcje sleep() wymagaj� innych jednostek.
Wykonane:
	Rezygnuj� z wielo�ci kolor�w.
	Sprawd� czy polskie znaki dzia�aj� pod innym systemem operacyjnym. Wyniki eksperymentu:
		na Windowsie wszysko dzia�aja
		w paiza.io nie dzia�a
		na Linuxie - napisany program testowy z polskimi znakami wykaza�, �e znaki z mojego programu tworzone t� metod� nie zadzia�aj� na Linuxie -
	Wobec tego rezygnuj� z polskich znak�w w programie.
	Sprawdzono wymiary (w liczbie znak�w) dost�pne w konsoli do wy�wietlania pracy programu.
	Wyniki: Programu konsolowe w Windows: maksymalna szeroko�� 80, wysoko�� jest wi�ksza. Parametry te s� niezale�ne od systemu a od wy�wietlanej konsoli. Mog� by� zatem wi�ksze.
	Opisz program og�lnie w pliku readme.txt. Okre�l specyfikacj� zadania i dane wej�ciowe.
	Dodaj nazwy plik�w wynikowych i plik�w danych wej�ciowych do readme.txt i opisz standard ich zawarto�ci.
	Do pliku readme.txt dodaj wyja�nienia planowanych oznacze� kom�rek w programie:
	' ' - 
	'O' - 
	'^' - 
	'X' - 
	Dodaj instrukcj� u�ycia programu - nie wewn�trz jego samego.
	WASD / strza�ki - zmiana perspektywy, np. o 20 p�l, przycisk zmiany wielko�ci kroku przesuwania - 1, 10, 20 .. 60 z wy�wietleniem aktualnej warto�ci na marginesie
	U�ytkownik mo�e zmienia� minimaln� d�ugo�� kroku czasowego w ENTER-auto, SPACJA-krok.
	Dodaj (do instrukcji) przycisk zmiany d�ugo�ci jednego kroku z wy�wietlaniem na marginesie. Mo�na te� wy�wietla� liczebno�� populacji, po�o�enie kursora itp.
	W przyk�adach poka� zasady gry w �ycie Conway'a oraz Gosper Glider Gun. Niech b�d� r�wnie� pocz�tkowymi zawarto�ciami plik�w wej�ciowych.


Nigdy nie "commituj" pliku wykonywalnego ani pliku 000commit.txt zawieraj�cego opis commita.
*/

#include <stdio.h>
#include <stdlib.h>

#define x_ekran 61
#define y_ekran 61
#define x_margines 19
#define y_margines 61
#define liczba_zasad_1 9
#define liczba_zasad_2 18
#define stand_margin_pustki 20

void wczytaj_zasady(char ZSD[], char *awaria);
int jestzeroosiem(char znak);
char** wczytaj_uklad(int *xT, int *yT, char *awaria);
void zapisz_uklad(char **T, int xT, int yT, char *awaria);
void zwolnij_pamiec(char **T, int xT, int yT);
void wypisz_komunikat_o_awarii(int awaria);
void wypisz_komunikat_zakonczenia();

char** zwieksz_rozmiar_planszy(int *xT, int *yT, int *x0, int *y0, char *awaria, int u, int l, int r, int d); // cztery ostatnie argumenty musza byc dlugosciami
char** zmniejsz_rozmiar_planszy(int *xT, int *yT, int *x0, int *y0, char *awaria); // obcina plansz� zostawiaj�c margines pustki r�wny marginesowi dodawanemu. Wywo�ywa� np. co 100 krok�w.
char** zmniejsz_rozmiar_planszy_maksymalnie(int *xT, int *yT, int *x0, int *y0, char *awaria); // nie zostawia marginesu pustki, te trzy funkcje na pewno nie maja zmienic polozenia kursora
char TT(char **T, int xT, int yT, int px, int py); // odczytuje element tablicy lub pustk� poza ni�

int main(int agrc, char *argv[])
{
	char **T=NULL, komunikacja, awaria=0;
	int xT=0, yT=0, x0=0, y0=0, xkur=0, ykur=0; // wymiary tablicy, po�o�enie punktu (0,0) wzgl�dem tablicy, po�o�enie kursora
	char ZSD[18]; // zasady od a0 do d8
	wczytaj_zasady(ZSD,&awaria);
	if (awaria==0)
	{
		T=wczytaj_uklad(&xT,&yT,&awaria);
		if (awaria==0)
		{
			x0=xT/2;
			y0=yT/2;
			xkur=x0; // ustawienie kursora na srodek
			ykur=y0; // musz� pami�ta� o sytuacji, gdy kursor wykracza poza tablic� - ma to byc dozwolone i obslugiwane
			
			
			
			// operacje na ukladzie, edytor
			
			
			
			
			
			
			
			
			
			zapisz_uklad(T,xT,yT,&awaria);
			if (awaria!=0)
			{
				wypisz_komunikat_o_awarii(awaria);
			}
			zwolnij_pamiec(T,xT,yT);
		}
		else
		{
			wypisz_komunikat_o_awarii(awaria);
		}
	}
	else
	{
		wypisz_komunikat_o_awarii(awaria);
	}
	wypisz_komunikat_zakonczenia();
	return 0;
}

void wczytaj_zasady(char ZSD[], char *awaria)
{
	int i=0;
	while (i<liczba_zasad_2)
	{
		ZSD[i]=0;
		i++;
	}
	i=0;
	FILE *plik_zasad=NULL;
	char znaki[3]={48,48,48};
	plik_zasad=fopen("zasady.txt","r");
	if (plik_zasad!=NULL)
	{
		do
		{
			znak[0]=znak[1];
			znak[1]=znak[2];
			znak[2]=fgetc(plik_zasad);
			if ((znak[0]==':') && (znak[1]==' ') && (i<liczba_zasad_2) && (jestzeroosiem(znak[2])))
			{
				ZSD[i]=znak[2]-48;
				i++;
			}				
		} while (znak[2]!=EOF);
		ZSD[9]=0; // d0 = 0
		fclose(plik_zasad);
	}
	else
	{
		awaria=131;
	}
}

int jestzeroosiem(char znak)
{
	if ((znak>=48) && (znak<=57)) return 1;
	else return 0;
}

char** wczytaj_uklad(int *xT, int *yT, char *awaria)
{
	char **D=NULL;
	
	
	
	
	
	
	return D;
}

void zapisz_uklad(char **T, int xT, int yT, char *awaria)
{
	
}

void zwolnij_pamiec(char **T, int xT, int yT)
{
	
}

void wypisz_komunikat_o_awarii(int awaria)
{
	system("cls");
	switch (awaria)
	{
		case 131:
		{
			fprintf(stderr, "Otwarcie pliku z zasadami nie powiodlo sie. Program zostanie zamkniety.\n");
		} break;
		default:
		{
			fprintf(stderr, "Wystapil nieznany blad. Program zostanie zamkniety.\n");
		}
	}
}

void wypisz_komunikat_zakonczenia()
{
	
}
