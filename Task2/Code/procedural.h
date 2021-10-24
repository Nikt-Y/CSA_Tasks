#ifndef __procedural__
#define __procedural__

//------------------------------------------------------------------------------
// procedural.h - содержит описание процедурных языков
//------------------------------------------------------------------------------

#include <fstream>

using namespace std;

#include "rnd.h"
#include "language.h"

//------------------------------------------------------------------------------
// Процедурный язык

class Procedural : public Language {
protected:
    static Random rnd_bool;
private:
    int name_len; // длина названия языка
    bool abstract_types; // наличие абстрактных типов
    double popularity; // популярность
    int year; // год создания
public:
    virtual ~Procedural() {}

    // Ввод параметров процедурного языка из файла
    virtual void In(ifstream &ifst);

    // Случайный ввод параметров процедурного языка
    virtual void InRnd();

    // Вывод параметров процедурного языка в форматируемый поток
    virtual void Out(ofstream &ofst);

    // Вычисление частного процедурного языка
    virtual double Quotient();
};

#endif //__procedural__