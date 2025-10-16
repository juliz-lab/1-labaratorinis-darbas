#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <random> //atsitiktiniam skaiciui rasti
#include <fstream>
#include <chrono>
#include <map>
#include <list>

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::ifstream;
using std::istringstream; // stringe esančių žodžių sk skaičiavimui
using std::left;
using std::mt19937;
using std::random_device;
using std::right;
using std::setprecision;
using std::setw;
using std::sort;
using std::string;
using std::uniform_int_distribution;
using std::vector;
using std::ws;
using std::ofstream;
using std::stringstream;
using std::to_string;
using std::map;
using std::list;
using std::sort;

struct Studentas
{
    string var;
    string pav;
    vector<int> paz;
    int egz;
    float gal;
    float med;
};

double Mediana(const Studentas &s);
bool paz_tikrinimas(int laik_paz);
int atsitiktinis_sk();
bool rusiavimas(Studentas Pirmas, Studentas Antras, string pagal);
Studentas Stud_iv();
void failu_generavimas(int eil, int paz);
bool islaike(const Studentas &s);
//void spausdink_studenta(ofstream &out, const Studentas &s, string tipas);
stringstream bufer_nusk(const std::string &failas);
void generuok_failus();
void rusiuok_vect(vector <Studentas> &konteineris, char pagal);
void rusiuok_list(list <Studentas> &konteineris, char pagal);

template <typename T>
void spausdink_grupe(const T &grupe, string tipas)
{
    stringstream ss;
    ss << setw(16) << left << "Pavarde" << setw(15) << left << "Vardas";
    if (tipas == "v")
    {
        ss << setw(10) << left << "Gal.";
        for (auto &stud : grupe)
        {
            ss << endl
               << setw(16) << left << stud.pav << setw(15) << left << stud.var << setw(10) << fixed << setprecision(2) << stud.gal;
        }
    }
    if (tipas == "m")
    {
        ss << "Med.";
        for (auto &stud : grupe)
        {
            ss << endl
               << setw(16) << left << stud.pav << setw(15) << left << stud.var << setw(10) << fixed << setprecision(2) << stud.med;
        }
    }
    if (tipas == "a")
    {
        ss << setw(10) << "Gal. " << setw(10) << " Med.";
        for (auto &stud : grupe)
        {
            ss << endl
               << setw(16) << left << stud.pav << setw(15) << left << stud.var << setw(10) << fixed << setprecision(2) << stud.gal << setw(10) << fixed << setprecision(2) << stud.med;
        }
    }
    auto it = grupe.begin(); //iteratorius i 1 elementa
    if (it->gal >= 5)
    {
        ofstream out("moksliukai.txt");
        out << ss.str();
        out.close();
    }
    else
    {
        ofstream out("nemoksos.txt");
        out << ss.str();
        out.close();
    }
}

template <typename T>
void ekrane_grupe(const T &grupe, string tipas)
{
    cout << setw(16) << left << "Pavarde" << setw(15) << left << "Vardas";
    if (tipas == "v")
    {
        cout << setw(10) << left << "Gal." << setw(16) << left << "Vieta atmintyje";
        for (auto &stud : grupe)
        {
            cout << endl
               << setw(16) << left << stud.pav << setw(15) << left << stud.var << setw(10) << fixed << setprecision(2) << stud.gal << setw(16) << left << &stud;
        }
    }
    if (tipas == "m")
    {
        cout << setw(10) << left << "Med." << setw(16) << left << "Vieta atmintyje";
        for (auto &stud : grupe)
        {
            cout << endl
               << setw(16) << left << stud.pav << setw(15) << left << stud.var << setw(10) << fixed << setprecision(2) << stud.med << setw(16) << left << &stud;
        }
    }
    if (tipas == "a")
    {
        cout << setw(10) << left << "Gal." << setw(10) << left << " Med." << setw(16) << left << "Vieta atmintyje";
        for (auto &stud : grupe)
        {
            cout << endl
               << setw(16) << left << stud.pav << setw(15) << left << stud.var << setw(10) << left << fixed << setprecision(2) << stud.gal << setw(10) << left << fixed << setprecision(2) << stud.med << setw(16) << left << &stud;
        }
    }
    cout << endl;
}

template <typename T>
void irasysiu_pats(T &Grupe)
{
    cout << "Kiek studentu yra grupeje? ";
    int n;
    cin >> n;

    for (int z = 0; z < n; z++)
    {
        Studentas stud = Stud_iv();
        cout << "Studento objektas saugomas atmintyje: " << &stud << endl; // adreso spausdinimas
        Grupe.push_back(stud);
    }
}

template <typename T>
void Failo_nuskaitymas(const string &failas, T &Grupe)
{
    ifstream fd(failas);
    stringstream buffer;
    buffer << fd.rdbuf(); // Visas failas iš karto perkeliamas į buferį
    fd.close();
    string eil;
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
        stud.med = double(Mediana(stud)) * 0.4 + 0.6 * stud.egz;
        Grupe.push_back(stud);
    }
}
