Projekt: Święty Mikołaj
Programowanie Systemowe i Współbieżne
Wojciech Gunia

========================================================================================

Opis zadania:

Święty Mikołaj śpi w swojej chatce na biegunie północnym. Może go zbudzić
jedynie przybycie dziewięciu reniferów lub trzy spośród dziesięciu skrzatów,
chcących poinformować Mikołaja o problemach z produkcją zabawek (snu
Mikołaja nie może przerwać mniej niż dziewięć reniferów ani mniej niż trzy
skrzaty!). Gdy zbiorą się wszystkie renifery, Mikołaj zaprzęga je do sań,
dostarcza zabawki grzecznym dzieciom (oraz studentom realizującym pilnie
zadania z synchronizacji współbieżnych procesów), wyprzęga je i pozwala
odejść na spoczynek. Mikołaj zbudzony przez skrzaty wprowadza je do biura,
udziela konsultacji, a później żegna. Obsługa reniferów ma wyższy priorytet
niż obsługa skrzatów.
Cel zadania: synchronizacja Św. Mikołaja, reniferów i skrzatów.

========================================================================================

Algorytm:

W pliku main.cpp znajdziemy algorytm uruchamiający i synchronizujący wątki Mikołaja 
z reniferami i skrzatami. W ich implementacji wykorzystano wątki threads, a do ich 
synchronizacji mechanizmów condition_variable oraz mutex. Program tworzy wątek 
Mikołaja, a następnie w nieskończonej pętli co sekundę tworzy nowy wątek renifera lub
skrzata. Po powstaniu określonej liczby elfów lub skrzatów, wątek Mikołaja zostaje 
wybudzony i wchodzi z nimi w interakcję, powodując ich kontynuację i zakończenie. 
Następnie wątek Mikołaja oczekuje na kolejne wybudzenie.

========================================================================================

Kompilacja i uruchomienie:

Windows: Należy otworzyć plik /Windows/main.cpp za pomocą środowiska obsługującego 
standard C++ 11 lub nowszy, a następnie skompilować kod.

Linux: Należy skompilować plik /Linux/main.cpp za pomocą terminala i komendy 
"g++ -g -Wall main.cpp", a następnie odpalić program wynikowy.

Do zakończenia działania programu należy użyć kombinacji klawiszy Ctrl+c.

========================================================================================