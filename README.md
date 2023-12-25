# Projektas 1
Projektas 1 v1.0

# Parametrai

|                        **CPU**                       |            **RAM**           |          **SSD**         |
|:----------------------------------------------------:|:----------------------------:|:------------------------:|
|   Intel(R) Celeron(R) CPUJ3455 @ 1.50 GHz 1.50 GHz   |     6 GB (5.85 naudotina)    | 58.4 GB (laisva 3.37 GB) |

# Versija v0.1:
Pradinėje programos versijoje, programa nuskaito vartotojų įvestus duomenis. Apdorojami duomenys ir su jais atliekami skaičiavimai, tai yra išvedami studentų vardas ir pavardė, ir jų rezultatai apskaičiuojami pagal formulę: 0.4*vidurkis/mediana + 0.6*egzaminas. Programa taip pat suteikia galimybę vartotojui nuskaityti duomenis iš failo ir sugeneruoti duomenis automatiškai. Programoje duomenys rūšiuojami pagal vardą ar pavardę ir joje taip pat panaudojamas išimčių valdymas.

# Versija v0.2: 
Patobulinta v0.1: programa kuria nurodyto dydžio failus. Studentų sąrašas padalinamas pagal kriterijų į du konteinerius. Konteineriuose esantys duomenys išvedami į naujus failus. Šioje versijoje atliekamas programos operacijų laiko trukmės matavimas. Taip pat vartotojui suteikiamas pasirinkimas pagal ką rūšiuoti (vardą/pavardę/pažymį).

# Versija v0.3:
Programoje std::vector<Studentai> pakeičiamas į std::list<Studentai> ir stebimi programos pokyčiai. Atlikus testus su programa savo kompiuteryje buvo pastebėta, kad naudojant <list> duomenų rūšiavimas buvo spartesnis, tačiau kitos operacijos kaip duomenų padalinimas į du konteinerius ir duomenų surašymas į failus užtruko ilgiau nei naudojant <vector>. Šioje versijoje prie studento duomenų išvedamas objekto saugojimo atmintyje adresas. 

# Versija v1.0:


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

|    **Testavimas**    | **1 000 ** | **10 000** | **100 000** | **1 000 000** | **10 000 000** |
|:--------------------:|:----------:|:----------:|:-----------:|:-------------:|:--------------:|
|      Nuskaitymas     |  0.0169311 |  0.108048  |   1.05017   |    12.4627    |     115.033    |
|      Rūšiavimas      |  0.0018016 |  0.0260735 |   0.400509  |    5.56375    |     77.0567    |
|      Padalinimas     |  0.0005952 |  0.0060376 |  0.0674251  |    0.986994   |      14.29     |
|  kietiakai surašymas |  0.0049674 |  0.0220177 |   0.201933  |    1.97096    |     23.6769    |
| vargšiukai surašymas |  0.0032952 |  0.015003  |   0.137754  |    1.38223    |     17.4768    |
|        bendras       |  0.0275905 |  0.1771798 |    1.8577   |    22.3666    |    282.5334    |

# List su strategija 1, 2, ir 3

|       **Testavimas**       |  **1 000** | **10 000** | **100 000** | **1 000 000** | **10 000 000** |
|:--------------------------:|:----------:|:----------:|:-----------:|:-------------:|:--------------:|
|      Failo nuskaitymas     |  0.0161149 |  0.1232576 |   1.176474  |    12.1417    |    123.6986    |
|         Rūšiavimas         | 0.00065016 | 0.01090172 |  0.2132942  |    3.321684   |     48.9476    |
|      Padalinimas 1 st.     | 0.00148918 | 0.01898806 |  0.1933934  |    2.251044   |    66.58564    |
|            2 st.           | 0.00069446 | 0.00970616 |  0.1109578  |    1.277226   |    24.96208    |
|            3 st.           |  0.0004266 | 0.00561224 |  0.07756816 |    0.922889   |    17.81402    |
|  kietiakai surašymas 1 st. | 0.00631702 | 0.02226062 |  0.2230144  |    2.284976   |     78.24      |
|            2 st.           |  0.003194  | 0.02702238 |   0.238118  |    2.51337    |    26.86538    |
|            3 st.           |  0.0046935 |   0.0256   |  0.2520192  |    2.572662   |    26.67326    |
| vargšiukai surašymas 1 st. | 0.00273956 | 0.01781874 |  0.1547266  |    1.549844   |     56.9757    |
|            2 st.           | 0.00251178 |  0.0185258 |  0.1695084  |    1.756564   |    15.005782   |
|           3 st.            |    3e-07   |    5e-07   |    6e-07    |     7e-07     |      5e-07     |
|        bendras 1 st.       |  0.0264752 |  0.197736  |    1.9609   |    21.5493    |     310.552    |
|            2 st.           |  0.0211652 |    0.184   |   1.822626  |    19.56236   |    216.7232    |
|            3 st.           |  0.0243322 |  0.1742964 |   1.655924  |    18.12688   |    200.9078    |
