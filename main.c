/*
PLAN REALIZACJI PROJEKTU
Niewykonane:
	Sprawd� czy polskie znaki dzia�aj� pod innym systemem operacyjnym.
	Dodaj polskie znaki do programu.
	Opisz program og�lnie w pliku readme.txt. Okre�l specyfikacj� zadania i dane wej�ciowe.
	�wiat tych automat�w kom�rkowych ma by� niesko�czony. Mo�na te� doda� mo�liwo�� tworzenia torusa.
	Dodaj nazwy plik�w wynikowych i plik�w danych wej�ciowych do readmme.txt i opisz standard ich zawarto�ci.
	pami�taj: d0 musi zasze wynosi� 0, aby pusta przestrze� nie ulega�a samowype�nieniu.
	W przyk�adzie poka� zasady gry w �ycie Conway'a.
	Dodaj instrukcj� u�ycia programu - nie wewn�trz jego samego.
	WASD / strza�ki - zmiana perspektywy, np. o 20 p�l, przycisk zmiany wielko�ci kroku przesuwania - 1, 10, 20 .. 60 z wy�wietleniem aktualnej warto�ci na marginesie
	Do przyjmowania polece� od u�ytkownika w trakcie dzia�ania programu wsz�dzie u�ywaj getch() z conio.h
	Linux - https://linux.die.net/man/3/sleep / Windows - sleep() windows.h, ifdef itp. 
	Dodaj przycisk zmiany d�ugo�ci jednego kroku z wy�wietlaniem na marginesie. Mo�na te� wy�wietla� liczebno�� populacji, po�o�enie kursora itp.
	U�ytkownik mo�e zmienia� minimaln� d�ugo�� kroku czasowego w ENTER-auto, SPACJA-krok, warunkowo zdefiniuj dzielnik, je�li funkcje sleep() wymagaj� innych jednostek.
	Rezygnuj� z wielo�ci kolor�w.
	Do pliku readme.txt dodaj wyja�nienia planowanych oznacze� kom�rek w programie:
	' ' - 
	'O' - 
	'^' - 
	'X' - 
Wykonane:



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
