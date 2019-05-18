/*
PLAN REALIZACJI PROJEKTU
Niewykonane:
	Opisz program ogólnie w pliku readme.txt. Okreœl specyfikacjê zadania i dane wejœciowe.
	Dodaj nazwy plików wynikowych i plików danych wejœciowych do readmme.txt i opisz standard ich zawartoœci.
	Œwiat tych automatów komórkowych ma byæ nieskoñczony. Mo¿na te¿ dodaæ mo¿liwoœæ tworzenia torusa.
	pamiêtaj: d0 musi zasze wynosiæ 0, aby pusta przestrzeñ nie ulega³a samowype³nieniu.
	W przyk³adach poka¿ zasady gry w ¿ycie Conway'a oraz Gosper Glider Gun. Niech bêd¹ równie¿ pocz¹tkowymi zawartoœciami plików wejœciowych.
	Dodaj instrukcjê u¿ycia programu - nie wewn¹trz jego samego.
	WASD / strza³ki - zmiana perspektywy, np. o 20 pól, przycisk zmiany wielkoœci kroku przesuwania - 1, 10, 20 .. 60 z wyœwietleniem aktualnej wartoœci na marginesie
	Dodaj przycisk zmiany d³ugoœci jednego kroku z wyœwietlaniem na marginesie. Mo¿na te¿ wyœwietlaæ liczebnoœæ populacji, po³o¿enie kursora itp.
	U¿ytkownik mo¿e zmieniaæ minimaln¹ d³ugoœæ kroku czasowego w ENTER-auto, SPACJA-krok.
	Do pliku readme.txt dodaj wyjaœnienia planowanych oznaczeñ komórek w programie:
	' ' - 
	'O' - 
	'^' - 
	'X' - 
	Do przyjmowania poleceñ od u¿ytkownika w trakcie dzia³ania programu wszêdzie u¿ywaj getch() z conio.h
	Linux - https://linux.die.net/man/3/sleep / Windows - sleep() windows.h, ifdef itp. 
	Warunkowo zdefiniuj dzielnik, jeœli funkcje sleep() wymagaj¹ innych jednostek.
Wykonane:
	Rezygnujê z wieloœci kolorów.
	SprawdŸ czy polskie znaki dzia³aj¹ pod innym systemem operacyjnym. Wyniki eksperymentu:
		na Windowsie wszysko dzia³aja
		w paiza.io nie dzia³a
		na Linuxie - napisany program testowy z polskimi znakami wykaza³, ¿e znaki z mojego programu tworzone t¹ metod¹ nie zadzia³aj¹ na Linuxie -
	Wobec tego rezygnujê z polskich znaków w programie.


Nigdy nie "commituj" pliku wykonywalnego ani pliku 000commit.txt zawieraj¹cego opis commita.
*/

#include <stdio.h>
#include <stdlib.h>

char **T;
int Tx, Ty, x0, y0;

void zwieksz_rozmiar_planszy(int u, int l, int r, int d); // planowane funkcje
void zmniejsz_rozmiar_planszy(); // obcina planszê zostawiaj¹c margines pustki równy marginesowi dodawanemu. Wywo³ywaæ np. co 100 kroków.
char TT(int x, int y);

int main(int agrc, char *argv[])
{
	return 0;
}
