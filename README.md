# Projektas 2
Projektas 2 v2.0

# Versija 2.0
v1.5 programiniam kodui sukurta dokumentacija naudojantis Doxygen.

# Programos paleidimo instrukcija
1. Tuščiame aplanke sukuriame du naujus aplankus: Incude ir src. Į 'Include' aplanką sukeliame header failus (pch.h), o į 'src'
visus programos cpp failus (main.cpp, pch.cpp), bei tekstinius failus su duomenimis. Bendrame aplanke turi būti CMakeLists.txt failas ir pagal pasirinkimą galima sukurti RUNMEE.bat failą su komandomis kurios reikalingos norint paleisti programai. Tame pačiame faile yra ir CMake programos instaliatorius.

<img width="687" alt="Screenshot 2023-12-27 212048" src="https://github.com/taurinho13/My-first-project/assets/146191931/c2f5e128-94d5-44ec-b231-64406b88850d">

2. Įjungiame powershell:
   
<img width="687" alt="Screenshot 2023-12-27 212638" src="https://github.com/taurinho13/My-first-project/assets/146191931/d845bbd6-aead-4dc0-b18b-8ca01d4182c9">

3. Tuomet suvedamos komandos: cmake CMakeLists.txt; cmake --install . ; cmake --build . ;

<img width="854" alt="Screenshot 2023-12-27 213127" src="https://github.com/taurinho13/My-first-project/assets/146191931/ac0c7ddb-4eb7-420d-bda5-9501e9838d46">

4. Programa dar neveiks, nes aplanke iš kurio vykdoma programa, nėra failų su duomenimis kuriuos programa apdoroja, todėl juos nukopijuojame iš 'src' į 'Debug' aplanką: copy src\students_1000.txt Debug\students_1000.txt; copy src\students_10000.txt Debug\students_10000.txt; copy src\students_100000.txt Debug\students_100000.txt
 
<img width="850" alt="Screenshot 2023-12-27 213713" src="https://github.com/taurinho13/My-first-project/assets/146191931/fe33fba7-bcfc-451e-a2a6-b3cb21e11bed">

5. Tuomet nueiname į Debug aplanką ir paleidžiame exe failą:

<img width="687" alt="image" src="https://github.com/taurinho13/My-first-project/assets/146191931/5054853c-9bca-4aa7-abce-da25c89bf6b8">

arba ją paleidžiame per komandinę eilutę:

<img width="837" alt="Screenshot 2023-12-27 214116" src="https://github.com/taurinho13/My-first-project/assets/146191931/eb3baf12-2af9-45e2-87d4-0e844a2030e1">

ir programa pradeda darbą. Pirmuoju atveju programa paleidžiama per Command Prompt, antruoju per Powershell.
Alternatyviai paleisti programą galima antrame žingsnyje įjungus powershell panaudojant bat failą kuriame yra visos aukščiau išvardintos komandos. Tam panaudojama komanda .\RUNMEE.bat:

<img width="614" alt="Screenshot 2023-12-27 215217" src="https://github.com/taurinho13/My-first-project/assets/146191931/208e332e-36d4-4190-938a-b6c1d542d4f5">


# Parametrai

|                        **CPU**                       |            **RAM**           |          **SSD**         |
|:----------------------------------------------------:|:----------------------------:|:------------------------:|
|   Intel(R) Celeron(R) CPUJ3455 @ 1.50 GHz 1.50 GHz   |     6 GB (5.85 naudotina)    | 58.4 GB (laisva 3.37 GB) |

# Vectorius su strategija 1

|      Testavimas      |    1 000   |   10 000   |  100 000 | 1 000 000  | 10 000 000 |
|:--------------------:|:----------:|:----------:|:--------:|:----------:|:----------:|
|      Nuskaitymas     | 0.01345906 |  0.104796  |  1.04519 |   10.9532  |   108.312  |
|      Rūšiavimas      |  0.0013722 |  0.0256748 | 0.389636 |   5.55111  |   76.1943  |
|      Padalinimas     | 0.00045536 |  0.0059923 | 0.066721 |  0.989759  |   14.084   |
|  kietiakai surašymas |  0.0030653 |  0.0230104 | 0.198478 |   1.99002  |   20.324   |
| vargšiukai surašymas |  0.0021897 |  0.0161488 | 0.137186 |   1.35657  |   13.8472  |
|        Bendras       | 0.02054162 | 0.17562229 | 1.837211 |  20.840659 |  232.7615  |

