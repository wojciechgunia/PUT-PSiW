<h1 align="left">Projekt: Święty Mikołaj</h1>

###

<p align="left">Programowanie Systemowe i Współbieżne<br>Wojciech Gunia</p>

###

<h2 align="left">Opis zadania:</h2>

###

<p align="left">Święty Mikołaj śpi w swojej chatce na biegunie północnym. Może go zbudzić<br>jedynie przybycie dziewięciu reniferów lub trzy spośród dziesięciu skrzatów,<br>chcących poinformować Mikołaja o problemach z produkcją zabawek (snu<br>Mikołaja nie może przerwać mniej niż dziewięć reniferów ani mniej niż trzy<br>skrzaty!). Gdy zbiorą się wszystkie renifery, Mikołaj zaprzęga je do sań,<br>dostarcza zabawki grzecznym dzieciom (oraz studentom realizującym pilnie<br>zadania z synchronizacji współbieżnych procesów), wyprzęga je i pozwala<br>odejść na spoczynek. Mikołaj zbudzony przez skrzaty wprowadza je do biura,<br>udziela konsultacji, a później żegna. Obsługa reniferów ma wyższy priorytet<br>niż obsługa skrzatów.<br><br>Cel zadania: synchronizacja Św. Mikołaja, reniferów i skrzatów.</p>

###

<h2 align="left">Algorytm:</h2>

###

<p align="left">W pliku main.cpp znajdziemy algorytm uruchamiający i synchronizujący wątki Mikołaja <br>z reniferami i skrzatami. W ich implementacji wykorzystano wątki threads, a do ich <br>synchronizacji mechanizmów condition_variable oraz mutex. Program tworzy wątek <br>Mikołaja, a następnie w nieskończonej pętli co sekundę tworzy nowy wątek renifera lub<br>skrzata. Po powstaniu określonej liczby elfów lub skrzatów, wątek Mikołaja zostaje <br>wybudzony i wchodzi z nimi w interakcję, powodując ich kontynuację i zakończenie. <br>Następnie wątek Mikołaja oczekuje na kolejne wybudzenie.</p>

###

<h2 align="left">Kompilacja i uruchomienie:</h2>

###

<p align="left">Windows: Należy otworzyć plik /Windows/main.cpp za pomocą środowiska obsługującego <br>standard C++ 11 lub nowszy, a następnie skompilować kod.<br><br>Linux: Należy skompilować plik /Linux/main.cpp za pomocą terminala i komendy <br>"g++ -g -Wall main.cpp", a następnie odpalić program wynikowy.<br><br>Do zakończenia działania programu należy użyć kombinacji klawiszy Ctrl+c.</p>

###

<div align="left">
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/cplusplus/cplusplus-original.svg" height="40" alt="cplusplus logo"  />
  <img width="12" />
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/windows8/windows8-original.svg" height="40" alt="windows8 logo"  />
  <img width="12" />
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/linux/linux-original.svg" height="40" alt="linux logo"  />
</div>

###