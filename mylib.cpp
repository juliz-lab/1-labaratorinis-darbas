#include "mylib.h"
#include "timer.h"

vector<Studentas> Failo_nuskaitymas(const string &failas)
{
    ifstream fd(failas);
    if (!fd)
    {
        cout << "nepavyko atidaryti failo: " << failas << endl;
        return {};
    }
    else
    {
        cout << "Nuskaitomas " << failas << endl;
    }
    stringstream buffer;
    vector<Studentas> Grupe;
    string eil;
    buffer << fd.rdbuf(); // Visas failas iš karto perkeliamas į buferį
    fd.close();
    getline(buffer, eil);
    while (getline(buffer, eil))
    {
        Studentas stud;
        int paz, suma = 0;
        istringstream iss(eil); // paverčiame eilutę į objektą.
        iss >> stud.var >> stud.pav;
        while (iss >> paz)
        {
            stud.paz.push_back(paz);
            suma += paz;
        }
        suma -= paz;
        stud.egz = stud.paz.back();
        stud.paz.pop_back();
        stud.gal = double(suma) / double(stud.paz.size()) * 0.4 + 0.6 * stud.egz;
        // stud.med = double(Mediana(stud)) * 0.4 + 0.6 * stud.egz;
        Grupe.push_back(stud);
    }
    return Grupe;
}

void pasiskirstymas_vector_1(const vector<Studentas> &Grupe, const int &irasu_sk)
{
    Timer t; // paleidzia laikmati
    vector<Studentas> moksliukai, nemoksos;
    moksliukai.reserve(irasu_sk);
    nemoksos.reserve(irasu_sk);

    for (auto &stud : Grupe)
    {
        if (stud.gal >= 5.0)
        {
            moksliukai.push_back(stud);
        }
        else
        {
            nemoksos.push_back(stud);
        }
    }
    cout << irasu_sk << " vektoriaus padalijimo i dvi grupes, vykdant 1 strategija, laikas " << t.elapsed() << endl;
    if (irasu_sk == 1000)
    {
        Spausdink(moksliukai, nemoksos, "1", "vector");
    }
}

void pasiskirstymas_list_1(const list<Studentas> &Grupe, const int &irasu_sk)
{
    Timer t;
    list<Studentas> moksliukai, nemoksos;
    for (auto &stud : Grupe)
    {
        if (stud.gal >= 5.0)
        {
            moksliukai.push_back(stud);
        }
        else
        {
            nemoksos.push_back(stud);
        }
    }
    cout << irasu_sk << " saraso padalijimo i dvi grupes, vykdant 1 strategija, laikas " << t.elapsed() << endl;
    if (irasu_sk == 1000)
    {
        Spausdink(moksliukai, nemoksos, "1", "list");
    }
}

void pasiskirstymas_vector_2(vector<Studentas> Grupe, const int &irasu_sk)
{
    Timer t;
    vector<Studentas> nemoksos;
    nemoksos.reserve(irasu_sk);
    size_t i = 0;

    for (size_t j = 0; j < Grupe.size(); ++j)
    {
        if (Grupe[j].gal >= 5.0)
        {
            Grupe[i] = move(Grupe[j]);
            i++;
        }
        else
        {
            nemoksos.push_back(move(Grupe[j]));
        }
    }
    Grupe.erase(Grupe.begin() + i, Grupe.end());
    cout << irasu_sk << " vektoriaus padalijimo i dvi grupes, vykdant 2 strategija, laikas " << t.elapsed() << endl;
    if (irasu_sk == 1000)
    {
        Spausdink(Grupe, nemoksos, "2", "vector");
    }
}

void pasiskirstymas_list_2(list<Studentas> Grupe, const int &irasu_sk)
{
    Timer t;
    list<Studentas> nemoksos;
    for (auto it = Grupe.begin(); it != Grupe.end();)
    {
        if (it->gal < 5.0)
        {
            nemoksos.push_back(*it);
            it = Grupe.erase(it);
        }
        else
        {
            ++it;
        }
    }
    cout << irasu_sk << " saraso padalijimo i dvi grupes, vykdant 2 strategija, laikas " << t.elapsed() << endl;
    if (irasu_sk == 1000)
    {
        Spausdink(Grupe, nemoksos, "2", "list");
    }
}

void pasiskirstymas_vector_3(vector<Studentas> &Grupe, const int &irasu_sk)
{
    Timer t;
    vector<Studentas> nemoksos;
    nemoksos.reserve(irasu_sk);

    auto it = partition(Grupe.begin(), Grupe.end(),
                        [](const Studentas &s)
                        { return s.gal >= 5.0; });
    nemoksos.assign(it, Grupe.end());
    Grupe.erase(it, Grupe.end());

    cout << irasu_sk << " vektoriaus padalijimo i dvi grupes, vykdant 3 strategija, laikas " << t.elapsed() << endl;
    if (irasu_sk == 1000)
    {
        Spausdink(Grupe, nemoksos, "3", "vector");
    }
}

void pasiskirstymas_list_3(list<Studentas> &Grupe, const int &irasu_sk)
{
    Timer t;
    list<Studentas> nemoksos;
    Grupe.remove_if([&nemoksos](const Studentas &s)
                    {
                        if (s.gal < 5.0)
                        {
                            nemoksos.push_back(s);
                            return true; // pasalins is grupes si studenta
                        }
                        return false; // paliks studenta
                    });
    cout << irasu_sk << " saraso padalijimo i dvi grupes, vykdant 3 strategija, laikas " << t.elapsed() << endl;
    if (irasu_sk == 1000)
    {
        Spausdink(Grupe, nemoksos, "3", "list");
    }
}
