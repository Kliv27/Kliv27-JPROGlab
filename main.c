/*
PLAN REALIZACJI PROJEKTU
Niewykonane:
	
	G³ównie zosta³o:
		- dodanie prostych reakcji na przyciski (na lokalnych zmiennych funkcji main)
		- dodanie zlozonych reakcji (dzialanie zasad automatu - funkcja wykonujaca krok, zmiana tempa z 1x na 4x czyli 4Hz itp.
		time_t do tego zeby kontrolowac ((dopelnienie roznicy t2-t1)+(t2-t1) = dlugosc_kroku) i sleep(dopelnienie roznicy) )
	Œwiat tych automatów komórkowych ma byæ nieskoñczony. Zastanowiê siê, czy dodaæ torus - nie ma takiej potrzeby.
	Porada: krok iteracyjny automatu nie powinien byc wykonywany w osobnej funkcji, zeby nie alokowac i dealokowac pamieci co chwila
	stworz tablice w funkcji glownej i ona zawiera nowy stan i zamien wskazniki
	Sprawdziæ, czy system("cls"); dzia³a pod Linuxem - poszukaæ odpowiedników.
	Linux ma pewnie swoje w³asne system("pause") (jakieœ inne polecenie ma do tego) wiêc nie ma potrzeby, ¿ebym liczy³ ile znaków wypisa³em printfem i je kasowa³.
	Do przyjmowania poleceñ od u¿ytkownika w trakcie dzia³ania programu wszêdzie u¿ywaj getch() z conio.h
	Linux - https://linux.die.net/man/3/sleep / Windows - sleep() z windows.h, ifdef itp. 
	Warunkowo zdefiniuj dzielnik, jeœli funkcje sleep() wymagaj¹ innych jednostek. Mo¿esz u¿ywaæ ró¿nic czasu z <time.h>
	Napisaæ readme2.txt bez polskich znaków - dopiero, gdy pewne jest, ¿e readme.txt nie ulegnie zmianom.
	
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
	pamiêtaj: d0 musi zasze wynosiæ 0, aby pusta przestrzeñ nie ulega³a samowype³nieniu.
	- Sprawdziæ wszystko to, co mam do tej pory (przejrzeæ kod).
	- dodanie wyswietlania (funkcja)


Nigdy nie "commituj" pliku wykonywalnego ani pliku 000commit.txt zawieraj¹cego opis commita.

	*(T+2) --> *(*(T+2)+0) ; *(*(T+2)+1) ; *(*(T+2)+2)
	*(T+1) --> *(*(T+1)+0) ; *(*(T+1)+1) ; *(*(T+1)+2)
	*(T+0) --> *(*(T+0)+0) ; *(*(T+0)+1) ; *(*(T+0)+2)
	/\
	|
	|
	T		*(*(T+y)+x)

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

#define KLAWISZ_STRZALKI 224
#define KLAWISZ_STRZALKA_W_LEWO 75
#define KLAWISZ_STRZALKA_W_PRAWO 77
#define KLAWISZ_STRZALKA_W_GORE 72
#define KLAWISZ_STRZALKA_W_DOL 80
/* CAPS i SHIFT nie wplywaja na strzalki, na SPACJE, na ENTER i na ESC*/
#define KLAWISZ_w 119
#define KLAWISZ_a 97
#define KLAWISZ_s 115
#define KLAWISZ_d 100
#define KLAWISZ_t 116
#define KLAWISZ_u 117
#define KLAWISZ_o 111
#define KLAWISZ_W 87
#define KLAWISZ_A 65
#define KLAWISZ_S 83
#define KLAWISZ_D 68
#define KLAWISZ_T 84
#define KLAWISZ_U 85
#define KLAWISZ_O 79
#define KLAWISZ_SPACJA 32
#define KLAWISZ_ENTER 13
#define KLAWISZ_ESC 27

void wczytaj_zasady(char ZSD[], char *awaria);
char** wczytaj_uklad(int *xT, int *yT, char *awaria);
void zapisz_uklad(char **T, int xT, int yT, char *awaria);
void zwolnij_pamiec(char **T, int yT);
void wypisz_komunikat_o_awarii(char awaria);
void wypisz_komunikat_zakonczenia();

int jest4849(char znak);
char TT(int Xc, int Yc, char **T, int xT, int yT, int x0, int y0); /* odczytuje element tablicy lub pustkê poza ni¹ */
int ile_populacja(char **T, int xT, int yT);
unsigned char nacisniecie_przycisku();
float tempo(int skala_tempa);
void wyswietl(char **T,  int xT, int yT, int x0, int y0, int xkur, int ykur, int skala_tempa, int dystans, int czas);





