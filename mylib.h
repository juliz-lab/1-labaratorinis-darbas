#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <random> //atsitiktiniam skaiciui rasti
#include <fstream>

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
bool rusiavimas(Studentas Pirmas, Studentas Antras);
Studentas Stud_iv();
void failu_generavimas(int eil, int paz);
bool islaike(const Studentas &s);
void spausdink_studenta(ofstream &out, const Studentas &s, string tipas);
stringstream bufer_nusk(const std::string &failas);




/*
#ifndef BUFER_NUSK_H
#define BUFER_NUSK_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

std::stringstream bufer_nusk(const std::string &failas);

#endif*/
