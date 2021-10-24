#ifndef __language__
#define __language__

//------------------------------------------------------------------------------
// language.h - содержит описание обобщенного языка программирования.
//------------------------------------------------------------------------------

#include <fstream>

using namespace std;

#include "rnd.h"

//------------------------------------------------------------------------------
// Класс, обобщающая все имеющиеся языки программирования
class Language {
protected:
    static Random rnd_lan;
    static Random rnd_len;
    static Random rnd_year;
    static Random rnd_popularity;
public:
    virtual ~Language() {};

    // Ввод обобщенного языка
    static Language *StaticIn(ifstream &ifdt);

    // Виртуальный метод ввода обобщенного языка
    virtual void In(ifstream &ifdt) = 0;

    // Случайный ввод обобщенного языка
    static Language *StaticInRnd();

    // Виртуальный метод ввода случайного языка
    virtual void InRnd() = 0;

    // Вывод обобщенного языка
    virtual void Out(ofstream &ofst) = 0;

    // Вычисление частного обобщенного языка
    virtual double Quotient() = 0;
};

#endif
