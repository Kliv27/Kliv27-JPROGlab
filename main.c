/*
PLAN REALIZACJI PROJEKTU
Niewykonane:
	
	G³ównie zosta³o:
	
	kbhit mo¿e nie dzia³aæ pod systemem... zaproponowane system("clear") tez - sprawdzic, czy dziala, juz zaimplementowane
	
	Mo¿na znacznie lepiej skomentowaæ kod, ale nie trzeba.
	Przyda siê usun¹æ niektóre komentarze z kodu na koniec.
	Poprawiæ zwrot "raczej zadzia³a" w readme.txt - pod wzglêdem treœci. - wykonano
	Napisaæ readme2.txt bez polskich znaków - dopiero, gdy pewne jest, ¿e readme.txt nie ulegnie zmianom.
	Usun¹æ PLAN REALIZACJI PROJEKTU z kodu po jego ukoñczeniu.
	
Wykonane:
	Rezygnujê z wieloœci kolorów.
	SprawdŸ czy polskie znaki dzia³aj¹ pod innym systemem operacyjnym. Wyniki eksperymentu:
		na Windowsie wszystkie dzia³aja
		w paiza.io nie dzia³a
		na Linuxie - napisany program testowy z polskimi znakami wykaza³, ¿e znaki z mojego programu tworzone t¹ metod¹ nie zadzia³aj¹ na Linuxie -
	Wobec tego rezygnujê z polskich znaków w programie.
	Sprawdzono wymiary (w liczbie znaków) dostêpne w konsoli do wyœwietlania pracy programu.
	Wyniki: Programy konsolowe w Windows: maksymalna szerokoœæ 80, wysokoœæ jest wiêksza. Parametry te s¹ niezale¿ne od systemu, natomiast zale¿¹ od wyœwietlanej konsoli. Mog¹ zatem byæ wiêksze.
	Opisz program ogólnie w pliku readme.txt. Okreœl specyfikacjê zadania i dane wejœciowe.
	Dodaj nazwy plików wynikowych i plików danych wejœciowych do readme.txt i opisz standard ich zawartoœci.
	Do pliku readme.txt dodaj wyjaœnienia planowanych oznaczeñ komórek w programie:
	' ' - 
	'O' - 
	'^' - 
	'X' - 
	Dodaj instrukcjê u¿ycia programu - nie wewn¹trz jego samego.
	WASD / strza³ki - zmiana perspektywy, np. o 20 pól, przycisk zmiany wielkoœci kroku przesuwania - 1, 10, 20 .. 60 z wyœwietleniem aktualnej wartoœci na marginesie
	U¿ytkownik mo¿e zmieniaæ minimaln¹ d³ugoœæ kroku czasowego wy³¹cznie wtedy, gdy tryb automatyczny jest wy³¹czony.
	Dodaj (do instrukcji) przycisk zmiany d³ugoœci jednego kroku z wyœwietlaniem na marginesie. Mo¿na te¿ wyœwietlaæ liczebnoœæ populacji, po³o¿enie kursora itp.
	W przyk³adach poka¿ zasady gry w ¿ycie Conway'a oraz Gosper Glider Gun. Niech bêd¹ równie¿ pocz¹tkowymi zawartoœciami plików wejœciowych.
	pamiêtaj: d0 musi zasze wynosiæ 0, aby pusta przestrzeñ nie ulega³a samowype³nieniu.
	- Sprawdziæ wszystko to, co mam do tej pory (przejrzeæ kod).
	- dodanie wyswietlania (funkcja)
	Do przyjmowania poleceñ od u¿ytkownika w trakcie dzia³ania programu wszêdzie u¿ywaj getch() z conio.h
	Œwiat tych automatów komórkowych ma byæ nieskoñczony. Decydujê siê ostatecznie nie dodawaæ opcji symulacji na torusie.
	- dodanie tablicy pomocniczej, jej przydzial pamieci, obsluga jej bledow
	- dodanie prostych reakcji na przyciski (na lokalnych zmiennych funkcji main) - za pomoca pojedynczych instrukcji
	- dodanie zlozonych reakcji (dzialanie zasad automatu zmiana tempa z 1x na 4x czyli 4Hz itp., zmiana dystansu)
	- napisanie funkcji wykonuj¹cych alokacjê/dealokacjê pamiêci
	- sprobuj alokowac pamiec (przy wczytywaniu danych) za pomoca innej funkcji (wywolaj inna)
	- dodanie reakcji na przycisk O (zmiana stanu komórki w edytorze)
	- napisanie funkcji wykonujacej krok - musi przekazywaæ wskaŸnik na wskaŸnik przez wskaŸnik (char ***T_adres)
		Porada: krok iteracyjny automatu jednak powinien byc wykonywany w osobnej funkcji, ale bez alokowania pamieci co chwila
		stworz tablice w funkcji glownej i ona zawiera nowy stan i zamien wskazniki
	- wywolanie funkcji dealokujacej nadmiar pamieci np. co 100 kroków
	Od teraz samo wyjœcie poza tablicê nie wywala programu - przydzia³ dynamiczny œwietnie dzia³a, zapisywanie wyniku te¿ - przetestowane.
	- sprawiæ, aby funkcja wykonania kroku nie wywala³a programu - trzeba do tego przejrzec dokladnie wiele funkcji
	Czy aby na pewno obydwie tablice g³ówne s¹ traktowane symetrycznie co do zmian ich rozmiaru? Teraz ju¿ wygl¹da na to, ¿e tak, bo program dzia³a prawid³owo.
	- kroki automatyczne (ENTER) - dopracowanie:
	U¿yj time_t do tego zeby kontrolowac ((dopelnienie roznicy t2-t1)+(t2-t1) = dlugosc_kroku) i sleep(dopelnienie roznicy) )
	Decydujê siê zmieniæ mechanikê tempa na szybkie (nie wywoluje wyswietlen) i obserwowalne, a nie wartoœci i wywaliæ sleep'y i time_t
	- zrobilem to, dziala, wystarczy zmienic w instrukcji opis do tego tempa inny
	Sprawdziæ, czy system("cls"); dzia³a pod Linuxem - poszukaæ odpowiedników. Teraz powywolywac zamiast tej innej.
	Linux ma pewnie swoje w³asne system("cls") (jakieœ inne polecenie ma do tego) wiêc nie ma potrzeby, ¿ebym liczy³ ile znaków wypisa³em printfem i je kasowa³.
	pod nim chyba system("clear"); bez biblioteki bo to systemowe - najlepiej w funkcji z ifdefem

Nigdy nie "commituj" pliku wykonywalnego ani pliku 000commit.txt zawieraj¹cego opis commita.

	*(T+2) --> *(*(T+2)+0) ; *(*(T+2)+1) ; *(*(T+2)+2)
	*(T+1) --> *(*(T+1)+0) ; *(*(T+1)+1) ; *(*(T+1)+2)
	*(T+0) --> *(*(T+0)+0) ; *(*(T+0)+1) ; *(*(T+0)+2)
	/\
	|
	|
	T		*(*(T+y)+x)

*/


