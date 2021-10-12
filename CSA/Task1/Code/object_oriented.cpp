//------------------------------------------------------------------------------
// object_oriented.cpp - содержит функции обработки Объектно-ориентированных языков
//------------------------------------------------------------------------------

#include "object_oriented.h"

//------------------------------------------------------------------------------
// Ввод параметров Объектно-ориентированного языка из потока
void In(object_oriented &o, ifstream &ifst) {
    int key_of_inheritance;
    string name;
    ifst >> name >> key_of_inheritance >> o.popularity >> o.year;
    o.name_len = name.size();
    switch (key_of_inheritance) {
        case (o.single):
            o.inheritance = o.single;
            break;
        case (o.multiple):
            o.inheritance = o.multiple;
            break;
        case (o.interfaces):
            o.inheritance = o.interfaces;
            break;
    }
}

// Случайный ввод параметров Объектно-ориентированного языка
void InRnd(object_oriented &o) {
    o.name_len = Random_len();
    int key = Random_inheritance();
    switch (key) {
        case (o.single):
            o.inheritance = o.single;
            break;
        case (o.multiple):
            o.inheritance = o.multiple;
            break;
        case (o.interfaces):
            o.inheritance = o.interfaces;
            break;
    }
    o.popularity = Random_popularity();
    o.year = Random_year();
}

//------------------------------------------------------------------------------
// Вывод параметров Объектно-ориентированного языка в поток
void Out(object_oriented &o, ofstream &ofst) {
    ofst << "It is Object oriented programming language: number of char. = "
         << o.name_len << ",  inheritance = ";
    switch (o.inheritance) {
        case (o.single):
            ofst << "single";
            break;
        case (o.multiple):
            ofst << "multiple";
            break;
        case (o.interfaces):
            ofst << "interfaces";
            break;
    }
    ofst << ".   \t\t\tPopularity = " << o.popularity
         << "%, year = " << o.year
         << ", quotient = " << Quotient(o) << "\n";
}

//------------------------------------------------------------------------------
// Вычисление частного Объектно-ориентированного языка
double Quotient(object_oriented &o) {
    return o.year / double(o.name_len);
}


