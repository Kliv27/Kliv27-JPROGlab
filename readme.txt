Program umo�liwia symulowanie w konsoli (na systemach z rodziny Windows i Linux - nie jest przeznaczony na inne, ale raczej zadzia�a) wszystkich automat�w kom�rkowych spe�niaj�cych nastepuj�ce warunki:
- s� dwuwymiarowe (dwa wymiary przestrzenne i czas);
- kom�rki s� u�o�one w s�siedztwie Moore'a (ka�da ma 8 s�siad�w);
- kom�rki mog� znajdowa� si� w dw�ch stanach (martwym - 0, �ywym - 1);
- przysz�y stan kom�rki zale�y wy��cznie od jej stanu obecnego oraz od ��cznej liczby jej �ywych s�siad�w - te parametry wraz z zestawem zasad okre�laj� w spos�b jednoznaczny jej stan przysz�y;

Specyfikacja zadania programu:
   Dane wej�ciowe:
	- zestaw zasad steruj�cych (okre�laj�cy dany automat kom�rkowy);
	- stan pocz�tkowy kom�rek
   Dane wyj�ciowe:
	- stan ko�cowy uk�adu kom�rek
W trakcie dzia�ania programu mo�liwe jest modyfikowanie stanu aktualnego przy pomocy edytora wewn�trz programu. Umo�liwia on r�wnie� wy�wietlanie chwilowego stanu uk�adu. Nie jest jednak mo�liwe zmienianie zasad w trakcie pracy programu. Mo�na to osi�gn�� jedynie zamykaj�c program (jego stan si� zapisze) i uruchamiaj�c go ponownie dopiero po podmianie zawarto�ci pliku a.txt na t� z out.txt i modyfikacji pliku zasady.txt. 

Ile ��cznie jest takich automat�w kom�rkowych? Mo�na to �atwo policzy�:
Dana kom�rka mo�e si� znajdowa� w dw�ch stanach - dwie mo�liwo�ci.
Spo�r�d 8 jej s�siad�w najmniejsza liczba �ywych kom�rek to 0 a najwy�sza to 8 - razem 9 mo�liwo�ci.
Oba powy�sze zdarzenia s� niezale�ne, wi�c ��czna liczba ich mo�liwo�ci to 2 x 9 = 18
Zatem dla 18 r�nych sytuacji w jakich mo�e si� znale�� kom�rka zestaw zasad przypisuje pewien wynik (stan kom�rki w nast�pnym kroku). Mo�liwe s� dwa stany: kom�rka martwa (0) lub �ywa (1). Wobec tego ��czna liczba sposob�w dobrania tych 18 zasad to 2 do pot�gi 18, czyli 262144.

Po�owa z nich przyporz�tkowuje martwej kom�rce z o�mioma martwymi s�siadami kom�rk� �yw�. Oznacza to, �e pusta przestrze� ulega samowype�nieniu. Jest to niedopuszczalne z przyczyn obliczeniowych, poniewa� program musi alokowa� dynamicznie pami�� w taki spos�b, aby wszystkie �ywe kom�rki mie�ci�y si� w strefie dost�pnej pami�ci. Wobec tego - aby unikn�� problem�w - zasada d0 zawsze b�dzie przez program ustawiana na 0, niezale�nie od danych wej�ciowych. Symulowanie cz�ci pozosta�ych 131072 automat�w kom�rkowych mo�na realizowa� poprzez odwr�cenie zasad - nale�y traktowa� kom�rki �ywe jak martwe a martwe jak �ywe przy ustawieniu regu�.

