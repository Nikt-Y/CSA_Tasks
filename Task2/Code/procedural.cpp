//------------------------------------------------------------------------------
// procedural.cpp - содержит функции обработки процедурных языков
//------------------------------------------------------------------------------

#include "procedural.h"

// от 0 до 1 для булева значения
Random Procedural::rnd_bool(0, 1);

//------------------------------------------------------------------------------
// Ввод параметров процедурного языка из потока
void Procedural::In(ifstream &ifst) {
    string name;
    ifst >> name >> abstract_types >> popularity >> year;
    name_len = name.size();
}

// Случайный ввод параметров процедурного языка
void Procedural::InRnd() {
    name_len = rnd_len.GetInt();
    abstract_types = static_cast<bool>(rnd_bool.GetInt());
    popularity = rnd_popularity.GetDouble();
    year = rnd_year.GetInt();
}

//------------------------------------------------------------------------------
// Вывод параметров процедурного языка в поток
void Procedural::Out(ofstream &ofst) {
    ofst << "It is Procedural programming language: number of characters = "
         << name_len << ",  abstract types = "
         << boolalpha << abstract_types << noboolalpha;

    if (abstract_types) {
        ofst << ".\t\t\tPopularity = " << popularity;
    } else {
        ofst << ".\t\t\tPopularity = " << popularity;
    }

    ofst << "%, year = " << year << ", quotient = " << Quotient() << "\n";
}

//------------------------------------------------------------------------------
// Вычисление частного процедурного языка
double Procedural::Quotient() {
    return year / double(name_len);
}
