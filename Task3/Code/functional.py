import random
from language import Language

# -----------------------------------
# Класс функционального языка программирования
class Functional(Language):
    # Инициализация объекта класса.
    def __init__(self):
        self.name_len = 0  # длина названия языка
        self.typing = 0  # типизация
        self.lazy_calculations = 0  # поддержка «ленивых» вычислений
        self.popularity = 0  # популярность
        self.year = 0  # год создания

    # Ввод данных в объект класса из строки файла
    def input(self, str):
        self.name_len = int(len(str[1]))
        self.typing = int(str[2])
        self.lazy_calculations = bool(str[3])
        self.popularity = float(str[4])
        self.year = int(str[5])

    # Ввод данных в объект класса случайным образом
    def inputrnd(self):
        self.name_len = random.randint(1, 20)
        self.typing = random.randint(1, 2)
        self.lazy_calculations = bool(random.randint(1, 2))
        self.popularity = round(random.random() * (100 - 1) + 1, 3)
        self.year = random.randint(1957, 2020)
        pass

    # Вывод данных объекта класса в файл
    def output(self, ostr):
        if self.typing == 1:
            self.typing = " strict"
        else:
            self.typing = "dynamic"
        ostr.write(
            f"It is Functional programming language: number of characters = {self.name_len},  "
            f"typing = {self.typing}, "
            f"lazy calculations = {self.lazy_calculations}"
            f".\tPopularity = {self.popularity}%, "
            f"year = {self.year}, "
            f"quotient = {self.quotient()}\n")
        pass

    # Подсчет частного для данного объекта класса языка программирования
    def quotient(self):
        return round(self.year / float(self.name_len), 3)
