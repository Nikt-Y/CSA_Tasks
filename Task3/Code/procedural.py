import random

from language import Language

# Класс Процедурного языка программирования
class Procedural(Language):
    def __init__(self):
        self.name_len = 0 # длина названия языка
        self.abstract_types = 0 # наличие абстрактных типов
        self.popularity = 0 # популярность
        self.year = 0 # год создания

    # Ввод данных в объект класса из строки файла
    def input(self, str):
        self.name_len = int(len(str[1]))
        self.abstract_types = bool(str[2])
        self.popularity = float(str[3])
        self.year = int(str[4])

    # Ввод данных в объект класса случайным образом
    def inputrnd(self):
        self.name_len = random.randint(1, 20)
        self.abstract_types = bool(random.randint(1, 2))
        self.popularity = round(random.random() * (100 - 1) + 1, 3)
        self.year = random.randint(1957, 2020)
        pass

    # Вывод данных объекта класса в файл
    def output(self, ostr):
        if self.abstract_types:
            self.abstract_types = "True.\t"
        else:
            self.abstract_types = "False."
        ostr.write(
            f"It is Procedural programming language: number of characters = {self.name_len},  "
            f"abstract types = {self.abstract_types}\t\t\tPopularity = {self.popularity}%, "
            f"year = {self.year}, quotient = {self.quotient()}\n")
        pass

    # Подсчет частного для данного объекта класса языка программирования
    def quotient(self):
        return round(self.year / float(self.name_len), 3)
