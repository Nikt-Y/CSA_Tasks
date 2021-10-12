#ifndef __functional__
#define __functional__

//------------------------------------------------------------------------------
// functional.h - содержит описание функциональных языков
//------------------------------------------------------------------------------

#include <fstream>

using namespace std;

# include "rnd.h"

//------------------------------------------------------------------------------
// Функциональный язык
struct functional {
    int name_len; // длина названия языка
    enum keys_of_typing { // типизация
        strict = 1,
        dynamic = 2,
    } typing;
    bool lazy_calculations; // поддержка «ленивых» вычислений
    double popularity; // популярность
    int year; // год создания
};

// Ввод параметров функционального языка из файла
void In(functional &f, ifstream &ifst);

// Случайный ввод параметров функционального языка
void InRnd(functional &f);

// Вывод параметров функционального языка в форматируемый поток
void Out(functional &f, ofstream &ofst);

// Вычисление частного функционального языка
double Quotient(functional &f);

#endif //__functional__
