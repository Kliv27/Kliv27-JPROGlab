Program umo¿liwia symulowanie w konsoli (na systemach z rodziny Windows i Unix - nie jest przeznaczony na inne) wszystkich automatów komórkowych spe³niaj¹cych nastêpuj¹ce warunki:
- s¹ dwuwymiarowe (dwa wymiary przestrzenne i czas);
- komórki s¹ u³o¿one w s¹siedztwie Moore'a (ka¿da ma 8 s¹siadów);
- komórki mog¹ znajdowaæ siê w dwóch stanach (martwym - 0, ¿ywym - 1);
- przysz³y stan komórki zale¿y wy³¹cznie od jej stanu obecnego oraz od ³¹cznej liczby jej ¿ywych s¹siadów - te wartoœci wraz z zestawem zasad okreœlaj¹ w sposób jednoznaczny jej stan przysz³y;

Specyfikacja zadania programu:
   Dane wejœciowe:
	- zestaw zasad steruj¹cych (okreœlaj¹cy dany automat komórkowy);
	- stan pocz¹tkowy komórek
   Dane wyjœciowe:
	- stan koñcowy uk³adu komórek
W trakcie dzia³ania programu mo¿liwe jest modyfikowanie stanu aktualnego przy pomocy edytora wewn¹trz programu. Umo¿liwia on równie¿ wyœwietlanie chwilowego stanu uk³adu. Nie jest jednak mo¿liwe zmienianie zasad w trakcie pracy programu. Mo¿na to osi¹gn¹æ jedynie zamykaj¹c program (jego stan siê zapisze) i uruchamiaj¹c go ponownie dopiero po podmianie zawartoœci pliku a.txt na t¹ z out.txt i modyfikacji pliku zasady.txt. 

INSTALACJA:
	Pod systemem Windows:
1. Dokonaj kompilacji kodu Ÿród³owego zawartego w pliku main.c za pomoc¹ kompilatora jêzyka C. Mo¿e to byæ np. kompilator wewn¹trz œrodowiska programistycznego. Je¿eli je¿eli nie masz takiego oprogramowania, to je pobierz (istniej¹ darmowe programy).
2. Powstanie plik .exe, który zasadniczo powinien byæ uruchamiany tylko na sprzêcie, na którym nast¹pi³a kompilacja. Umieœæ ten plik w jednym folderze wraz z plikami a.txt, zasady.txt i out.txt.
3. Je¿eli nie posiadasz tych plików, stwórz je wed³ug wzorów ich zawartoœci, które mo¿esz znaleŸæ w dalszej czêœci tego pliku informacyjnego.
4. Plik wykonywalny (.exe) jest gotowy do uruchomienia.
	Pod systemem Linux:
1. Dokonaj kompilacji kodu Ÿród³owego zawartego w pliku main.c za pomoc¹ kompilatora jêzyka C.
$ mkdir Automat
$ cd ./Automat
$ cp [sciezka]/main.c ./automat.c
Je¿eli dysponujesz odpowiednim kompilatorem, to prawdopodobnie (zak³adaj¹c miêdzy innymi, ¿e twoj¹ pow³ok¹ jest bash) mo¿esz tego dokonaæ jednym z poni¿szych poleceñ:
$ cc automat.c -o automat
$ gcc automat.c -o automat
2. Powstanie plik wykonywalny o nazwie "automat", który zasadniczo powinien byæ uruchamiany tylko na sprzêcie, na którym nast¹pi³a kompilacja. Umieœæ ten plik w jednym folderze wraz z plikami a.txt, zasady.txt i out.txt.
3. Je¿eli nie posiadasz tych plików, stwórz je wed³ug wzorów, które mo¿esz znaleŸæ w dalszej czêœci tego pliku informacyjnego.
$ touch a.txt
$ touch out.txt
$ touch zasady.txt
$ echo “010” >> a.txt
$ echo “011” >> a.txt
$ echo "a0: 0" >> zasady.txt
$ echo "a1: 0" >> zasady.txt
$ echo "a2: 1" >> zasady.txt
$ echo "a3: 1" >> zasady.txt
...
$ echo "d7: 0" >> zasady.txt
$ echo "d8: 0" >> zasady.txt
4. Plik wykonywalny "automat" jest gotowy do uruchomienia.
$ ./automat

