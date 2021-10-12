//------------------------------------------------------------------------------
// procedural.cpp - содержит функции обработки процедурных языков
//------------------------------------------------------------------------------

#include "procedural.h"

//------------------------------------------------------------------------------
// Ввод параметров процедурного языка из потока
void In(procedural &p, ifstream &ifst) {
    string name;
    ifst >> name >> p.abstract_types >> p.popularity >> p.year;
    p.name_len = name.size();
}

// Случайный ввод параметров процедурного языка
void InRnd(procedural &p) {
    p.name_len = Random_len();
    p.abstract_types = static_cast<bool>(Random_bool());
    p.popularity = Random_popularity();
    p.year = Random_year();
}

//------------------------------------------------------------------------------
// Вывод параметров процедурного языка в поток
void Out(procedural &p, ofstream &ofst) {
    ofst << "It is Procedural programming language: number of characters = "
         << p.name_len << ",  abstract types = "
         << boolalpha << p.abstract_types << noboolalpha;

    if (p.abstract_types) {
        ofst << ".\t\t\tPopularity = " << p.popularity;
    } else {
        ofst << ".\t\t\tPopularity = " << p.popularity;
    }

    ofst << "%, year = " << p.year << ", quotient = " << Quotient(p) << "\n";
}

//------------------------------------------------------------------------------
// Вычисление частного процедурного языка
double Quotient(procedural &p) {
    return p.year / double(p.name_len);
}
