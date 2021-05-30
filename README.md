# String ir asociatyvūs konteineriai

Programa, skirta ištirti tekstui naudojant string ir asociatyvius (specifiškai - map) konteinerius.

## Programos diegimas

1. Parsisiųsti norimą programos versijos kodą iš releases;
2. Kodą sukompiliuoti per komandinę eilutę arba pasirinktą IDE;
Rankiniu būdu:
```sh
g++ main.cpp -o asociatyvuskont
```
Naudojant Makefile per Windows su mingw32-make:
```sh
mingw32-make -f MakeFileWin
```
Naudojant MacOS, Linux, ar kitą UNIX sistemą:
```sh
make -f MakeFile
```

## Pagrindinės funkcijos

1) Sukompiliavus programą ir ją paleidus, ji automatiškai apdoroja jai suteiktą tekstą faile input.txt.
2) Apdorodama tekstą programa visas raides padaro mažosiomis ir iš teksto ištraukia hipersaitus. (URL suradimas)
3) Jei paimtas žodis nėra hipersaitas, programa atitinkamai nuima skyrybos ženklus (ir apeina tam tikras išimtis, kurios randomos anglų kalboje).
4) Jei žodis tvarkingas, jis pridedamas prie map konteinerio ir atitinkamai didinamas žodžio pasikartojimų skaitliukas. (skirtingų žodžių skaičiavimas)
5) Kiekvienoje paragrafoje (paragrafas eina iki naujos eilutės) taip pat yra tikrinama, kuriose vietose pasikartoja tam tikri žodžiai. (cross-check)
6) Galų gale išvedamos cross-check lentelės kiekvienai paragrafai ir tada išvedama galutinė lentelė su visais skaitliukais.

## Versijos
* [v1.0](https://github.com/gustaz/StringAndAssociativeContainers/releases/tag/v1.0) Įgyvendintas esminis funkcionalumas