#ifdef _WIN64
	#define STWIERDZONO_WINDOWS 4
#else
	#ifdef _WIN32
		#define STWIERDZONO_WINDOWS 3
	#endif
#endif

#ifdef __linux__
	#define STWIERDZONO_UNIX 2
#else
	#ifdef __unix__
		#define STWIERDZONO_UNIX 1
	#endif
#endif

#ifndef STWIERDZONO_WINDOWS
	#ifndef STWIERDZONO_UNIX
		#error Kompilacja pod blednym systemem!
	#endif
#endif
/*
NIEPOTRZEBNE (ZREZYGNOWA£EM Z TEJ MECHANIKI TEMPA):
ifdef STWIERDZONO_WINDOWS
	include <Windows.h>
endif

ifdef STWIERDZONO_UNIX
	include <unistd.h> 
endif
*/

#include <stdio.h>
#include <stdlib.h>
/*NIEPOTRZEBNE (ZREZYGNOWA£EM Z TEJ MECHANIKI TEMPA): include <time.h>*/

#define x_ekran 61
#define y_ekran 61
#define x_margines 19
#define y_margines 61
#define liczba_zasad_1 9
#define liczba_zasad_2 18
#define stand_margin_pustki 20

#ifdef STWIERDZONO_WINDOWS
   #define KLAWISZ_ENTER 13
   #define KLAWISZ_STRZALKI 224
   #define KLAWISZ_STRZALKA_W_LEWO 75
   #define KLAWISZ_STRZALKA_W_PRAWO 77
   #define KLAWISZ_STRZALKA_W_GORE 72
   #define KLAWISZ_STRZALKA_W_DOL 80