char** zwieksz_rozmiar_planszy(int *xT, int *yT, int *x0, int *y0, char *awaria, int u, int l, int r, int d); /* cztery ostatnie argumenty musza byc dlugosciami */
char** zmniejsz_rozmiar_planszy(int *xT, int *yT, int *x0, int *y0, char *awaria); /* obcina planszê zostawiaj¹c margines pustki równy marginesowi dodawanemu. Wywo³ywaæ np. co 100 kroków. */
char** zmniejsz_rozmiar_planszy_maksymalnie(int *xT, int *yT, int *x0, int *y0, char *awaria); /* nie zostawia marginesu pustki, te trzy funkcje na pewno nie maja zmienic polozenia kursora */

int main(int agrc, char *argv[])
{
	char **T=NULL, awaria=0;
	unsigned char komunikacja;
	int xT=0, yT=0, x0=0, y0=0, xkur=0, ykur=0; /* wymiary tablicy, po³o¿enie punktu (0,0) wzglêdem tablicy, po³o¿enie kursora */
	int skala_tempa=0, dystans=1, czas=0;
	/* skala_tempa od -1 (0.5x) do 4 (16x)  */
	/* dystans 1 3 5 10 20 40 */
	char ZSD[18]; /* zasady od a0 do d8 */
	wczytaj_zasady(ZSD,&awaria);
	if (awaria==0)
	{
		T=wczytaj_uklad(&xT,&yT,&awaria);
		if (awaria==0)
		{
			x0=xT/2; /* x0 jest zawsze >=0, bo jest wzgledem tablicy */
			y0=yT/2; /* y0 jest zawsze >=0, bo jest wzgledem tablicy */
			xkur=x0; /* ustawienie kursora na srodek */
			ykur=y0; /* muszê pamiêtaæ o sytuacji, gdy kursor wykracza poza tablicê - ma to byc dozwolone i obslugiwane */
			do
			{
				wyswietl(T,xT,yT,x0,y0,xkur,ykur,skala_tempa,dystans,czas);
				komunikacja=nacisniecie_przycisku();
				if ((komunikacja==STRZALKA_W_LEWO) || (komunikacja==KLAWISZ_A) || (komunikacja==KLAWISZ_a))
				{
					
				}
				if ((komunikacja==STRZALKA_W_PRAWO) || (komunikacja==KLAWISZ_D) || (komunikacja==KLAWISZ_d))
				{
					
				}
				if ((komunikacja==STRZALKA_W_GORE) || (komunikacja==KLAWISZ_W) || (komunikacja==KLAWISZ_w))
				{
					
				}
				if ((komunikacja==STRZALKA_W_DOL) || (komunikacja==KLAWISZ_S) || (komunikacja==KLAWISZ_s))
				{
					
				}
				if ((komunikacja==KLAWISZ_T) || (komunikacja==KLAWISZ_t))
				{
					
				}
				if ((komunikacja==KLAWISZ_U) || (komunikacja==KLAWISZ_u))
				{
					
				}
				if ((komunikacja==KLAWISZ_O) || (komunikacja==KLAWISZ_o))
				{
					
				}
				if (komunikacja==KLAWISZ_SPACJA)
				{
					/* po prostu wykona jeden krok - ale nie za pomoca funkcji zewnetrznej - porzebna ci tablica pom P i jej obsluga bledow i pilnowanie zeby miala ten sam rozmiar */
				}
				if (komunikacja==KLAWISZ_ENTER)
				{
					/* gdzies brakuje if(kbhit()) */
				}
			} while (komunikacja!=KLAWISZ_ESC);
			zapisz_uklad(T,xT,yT,&awaria);
			if (awaria!=0)
			{
				wypisz_komunikat_o_awarii(awaria);
			}
			zwolnij_pamiec(T,yT);
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
	FILE *plik_zasad=NULL;
	char znak[3]={48,48,48};
	while (i<liczba_zasad_2)
	{
		ZSD[i]=0;
		i++;
	}
	i=0;
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
		} while (znak[2]!=EOF && (!feof(plik_zasad))); /* podwójne zabezpieczenie */
		ZSD[9]=0; /* d0 = 0 */
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
		} while (jest4849(znak)); /* podwójne zabezpieczenie */
		fseek(plik_danych,0,SEEK_SET); /* kursor czytaj¹cy na poczatek pliku */
		do
		{
			znak=fgetc(plik_danych);
			if (jest4849(znak)) dlugosc_pliku++;
		} while (znak!=EOF && !feof(plik_danych));
		if (dlugosc_linii>0)
		{
			*xT=dlugosc_linii;
			*yT=dlugosc_pliku/dlugosc_linii; /* zawsze bedzie > 0, brak bledu */
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
					zwolnij_pamiec(D,*yT);
					D=NULL;
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
			fputc('\n',plik_wyjsciowy); /* na wiki pisza, ze \n samo sie zmieni na \r\n pod Windows, Linux - \n dziala najzwyczajniej */
		}
	}
	else
	{
		*awaria=35;
	}
}

