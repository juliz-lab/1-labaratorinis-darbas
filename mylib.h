#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <random> //atsitiktiniam skaiciui rasti
#include <fstream>
#include <chrono>
#include <map>

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
// using std::out;
using std::ofstream;
using std::stringstream;
using std::to_string;
using std::map;

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
void spausdink_grupe(const vector <Studentas> &vekt, string tipas);