#else
   #define KLAWISZ_ENTER 10
   #define KLAWISZ_STRZALKI 91
   #define KLAWISZ_STRZALKA_W_LEWO 168 /* naprawde 68, ale litery tyle maja wiec przesunalem wszystkie strzalki o + 100 */
   #define KLAWISZ_STRZALKA_W_PRAWO 167
   #define KLAWISZ_STRZALKA_W_GORE 165
   #define KLAWISZ_STRZALKA_W_DOL 166
#endif
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
#define KLAWISZ_ESC 27

/*W przypadku kompilacji pod Unix problemem jest brak dostepu do polecen takich jak getch() czy kbhit().
Aby to rozwiazac wykorzystalem kody, ktorych nie rozumiem, z nastepujacych zrodel:
https://stackoverflow.com/questions/7469139/what-is-the-equivalent-to-getch-getche-in-linux
https://cboard.cprogramming.com/c-programming/63166-kbhit-linux.html
*/
#ifdef STWIERDZONO_UNIX
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
static struct termios stary, nowy;
void initTermios(int echo) 
{
  tcgetattr(0, &stary); /* grab old terminal i/o settings */
  nowy = stary; /* make new settings same as old settings */
  nowy.c_lflag &= ~ICANON; /* disable buffered i/o */
  if (echo) {
      nowy.c_lflag |= ECHO; /* set echo mode */
  } else {
      nowy.c_lflag &= ~ECHO; /* set no echo mode */
  }
  tcsetattr(0, TCSANOW, &nowy); /* use these new terminal i/o settings now */
}
char getch(void) 
{
	char ch;
	initTermios(0);
	ch = getchar();
	tcsetattr(0, TCSANOW, &stary);
	return ch;
}
int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }
  return 0;
}
#endif

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
/*
NIEPOTRZEBNE (ZREZYGNOWA£EM Z TEJ MECHANIKI TEMPA):
float tempo(int skala_tempa);
*/
void wyswietl(char **T,  int xT, int yT, int x0, int y0, int xkur, int ykur, int tryb_tempa, /*NIEPOTRZEBNE (ZREZYGNOWA£EM Z TEJ MECHANIKI TEMPA):int skala_tempa, */int dystans, int czas);
void wyczysc();
char** przydziel_pamiec_tablicy_pomocniczej(int xT, int yT, char *awaria);
void zmien_tryb_tempa(int *wsk_tryb_tempa);
/*NIEPOTRZEBNE (ZREZYGNOWA£EM Z TEJ MECHANIKI TEMPA):void zmien_skale_tempa(int *wsk_skala_tempa);*/
void zmien_dystans(int *wsk_dystans);
char** zmniejsz_rozmiar_planszy_maksymalnie(char **D, int *xT, int *yT, int *x0, int *y0, char *awaria);
/* wywo³anie: T=zmniejsz_rozmiar_planszy_maksymalnie(T,&xT,&yT,&x0,&y0,&awaria)*/
/* nie zostawia marginesu pustki, te trzy funkcje na pewno nie maja zmienic polozenia kursora, wywolac przed zapisem */
char** zwieksz_rozmiar_planszy(char **D, int *xT, int *yT, int *x0, int *y0, char *awaria, int u, int l, int r, int d);
/* cztery ostatnie argumenty musza byc dlugosciami, ma nie zostawiac oprocz tego jeszcze marginesu dodawanego - jak go chcesz, to zwieksz argument */
char** zmniejsz_rozmiar_planszy(char **D, int *xT, int *yT, int *x0, int *y0, char *awaria);
/* obcina planszê zostawiaj¹c margines pustki równy marginesowi dodawanemu. Wywo³ywaæ np. co 100 kroków. */
void zmien_stan_komorki(char ***T, char ***P, int *xT, int *yT, int *x0, int *y0, int xkur, int ykur, char *awaria);
void wykonaj_krok(char ***T, char ***P, int *xT, int *yT, int *x0, int *y0, char ZSD[], char *awaria);
int czy_w_lewo(unsigned char komunikacja);
int czy_w_prawo(unsigned char komunikacja);
int czy_w_gore(unsigned char komunikacja);
int czy_w_dol(unsigned char komunikacja);
int czy_klawisz_U(unsigned char komunikacja);
void wykonaj_krok_2(char ***T, char ***P, int *xT, int *yT, int *x0, int *y0, char ZSD[], char *awaria, int *czas);

