#ifndef __object_oriented__
#define __object_oriented__

//------------------------------------------------------------------------------
// object_oriented.h - содержит описание Объектно-ориентированных языков
//------------------------------------------------------------------------------

#include <fstream>

using namespace std;

# include "rnd.h"
#include "language.h"

//------------------------------------------------------------------------------
// Объектно-ориентированный язык

class ObjectOriented : public Language {
protected:
    static Random rnd_inheritance;
private:
    int name_len; // длина названия языка
    enum keys_of_inheritance { // наследование
        single = 1,
        multiple = 2,
        interfaces = 3
    } inheritance;
    double popularity; // популярность
    int year; // год создания
public:
    virtual ~ObjectOriented() {}

    // Ввод параметров Объектно-ориентированного языка из файла
    virtual void In(ifstream &ifst);

    // Случайный ввод параметров Объектно-ориентированного языка
    virtual void InRnd();

    // Вывод параметров Объектно-ориентированного языка в форматируемый поток
    virtual void Out(ofstream &ofst);

    // Вычисление частного Объектно-ориентированного языка
    virtual double Quotient();
};

#endif //__object_oriented__