# Vectorius su strategija 2

|    **Testavimas**    | **1 000** | **10 000** | **100 000** | **1 000 000** |   **10 000 000**   |
|:--------------------:|:----------:|:----------:|:-----------:|:-------------:|:------------------:|
|      Nuskaitymas     |  0.0126317 |  0.106484  |    1.0853   |     10.687    |       113.094      |
|      Rūšiavimas      |  0.0012471 |  0.0256391 |   0.395775  |    5.43938    |       75.8923      |
|      Padalinimas     |  0.0021445 |  0.216883  |   28.6432   |    2865.56    | Nepavyko išmatuoti |
|  kietiakai surašymas |  0.0028807 |  0.0234861 |   0.203199  |    2.13127    | Nepavyko išmatuoti |
| vargšiukai surašymas |  0.0021379 |  0.0149985 |   0.156963  |     1.4546    | Nepavyko išmatuoti |
|        bendras       |  0.0211233 |  0.3874907 |  30.484437  |   2885.27225  |                    |

# Vektorius su strategija 3

|    **Testavimas**    | **1 000** | **10 000** | **100 000** | **1 000 000** | **10 000 000** |
|:--------------------:|:----------:|:----------:|:-----------:|:-------------:|:--------------:|
|      Nuskaitymas     |  0.0169311 |  0.108048  |   1.05017   |    12.4627    |     115.033    |
|      Rūšiavimas      |  0.0018016 |  0.0260735 |   0.400509  |    5.56375    |     77.0567    |
|      Padalinimas     |  0.0005952 |  0.0060376 |  0.0674251  |    0.986994   |      14.29     |
|  kietiakai surašymas |  0.0049674 |  0.0220177 |   0.201933  |    1.97096    |     23.6769    |
| vargšiukai surašymas |  0.0032952 |  0.015003  |   0.137754  |    1.38223    |     17.4768    |
|        bendras       |  0.0275905 |  0.1771798 |    1.8577   |    22.3666    |    244.5334    |

# List su strategija 1, 2, ir 3

|       **Testavimas**       |  **1 000** | **10 000** | **100 000** | **1 000 000** | **10 000 000** |
|:--------------------------:|:----------:|:----------:|:-----------:|:-------------:|:--------------:|
|      Failo nuskaitymas     |  0.0161149 |  0.1232576 |   1.176474  |    12.1417    |    123.6986    |
|         Rūšiavimas         | 0.00065016 | 0.01090172 |  0.2132942  |    3.321684   |     48.9476    |
|      Padalinimas 1 st.     | 0.00148918 | 0.01898806 |  0.1933934  |    2.251044   |    66.58564    |
|            2 st.           | 0.00069446 | 0.00970616 |  0.1109578  |    1.277226   |    24.96208    |
|            3 st.           |  0.0011001 | 0.0193316  |   0.20794   |     2.3286    |     84.5341    |
|  kietiakai surašymas 1 st. | 0.00631702 | 0.02226062 |  0.2230144  |    2.284976   |     78.24      |
|            2 st.           |  0.003194  | 0.02702238 |   0.238118  |    2.51337    |    26.86538    |
|            3 st.           |  0.0020718 |  0.01868   |   0.158666  |    1.63161    |     19.8821    |
| vargšiukai surašymas 1 st. | 0.00273956 | 0.01781874 |  0.1547266  |    1.549844   |     56.9757    |
|            2 st.           | 0.00251178 |  0.0185258 |  0.1695084  |    1.756564   |    15.005782   |
|           3 st.            |  0.0029734 |  0.0211564 |  0.207162   |    2.03661    |     43.9575    |
|        bendras 1 st.       |  0.0264752 |  0.197736  |    1.9609   |    21.5493    |     372.552    |
|            2 st.           |  0.0211652 |    0.184   |   1.822626  |    19.56236   |    216.7232    |
|            3 st.           |  0.0243322 |  0.1742964 |   1.655924  |    18.12688   |     231.734    |


