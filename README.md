# Block_1

## Versijų istorija (changelog)

### [v.0.1.2]() 2020-10-22

- Pataisytas README failas (pseudokodas, stiprybės/trūkumai);
- Ankščiau nepaminėta, kad buvo sukurtos papildomos programos tikrinti porų kolizijoms bei konvertuoti hashus į binary sistemą;
- Pataisytos papildomos programos, tapo optimalesnės;
- Pridėta daugiau kompentarų;


### [v.0.1.1](https://github.com/GudUgne/Block_1/releases/tag/v0.1.1) 2020-10-16

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

- Pasirenkama - tekstas faile ar įvedimas ranka;

- Prasideda ciklas cikle: pirmas ciklas ( nuo 0 eina per kiekvieną simbolį atskirai)
- Kiekvienas simbolis paverčiamas į intą pagal ASCII;
- Padauginamas iš savo pozicijos;
- Jei pasiekia labai didelį skaičių, mažinamas, nes kitaip skaičius užeitų už kintamojo ribų ir tiesiog užtruktų ilgiau;
- Antras ciklas(kviečiamas 16 kartų):
- Skaičius yra didinamas aritmetine ir geometrine progresijomis;
- Vyksta spausdinimas:
- Antras ciklas sukūrė tokio dydžio skaičių, kad jo užtenka 4 arba 5 hasho simboliams sukurti;
- Pirmas if'as tikrina ar paskutiniai 5 skaitmenys viršija 65535 (FFFF pavertus į decimal, gauname šią sumą), jei viršija, negerai, atspausdins netinkama hashą, tokiu atvėju vyksta else ir į hexą verčiami paskutiniai 4 skatmenys;
- Jei vis dėl to 5 skaitmenys neviršija 65535, tada 5 skaitmenys konvertuojami į 4 hasho simbolius;
- Viskas daroma ciklais tol, kol išspausdinama 16 grupių po 4 simbolius;


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
- Binary max panašumų 238, min panašumų - 64, o kiekvienoje poroje simboliai vidutiniškai kartojasi 135 kartus;


## Kodo stiprybės

- Greitas veikimas;
- Mažai kolizijų;
- Individualus hashavimo būdas, nesiremta jau sukurtais hash'ais;

## .. bei trūkumai

- Kodas nėra optimalus, naujam vartotojui gali būti sunku naudotis;
- Kodas reikalingas analizei vykdyti nėra sujungtas su pagrindine programa;
- Nėra exception handling;
