//------------------------------------------------------------------------------
// functional.cpp - содержит функции обработки функциональных языков
//------------------------------------------------------------------------------

#include "functional.h"

// от 0 до 1 для булева значения
Random Functional::rnd_bool(0, 1);
// от 1 до 2 для типизации
Random Functional::rnd_typing(1, 2);

//------------------------------------------------------------------------------
// Ввод параметров функционального языка из потока
void Functional::In(ifstream &ifst) {
    int key_of_typing;
    string name;
    ifst >> name >> key_of_typing >> lazy_calculations >> popularity >> year;
    switch (key_of_typing) {
        case (strict):
            typing = strict;
            break;
        case (dynamic):
            typing = dynamic;
            break;
    }
    name_len = name.size();
}

// Случайный ввод параметров функционального языка
void Functional::InRnd() {
    name_len = rnd_len.GetInt();
    int key_of_typing = rnd_typing.GetInt();
    switch (key_of_typing) {
        case (strict):
            typing = strict;
            break;
        case (dynamic):
            typing = dynamic;
            break;
    }
    lazy_calculations = rnd_bool.GetInt();
    popularity = rnd_popularity.GetDouble();
    year = rnd_year.GetInt();
}

//------------------------------------------------------------------------------
// Вывод параметров функционального языка в поток
void Functional::Out(ofstream &ofst) {
    ofst << "It is Functional programming language: number of characters = "
         << name_len << ",  typing = ";
    switch (typing) {
        case (strict):
            ofst << "strict";
            break;
        case (dynamic):
            ofst << "dynamic";
            break;
    }
    ofst << ", lazy calculations = "
         << boolalpha << lazy_calculations << noboolalpha;
    if (typing == dynamic) {
        ofst << ".\tPopularity = " << popularity;
    } else {
        ofst << ". \tPopularity = " << popularity;
    }
    ofst << "%, year = " << year
         << ", quotient = " << Quotient() << "\n";
}

//------------------------------------------------------------------------------
// Вычисление частного функционального языка
double Functional::Quotient() {
    return year / double(name_len);
}
