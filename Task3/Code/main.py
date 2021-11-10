import sys
import time

from container import Container

# -------------------------------
# Ввод аргументов командной строки
if len(sys.argv) != 5:
    print("Incorrect command line!\n"
          "Waited:\n"
          "   command -f infile outfile01 outfile02\n"
          "Or:\n"
          "   command -n number outfile01 outfile02\n")
    exit(1)

print("Start")
start_time = time.time()
container = Container()

# -------------------------------
# Чтение данных из файла
if sys.argv[1] == "-f":
    ifile = open(sys.argv[2])
    insert = ifile.read()
    ifile.close()

    container.input(insert.split('\n'))

# Случайная генерация языков программирования
elif sys.argv[1] == "-n":
    number = int(sys.argv[2])
    if (number < 1) or (number > 10000):
        print("Incorrect number! " + str(number)
              + ". Set 0 < number <= 10000\n")
        exit(3)

    container.inputrnd(number)
else:
    print("Incorrect command line! You must write:\n"
          "   command -f infile outfile01 outfile02\n"
          "Or:\n"
          "   command -n number outfile01 outfile02\n")
    exit(2)

# -------------------------------
# Вывод содержимого контейнера в файл outfile1
ofile = open(sys.argv[3], 'w')
ofile.write("Filled Container:\n")
container.output(ofile)
ofile.close()

# Вывод содержимого отсортированного контейнера в файл outfile2
container.qsort()
ofile = open(sys.argv[4], 'w')
ofile.write("Sorted Container:\n")
container.output(ofile)

# Вывод времени работы программы в консоль и в два выходных файла
end_time = time.time()
result_time = str(round((end_time - start_time) * 1000))
print("Time: " + result_time + " milliseconds")
ofile.write("Time: " + result_time + " milliseconds")
ofile.close()
print("Finish")