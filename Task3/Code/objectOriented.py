import random
from language import Language

# Класс Объектно-ориентированного языка программирования
class ObjectOriented(Language):
    def __init__(self):
        self.name_len = 0  # длина названия языка
        self.inheritance = 0  # наследование
        self.popularity = 0  # популярность
        self.year = 0  # год создания

    # Ввод данных в объект класса из строки файла
    def input(self, str):
        self.name_len = int(len(str[1]))
        self.inheritance = int(str[2])
        self.popularity = float(str[3])
        self.year = int(str[4])

    # Ввод данных в объект класса случайным образом
    def inputrnd(self):
        self.name_len = random.randint(1, 20)
        self.inheritance = random.randint(1, 3)
        self.popularity = round(random.random() * (100 - 1) + 1, 3)
        self.year = random.randint(1957, 2020)
        pass

    # Вывод данных объекта класса в файл
    def output(self, ostr):
        if self.inheritance == 1:
            self.inheritance = "single.\t"
        elif self.inheritance == 2:
            self.inheritance = "multiple."
        else:
            self.inheritance = "interfaces."
        ostr.write(
            f"It is Object oriented programming language: number of char. = {self.name_len},  "
            f"inheritance = {self.inheritance}    \t\t\tPopularity = {self.popularity}%, "
            f"year = {self.year}, "
            f"quotient = {self.quotient()}\n")
        pass

    # Подсчет частного для данного объекта класса языка программирования
    def quotient(self):
        return round(self.year / float(self.name_len), 3)