# Versija v0.1:
Pradinėje programos versijoje, programa nuskaito vartotojų įvestus duomenis. Apdorojami duomenys ir su jais atliekami skaičiavimai, tai yra išvedami studentų vardas ir pavardė, ir jų rezultatai apskaičiuojami pagal formulę: 0.4*vidurkis/mediana + 0.6*egzaminas. Programa taip pat suteikia galimybę vartotojui nuskaityti duomenis iš failo ir sugeneruoti duomenis automatiškai. Programoje duomenys rūšiuojami pagal vardą ar pavardę ir joje taip pat panaudojamas išimčių valdymas.

# Versija v0.2: 
Patobulinta v0.1: programa kuria nurodyto dydžio failus. Studentų sąrašas padalinamas pagal kriterijų į du konteinerius. Konteineriuose esantys duomenys išvedami į naujus failus. Šioje versijoje atliekamas programos operacijų laiko trukmės matavimas. Taip pat vartotojui suteikiamas pasirinkimas pagal ką rūšiuoti (vardą/pavardę/pažymį).

# Versija v0.3:
Programoje std::vector<Studentai> pakeičiamas į std::list<Studentai> ir stebimi programos pokyčiai. Atlikus testus su programa savo kompiuteryje buvo pastebėta, kad naudojant <list> duomenų rūšiavimas buvo spartesnis, tačiau kitos operacijos kaip duomenų padalinimas į du konteinerius ir duomenų surašymas į failus užtruko ilgiau nei naudojant <vector>. Šioje versijoje prie studento duomenų išvedamas objekto saugojimo atmintyje adresas. 

# Versija v1.0:
Iš praeitų versijų dviems konteinerių tipams (vector ir list) buvo taikoma viena studentų dalijimo į dvi kategorijas strategija. Versijoje 1.0 naudojamos dvi naujos dalijimo strategijos ir matuojama visų trijų strategijų sparta. Pirmoji - studentų konteineris padalijamas į du naujus konteinerius: kietiakai ir vargšiukai. Antroji strategija sukuria tik vieną naują konteinerį vargšiukai, ištrindama vargšiukus iš pradinio konteinerio ir jame palikdama tik kietiakus. Trečioji strategija yra spartesnės strategijos iš pirmų dviejų patobulinimas. Matuojant strategijų spartumą su vektoriumi pastebėjau, kad mano pirmoji strategija buvo greitesnė, todėl patobulinau ją panaudodamas algoritmą partition ir copy. Partition algoritmas suskirsto pradinį vektorių į dvi dalis pagal nurodytą sąlygą. Elementai tenkinantys sąlygą surikiuojami į pirmąją vektoriaus dalį, o netenkinantys patenka į antrąją. Tada copy algoritmas nukopijuoja pirmoje dalyje esančius elementus į naują vektorių, o likusius į kitą naują vektorių. 

Išvados:
Išmatavęs strategijų veikimo trukmę abiejų konteinerių atveju pastebėjau šiuos dalykus: Vector atveju 2-oji strategija veikė labai ilgai, 10 kartų didesniam duomenų failui duomenų padalinimas paiilgėdavo 100 kartų ir dėl šio paiilgėjimo nepavyko išmatuoti failo su 10 milijonų eilučių duomenų. Tokį ilgą strategijos veikimą priskirčiau žemam kompiuterio pajėgumui ir nepakankamai gerai sustrukturizuotam programiniam kodui. Todėl patobulinta buvo pirmoji strategija. Tačiau strategijos veikimas nepagreitėjo ir liko panašus (~14s veikė lėčiau). List atveju 2 strategija veikė greičiau už 1, bet patobulinus 2 ji suletėjo. Kadangi 2 strategija veikia greičiausiai ir užima mažiau atminties negu pirmoji todėl list atveju optimaliausia yra strategija 2, tačiau mano parašytam programiniam kodui vector atveju optimaliausia yra strategija 1, nes ji veikia greičiausiai ir neužima daugiau atminties negu 3-oji.

