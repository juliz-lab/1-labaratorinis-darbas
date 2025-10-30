**Julija Kučinskaitė** <br>
**Vilniaus universitetas** <br>
**Duomenų mokslas** <br>
**Objektinis programavimas** <br>
**1 laboratorinis darbas** <br>

**V0.1** <br>
1. Funkcija galutiniam pažymiui skaičiuoti;
2. Įvesta galimybė naudotojui pasirinkti medianos ar vidurkio įvertinimo skaičiavimą;
3. Sukurta atskira funkcija įvesto pažymio tikrinimui;
4. Sukurtas atsitiktinių pažymių generavimas;
5. Sukurta galimybė nuskaityti duomenis iš .txt failo;
6. Pridėta išvestis į vartotojo nurodomą failą;
7. Pridėtas rezultatų rikiavimas pagal pavardę ir vardą.

**V0.2** <br>
1. Sukurta studentų duomenų generavimo programa;
3. Sukurta funkcija studentų išskaidymui į išlaikiusius ir neišlaikiusius;
4. Pridėta galimybė vartotojui pasirinkti, pagal ką rikiuoti rezultatus;
5. Funkcijos ir struktūros perkeltos į atskirus failus;

**V0.3** <br>
1. Pridėtas objekto vietos atmintyje spausdinimas;
2. Pridėta galimybė duomenis talpinti ir std::list struktūroje;
3. Atlikta programos spartos analizė taikant std::vector ir std::list konteinerius. <br>

Analizės apžvalga. Matuoti trys programos etapai: studentų surūšiavimas į moksliukus ir nemokšas, duomenų išrikiavimas pagal galutinį pažymį, rezultatų įrašymas į failus. Testai atlikti 3 kartus.

Rezultatai:
<table>
  <caption><b>Surūšiavimas į dvi grupes:</b></caption>
    <thread>
      <tr>
        <th>Įrašų skaičius</th>
        <th>Vektoriaus vid.</th>
        <th>Sąrašo vid.</th>
      </tr>
    </thread>
    <tbody>
      <tr>
        <td>1000</td>
        <td>0,0004</td>
        <td>0,0007</td>
      </tr>
      <tr>
        <td>10000</td>
        <td>0,0026</td>
        <td>0,0039</td>
      </tr>
      <tr>
        <td>100000</td>
        <td>0,0311</td>
        <td>0,0448</td>
      </tr>
      <tr>
        <td>1000000</td>
        <td>0,3509</td>
        <td>0,3538</td>
      </tr>
      <tr>
        <td>10000000</td>
        <td>2,8381</td>
        <td>3,7053</td>
      </tr>
    </tbody>
</table>

<table>
  <caption><b>Išrikiavimas:</caption>
    <thread>
      <tr>
        <th>Įrašų skaičius</th>
        <th>Vektoriaus vid.</th>
        <th>Sąrašo vid.</th>
      </tr>
    </thread>
    <tbody>
      <tr>
        <td>1000</td>
        <td>0,0006</td>
        <td>0,0005</td>
      </tr>
      <tr>
        <td>10000</td>
        <td>0,0029</td>
        <td>0,0044</td>
      </tr>
      <tr>
        <td>100000</td>
        <td>0,0538</td>
        <td>0,1112</td>
      </tr>
      <tr>
        <td>1000000</td>
        <td>0,6387</td>
        <td>1,0909</td>
      </tr>
      <tr>
        <td>10000000</td>
        <td>7,9140</td>
        <td>15,6038</td>
      </tr>
    </tbody>
</table>

<table>
  <caption><b>Įrašymas į failus:</caption>
    <thread>
      <tr>
        <th>Įrašų skaičius</th>
        <th>Vektoriaus vid.</th>
        <th>Sąrašo vid.</th>
      </tr>
    </thread>
    <tbody>
      <tr>
        <td>1000</td>
        <td>0,0182</td>
        <td>0,0218</td>
      </tr>
      <tr>
        <td>10000</td>
        <td>0,0461</td>
        <td>0,0610</td>
      </tr>
      <tr>
        <td>100000</td>
        <td>0,5138</td>
        <td>0,5286</td>
      </tr>
      <tr>
        <td>1000000</td>
        <td>4,8555</td>
        <td>4,9960</td>
      </tr>
      <tr>
        <td>10000000</td>
        <td>48,7652</td>
        <td>49,2713</td>
      </tr>
    </tbody>
</table>


**Išvados:**
- Surūšiavimas su visų dydžių duomenimis vektoriaus yra greitesnis nei sąrašo (list).
- Žymus išrikiavimo laiko skirtumas yra su 10 mln. duomenų. Vektorius yra vidutiniškai 7,7 sek. greitesnis.
- Įrašymo į failus laikas yra truputį greitesnis vektroriaus.


Kompiuterio, su kuriuo atlikta analizė, parametrai: 2.00 GHz procesorius, 8.00 GB RAM, SSD 477 GB.