void zwolnij_pamiec(char **T, int yT)
{
	/* UWAGA! Funkcja nie zeruje wskaznika z innej funkcji, bo jest on przekazany przez wartosc.*/
	int i;
	if (T!=NULL)
	{
		for (i=0;i<yT;i++)
		{
			if (*(T+i)!=NULL) free(*(T+i));
		}
		free(T);
	}
}

void wypisz_komunikat_o_awarii(char awaria)
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
	system("cls");
	printf("Praca programu zostala zakonczona. Program zostanie zamkniety. Nacisnij dowolny przycisk, aby kontynuowac.");
	fflush(stdin);
	getch();
}

int jest4849(char znak)
{
	if (znak==48 || znak==49) return 1;
	else return 0;
}

char TT(int Xc, int Yc, char **T, int xT, int yT, int x0, int y0)
{
	int tabx;
	int taby;
	tabx=x0+Xc; /* polozenie kartezjanskich Xc Yc we wspolrzednych tablicowych*/
	taby=y0+Yc;
	if ((tabx>0) && (taby>0) && (tabx<xT) && (taby<yT)) {return (*(*(T+taby)+tabx));}
	return 0; /* poza tablic¹ jest bezkresna pustka */
}

int ile_populacja(char **T, int xT, int yT)
{
	int wynik=0;
	int i, j;
	for (i=0;i<xT;i++)
	{
		for (j=0;j<yT;j++)
		{
			if ((*((*(T+j))+i))==1) wynik++;
		}
	}
	return wynik;
}

unsigned char nacisniecie_przycisku();
{
	unsigned char klawisz;
    fflush(stdin);
    klawisz=getch();
	if (klawisz==KLAWISZ_STRZALKI)
    {
        klawisz=getch();
        fflush(stdin);
	}
	return klawisz;
}

float tempo(int skala_tempa)
{
	float wynik=1.0;
	if (skala_tempa>0)
	{
		while (skala_tempa!=0)
		{
			wynik=wynik*2.0;
			skala_tempa--;
		}
	}
	else
	{
		while (skala_tempa!=0)
		{
			wynik=wynik/2.0;
			skala_tempa++;
		}
	}
	return wynik;
}

void wyswietl(char **T, int xT, int yT, int x0, int y0, int xkur, int ykur, int skala_tempa, int dystans, int czas)
{
	int i, j, imin, imax, jmin, jmax, pomx, pomy;
	/* kursor wzgledem ekranu jest na: (30, 30) */
	pomx=(x_ekran-1)/2;
	pomy=(y_ekran-1)/2;
	imin=xkur-pomx;
	imax=xkur+pomx;
	jmin=ykur-pomy;
	jmax=ykur+pomy;
	system("cls");
	for (j=jmax;j>=jmin;j--)
	{
		for (i=imin;i<=imax;i++)
		{
			if ((i==xkur) && (j==ykur))
			{
				switch (TT(i,j,T,xT,yT,x0,y0))
				{
					case 0: putchar('^'); break;
					case 1: putchar('X');
				}
			}
			else
			{
				switch (TT(i,j,T,xT,yT,x0,y0))
				{
					case 0: putchar(' '); break;
					case 1: putchar('O');
				}
			}
		}
		putchar('#');
		switch (jmax-j)
		{
			case 0: printf(" Populacja: %d",ile_populacja(T,xT,yT)%1000000); break;
			case 1: printf(" Czas: %d",czas%1000000); break;
			case 2: printf(" Tempo: %2.2fx",tempo(skala_tempa)); break;
			case 3: printf(" Dystans: %d",dystans%1000000); break;
			case 4: printf(" x: %d",xkur%1000000); break;
			case 5: printf(" y: %d",ykur%1000000);
		}
		putchar('\n');
	}
	for (i=-1;i<x_ekran;i++)
	{
		putchar('#');
	}
}
