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
#include <chrono>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::ifstream;
using std::istringstream; // stringe esančių žodžių sk skaičiavimui
using std::left;
using std::list;
using std::map;
using std::move;
using std::mt19937;
using std::ofstream;
using std::partition;
using std::random_device;
using std::right;
using std::setprecision;
using std::setw;
using std::sort;
using std::string;
using std::stringstream;
using std::to_string;
using std::uniform_int_distribution;
using std::vector;
using std::ws;

struct Studentas
{
    string var;
    string pav;
    vector<int> paz;
    int egz;
    float gal;
    float med;
};

vector<Studentas> generuok_vector(const int &stud_sk);
void pasiskirstymas_vector_1(const vector<Studentas> &Grupe, const int &irasu_sk);
void pasiskirstymas_list_1(const list<Studentas> &Grupe, const int &irasu_sk);
void pasiskirstymas_vector_2(vector<Studentas> Grupe, const int &irasu_sk);
void pasiskirstymas_list_2(list<Studentas> Grupe, const int &irasu_sk);
void pasiskirstymas_vector_3(vector<Studentas> &Grupe, const int &irasu_sk);
void pasiskirstymas_list_3(list<Studentas> &Grupe, const int &irasu_sk);
vector<Studentas> Failo_nuskaitymas(const string &failas);

template <typename Container>
void Spausdink(const Container &moksliukai, const Container &nemoksos, const string &strategija, const string &konteineris)
{
    string sablonas = "rezultatai_" + strategija + "_" + konteineris;
    ofstream frM(sablonas + "_moksliukai.txt");
    ofstream frN(sablonas + "_nemoksos.txt");
    for (auto it = std::begin(moksliukai); it != std::end(moksliukai); ++it)
    {
        frM << it->var << ' ' << it->pav << ' ' << it->gal << endl;
    }
    for (auto it = std::begin(nemoksos); it != std::end(nemoksos); ++it)
    {
        frN << it->var << ' ' << it->pav << ' ' << it->gal << endl;
    }
}
