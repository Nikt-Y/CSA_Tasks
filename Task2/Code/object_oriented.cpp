//------------------------------------------------------------------------------
// object_oriented.cpp - содержит функции обработки Объектно-ориентированных языков
//------------------------------------------------------------------------------

#include "object_oriented.h"

// от 1 до 3 для наследования
Random ObjectOriented::rnd_inheritance(1, 3);

//------------------------------------------------------------------------------
// Ввод параметров Объектно-ориентированного языка из потока
void ObjectOriented::In(ifstream &ifst) {
    int key_of_inheritance;
    string name;
    ifst >> name >> key_of_inheritance >> popularity >> year;
    name_len = name.size();
    switch (key_of_inheritance) {
        case (single):
            inheritance = single;
            break;
        case (multiple):
            inheritance = multiple;
            break;
        case (interfaces):
            inheritance = interfaces;
            break;
    }
}

// Случайный ввод параметров Объектно-ориентированного языка
void ObjectOriented::InRnd() {
    name_len = rnd_len.GetInt();
    int key = rnd_inheritance.GetInt();
    switch (key) {
        case (single):
            inheritance = single;
            break;
        case (multiple):
            inheritance = multiple;
            break;
        case (interfaces):
            inheritance = interfaces;
            break;
    }
    popularity = rnd_popularity.GetDouble();
    year = rnd_year.GetInt();
}

//------------------------------------------------------------------------------
// Вывод параметров Объектно-ориентированного языка в поток
void ObjectOriented::Out(ofstream &ofst) {
    ofst << "It is Object oriented programming language: number of char. = "
         << name_len << ",  inheritance = ";
    switch (inheritance) {
        case (single):
            ofst << "single";
            break;
        case (multiple):
            ofst << "multiple";
            break;
        case (interfaces):
            ofst << "interfaces";
            break;
    }
    ofst << ".   \t\t\tPopularity = " << popularity
         << "%, year = " << year
         << ", quotient = " << Quotient() << "\n";
}

//------------------------------------------------------------------------------
// Вычисление частного Объектно-ориентированного языка
double ObjectOriented::Quotient() {
    return year / double(name_len);
}
