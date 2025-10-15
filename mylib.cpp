#include "mylib.h"

void generuok_failus()
{
    int sk;
    char ats;
    cout << "Ar noretumete sugeneruoti failus dabar (t arba n)? ";
    cin >> ats;
    if (ats == 't')
    {
        cout << "Sugeneruosime 5 skirtingo dydzio failus. " << endl;
        cout << "Kiek pazymiu generuojam kiekvienam studentui? ";
        cin >> sk;
        cout << "Generuojami failai..." << endl;

        auto start = std::chrono::high_resolution_clock::now();
        auto st = start;
        failu_generavimas(1000, sk);
        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start; // Skirtumas (s)
        cout << "Failo su 1000 sukurimas uztruko: " << diff.count() << " s\n";

        start = std::chrono::high_resolution_clock::now();
        failu_generavimas(10000, sk);
        diff = std::chrono::high_resolution_clock::now() - start;
        cout << "Failo su 10000 sukurimas uztruko: " << diff.count() << " s\n";

        start = std::chrono::high_resolution_clock::now();
        failu_generavimas(100000, sk);
        diff = std::chrono::high_resolution_clock::now() - start;
        cout << "Failo su 100000 sukurimas uztruko: " << diff.count() << " s\n";

        start = std::chrono::high_resolution_clock::now();
        failu_generavimas(1000000, sk);
        diff = std::chrono::high_resolution_clock::now() - start;
        cout << "Failo su 1000000 sukurimas uztruko: " << diff.count() << " s\n";

        start = std::chrono::high_resolution_clock::now();
        failu_generavimas(10000000, sk);
        diff = std::chrono::high_resolution_clock::now() - start;
        cout << "Failo su 10000000 sukurimas uztruko: " << diff.count() << " s\n";

        diff = std::chrono::high_resolution_clock::now() - st;
        cout << "Visu failu sukurimas uztruko: " << diff.count() << " s\n";
    }
}

// list

void rusiuok_list(list <Studentas> &konteineris, char pagal = 'g')
{
    konteineris.sort([pagal](const Studentas &a, const Studentas &b)
                     {
                         if (pagal == 'v') return a.var < b.var;
                         else if (pagal == 'p') return a.pav < b.pav;
                         else return a.gal > b.gal; });
}

// vector
void rusiuok_vect(vector <Studentas> &konteineris, char pagal = 'g')
{
    sort(konteineris.begin(), konteineris.end(), [pagal](const Studentas &a, const Studentas &b)
         {
        if (pagal == 'v') {
            return a.var < b.var;
        }
        else if (pagal == 'p') {
            return a.pav < b.pav;
        }
        else if (pagal == 'g') {
            return a.gal > b.gal;
        }
        else return false; });
}

stringstream bufer_nusk(const string &failas)
{
    ifstream fd(failas);
    stringstream buffer;
    buffer << fd.rdbuf(); // Visas failas iš karto perkeliamas į buferį
    fd.close();
    return buffer;
}

double Mediana(const Studentas &s)
{
    vector<int> visi;
    visi = s.paz;
    visi.push_back(s.egz);
    sort(visi.begin(), visi.end());
    if (visi.size() % 2 != 0)
    {
        return visi[visi.size() / 2];
    }
    else
    {
        return (float(visi[visi.size() / 2]) + visi[(visi.size() / 2) - 1]) / 2;
    }
}

bool paz_tikrinimas(int laik_paz)
{
    if (cin.fail()) // naudojamas patikrinti ar inputas teisingas.
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Ivedete ne skaiciu. Iveskite skaiciu." << endl;
        return false;
    }
    if (laik_paz > 0 && laik_paz <= 10)
    {
        return true;
    }
    else
    {
        cout << "Netinkamas skaicius. Pabandykite dar karta." << endl;
        return false;
    }
}

int atsitiktinis_sk()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 10); // uztikrina, kad skaiciai butu butent nuo 1 iki 10.
    return dist(gen);
}

bool rusiavimas(Studentas Pirmas, Studentas Antras, string pagal)
{
    if (pagal == "V") // pagal vardą
        return Pirmas.var < Antras.var;
    else if (pagal == "P") // pagal pavardę
        return Pirmas.pav < Antras.pav;
    else if (pagal == "G") // pagal galutinį pažymį
        return Pirmas.gal < Antras.gal;
    return false;
}

