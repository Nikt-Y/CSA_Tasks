#ifndef __language__
#define __language__

//------------------------------------------------------------------------------
// language.h - содержит описание обобщающей языки программирования,
//------------------------------------------------------------------------------

#include "procedural.h"
#include "object_oriented.h"
#include "functional.h"

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся языки программирования
struct language {
    // значения ключей для каждого из языков
    enum key {
        PROCEDURAL, OBJECT_ORIENTED, FUNCTIONAL
    };
    key k; // ключ
    // используемые альтернативы
    union {
        procedural p;
        object_oriented o;
        functional f;
    };
};

// Ввод обобщенного языка
bool In(language &l, ifstream &ifdt);

// Случайный ввод обобщенного языка
bool InRnd(language &l);

// Вывод обобщенного языка
void Out(language &l, ofstream &ofst);

// Вычисление частного обобщенного языка
double Quotient(language &l);

#endif
