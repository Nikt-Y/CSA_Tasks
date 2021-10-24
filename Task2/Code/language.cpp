//------------------------------------------------------------------------------
// language.cpp - содержит процедуры связанные с обработкой обобщенного языка программирования
// и создания произвольного языка
//------------------------------------------------------------------------------

#include "procedural.h"
#include "object_oriented.h"
#include "functional.h"

//------------------------------------------------------------------------------
// От 1 до 3 для типа языка
Random Language::rnd_lan(1, 3);
// От 1 до 20 для длинны называния языка программирования
Random Language::rnd_len(1, 20);
// от 1957 до 2020 для года создания языка программирования
Random Language::rnd_year(1957, 2020);
// от 0 до 99.9 для популярности языка программирования
Random Language::rnd_popularity(0, 100);

//------------------------------------------------------------------------------
// Ввод параметров обобщенного языка из файла
Language *Language::StaticIn(ifstream &ifst) {
    int k;
    ifst >> k;
    Language *lan = nullptr;
    switch (k) {
        case 1:
            lan = new Procedural;
            break;
        case 2:
            lan = new ObjectOriented;
            break;
        case 3:
            lan = new Functional;
            break;
    }
    lan->In(ifst);
    return lan;
}

// Случайный ввод обобщенного языка
Language *Language::StaticInRnd() {
    auto k = Language::rnd_lan.GetInt();
    Language *lan = nullptr;
    switch (k) {
        case 1:
            lan = new Procedural;
            break;
        case 2:
            lan = new ObjectOriented;
            break;
        case 3:
            lan = new Functional;
            break;
    }
    lan->InRnd();
    return lan;
}