Naudojimosi instrukcija: 
Paleidus programą, vartotojas pasirenka ar duomenys generuojami automatiškai ar skaitomi iš failo. Pasirinkus opciją skaityti iš failo vartotojui tuomet leidžiama rinktis ar skaityti iš failo ar duomenis įvesti pačiam. Pirmame žingsnyje pasirinkus automatinį duomenų generavimą, vartotojas renkasi pagal ką bus rūšiuojami duomenys: pagal vardą, pavardę ar galutinį įvertinimą. Galiausiai vartotojas pasirenka strategiją pagal kurią bus apdorojami duomenys. Tuomet programa tikrina ar norimi sukurti failai jau egzistuoja, jei taip, tuomet failu kurimas praleidžiamas. 

# Versija v1.1:
testavimas programų operacijų trukmės su list naudojančią struct ir naudojančios class

|    **Testavimas**    | **100 000 (struct)** | **100 000 (class)** | **1 000 000 (struct)** | **1 000 000 (class)** |
|:--------------------:|:--------------------:|:-------------------:|:----------------------:|:---------------------:|
|      Nuskaitymas     |      1.060608 s      |      1.687356 s     |       10.96734 s       |       12.7896 s       |
|      Rūšiavimas      |      0.1943938 s     |     0.6281548 s     |        3.11798 s       |       9.068438 s      |
|      Padalinimas     |     0.09983484 s     |     0.10263866 s    |       1.198092 s       |       1.212832 s      |
|  Kietiakai surašymas |      0.2279868 s     |     0.2369668 s     |       2.347954 s       |       2.530776 s      |
| Vargšiukai surašymas |      0.1579266 s     |     0.1505388 s     |       1.574678 s       |        1.683 s        |
|        Bendras       |       1.74075 s      |      2.80565 s      |       19.20606 s       |       27.28464 s      |


Testavimas su priklausomybe nuo kompiliatoriaus optimizavimo su list naudojant struct
|    **Testavimas**    | **100 000 O1** | **1 000 000 O1** | **100 000 O2** | **1 000 000 O2** | **100 000 O3** | **1 000 000 O3** |
|:--------------------:|:--------------:|:----------------:|:--------------:|:----------------:|:--------------:|:----------------:|
|      Nuskaitymas     |     1.1332s    |     11.76288s    |    1.083664s   |      11.0147s    |    1.111056s   |     11.2204s     |
|      Rūšiavimas      |    0.1963912s  |      3.11804s    |    0.1943242s  |     3.114318s    |   0.1945002s   |     3.107342s    |
|      Padalinimas     |   0.09925314s  |      1.19777s    |    0.1009861s  |     1.201144s    |   0.09954998s  |     1.201328s    |
|  Kietiakai surašymas |    0.2294352s  |      2.42044s    |    0.243509s   |      2.33087s    |   0.2240376s   |     2.331014s    |
| Vargšiukai surašymas |    0.1549022s  |     1.647926s    |    0.2155586s  |     1.569412s    |   0.1566188s   |     1.60192s     |
|        Bendras       |    1.812392s   |     20.13288s    |    1.816642s   |     19.41466s    |    1.786362s   |     19.26294s    |



