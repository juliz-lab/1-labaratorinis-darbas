#include "mylib.h"

int main()
{
    for (int i = 1'000; i <= 10'000'000; i *= 10)
    {
        vector<Studentas> Grupe = generuok_vector(i);
        list<Studentas> Grupelist(Grupe.size());
        std::copy(Grupe.begin(), Grupe.end(), Grupelist.begin());
        pasiskirstymas_vector_1(Grupe, i);
        pasiskirstymas_vector_2(Grupe, i);
        pasiskirstymas_vector_3(Grupe, i);

        pasiskirstymas_list_1(Grupelist, i);
        pasiskirstymas_list_2(Grupelist, i);
        pasiskirstymas_list_3(Grupelist, i);

        cout << endl;
    }
}