**V1.0** <br>
Atlikta studentų rūšiavimo į dvi skirtingas grupes pagal galutinį pažymį spartos analizė pagal 3 strategijas:
1) Ankstesniose versijose taikytas metodas - skaidyti studentus į nemoksas į moksliukus tiesiog iteruojant per Grupę ir išrūšiuojant juos į atitinkamus konteinerius.
2) Iteruojam Grupes elementus (studentus) ir tikrinam jų galutinį pažymį. Neišlaikiusius išsaugome naujame konteineryje "nemoksos" ir ištriname juos iš Grupes, todėl Grupeje lieka tik "moksliukai". Čia jokie `<algorithm>` metodai nepanaudoti, sužaista su move() ir erase() funkcijom.
3) Panaudojamos <algorithm> bibliotekos funkcijos partition() ir remove_if(), kurios leidžia efektyviai suskirstyti studentus į grupes pagal pažymį.

Rezultatai: 
<table>
  <caption><b>1 STRATEGIJA</caption>
    <thread>
      <tr>
        <th>Irašų skaičius</th>
        <th>VEKTORIUS</th>
        <th>SĄRAŠAS</th>
      </tr>
    </thread>
      <tbody>
        <tr>
          <td>1000</td>
          <td>0.0002</td>
          <td>0.0003</td>
        </tr>
        <tr>
          <td>10000</td>
          <td>0.0008</td>
          <td>0.0016</td>
        </tr>
        <tr>
          <td>100000</td>
          <td>0.0074</td>
          <td>0.0166</td>
        </tr>
        <tr>
          <td>1000000</td>
          <td>0.0761</td>
          <td>0.1643</td>
        </tr>
        <tr>
          <td>10000000</td>
          <td>3.2367</td>
          <td>5.8738</td>
        </tr>
      </tbody>
  </b>
      </tbody>
      </thread>
</table>


<table>
  <caption><b>2 STRATEGIJA</caption>
    <thread>
      <tr>
        <th>Irašų skaičius</th>
        <th>VEKTORIUS</th>
        <th>SĄRAŠAS</th>
      </tr>
    </thread>
      <tbody>
        <tr>
          <td>1000</td>
          <td>0.0001</td>
          <td>0.0001</td>
        </tr>
        <tr>
          <td>10000</td>
          <td>0.0004</td>
          <td>0.0007</td>
        </tr>
        <tr>
          <td>100000</td>
          <td>0.00029</td>
          <td>0.0008</td>
        </tr>
        <tr>
          <td>1000000</td>
          <td>0.0322</td>
          <td>0.0837</td>
        </tr>
        <tr>
          <td>10000000</td>
          <td>0.5013</td>
          <td>0.9885</td>
        </tr>
      </tbody>
  </b>
      </tbody>
      </thread>
</table>


<table>
  <caption><b>3 STRATEGIJA</caption>
    <thread>
      <tr>
        <th>Irašų skaičius</th>
        <th>VEKTORIUS</th>
        <th>SĄRAŠAS</th>
      </tr>
    </thread>
      <tbody>
        <tr>
          <td>1000</td>
          <td>0.0001</td>
          <td>0.0001</td>
        </tr>
        <tr>
          <td>10000</td>
          <td>0.0006</td>
          <td>0.0011</td>
        </tr>
        <tr>
          <td>100000</td>
          <td>0.0074</td>
          <td>0.0137</td>
        </tr>
        <tr>
          <td>1000000</td>
          <td>0.0727</td>
          <td>0.1341</td>
        </tr>
        <tr>
          <td>10000000</td>
          <td>1.0301</td>
          <td>1.7417</td>
        </tr>
      </tbody>
  </b>
      </tbody>
      </thread>
</table>
<br>
**Išvados:** <br>
- 2 strategija su dideliais failais (įskaitant 10 mln) tiek su vektoriu tiek su sąrašu veikia stulbinamai greitai. <br>
- Vektorius yra geresnis pasirinkimas duomenų saugojimui, nes praktiškais visais atvejais veikia greičiau už sąrašą. <br>
- Su mažais duomenų kiekiais (1000-10000 įrašais) paprastesnė 1 strategija veikia kiek greičiau už kitas. <br>
- 3 strategijai praktiškai neturi įtakos konteinerio tipo pasirinkimas.
<br> <br>
**Naudojimosi instrukcija** <br>
1. Įsitikinkite, kad savo kompiuteryje turite įdiegtus C++ kompiliatorių bei projekto generavimo įrankius cmake, jei ne – įsidiekite. <br>
    * Komandinėje eilutėje parašykite g++ --version, cmake --version. <br>
2. Parsisiųskite failus main.cpp, mylib.cpp, mylib.h, timer.h ir CMakeLists.txt. <br>
3. Sukurkite aplanką, kuriame bus vykdomas kodo paleidimas. Į jį įkelkite parsisiųstą failą CMakeLists.txt ir sukurkite aplankus „src“ bei „include“. <br>
4. Į aplanką „src“ perkelkite visus parsisiųstus projekto .cpp failus, į aplanką „include“ – visus projekto .h failus. <br>
5. Per komandinę eilutę nueikite iki savo aplankalo, kuriame paruošti failai programos paleidimui. Tuomet komandinėje eilutėje parašykite šias komandas: <br>
  5.1. mkdir build <br>
  5.2. cd build <br>
  5.3. cmake [-DCMAKE_BUILD_TYPE=Release] .. <br>
  5.4. cmake --build . <br>
6. Buvo sukurtas vykdomasis failas v1_0.exe. Belieka jį pavykdyti, į komandinę eilutę parašant v1_0.exe. <br>
