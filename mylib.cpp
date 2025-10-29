#include "mylib.h"
#include "timer.h"

vector<Studentas> generuok_vector(const int &stud_sk)
{
    vector<Studentas> Grupe;
    Grupe.reserve(stud_sk);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 10); // uztikrina, kad skaiciai butu butent nuo 1 iki 10.

    for (int i = 0; i <= stud_sk; i++)
    {
        Studentas temp;
        int suma = 0;
        temp.var = "Vardas" + to_string(i);
        temp.pav = "Pavarde" + to_string(i);
        for (int j = 1; j <= 5; j++)
        {
            int p = dist(gen);
            suma += p;
            temp.paz.push_back(p);
        }
        temp.egz = dist(gen);
        temp.gal = 0.4 * (suma * 1.0 / 5.0) + 0.6 * temp.egz;
        Grupe.push_back(temp);
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
}

void pasiskirstymas_list_1(const list<Studentas> &Grupe, const int &irasu_sk)
{
    Timer t;
    list<Studentas> moksliukai, nemoksos;
    for (auto &stud : Grupe)
    {
        if (stud.gal >= 0.5)
        {
            moksliukai.push_back(stud);
        }
        else
        {
            nemoksos.push_back(stud);
        }
    }
    cout << irasu_sk << " saraso padalijimo i dvi grupes, vykdant 1 strategija, laikas " << t.elapsed() << endl;
}

void pasiskirstymas_vector_2(vector<Studentas> &Grupe, const int &irasu_sk)
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
}

void pasiskirstymas_list_2(list<Studentas> &Grupe, const int &irasu_sk)
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
}
