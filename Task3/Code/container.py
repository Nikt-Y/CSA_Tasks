from languageNew import *

# Класс, описывающий простейший контейнер на основе одномерного массива
class Container:
    # Конструктор контейнера
    def __init__(self):
        self.store = []

    # Заполнение контейнера по информации из файла
    def input(self, inputListStr):
        for inputStr in inputListStr:
            self.store.append(lan_input(inputStr.split(" ")))
        pass

    # Заполнение контейнера случайными данными
    def inputrnd(self, size):
        for i in range(0, size):
            self.store.append(lan_rnd())
        pass

    # Вывод содержимого контейнера в файл
    def output(self, ostr):
        i = 0
        ostr.write("Container include {} elements:\n".
                      format(len(self.store)))
        for language in self.store:
            ostr.write("{}: ".format(i))
            language.output(ostr)
            i += 1
        pass

    # Сортировка языков программирования методом quicksort
    # по их частному
    def qsort(self):
        Container.quicksort(self.store, 0, len(self.store)-1)

    # Первый вспомогательный метод quicksort
    def quicksort(arr, first, last):
        if first < last:
            q = Container.partition(arr, first, last)
            Container.quicksort(arr, first, q - 1)
            Container.quicksort(arr, q + 1, last)

    # Второй вспомогательный метод quicksort
    def partition(arr, p, r):
        x = arr[r].quotient()
        i = p - 1
        for j in range(p, r):
            if arr[j].quotient() > x:
                i = i + 1
                arr[i], arr[j] = arr[j], arr[i]
        arr[i + 1], arr[r] = arr[r], arr[i + 1]
        return i + 1