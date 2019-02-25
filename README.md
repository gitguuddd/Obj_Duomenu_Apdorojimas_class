
## Versijų istorija (changelog)
### [v0.3](https://github.com/gitguuddd/Obj_Duomenu_apdorojimas/releases/tag/v0.3)
(2019-02-25)

**Pridėta**
- ```Input.h, Mutual.h, Output.h, Mutual.cpp, Output.cpp, Input.cpp```
- Input handling (pagrinde ```cin.fail()```)
- Naudojami ```vector.reserve()``` ir ```vector.shrink_to_fit()```
- Exception handling (```try - catch```) ties ```students.push_back``` ir ```stud.nd.push_back```, nes pereita prie vektorių atminties rezervavimo
- Input handling nuskaitant failą - galima nuskaityti namų darbų pažymius net ir jei jie yra ne skaičiai arba mazesni uz 0/ didesni uz 10 (aptikus - nulinami), jei netinkamas input yra ilgesnis nei 4 simboliai - didelė rizika sugadinti nuskaitytų duomenų tikslumą 
- Nested switch meniu klaidų spausdinimui
- Programos struktūros sekcija README.MD faile
- ![alt text](Meme.jpg "Send Bob")

**Koreguota**
- Panaikinti goto, taip pat ir easter egg (LINEKAPUT:), perdaryta switch logika.
- Pasirodo, kad senesnių versijų duomenys nebuvo labai tikslūs, duomenys patikslinti.
- kursiokai.txt failas tikslingai sucorruptintas norint išbandyti input handling'a.
### [v0.2](https://github.com/gitguuddd/Obj_Duomenu_apdorojimas/releases/tag/v0.2)
(2019-02-18)

**Pridėta**
 - Kursiokai.txt
 - Rūšiavimas pagal studento vardą ir pavardę
 - Nuskaitymas iš failo
 - Galimybė visais būdais gautus duomenis atspausdinti viename output sąraše
 - Primityvus switch'o error handling'as naudojant goto
 - Easter egg
 
 **Koreguota**
 - Pakeistas README.md failas
 
 **Žinomi trūkumai/ką reikia kuo greičiau ištaisyti**
 - Goto switche reikia pakeisti į normalų refactoringa dirbant prie v0.3
 - Studentų rikiavimas veiks keistokai jei bus naudojami ne vienodo ilgio vardai ir pavardės.
 - Nemažai vietų trūksta exception/error handling'o

### [v0.1](https://github.com/gitguuddd/Obj_Duomenu_apdorojimas/releases/tag/v0.1)
(2019-02-18)

**Pridėta**
- CMake failas
- Pirmininis programos ```cpp``` failas
- Alternatyvios programos (su masyvu ) ```cpp``` failas (veikiantis bardakas)

**Koreguota**
- Pakeistas README.md failas

## Programos struktūra
- ```Input.h``` ir ```Input.cpp``` funkcijos/kintamieji/include'ai susyję su duomenų įvedimu
- ```Output.h```ir ```Output.cpp``` funkcijos/kintamieji/include'ai susyję su duomenų išvedimu
- ```Mutual.h```ir ```Mutual.cpp``` funkcijos/kintamieji/include'ai bendri visai programai (```#include iostream```,```handleinput()``` )
- ```main.cpp``` pagrindinis failas - meniu