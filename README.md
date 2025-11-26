# Termuzelky (tymovy projekt pri studiu UO)
Tento repozitar obsahuje jednoduchou konzolovou hru Kuzelky napsanou v jazyce C++.

## Obsah repozitare
. main.cpp - hlavni soubor hry
. kuzelky.cpp, kuzelky.h - logika kuzelek, vykreslovani jednotlivych stavu schozenych kuzelek a sprava hodu
. draha.cpp, draha.h - animace drahy a pohyb koule
. vypocet_skore.cpp, vypocet_skore.h - vypocet skore hry

## Jak zkompilovat a spustit
Projekt lze zkompilovat nasledujicim prikazem:
```bash
cd "/CESTA/K/ADRESARI" && g++ main.cpp draha.cpp kuzelky.cpp vypocet_skore.cpp -std=c++17 -Wall -Wextra -pthread -o main && ./main
```

## Jak ptispivat
. forknuti originalniho repozitare (https://github.com/SmerovacDusan/informatika-tymovy-projekt) a po uprave nasledny pull request (spravce projektu https://github.com/SmerovacDusan)

## Kontakt / autori
. spravce, hlavni programator: github.com/SmerovacDusan
. hlavni programator: github.com/novoma05
. pomocny programator: github.com/kopec-221
. napad, grafika, koordinace: github.com/LiberaFatum
. vypocet skore: github.com/Speron4
. vykreslovani stavu kuzelek: github.com/zznkrskova
