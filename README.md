# Block_1

## Versijų istorija (changelog)

### [v.0.1.1]() 2020-10-16

- Įkelti testiniai failai, sugeneruoti tie, kurių reikalavo sąlyga (atskiru kodu);
- Programa papildyta, kad atitiktų visus reikalavimus;
- Atlikta veikimo analizė;
- Testai 11 ir 12 - turi po vieną skirtingą simbolį;
- Testai 21 ir 22 - atsitiktinai sugeneruoti simboliai;
- Testai 31 ir 32 - failai, kurie skiriasi tik vienu simboliu;
- Output'as yra 64 simbolių hex'as;


### [v.0.1](https://github.com/GudUgne/Block_1/releases/tag/v0.1) 2020-10-09

- Bazinė hašuojanti programa;
- Dar nedaryta analizė;
- Galimybė vesti norimą hašuoti tekstą ranka arba skaityti iš failo;


# Analizė


## Pseudo kodas

- paimamas simbolis iš failo/įvedamas ranka;
- paverčiamas į int pagal ASCII;
- padauginamas iš savo pozicijos;
- jei pasiekia labai didelį skaičių, mažinamas, nes kitaip skaičius užeitų už kintamojo ribų;
- vėliau skaičius yra didinamas aritmetine ir geometrine progresijomis;
- kai pasiekia tam tikrą ribą, yra žiūrimi paskutiniai 5 skaičiai, jei jie yra didesni už 65535, iš paskutinių 4 yra verčiama į hexadecimal sistemą, kitu atveju - iš paskutinių 5;
- viskas daroma ciklu tol, kol išspausdinama 16 grupių po 4 simbolius;


## Testinių failų sutapimas
Kai yra po vieną skirtingą simbolį

![Kai yra po vieną skirtingą simbolį](https://github.com/GudUgne/Block_1/blob/main/Screenshot_1.png)


Kai yra > 1000 atsitiktinių

![Kai yra > 1000 atsitiktinių](https://github.com/GudUgne/Block_1/blob/main/Screenshot_2.png)

Kai yra > 1000 simbolių, o skiriasi tik 1

![Kai yra > 1000 simbolių, o skiriasi tik 1](https://github.com/GudUgne/Block_1/blob/main/Screenshot_3.png)


- Hashinant tuščią failą, hashas gaunamas toks pat;

- Žinoma, hashinant tokį patį tekstą, hashas išlieka, o pakeitus tekstą minimaliai - hashas visiškai skiriasi;

- Generuojant įvairaus simbolių ilgių poras sutapimų nebuvo (tikrinta pasirašius atskirą mažą programėlę);

- Konstitucija:
Hashinimas truko 0.0411979 sek.


## Porų panašumai

- Sugeneravus poras ir palyginus remiantis 4 ir 5 punktų sąlyga, vienodų porų nebuvo;
- Remiantis 6 punktu, hex lygmenyje max panašumų buvo 55, min - 0, o bendras vidurkis - 7 vienodi simboliai;
- Binary max 238, min - 64, o kiekvienoje poroje vidutiniškai kartojasi 135 kartus;