Wszelkie pliki powi�zane z programem musz� znajdowa� si� w tym samym katalogu co plik wykonywalny.
Dane wej�ciowe dla programu przechowywane s� w dw�ch plikach. Pierwszym z nich jest zasady.txt. Zawiera on zestaw zasad postaci:
"an: X"
"dn: X"
gdzie:
"n" jest liczb� ca�kowit� od 0 do 8;
"X" jest liczb� ca�kowit� r�wn� 0 lub 1;
an - okre�la stan kom�rki �ywej w nast�pnym kroku, je�li ma ona n �ywych s�siad�w w kroku obecnym;
dn - okre�la stan kom�rki martwej w nast�pnym kroku, je�li ma ona n �ywych s�siad�w w kroku obecnym;
Przyk�adowa zawarto�� pliku zasady.txt przedstawiona jest poni�ej, mi�dzy znakami ------- (w przyk�adzie poni�ej s� ustawione zasady Gry w �ycie John'a Conway'a b�d�cej jedynie jedn� z kilkuset tysi�cy mo�liwo�ci programu):
--------------------------------------------
a0: 0
a1: 0
a2: 1
a3: 1
a4: 0
a5: 0
a6: 0
a7: 0
a8: 0
d0: 0
d1: 0
d2: 0
d3: 1
d4: 0
d5: 0
d6: 0
d7: 0
d8: 0
--------------------------------------------
Drugim z plik�w wej�ciowych jest a.txt, kt�ry zawiera pocz�tkowy stan uk�adu. Sk�ada si� on jedynie ze znak�w:
- 0
- 1
- nowej linii (nie wyst�puje tu problem z r�nicami mi�dzy znakiem nowej linii na systemach z rodziny Windows i Linux - dzia�aj� obydwie metody zapisania znaku nowej linii)
D�ugo�� ka�dej linii tego pliku powinna by� identyczna. Mo�e by� dowolnie dobrana (pod warunkiem, �e wszystkie linie s� r�wnej d�ugo�ci). Liczba wierszy r�wnie� jest dowolna.
Przyk�adowa zawarto�� pliku a.txt przedstawiona jest poni�ej, mi�dzy znakami ------- (w przyk�adzie poni�ej widoczny jest zal��ek uk�adu Gosper Glider Gun z Gry w �ycie John'a Conway'a):
----------------------------------------------------------------------------------------
000000000000000000000000000001010000
000000000000000000000011000001100000
000000000000000000000010100000100000
000000010000110000000001100000000011
000001010001010000000000000000000011
110000110001100000000000000000000000
110000000000000000000000000000000000
----------------------------------------------------------------------------------------

out.txt - plik zawieraj�cy wynik dzia�ania programu po jego zako�czeniu. Ma identyczn� budow� jak plik a.txt.

EDYTOR
Stan uk�adu wy�wietlany jest w ekranie o wymiarach 61 x 61. Ekran ten mo�na przesuwa� po niesko�czonym �wiecie (z ograniczeniem do mo�liwo�ci obliczeniowych komputera). Po jego prawej stronie znajduje si� margines z informacjami. Na samym �rodku ekranu znajduje si� kursor. S�u�y on do zmieniania stanu kom�rki, na kt�ry wskazuje. Jest to mo�liwe wy��cznie w czasie, gdy symulacja jest zatrzymana.
Oznaczenia wyst�puj�ce na planszy:
' ' - oznacza martw� kom�rk�;
'O' - oznacza �yw� kom�rk�;
'^' - oznacza kursor, je�li pod nim jest martwa kom�rka;
'X' - oznacza kursor, je�li pod nim jest �ywa kom�rka;

STEROWANIE:
przyciski WASD lub strza�ki - do przemieszczania widoku (i kursora) po wirtualnym �wiecie;
przycisk ESC - do zako�czenia pracy programu (stan ko�cowy zostanie zapisany automatycznie);
przycisk SPACJA - wykonanie jednego kroku czasowego;
przycisk ENTER - przej�cie mi�dzy stanem EDYCJI (pauzy) a stanem ci�g�ego automatycznego wykonywania krok�w przez program;
przycisk T - zmiana tempa;
przycisk U - zmiana dystansu, na jaki przemieszcza si� kursor;
przycisk O - zmiana stanu kom�rki pod kursorem w trybie edycji;