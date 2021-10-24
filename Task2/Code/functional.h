#ifndef __functional__
#define __functional__

//------------------------------------------------------------------------------
// functional.h - содержит описание функциональных языков
//------------------------------------------------------------------------------

#include <fstream>

using namespace std;

# include "rnd.h"
#include "language.h"

//------------------------------------------------------------------------------
// Функциональный язык

class Functional : public Language {
protected:
    static Random rnd_bool;
    static Random rnd_typing;
private:
    int name_len; // длина названия языка
    enum keys_of_typing { // типизация
        strict = 1,
        dynamic = 2,
    } typing;
    bool lazy_calculations; // поддержка «ленивых» вычислений
    double popularity; // популярность
    int year; // год создания
public:
    virtual ~Functional() {}

    // Ввод параметров функционального языка из файла
    virtual void In(ifstream &ifst);

    // Случайный ввод параметров функционального языка
    virtual void InRnd();

    // Вывод параметров функционального языка в форматируемый поток
    virtual void Out(ofstream &ofst);

    // Вычисление частного функционального языка
    virtual double Quotient();
};

#endif //__functional__