Oczywiœcie instalacji dokonuje siê tylko raz. Za ka¿dym kolejnym razem wystarczy przejœæ od razu do punktu 4.

Ile ³¹cznie jest takich automatów komórkowych? Mo¿na to ³atwo policzyæ:
Dana komórka mo¿e siê znajdowaæ w dwóch stanach - dwie mo¿liwoœci.
Spoœród 8 jej s¹siadów najmniejsza mo¿liwa liczba ¿ywych komórek to 0 a najwiêksza to 8 - razem 9 mo¿liwoœci.
Oba powy¿sze zdarzenia s¹ niezale¿ne, wiêc ³¹czna liczba ich mo¿liwoœci to 2 x 9 = 18
Zatem dla 18 ró¿nych sytuacji w jakich mo¿e siê znaleŸæ komórka zestaw zasad przypisuje pewien wynik (stan komórki w nastêpnym kroku). Mo¿liwe s¹ dwa stany: komórka martwa (0) lub ¿ywa (1). Wobec tego ³¹czna liczba sposobów dobrania tych 18 zasad to 2 do potêgi 18, czyli 262144.

Po³owa z nich przyporz¹dkowuje martwej komórce z oœmioma martwymi s¹siadami komórkê ¿yw¹. Oznacza to, ¿e pusta przestrzeñ ulega samowype³nieniu. Jest to niedopuszczalne z przyczyn obliczeniowych, poniewa¿ program musi alokowaæ dynamicznie pamiêæ w taki sposób, aby wszystkie ¿ywe komórki mieœci³y siê w strefie dostêpnej pamiêci. Wobec tego - aby unikn¹æ problemów - zasada d0 zawsze bêdzie przez program ustawiana na 0, niezale¿nie od danych wejœciowych. Symulowanie czêœci pozosta³ych 131072 automatów komórkowych mo¿na realizowaæ poprzez odwrócenie zasad - nale¿y traktowaæ komórki ¿ywe jak martwe a martwe jak ¿ywe przy ustawieniu regu³.

Wszelkie pliki powi¹zane z programem musz¹ znajdowaæ siê w tym samym katalogu co plik wykonywalny.
Dane wejœciowe dla programu przechowywane s¹ w dwóch plikach. Pierwszym z nich jest zasady.txt. Zawiera on zestaw zasad postaci:
"an: X"
"dn: X"
gdzie:
"n" jest liczb¹ ca³kowit¹ od 0 do 8;
"X" jest liczb¹ ca³kowit¹ równ¹ 0 lub 1;
an - okreœla stan komórki ¿ywej w nastêpnym kroku, jeœli ma ona n ¿ywych s¹siadów w kroku obecnym;
dn - okreœla stan komórki martwej w nastêpnym kroku, jeœli ma ona n ¿ywych s¹siadów w kroku obecnym;
Zasady musz¹ byæ przedstawione w œciœle okreœlonej kolejnoœci - takiej, jak w niniejszym przyk³adzie.
Przyk³adowa zawartoœæ pliku zasady.txt przedstawiona jest poni¿ej, miêdzy znakami ------- (w poni¿szym przyk³adzie ustawione s¹ zasady Gry w ¯ycie John'a Conway'a bêd¹cej jedynie jedn¹ z kilkuset tysiêcy mo¿liwoœci programu):
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
Drugim z plików wejœciowych jest a.txt, który zawiera pocz¹tkowy stan uk³adu. Sk³ada siê on jedynie ze znaków:
- 0
- 1
- nowej linii (nie wystêpuje tu problem z ró¿nicami miêdzy znakiem nowej linii na systemach z rodziny Windows i Linux - dzia³aj¹ obydwie metody zapisania znaku nowej linii)
D³ugoœæ ka¿dej linii tego pliku powinna byæ identyczna. Mo¿e byæ dowolnie dobrana (pod warunkiem, ¿e wszystkie linie s¹ równej d³ugoœci). Liczba wierszy równie¿ jest dowolna.
Przyk³adowa zawartoœæ pliku a.txt przedstawiona jest poni¿ej, miêdzy znakami ------- (w przyk³adzie poni¿ej widoczny jest zal¹¿ek uk³adu Gosper Glider Gun z Gry w ¯ycie John'a Conway'a):
----------------------------------------------------------------------------------------
000000000000000000000000000001010000
000000000000000000000011000001100000
000000000000000000000010100000100000
000000010000110000000001100000000011
000001010001010000000000000000000011
110000110001100000000000000000000000
110000000000000000000000000000000000
----------------------------------------------------------------------------------------