int main(int agrc, char *argv[])
{
	char **T=NULL;
	char **P=NULL;
	char awaria=0;
	unsigned char komunikacja;
	int xT=0, yT=0, x0=0, y0=0, xkur=0, ykur=0; /* wymiary tablicy, po³o¿enie punktu (0,0) wzglêdem tablicy, po³o¿enie kursora */
	/* po³o¿enie kursora jest wzgledem kartezjanskich wspolrzednych, x0 i y0 wzgledem tablicy */
	int tryb_tempa=1, dystans=1, czas=0;
	/* tryb 0 - szybki, 1 - wolny */
	/* NIEPOTRZEBNE (ZREZYGNOWA£EM Z TEJ MECHANIKI TEMPA):int skala_tempa=0;*/
	/* skala_tempa od -1 (0.5x) do 4 (16x)  */
	/* dystans 1 3 5 10 20 40 */
	char ZSD[18]; /* zasady od a0 do d8 */
	/*
	NIEPOTRZEBNE (ZREZYGNOWA£EM Z TEJ MECHANIKI TEMPA):
	time_t t1, t2;
	double deltate, opoznienie;
	int ile_mikrosekund;
	*/
	
	wczytaj_zasady(ZSD,&awaria);
	if (awaria==0)
	{
		T=wczytaj_uklad(&xT,&yT,&awaria);
		if (awaria==0)
		{
			P=przydziel_pamiec_tablicy_pomocniczej(xT,yT,&awaria);
			if (awaria==0)
			{
				x0=xT/2; /* x0 jest zawsze >=0 (ale tylko na poczatku), bo jest wzgledem tablicy */
				y0=yT/2; /* y0 jest zawsze >=0 (ale tylko na poczatku), bo jest wzgledem tablicy */
				xkur=x0; /* ustawienie kursora na srodek */
				ykur=y0; /* muszê pamiêtaæ o sytuacji, gdy kursor wykracza poza tablicê - ma to byc dozwolone i obslugiwane - juz zrobilem */
				do
				{
					wyswietl(T,xT,yT,x0,y0,xkur,ykur,tryb_tempa/*NIEPOTRZEBNE (ZREZYGNOWA£EM Z TEJ MECHANIKI TEMPA):skala_tempa*/,dystans,czas);
					komunikacja=nacisniecie_przycisku();
					if (czy_w_lewo(komunikacja))
					{
						xkur-=dystans;
					}
					else if (czy_w_prawo(komunikacja))
					{
						xkur+=dystans;
					}
					else if (czy_w_gore(komunikacja))
					{
						ykur+=dystans;
					}
					else if (czy_w_dol(komunikacja))
					{
						ykur-=dystans;
					}
					else if ((komunikacja==KLAWISZ_T) || (komunikacja==KLAWISZ_t))
					{
						zmien_tryb_tempa(&tryb_tempa);
						/*NIEPOTRZEBNE (ZREZYGNOWA£EM Z TEJ MECHANIKI TEMPA):zmien_skale_tempa(&skala_tempa);*/
					}
					else if (czy_klawisz_U(komunikacja))
					{
						zmien_dystans(&dystans);
					}
					else if ((komunikacja==KLAWISZ_O) || (komunikacja==KLAWISZ_o))
					{
						zmien_stan_komorki(&T,&P,&xT,&yT,&x0,&y0,xkur,ykur,&awaria);
					}
					else if (komunikacja==KLAWISZ_SPACJA)
					{
						wykonaj_krok_2(&T,&P,&xT,&yT,&x0,&y0,ZSD,&awaria,&czas);
					}
					else if (komunikacja==KLAWISZ_ENTER)
					{
						komunikacja=KLAWISZ_T; /* ustawienie na dowolne inne makro */
						if (!tryb_tempa)
						{
							wyczysc();
							printf("Szybkie obliczenia w tle... Nacisnij ENTER aby zatrzymac.");
						}
						do
						{
							if (tryb_tempa) wyswietl(T,xT,yT,x0,y0,xkur,ykur,tryb_tempa/*NIEPOTRZEBNE (ZREZYGNOWA£EM Z TEJ MECHANIKI TEMPA):skala_tempa*/,dystans,czas);
							/*NIEPOTRZEBNE (ZREZYGNOWA£EM Z TEJ MECHANIKI TEMPA):time(&t1);*/
							wykonaj_krok_2(&T,&P,&xT,&yT,&x0,&y0,ZSD,&awaria,&czas);
							/*NIEPOTRZEBNE (ZREZYGNOWA£EM Z TEJ MECHANIKI TEMPA):
							time(&t2);
							deltate=difftime(t2,t1);
							opoznienie=(double)tempo(skala_tempa);
							ile_mikrosekund=(int)(1000000.0*((opoznienie-deltate)>0.0)?(opoznienie-deltate):(0.0));
							ifdef STWIERDZONO_WINDOWS
								include "kod_dodatkowy2.c"
							endif
	
							ifdef STWIERDZONO_UNIX
								include "kod_dodatkowy1.c"
							endif
							*/
							if (kbhit())
							{
								komunikacja=nacisniecie_przycisku();
								if (czy_klawisz_U(komunikacja))
								{
									zmien_dystans(&dystans);
								}
								else if (czy_w_lewo(komunikacja))
								{
									xkur-=dystans;
								}
								else if (czy_w_prawo(komunikacja))
								{
									xkur+=dystans;
								}
								else if (czy_w_gore(komunikacja))
								{
									ykur+=dystans;
								}
								else if (czy_w_dol(komunikacja))
								{
									ykur-=dystans;
								}
							}
						} while (komunikacja!=KLAWISZ_ENTER && awaria==0);
					}
				} while (komunikacja!=KLAWISZ_ESC && awaria==0);
				if (awaria==0) T=zmniejsz_rozmiar_planszy_maksymalnie(T,&xT,&yT,&x0,&y0,&awaria);
				if (awaria==0)
				{
					zapisz_uklad(T,xT,yT,&awaria);
					if (awaria!=0)
					{
						wypisz_komunikat_o_awarii(awaria);
					}
				}
				else
				{
					wypisz_komunikat_o_awarii(awaria);
				}
				zwolnij_pamiec(T,yT);
				zwolnij_pamiec(P,yT);
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
	/* funkcja zostala przetestowana i dziala swietnie */
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
	/* funkcja zostala przetestowana i dziala swietnie */
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
			D=przydziel_pamiec_tablicy_pomocniczej(*xT,*yT,awaria);
			if (D!=NULL)
			{	
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
	/* naprawiono i przetestowano - poprzednio odwraca³a wzglêdem OX */
	int x, y;
	FILE *plik_wyjsciowy=NULL;
	char znak;
	plik_wyjsciowy=fopen("out.txt","w");
	if (plik_wyjsciowy!=NULL)
	{
		for (y=yT-1;y>=0;y--)
		{
			for (x=0;x<xT;x++)
			{
				fputc(48+(*(*(T+y)+x)),plik_wyjsciowy);
			}
			if (y!=0) fputc('\n',plik_wyjsciowy); /* na wiki pisza, ze \n samo sie zmieni na \r\n pod Windows, Linux - \n dziala najzwyczajniej */
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
	wyczysc();
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
			fprintf(stderr, "Nie udalo sie otworzyc pliku out.txt. Program zostanie zamkniety a wyniki - utracone.\n");
		} break;
		default:
		{
			fprintf(stderr, "Wystapil nieznany blad. Program zostanie zamkniety.\n");
		}
	}
	fprintf(stderr, "\nNacisnij dowolny przycisk, aby kontynuowac....\n");
	fflush(stdin);
	getch();
}

void wypisz_komunikat_zakonczenia()
{
	wyczysc();
	printf("Praca programu zostala zakonczona. Program zostanie zamkniety. Nacisnij dowolny przycisk, aby kontynuowac.");
	fflush(stdin);
	getch();
}

int jest4849(char znak)
{
	if (znak==48 || znak==49) return 1;
	return 0;
}

char TT(int Xc, int Yc, char **T, int xT, int yT, int x0, int y0)
{
	int tabx;
	int taby;
	tabx=x0+Xc; /* polozenie kartezjanskich Xc Yc we wspolrzednych tablicowych*/
	taby=y0+Yc;
	if ((tabx>=0) && (taby>=0) && (tabx<xT) && (taby<yT)) {return (*(*(T+taby)+tabx));}
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

unsigned char nacisniecie_przycisku()
{
	int pomoc=0;
	unsigned char klawisz;
    fflush(stdin);
    klawisz=getch();
    if (klawisz==KLAWISZ_ESC && kbhit()) klawisz=getch(); /* wykombinowalem polaczenie na oba systemy*/
	
	if (klawisz==KLAWISZ_STRZALKI)
    {
        klawisz=getch();
	if (klawisz==(KLAWISZ_STRZALKA_W_GORE-100)) klawisz+=100; 
	if (klawisz==(KLAWISZ_STRZALKA_W_LEWO-100)) klawisz+=100;
	if (klawisz==(KLAWISZ_STRZALKA_W_PRAWO-100)) klawisz+=100; 
	if (klawisz==(KLAWISZ_STRZALKA_W_DOL-100)) klawisz+=100;
        fflush(stdin);
	}
	return klawisz;
}

/*
NIEPOTRZEBNE (ZREZYGNOWA£EM Z TEJ MECHANIKI TEMPA):
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
*/

void wyswietl(char **T, int xT, int yT, int x0, int y0, int xkur, int ykur, int tryb_tempa, int dystans, int czas)
{
	/* chyba dzia³a œwetnie */
	int i, j, imin, imax, jmin, jmax, pomx, pomy;
	/* kursor wzgledem ekranu jest na: (30, 30) */
	pomx=(x_ekran-1)/2;
	pomy=(y_ekran-1)/2;
	imin=xkur-pomx;
	imax=xkur+pomx;
	jmin=ykur-pomy;
	jmax=ykur+pomy;
	wyczysc();
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
			case 2: {printf(" Tempo: "); if (tryb_tempa) printf("widok"); else printf("w tle");} break;
			/*NIEPOTRZEBNE (ZREZYGNOWA£EM Z TEJ MECHANIKI TEMPA):case 2: printf(" Tempo: %.1fx",tempo(skala_tempa)); break;*/
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

void wyczysc()
{
	#ifdef STWIERDZONO_WINDOWS
		system("cls");
	#else
		system("clear");
	#endif
}

char** przydziel_pamiec_tablicy_pomocniczej(int xT, int yT, char *awaria)
{
	/* na testach zdaje siê dzia³aæ dobrze */
	char **P=NULL;
	int i, j, przydzial_udany=1;
	P=malloc(yT*sizeof(char*));
	if (P!=NULL)
	{
		for (i=0;i<yT;i++)
		{
			*(P+i)=NULL;
			*(P+i)=malloc(xT*sizeof(char));
			if ((*(P+i))==NULL) przydzial_udany=0;
		}
		if (przydzial_udany)
		{
			for (i=0;i<xT;i++)
			{
				for (j=0;j<yT;j++)
				{
					*(*(P+j)+i)=0;
				}
			}
		}
		else
		{
			*awaria=34;
			zwolnij_pamiec(P,yT);
			P=NULL;
		}
	}
	else
	{
		*awaria=34;
	}
	return P;
}

void zmien_tryb_tempa(int *wsk_tryb_tempa)
{
	if (*wsk_tryb_tempa) *wsk_tryb_tempa=0;
	else *wsk_tryb_tempa=1;
}
/*NIEPOTRZEBNE (ZREZYGNOWA£EM Z TEJ MECHANIKI TEMPA):
void zmien_skale_tempa(int *wsk_skala_tempa)
{
	(*wsk_skala_tempa)++;
	if ((*wsk_skala_tempa)>4) *wsk_skala_tempa=-1;
}
*/

void zmien_dystans(int *wsk_dystans)
{
	/* dystans 1 3 5 10 20 40 */
	switch (*wsk_dystans)
	{
		case 1: *wsk_dystans=3; break;
		case 3: *wsk_dystans=5; break;
		case 5: *wsk_dystans=10; break;
		case 10: *wsk_dystans=20; break;
		case 20: *wsk_dystans=40; break;
		default: *wsk_dystans=1;
	}
}

char** zmniejsz_rozmiar_planszy_maksymalnie(char **D, int *xT, int *yT, int *x0, int *y0, char *awaria)
{
	/* przetestowana, prawopodobnie bezb³êdna */
	int wciecie_u=0, wciecie_d=0, wciecie_l=0, wciecie_r=0;
	int i, j, logika, stareyT;
	char **N=NULL;
	
	stareyT=(*yT);
	
	logika=1;
	j=(*yT)-1;
	while (logika && j>=0)
	{
		i=0;
		while (i<*xT)
		{
			if (*((*(D+j))+i)) logika=0;
			i++;
		}
		j--;
	}
	if (!logika)
	{
		wciecie_u=*yT-j-2;
		
		logika=1;
		i=(*xT)-1;
		while (logika && i>=0)
		{
			j=0;
			while (j<*yT)
			{
				if (*((*(D+j))+i)) logika=0;
				j++;
			}
			i--;
		}
		wciecie_r=*xT-i-2;
		
		logika=1;
		i=0;
		while (logika && i<*xT)
		{
			j=0;
			while (j<*yT)
			{
				if (*((*(D+j))+i)) logika=0;
				j++;
			}
			i++;
		}
		wciecie_l=i-1;
		
		logika=1;
		j=0;
		while (logika && j<*yT)
		{
			i=0;
			while (i<*xT)
			{
				if (*((*(D+j))+i)) logika=0;
				i++;
			}
			j++;
		}
		wciecie_d=j-1;
		*xT=(*xT)-wciecie_l-wciecie_r;
		*yT=(*yT)-wciecie_u-wciecie_d;
		*x0=(*x0)-wciecie_l;
		*y0=(*y0)-wciecie_d;
		N=przydziel_pamiec_tablicy_pomocniczej((*xT),(*yT),awaria);
		if (*awaria==0)
		{
			for (i=0;i<(*xT);i++)
			{
				for (j=0;j<(*yT);j++)
				{
					*((*(N+j))+i)=*((*(D+j+wciecie_d))+i+wciecie_l);
				}
			}
		}
	}
	else
	{
		/* tablica jest pusta */
		N=przydziel_pamiec_tablicy_pomocniczej(5,5,awaria);
		*xT=5;
		*yT=5;
	}
	zwolnij_pamiec(D,stareyT);
	return N;
}

char** zwieksz_rozmiar_planszy(char **D, int *xT, int *yT, int *x0, int *y0, char *awaria, int u, int l, int r, int d)
{
	/* przetestowana, œwietnie dzia³a */
	int i, j, stareyT=(*yT);
	char **N=NULL;
	N=przydziel_pamiec_tablicy_pomocniczej((*xT)+l+r,(*yT)+u+d,awaria);
	if (*awaria==0)
	{
		for (i=0;i<(*xT);i++)
		{
			for (j=0;j<(*yT);j++)
			{
				*((*(N+j+d))+i+l)=*((*(D+j))+i);
			}
		}
	}
	*xT=(*xT)+l+r;
	*yT=(*yT)+u+d;
	*x0=(*x0)+l;
	*y0=(*y0)+d;
	zwolnij_pamiec(D,stareyT);
	return N;
}

char** zmniejsz_rozmiar_planszy(char **D, int *xT, int *yT, int *x0, int *y0, char *awaria)
{
	D=zmniejsz_rozmiar_planszy_maksymalnie(D,xT,yT,x0,y0,awaria);
	if (*awaria==0)
	{
		D=zwieksz_rozmiar_planszy(D,xT,yT,x0,y0,awaria,stand_margin_pustki,stand_margin_pustki,stand_margin_pustki,stand_margin_pustki);
	}
	return D;
}

void zmien_stan_komorki(char ***T, char ***P, int *xT, int *yT, int *x0, int *y0, int xkur, int ykur, char *awaria)
{
	/* *(*(*T+y)+x) */
	
	/* prostokat: (-x0,-y0) w kartez. lewy dolny róg prostok¹ta, a prawy górny (-x0+xT-1,-y0+yT-1) */
	int stareyT, dokonano_zmiany=0;
	stareyT=(*yT);
	
	if (xkur>((-1)*(*x0)+(*xT)-1))
	{
		*T=zwieksz_rozmiar_planszy(*T,xT,yT,x0,y0,awaria,0,0,xkur+(*x0)-(*xT)+1+stand_margin_pustki,0);
		dokonano_zmiany=1;
	}
	else
	{
		if (xkur<((-1)*(*x0)))
		{
			*T=zwieksz_rozmiar_planszy(*T,xT,yT,x0,y0,awaria,0,(-1)*(*x0)-xkur+stand_margin_pustki,0,0);
			dokonano_zmiany=1;
		}
	}
	if (*awaria==0)
	{
		if (ykur>((-1)*(*y0)+(*yT)-1))
		{
			*T=zwieksz_rozmiar_planszy(*T,xT,yT,x0,y0,awaria,ykur+(*y0)-(*yT)+1+stand_margin_pustki,0,0,0);
			dokonano_zmiany=1;
		}
		else
		{
			if (ykur<((-1)*(*y0)))
			{
				*T=zwieksz_rozmiar_planszy(*T,xT,yT,x0,y0,awaria,0,0,0,(-1)*(*y0)-ykur+stand_margin_pustki);
				dokonano_zmiany=1;
			}
		}
		if (*awaria==0)
		{
			if ((*(*(*T+(*y0)+ykur)+(*x0)+xkur))==1) (*(*(*T+(*y0)+ykur)+(*x0)+xkur))=0;
			else (*(*(*T+(*y0)+ykur)+(*x0)+xkur))=1;
			if (*awaria==0 && dokonano_zmiany)
			{
				zwolnij_pamiec(*P,stareyT);
				*P = przydziel_pamiec_tablicy_pomocniczej(*xT,*yT,awaria);
			}
		}
	}
}

void wykonaj_krok(char ***T, char ***P, int *xT, int *yT, int *x0, int *y0, char ZSD[], char *awaria)
{
	int czy_u=0, czy_d=0, czy_l=0, czy_r=0, i, j, v, w, suma, zywa, stareyT;
	char **zamiana;
	
	stareyT=(*yT);
	for (i=0;i<(*xT);i++)
	{
		if (*(*(*T+0)+i)==1) czy_d=1;
		if (*(*(*T+(*yT)-1)+i)==1) czy_u=1;
	}
	for (i=0;i<(*yT);i++)
	{
		if (*(*(*T+i)+0)==1) czy_l=1;
		if (*(*(*T+i)+(*xT)-1)==1) czy_r=1;
	}
	*T=zwieksz_rozmiar_planszy(*T,xT,yT,x0,y0,awaria,czy_u?stand_margin_pustki:0,czy_l?stand_margin_pustki:0,czy_r?stand_margin_pustki:0,czy_d?stand_margin_pustki:0);
	if (*awaria==0)
	{
		zwolnij_pamiec(*P,stareyT);
		*P = przydziel_pamiec_tablicy_pomocniczej(*xT,*yT,awaria);
		if (*awaria==0)
		{
			/*
			(a,b) - wspolrzedne tablicowe
			(a-x0,b-y0) - odpowiadajace wsp. kartez.
			*/
			for (j=0;j<(*yT);j++)
			{
				for (i=0;i<(*xT);i++)
				{
					suma=0;
					for (v=(-1);v<2;v++)
					{
						for (w=(-1);w<2;w++)
						{
							suma+=TT(i-(*x0)+w,j-(*y0)+v,*T,*xT,*yT,*x0,*y0);
						}
					}
					zywa=TT(i-(*x0),j-(*y0),*T,*xT,*yT,*x0,*y0);
					if (zywa) suma--;
					*(*(*P+j)+i)=ZSD[(zywa?0:liczba_zasad_1)+suma];
				}
			}
			zamiana=*P;
			*P=*T;
			*T=zamiana;
		}
	}
}

int czy_w_lewo(unsigned char komunikacja)
{
	if ((komunikacja==KLAWISZ_STRZALKA_W_LEWO) || (komunikacja==KLAWISZ_A) || (komunikacja==KLAWISZ_a)) return 1;
	return 0;
}

int czy_w_prawo(unsigned char komunikacja)
{
	if ((komunikacja==KLAWISZ_STRZALKA_W_PRAWO) || (komunikacja==KLAWISZ_D) || (komunikacja==KLAWISZ_d)) return 1;
	return 0;
}

int czy_w_gore(unsigned char komunikacja)
{
	if ((komunikacja==KLAWISZ_STRZALKA_W_GORE) || (komunikacja==KLAWISZ_W) || (komunikacja==KLAWISZ_w)) return 1;
	return 0;
}

int czy_w_dol(unsigned char komunikacja)
{
	if ((komunikacja==KLAWISZ_STRZALKA_W_DOL) || (komunikacja==KLAWISZ_S) || (komunikacja==KLAWISZ_s)) return 1;
	return 0;
}

int czy_klawisz_U(unsigned char komunikacja)
{
	if ((komunikacja==KLAWISZ_U) || (komunikacja==KLAWISZ_u)) return 1;
	return 0;
}

void wykonaj_krok_2(char ***T, char ***P, int *xT, int *yT, int *x0, int *y0, char ZSD[], char *awaria, int *czas)
{
	int stareyT;
	
	stareyT=(*yT);
	wykonaj_krok(T,P,xT,yT,x0,y0,ZSD,awaria);
	*czas=(*czas)+1;
	if (((*czas)%100)==0)
	{
		if (*awaria==0) *T=zmniejsz_rozmiar_planszy(*T,xT,yT,x0,y0,awaria);
		if (*awaria==0)
		{
			zwolnij_pamiec(*P,stareyT);
			*P = przydziel_pamiec_tablicy_pomocniczej(*xT,*yT,awaria);
		}
	}
}
