#ifndef __rnd__
#define __rnd__

#include <cstdlib>

//------------------------------------------------------------------------------
// rnd.h - содержит генераторы случайных чисел
//------------------------------------------------------------------------------

// От 1 до 20 для длинны называния языка программирования
inline auto Random_len() {
    return rand() % 20 + 1;
}

// от 1957 до 2020 для года создания языка программирования
inline auto Random_year() {
    return rand() % 64 + 1957;
}

// от 0 до 99.9 для популярности языка программирования
inline auto Random_popularity() {
    return (rand() % 1000) / 10.0;
}

// от 0 до 1 для булева значения
inline auto Random_bool() {
    return rand() % 2;
}

// от 1 до 3 для наследования
inline auto Random_inheritance() {
    return rand() % 3 + 1;
}

// от 1 до 2 для типизации
inline auto Random_typing() {
    return rand() % 2 + 1;
}

#endif //__rnd__
