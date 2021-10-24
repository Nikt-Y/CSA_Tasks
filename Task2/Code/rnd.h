#ifndef __rnd__
#define __rnd__

#include <cstdlib>
#include <ctime>    // для функции time()

//------------------------------------------------------------------------------
// rnd.h - содержит генераторы случайных чисел
//------------------------------------------------------------------------------

class Random {
private:
    int first;
    int last;
public:
    Random(int f, int l) {
        if (f <= l) {
            first = f;
            last = l;
        } else {
            first = l;
            last = f;
        }
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
    }

    // Генерация случайного целого числа в заданном диапазоне
    int GetInt() {
        return rand() % (last - first + 1) + first;
    }

    // Генерация случайного вещественного числа в заданном диапазоне
    double GetDouble() {
        return (rand() % (last * 10 - first * 10) + first * 10) / 10.0;
    }
};

#endif //__rnd__
