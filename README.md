# Block_1

## Įdiegimas (Unix sistemoje)

## Versijų istorija (changelog)

### [v.0.1.1]() 2020-10-15

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


## Analizė


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
