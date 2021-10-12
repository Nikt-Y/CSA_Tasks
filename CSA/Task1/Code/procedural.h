#ifndef __procedural__
#define __procedural__

//------------------------------------------------------------------------------
// procedural.h - содержит описание процедурных языков
//------------------------------------------------------------------------------

#include <fstream>

using namespace std;

# include "rnd.h"

//------------------------------------------------------------------------------
// Процедурный язык
struct procedural {
    int name_len; // длина названия языка
    bool abstract_types; // наличие абстрактных типов
    double popularity; // популярность
    int year; // год создания
};

// Ввод параметров процедурного языка из файла
void In(procedural &p, ifstream &ifst);

// Случайный ввод параметров процедурного языка
void InRnd(procedural &p);

// Вывод параметров процедурного языка в форматируемый поток
void Out(procedural &p, ofstream &ofst);

// Вычисление частного процедурного языка
double Quotient(procedural &p);

#endif //__procedural__