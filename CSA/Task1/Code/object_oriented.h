#ifndef __object_oriented__
#define __object_oriented__

//------------------------------------------------------------------------------
// object_oriented.h - содержит описание Объектно-ориентированных языков
//------------------------------------------------------------------------------

#include <fstream>

using namespace std;

#include "rnd.h"

//------------------------------------------------------------------------------
// Объектно-ориентированный язык
struct object_oriented {
    int name_len; // длина названия языка
    enum keys_of_inheritance { // наследование
        single = 1,
        multiple = 2,
        interfaces = 3
    } inheritance;
    double popularity; // популярность
    int year; // год создания
};

// Ввод параметров Объектно-ориентированного языка из файла
void In(object_oriented &t, ifstream &ifst);

// Случайный ввод параметров Объектно-ориентированного языка
void InRnd(object_oriented &е);

// Вывод параметров Объектно-ориентированного языка в форматируемый поток
void Out(object_oriented &t, ofstream &ofst);

// Вычисление частного Объектно-ориентированного языка
double Quotient(object_oriented &t);

#endif //__object_oriented__