Studentas Stud_iv()
{
    int m, laik_paz, suma = 0;
    string ats;
    Studentas Pirmas;
    cout << "Prasau ivesti studento duomenis: " << endl;
    cout << "Vardas: ";
    cin >> Pirmas.var;
    cout << "Pavarde: ";
    cin >> Pirmas.pav;
    cout << "Ar norite, kad " << Pirmas.var << " pazymiai butu generuojami atsitiktinai (T arba N)? " << endl;
    cin >> ats;

    if (ats == "T")
    {
        bool dar = true;
        int paz = 1;
        while (dar)
        {
            if (paz == 1)
            {
                int x = atsitiktinis_sk();
                cout << "Sugeneruotas " << paz << "-as pazymys yra " << x << endl;
                Pirmas.paz.push_back(x);
                suma += x;
                paz += 1;
            }
            else
            {
                cout << "Ar sugeneruoti dar viena pazymi (T arba N)?" << endl;
                cin >> ats;
                if (ats == "T")
                {
                    int x = atsitiktinis_sk();
                    cout << "Sugeneruotas " << paz << " yra " << x << endl;
                    Pirmas.paz.push_back(x);
                    suma += x;
                    paz += 1;
                }
                else
                {
                    dar = false;
                }
            }
        }
        int x = atsitiktinis_sk();
        cout << "Sugeneruotas egzamino rezultatas yra :" << x << endl;
        Pirmas.egz = x;
        Pirmas.gal = double(suma) / double(Pirmas.paz.size()) * 0.4 + 0.6 * Pirmas.egz;
        Pirmas.med = double(Mediana(Pirmas)) * 0.4 + 0.6 * Pirmas.egz;

        return Pirmas;
    }
    else
    {
        bool yra = true;
        int k = 1;
        while (yra)
        {
            if (k == 1)
            {
                bool tinkamas = false;
                while (!tinkamas)
                {
                    cout << "Iveskite " << k << " pazymi:";
                    cin >> laik_paz;
                    if (paz_tikrinimas(laik_paz) == true)
                    {
                        Pirmas.paz.push_back(laik_paz);
                        suma += laik_paz;
                        tinkamas = true;
                        k += 1;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            else
            {
                cout << "Ar " << Pirmas.var << " dar turi pazymiu (T arba N)?" << endl;
                cin >> ats;
                if (ats == "T")
                {
                    bool tinkamas = false;
                    while (!tinkamas)
                    {
                        cout << "Iveskite " << k << " pazymi:";
                        cin >> laik_paz;
                        if (paz_tikrinimas(laik_paz) == true)
                        {
                            Pirmas.paz.push_back(laik_paz);
                            suma += laik_paz;
                            tinkamas = true;
                            k += 1;
                        }
                        else
                        {
                            continue;
                        }
                        Pirmas.paz.push_back(laik_paz);
                        suma += laik_paz;
                    }
                }
                else
                {
                    yra = false;
                }
            }
        }
        bool tinkamas = false;
        int egz;
        while (!tinkamas)
        {
            cout << "Koks egzamino razultatas :";
            cin >> egz;
            if (paz_tikrinimas(egz) == true)
            {
                Pirmas.egz = egz;
                Pirmas.gal = double(suma) / double(Pirmas.paz.size()) * 0.4 + 0.6 * Pirmas.egz;
                Pirmas.med = double(Mediana(Pirmas)) * 0.4 + 0.6 * Pirmas.egz;
                tinkamas = true;
            }
            else
            {
                continue;
            }
        }
        return Pirmas;
    }
}

void failu_generavimas(int eil, int paz)
{
    string fvardas = "studentai" + to_string(eil) + ".txt";
    stringstream srautas;
    srautas << "Vardas Pavarde ";
    for (int i = 1; i <= paz; i++)
    {
        srautas << "ND" << i << " ";
    }
    srautas << "Egz" << endl;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 10);

    for (int i = 1; i <= eil; i++)
    {
        srautas << "Vardas" << i << " Pavarde" << i << " ";
        for (int j = 1; j <= paz; j++)
        {
            srautas << dist(gen) << " ";
        }
        srautas << dist(gen) << endl;
    }
    ofstream out(fvardas);
    out << srautas.str();
    out.close();
}

bool islaike(const Studentas &s)
{
    return s.gal >= 5.0;
}