naudojant class
|    **Testavimas**    | **100 000 O1** | **1 000 000 O1** | **100 000 O2** | **1 000 000 O2** | **100 000 O3** | **1 000 000 O3** |
|:--------------------:|:--------------:|:----------------:|:--------------:|:----------------:|:--------------:|:----------------:|
|      Nuskaitymas     |    1.924606s   |     13.40491s    |     1.0423s    |     11.05904s    |    1.055416s   |     10.9818s     |
|      Rūšiavimas      |    0.6403236s  |      9.53741s    |    0.6024054s  |      8.9259s     |   0.6159908s   |     9.06301s     |
|      Padalinimas     |    0.1043056s  |     1.21553s     |   0.09920224s  |     1.198122s    |   0.10051744s  |     1.20797s     |
|  Kietiakai surašymas |    0.234864s   |      2.62226s    |    0.2234832s  |     2.485396s    |   0.2222678s   |     2.51677s     |
| Vargšiukai surašymas |    0.157575s   |     1.783294s    |    0.1479778s  |     1.655514s    |   0.1483184s   |     1.67435s     |
|        Bendras       |    3.061674s   |     28.56338s    |     2.11537s   |     25.32398s    |    2.142508s   |     25.4439s     |

list struct failo dydis be flag'ų: 108KB; list class: 114KB

| **flags** | **struct** | **class** |
|:---------:|:----------:|:---------:|
|     O1    |    64KB    |    73KB   |
|     O2    |    78KB    |    86KB   |
|     O3    |    80KB    |    86KB   |


# Versija v1.2:
Šioje versijoje vykdomas įvesties (>>) ir išvesties (<<) operatorių perdengimas. Šioje versijoje užtikrinama, kad klasėje galiotų "Rule Of Three" taisyklė, kuri teigia, jeigu naudojamas vienas iš šių: kopijavimo konstruktorius, kopijavimo priskyrimo konstruktorius arba destruktorius, tuomet turi būti panaudoti ir kiti du, norint, kad kopijavimas vyktų tinkamai. 

Klasė mano programoje su friend funkcijomis reikalingomis įvykdyti operatorių perdengimą, bei copy konstruktorius, copy assignment konstruktorius ir destruktorius: 
<img width="960" alt="klase" src="https://github.com/taurinho13/Project_2/assets/146191931/3fedeac2-7e10-45ab-a04e-444dbe800899">

Įvesties operatoriaus apibrėžimas ir jo naudojimas inputStudentData funkcijoje:
<img width="960" alt="operatoriusIN" src="https://github.com/taurinho13/Project_2/assets/146191931/cd1a5385-0f49-410a-8225-e027a0cc224a">
operatoriaus iškvietimas fukcijoje:
<img width="292" alt="operatoriaus_naudojimas" src="https://github.com/taurinho13/Project_2/assets/146191931/a5a28d6c-18d3-4cc4-902d-636a1ea3e4e4">

rule of three patikrinimas:
<img width="960" alt="ruleOfThree" src="https://github.com/taurinho13/Project_2/assets/146191931/3ab0e050-81da-41eb-bd3c-8e228079040e">


# Versija v1.5:
Iš turimos vienos klasės 'zmogus' sukuriamos dvi naujos klasės: bazinė klasė 'Person' ir jos išvestinė klasė 'zmogus'. 'Person' klasėje aprašyta bendresnė informacija kaip vardas ir pavardė, o detalesnė informacija kaip pažymiai aprašyti išvestinėje klasėje 'zmogus'. Šioje versijoje įvykdoma, kad 'Person' klasė būtų apbstrakčioji, tai yra jos klasės tipo objektų kūrimas neleidžiamas.
Abi klasės kode: 
<img width="960" alt="klases_abi" src="https://github.com/taurinho13/Project_2/assets/146191931/e2a12f76-c4b8-4ab3-81dc-96c0b65c8941">

Kuriant bazinės klasės objektą gaunama klaida, nes toks veiksmas neleistinas:
<img width="960" alt="person_ne" src="https://github.com/taurinho13/Project_2/assets/146191931/05b98417-cb14-4233-bfb9-ebcf776f8775">

užkomentavus ankstesnyjį veiksmą ir kuriant objektą pasinaudojus išvestine 'zmogus' klase objektas sukuriamas ir išvedamas su virtualia funkcija:
<img width="960" alt="zmog_obj" src="https://github.com/taurinho13/Project_2/assets/146191931/a8ed45ce-5121-40fb-bbae-aa64391305d3">