out.txt - plik zawieraj¹cy wynik dzia³ania programu po jego zakoñczeniu. Ma identyczn¹ budowê jak plik a.txt.

EDYTOR
Stan uk³adu wyœwietlany jest w ekranie o wymiarach 61 x 61. Ekran ten mo¿na przesuwaæ po nieskoñczonym œwiecie (z ograniczeniem do mo¿liwoœci obliczeniowych komputera). Po jego prawej stronie znajduje siê margines z informacjami. Na samym œrodku ekranu znajduje siê kursor. S³u¿y on do zmieniania stanu komórki, na który wskazuje. Jest to mo¿liwe wy³¹cznie w czasie, gdy symulacja jest zatrzymana.
Oznaczenia wystêpuj¹ce na planszy:
  " " - oznacza martw¹ komórkê;
  "O" - oznacza ¿yw¹ komórkê;
  "^" - oznacza kursor, jeœli pod nim jest martwa komórka;
  "X" - oznacza kursor, jeœli pod nim jest ¿ywa komórka;
Na marginesie poza plansz¹ w prawym górnym rogu widoczne s¹ wartoœci opisuj¹ce bie¿¹c¹ sytuacjê. Podaj¹ one maksymalnie 6 cyfr. Oto, co oznaczaj¹:
  Populacja - podaje ³¹czn¹ liczbê ¿ywych komórek w chwili obecnej;
  Czas - podaje numer iteracji (kroku czasowego) przyjmuj¹c, ¿e stan pocz¹tkowy to chwila oznaczana jako 0;
  Tempo - podaje chwilowo wybrany (jeden z dwóch) sposobów dzia³ania trybu automatycznego. Symulacja "w tle" jest szybsza, ale jej kroki nie s¹ widoczne.
  Dystans - podaje, na jak¹ odleg³oœæ przesunie siê perspektywa w edytorze;
  x, y - podaj¹ po³o¿enie (w dyskretnym kartezjañskim uk³adzie wspó³rzêdnych) komórki znajduj¹cej siê pod kursorem (na œrodku planszy);
Wspó³rzêdne kartezjañskie jednoznacznie identyfikuj¹ komórkê w przestrzeni - jest ona powi¹zana ze swoimi przesz³ymi i przysz³ymi stanami. Dziêki nim mo¿na okreœliæ to, jak uk³ad komórek (np. statek) siê przemieœci³.

STEROWANIE:
przyciski WASD lub strza³ki - do przemieszczania widoku (i kursora) po wirtualnym œwiecie, dzia³aj¹ równie¿ w trybie automatycznym;
przycisk ESC - do zakoñczenia pracy programu (stan koñcowy zostanie zapisany automatycznie) - wymaga zatrzymania symulacji (wy³¹czenia trybu automatycznego);
przycisk SPACJA - wykonanie jednego kroku czasowego;
przycisk ENTER - przejœcie miêdzy stanem EDYCJI (pauzy) a stanem ci¹g³ego automatycznego wykonywania kroków przez program;
przycisk T - zmiana sposobu dzia³ania trybu automatycznego (widocznego jako Tempo) - przycisk nie jest mo¿liwy do u¿ycia w trakcie dzia³ania trybu automatycznego - naciœniêcie go niczego nie spowoduje;
przycisk U - zmiana dystansu, na jaki przemieszcza siê perspektywa/kursor - mo¿na u¿ywaæ w trybie automatycznym;
przycisk O - zmiana stanu komórki pod kursorem w trybie edycji - nie mo¿liwe do u¿ycia w trybie automatycznym;