#include "mylib.h"

int main()
{
    vector<Studentas> Grupe = generuok_vector(1000000);
    pasiskirstymas_vector_1(Grupe, 1000000);
    pasiskirstymas_vector_2(Grupe, 1000000);
    pasiskirstymas_vector_3(Grupe, 1000000);

    list<Studentas> Grupelist(Grupe.size());
    std::copy(Grupe.begin(), Grupe.end(), Grupelist.begin());
    pasiskirstymas_list_1(Grupelist, 1000000);
    pasiskirstymas_list_2(Grupelist, 1000000);
    pasiskirstymas_list_3(Grupelist, 1000000);
}
