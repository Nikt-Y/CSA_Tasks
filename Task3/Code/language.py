from abc import ABC

# ------------------------------
# Класс, от которого наследуются все языки программирования
class Language(ABC):

    # Ввод данных в объект класса из строки файла
    def input(self, str):
        pass

    # Ввод данных в объект класса случайным образом
    def inputrnd(self):
        pass

    # Вывод данных объекта класса в файл
    def output(self, ostr):
        pass

    # Подсчет частного для данного объекта класса языка программирования
    def quotient(self):
        pass
