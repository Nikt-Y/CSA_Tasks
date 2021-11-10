import random

from procedural import Procedural
from objectOriented import ObjectOriented
from functional import Functional

# Ввод типа языка программирования из файла
def lan_input(str):
    k = int(str[0])
    language = None

    if k == 1:
        language = Procedural()
    elif k == 2:
        language = ObjectOriented()
    elif k == 3:
        language = Functional()

    language.input(str)
    return language


# Ввод типа языка программирования случайным образом
def lan_rnd():
    k = random.randint(1, 3)
    language = None
    if k == 1:
        language = Procedural()
    elif k == 2:
        language = ObjectOriented()
    elif k == 3:
        language = Functional()

    language.inputrnd()
    return language
