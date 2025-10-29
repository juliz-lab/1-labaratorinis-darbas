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
using std::partition;
using std::move;

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
