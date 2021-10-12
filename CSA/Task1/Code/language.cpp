//------------------------------------------------------------------------------
// language.cpp - содержит процедуры связанные с обработкой обобщенного языка программирования
// и создания произвольного языка
//------------------------------------------------------------------------------

#include "language.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенного языка из файла
bool In(language &l, ifstream &ifst) {
    int k;
    ifst >> k;
    switch (k) {
        case 1:
            l.k = language::PROCEDURAL;
            In(l.p, ifst);
            return true;
        case 2:
            l.k = language::OBJECT_ORIENTED;
            In(l.o, ifst);
            return true;
        case 3:
            l.k = language::FUNCTIONAL;
            In(l.f, ifst);
            return true;
        default:
            return false;
    }
}

// Случайный ввод обобщенного языка
bool InRnd(language &l) {
    auto k = rand() % 3 + 1;
    switch (k) {
        case 1:
            l.k = language::PROCEDURAL;
            InRnd(l.p);
            return true;
        case 2:
            l.k = language::OBJECT_ORIENTED;
            InRnd(l.o);
            return true;
        case 3:
            l.k = language::FUNCTIONAL;
            InRnd(l.f);
            return true;
        default:
            return false;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров текущего языка в поток
void Out(language &l, ofstream &ofst) {
    switch (l.k) {
        case language::PROCEDURAL:
            Out(l.p, ofst);
            break;
        case language::OBJECT_ORIENTED:
            Out(l.o, ofst);
            break;
        case language::FUNCTIONAL:
            Out(l.f, ofst);
            break;
        default:
            ofst << "Incorrect language!" << endl;
    }
}

//------------------------------------------------------------------------------
// Вычисление частного языка
double Quotient(language &l) {
    switch (l.k) {
        case language::PROCEDURAL:
            return Quotient(l.p);
            break;
        case language::OBJECT_ORIENTED:
            return Quotient(l.o);
            break;
        case language::FUNCTIONAL:
            return Quotient(l.f);
            break;
        default:
            return 0.0;
    }
}
