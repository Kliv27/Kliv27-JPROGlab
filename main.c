/*
PLAN REALIZACJI PROJEKTU
Niewykonane:
	Opisz program og�lnie w pliku readme.txt. Okre�l specyfikacj� zadania i dane wej�ciowe.
	Dodaj nazwy plik�w wynikowych i plik�w danych wej�ciowych do readmme.txt i opisz standard ich zawarto�ci.
	�wiat tych automat�w kom�rkowych ma by� niesko�czony. Mo�na te� doda� mo�liwo�� tworzenia torusa.
	pami�taj: d0 musi zasze wynosi� 0, aby pusta przestrze� nie ulega�a samowype�nieniu.
	W przyk�adach poka� zasady gry w �ycie Conway'a oraz Gosper Glider Gun. Niech b�d� r�wnie� pocz�tkowymi zawarto�ciami plik�w wej�ciowych.
	Dodaj instrukcj� u�ycia programu - nie wewn�trz jego samego.
	WASD / strza�ki - zmiana perspektywy, np. o 20 p�l, przycisk zmiany wielko�ci kroku przesuwania - 1, 10, 20 .. 60 z wy�wietleniem aktualnej warto�ci na marginesie
	Dodaj przycisk zmiany d�ugo�ci jednego kroku z wy�wietlaniem na marginesie. Mo�na te� wy�wietla� liczebno�� populacji, po�o�enie kursora itp.
	U�ytkownik mo�e zmienia� minimaln� d�ugo�� kroku czasowego w ENTER-auto, SPACJA-krok.
	Do pliku readme.txt dodaj wyja�nienia planowanych oznacze� kom�rek w programie:
	' ' - 
	'O' - 
	'^' - 
	'X' - 
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


Nigdy nie "commituj" pliku wykonywalnego ani pliku 000commit.txt zawieraj�cego opis commita.
*/

#include <stdio.h>
#include <stdlib.h>

char **T;
int Tx, Ty, x0, y0;

void zwieksz_rozmiar_planszy(int u, int l, int r, int d); // planowane funkcje
void zmniejsz_rozmiar_planszy(); // obcina plansz� zostawiaj�c margines pustki r�wny marginesowi dodawanemu. Wywo�ywa� np. co 100 krok�w.
char TT(int x, int y);

int main(int agrc, char *argv[])
{
	return 0;
}
