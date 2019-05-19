/*
PLAN REALIZACJI PROJEKTU
Niewykonane:
	Sprawdziæ wszystko to, co mam do tej pory (przejrzeæ kod).
	Sprawdziæ, czy system("cls"); dzia³a pod Linuxem
	Œwiat tych automatów komórkowych ma byæ nieskoñczony. Zastanowiê siê, czy dodaæ torus.
	pamiêtaj: d0 musi zasze wynosiæ 0, aby pusta przestrzeñ nie ulega³a samowype³nieniu.
	Do przyjmowania poleceñ od u¿ytkownika w trakcie dzia³ania programu wszêdzie u¿ywaj getch() z conio.h
	Linux - https://linux.die.net/man/3/sleep / Windows - sleep() windows.h, ifdef itp. 
	Warunkowo zdefiniuj dzielnik, jeœli funkcje sleep() wymagaj¹ innych jednostek.
	
	*(T+2) --> *(*(T+2)+0) ; *(*(T+2)+1) ; *(*(T+2)+2)
	*(T+1) --> *(*(T+1)+0) ; *(*(T+1)+1) ; *(*(T+1)+2)
	*(T+0) --> *(*(T+0)+0) ; *(*(T+0)+1) ; *(*(T+0)+2)
	/\
	|
	|
	T		*(*(T+y)+x)
	
Wykonane:
	Rezygnujê z wieloœci kolorów.
	SprawdŸ czy polskie znaki dzia³aj¹ pod innym systemem operacyjnym. Wyniki eksperymentu:
		na Windowsie wszysko dzia³aja
		w paiza.io nie dzia³a
		na Linuxie - napisany program testowy z polskimi znakami wykaza³, ¿e znaki z mojego programu tworzone t¹ metod¹ nie zadzia³aj¹ na Linuxie -
	Wobec tego rezygnujê z polskich znaków w programie.
	Sprawdzono wymiary (w liczbie znaków) dostêpne w konsoli do wyœwietlania pracy programu.
	Wyniki: Programu konsolowe w Windows: maksymalna szerokoœæ 80, wysokoœæ jest wiêksza. Parametry te s¹ niezale¿ne od systemu a od wyœwietlanej konsoli. Mog¹ byæ zatem wiêksze.
	Opisz program ogólnie w pliku readme.txt. Okreœl specyfikacjê zadania i dane wejœciowe.
	Dodaj nazwy plików wynikowych i plików danych wejœciowych do readme.txt i opisz standard ich zawartoœci.
	Do pliku readme.txt dodaj wyjaœnienia planowanych oznaczeñ komórek w programie:
	' ' - 
	'O' - 
	'^' - 
	'X' - 
	Dodaj instrukcjê u¿ycia programu - nie wewn¹trz jego samego.
	WASD / strza³ki - zmiana perspektywy, np. o 20 pól, przycisk zmiany wielkoœci kroku przesuwania - 1, 10, 20 .. 60 z wyœwietleniem aktualnej wartoœci na marginesie
	U¿ytkownik mo¿e zmieniaæ minimaln¹ d³ugoœæ kroku czasowego w ENTER-auto, SPACJA-krok.
	Dodaj (do instrukcji) przycisk zmiany d³ugoœci jednego kroku z wyœwietlaniem na marginesie. Mo¿na te¿ wyœwietlaæ liczebnoœæ populacji, po³o¿enie kursora itp.
	W przyk³adach poka¿ zasady gry w ¿ycie Conway'a oraz Gosper Glider Gun. Niech bêd¹ równie¿ pocz¹tkowymi zawartoœciami plików wejœciowych.


Nigdy nie "commituj" pliku wykonywalnego ani pliku 000commit.txt zawieraj¹cego opis commita.
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
char** wczytaj_uklad(int *xT, int *yT, char *awaria);
void zapisz_uklad(char **T, int xT, int yT, char *awaria);
void zwolnij_pamiec(char **T, int xT, int yT);
void wypisz_komunikat_o_awarii(int awaria);
void wypisz_komunikat_zakonczenia();

int jest4849(char znak);

char** zwieksz_rozmiar_planszy(int *xT, int *yT, int *x0, int *y0, char *awaria, int u, int l, int r, int d); // cztery ostatnie argumenty musza byc dlugosciami
char** zmniejsz_rozmiar_planszy(int *xT, int *yT, int *x0, int *y0, char *awaria); // obcina planszê zostawiaj¹c margines pustki równy marginesowi dodawanemu. Wywo³ywaæ np. co 100 kroków.
char** zmniejsz_rozmiar_planszy_maksymalnie(int *xT, int *yT, int *x0, int *y0, char *awaria); // nie zostawia marginesu pustki, te trzy funkcje na pewno nie maja zmienic polozenia kursora
char TT(char **T, int xT, int yT, int px, int py); // odczytuje element tablicy lub pustkê poza ni¹

int main(int agrc, char *argv[])
{
	char **T=NULL, komunikacja, awaria=0;
	int xT=0, yT=0, x0=0, y0=0, xkur=0, ykur=0; // wymiary tablicy, po³o¿enie punktu (0,0) wzglêdem tablicy, po³o¿enie kursora
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
			ykur=y0; // muszê pamiêtaæ o sytuacji, gdy kursor wykracza poza tablicê - ma to byc dozwolone i obslugiwane
			
			
			
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
	char znak[3]={48,48,48};
	plik_zasad=fopen("zasady.txt","r");
	if (plik_zasad!=NULL)
	{
		do
		{
			znak[0]=znak[1];
			znak[1]=znak[2];
			znak[2]=fgetc(plik_zasad);
			if ((znak[0]==':') && (znak[1]==' ') && (i<liczba_zasad_2) && (jest4849(znak[2])))
			{
				ZSD[i]=znak[2]-48;
				i++;
			}				
		} while (znak[2]!=EOF && (!feof(plik_zasad))); // podwójne zabezpieczenie
		ZSD[9]=0; // d0 = 0
		fclose(plik_zasad);
	}
	else
	{
		*awaria=31;
	}
}

char** wczytaj_uklad(int *xT, int *yT, char *awaria)
{
	char **D=NULL;
	int i, x, y, przydzial_udany=1;
	int dlugosc_linii=-1, dlugosc_pliku=0;
	FILE *plik_danych=NULL;
	char znak;
	plik_danych=fopen("a.txt","r");
	if (plik_danych!=NULL)
	{
		do
		{
			dlugosc_linii++;
			znak=fgetc(plik_danych);
		} while (jest4849(znak)); // podwójne zabezpieczenie
		fseek(plik_danych,0,SEEK_SET); // kursor czytaj¹cy na poczatek pliku
		do
		{
			znak=fgetc(plik_danych);
			if (jest4849(znak)) dlugosc_pliku++;
		} while (znak!=EOF && !feof(plik_danych));
		if (dlugosc_linii>0)
		{
			*xT=dlugosc_linii;
			*yT=dlugosc_pliku/dlugosc_linii; // zawsze bedzie > 0, brak bledu
			D=malloc((*yT)*sizeof(char*));
			if (D==NULL) przydzial_udany=0;
			if (przydzial_udany)
			{
				for (i=0;i<(*yT);i++)
				{
					*(D+i)=NULL;
					*(D+i)=malloc((*xT)*sizeof(char));
					if ((*(D+i))==NULL) przydzial_udany=0;
				}
				if (przydzial_udany)
				{
					for (x=0;x<(*xT);x++)
					{
						for (y=0;y<(*yT);y++)
						{
							*(*(D+y)+x)=0;
						}
					}
					fseek(plik_danych,0,SEEK_SET);
					i=(*yT)-1;
					x=0;
					do
					{
						znak=fgetc(plik_danych);
						if (jest4849(znak))
						{
							*(*(D+i)+x)=znak-48;
							x++;
							if (x==(*xT))
							{
								x=0;
								i--;
							}
						}
					} while ((znak!=EOF) && (!feof(plik_danych)) && (i>-1));
				}
				else
				{
					*awaria=34;
					for (i=0;i<(*yT);i++)
					{
						if (*(D+i)!=NULL) free(*(D+i));
					}
				}
				
			}
			else
			{
				*awaria=34;
			}
		}
		else
		{
			*awaria=33;
		}
	}
	else
	{
		*awaria=32;
	}
	return D;
}

void zapisz_uklad(char **T, int xT, int yT, char *awaria)
{
	int x, y;
	FILE *plik_wyjsciowy=NULL;
	char znak;
	plik_wyjsciowy=fopen("out.txt","w");
	if (plik_wyjsciowy!=NULL)
	{
		for (y=0;y<yT;y++)
		{
			for (x=0;x<xT;x++)
			{
				fputc(48+(*(*(T+y)+x)),plik_wyjsciowy);
			}
			fputc('\r',plik_wyjsciowy);
			fputc('\n',plik_wyjsciowy);
		}
	}
	else
	{
		*awaria=35;
	}
}

void zwolnij_pamiec(char **T, int xT, int yT)
{
	// if T!=NULL
}

void wypisz_komunikat_o_awarii(int awaria)
{
	system("cls");
	switch (awaria)
	{
		case 31:
		{
			fprintf(stderr, "Otworzenie pliku z zasadami nie powiodlo sie. Program zostanie zamkniety.\n");
		} break;
		case 32:
		{
			fprintf(stderr, "Otworzenie pliku ze stanem poczatkowym ukladu komorek nie powiodlo sie. Program zostanie zamkniety.\n");
		} break;
		case 33:
		{
			fprintf(stderr, "Plik ze stanem poczatkowym ukladu komorek nie ma prawidlowej struktury. Program zostanie zamkniety.\n");
		} break;
		case 34:
		{
			fprintf(stderr, "Dynamiczny przydzial pamieci nie powiodl sie. Program zostanie zamkniety.\n");
		} break;
		case 35:
		{
			fprintf(stderr, "Nie udalo sie otworzyc pliku a.txt. Program zostanie zamkniety a wyniki - utracone.\n");
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

int jest4849(char znak)
{
	if (znak==48 || znak==49) return 1;
	else return 0;
}
