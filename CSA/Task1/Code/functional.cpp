//------------------------------------------------------------------------------
// functional.cpp - содержит функции обработки функциональных языков
//------------------------------------------------------------------------------

#include "functional.h"

//------------------------------------------------------------------------------
// Ввод параметров функционального языка из потока
void In(functional &f, ifstream &ifst) {
    int key_of_typing;
    string name;
    ifst >> name >> key_of_typing >> f.lazy_calculations >> f.popularity >> f.year;
    switch (key_of_typing) {
        case (f.strict):
            f.typing = f.strict;
            break;
        case (f.dynamic):
            f.typing = f.dynamic;
            break;
    }
    f.name_len = name.size();
}

// Случайный ввод параметров функционального языка
void InRnd(functional &f) {
    f.name_len = Random_len();
    int key_of_typing = Random_typing();
    switch (key_of_typing) {
        case (f.strict):
            f.typing = f.strict;
            break;
        case (f.dynamic):
            f.typing = f.dynamic;
            break;
    }
    f.lazy_calculations = Random_bool();
    f.popularity = Random_popularity();
    f.year = Random_year();
}

//------------------------------------------------------------------------------
// Вывод параметров функционального языка в поток
void Out(functional &f, ofstream &ofst) {
    ofst << "It is Functional programming language: number of characters = "
         << f.name_len << ",  typing = ";
    switch (f.typing) {
        case (f.strict):
            ofst << "strict";
            break;
        case (f.dynamic):
            ofst << "dynamic";
            break;
    }
    ofst << ", lazy calculations = "
         << boolalpha << f.lazy_calculations << noboolalpha;
    if (f.typing == f.dynamic) {
        ofst << ".\tPopularity = " << f.popularity;
    } else {
        ofst << ". \tPopularity = " << f.popularity;
    }
    ofst << "%, year = " << f.year
         << ", quotient = " << Quotient(f) << "\n";
}

//------------------------------------------------------------------------------
// Вычисление частного функционального языка
double Quotient(functional &f) {
    return f.year / double(f.name_len);
}

