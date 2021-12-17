#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <algorithm>
#include <ctime>
#include <mutex>

// Проверяет, является ли строка числом.
bool isNumber(const std::string &string) {
    for (char i: string) {
        if (!isdigit(i)) {
            return false;
        }
    }
    return true;
}

// Метод для считывания текста из входного файла.
std::string readTextFile(const std::string &input_path, bool &flag) {
    std::string text;
    std::ifstream inFile(input_path);

    if (!inFile.is_open()) {
        std::cout << "Error in the address of the text input file.";
        flag = false;
        return text;
    }

    std::string line;
    while (getline(inFile, line)) {
        text += line + "\n";
    }

    return text;
}

// Метод для потоков. Здесь выполняется кодирование текста.
// В качестве параметров передается сам исходный текст (ссылка), алфавит, число потоков,
// чисто символов на один поток, и массив из строк, который содержит кусочки закодированного текста.
std::mutex m;
void encode(const std::string &text, std::string *alphabet, int num_of_thread,
            int one_thread_letters, std::string *parted_text_code) {
    int num_of_letter = 0;
    for (int i = num_of_thread * one_thread_letters;
         i < (num_of_thread + 1) * one_thread_letters; ++i, ++num_of_letter) {
        if (i >= text.length()) {
            break;
        }
        if (isalpha(text[i])) {
            parted_text_code[num_of_thread] += alphabet[(int) tolower(text[i]) - (int) 'a'];
        } else {
            parted_text_code[num_of_thread] += text[i];
        }
    }
    m.lock();
    std::cout << "The thread " << num_of_thread <<" has done its job...\n";
    m.unlock();
}

std::string briefcase(const std::string &text, std::string *alphabet, int number_of_threads) {
    std::string text_code;

    // Количество символов, которое будет обрабатывать 1 поток.
    int one_thread_letters = ((int) text.length() / number_of_threads) + 1;
    if (number_of_threads > text.size()) {
        // Если введенное количество потоков больше количества символов в тексте,
        // то приравниваем количество потоков к размеру текста.
        std::cout << "The number of streams is more than the size of the text!\n"
                     "The program replaced the number of threads " << number_of_threads <<
                  " on the size of the text " << text.length() << ".";
        one_thread_letters = 1;
        number_of_threads = (int) text.length();
    }

    // Массив из строк, в который будет содержать кусочки закодированного текста.
    auto parted_text_code = new std::string[number_of_threads];

    // Инициализируем массив потоков.
    auto *threads = new std::thread[number_of_threads];

    // Цикл, который создает потоки.
    for (int i = 0; i < number_of_threads; ++i) {
        threads[i] = std::thread(encode, text, alphabet, i, one_thread_letters, parted_text_code);
    }

    // Следим за тем, чтобы программа не завершилась еще до того,
    // как потоки завершат свою работу.
    for (int i = 0; i < number_of_threads; ++i) {
        threads[i].join();
    }

    // Склеиваем кусочки закодированного текста.
    for (int i = 0; i < number_of_threads; ++i) {
        text_code += parted_text_code[i];
    }
    return text_code;
}

// Метод для случайной генерации кодировки алфавита.
std::string *getRndAlph() {
    srand((unsigned int) time(nullptr));

    int rnd;
    int *arr_rnd = new int[100];
    auto *alph_code = new std::string[26];

    for (int i = 0; i < 100; ++i) {
        arr_rnd[i] = -1;
    }
    for (int i = 0; i < 26; ++i) {
        rnd = rand() % 100 + 10;
        while (arr_rnd[rnd] != -1) {
            rnd = (rnd - 1 + 100) % 100;
        }
        arr_rnd[rnd] = 1;
        alph_code[i] = std::to_string(rnd);
    }

    return alph_code;
}

// Метод для получения массива с закодированными буквами.
std::string *getAlphabet(const std::string &alphabet_file, bool &flag) {
    if (alphabet_file == "rnd") {
        return getRndAlph();
    }

    std::ifstream inFile(alphabet_file);
    auto *alph_code = new std::string[26];
    if (!inFile.is_open()) {
        std::cout << "Error in the address of the input file with the alphabet!";
        flag = false;
        return new std::string[1];
    }
    std::string line;
    for (int i = 0; i < 26; ++i) {
        getline(inFile, line);
        alph_code[i] = line.substr(2);
    }
    return alph_code;
}

bool paramsIsCorrect(int argc, char *argv[]) {
    // Проверка на количество введенных параметров.
    if (argc != 5) {
        std::cout << "Invalid input data format!\n"
                     "It is required to enter first the full path to the file for text input, \n"
                     "then the full path to the output file, \n"
                     "then the parameter for the alphabet (rnd - if random, "
                     "otherwise the path to the file with the alphabet \n"
                     "and finally the number of threads.";
        return false;
    }

    if (!isNumber(argv[4])) {
        std::cout << "It is required to enter the number of threads as a number.";
        return false;
    }

    if (atoi(argv[4]) < 1 | atoi(argv[4]) > std::thread::hardware_concurrency()) {
        std::cout << "Incorrect number of threads. \n"
                     "It is required to enter from 1 to " << std::thread::hardware_concurrency() << "inclusive.";
        return false;
    }

    return true;
}

void output(const std::string &output_path, std::string *alphabet, const std::string &text_code) {
    std::ofstream outFile(output_path);
    outFile << "Alphabet:\n";
    for (int i = 0; i < 26; ++i) {
        outFile << (char) ('a' + i) << " - " << alphabet[i] << "\n";
    }
    outFile << "\nEncoded text:\n" << text_code;
}

int main(int argc, char *argv[]) {
    // Имя входного файла.
    std::string input_path;
    // Имя выходного файла.
    std::string output_path;
    // Имя файла с закодированным алфавитом.
    std::string alphabet_path;

    // Переменная для считанного из файла текста.
    std::string text;

    // Проверка параметров запуска на корректность.
    if (!paramsIsCorrect(argc, argv)) {
        return 1;
    }

    input_path = argv[1];
    bool flag = true;
    std::cout << "Reading text from an input file...\n";
    text = readTextFile(input_path, flag);
    if (!flag) {
        return 2;
    }

    output_path = argv[2];

    alphabet_path = argv[3];
    std::string *alphabet = getAlphabet(alphabet_path, flag);
    if (!flag) {
        return 3;
    }

    int numberOfThreads = atoi(argv[4]);
    std::cout << "Text encoding...\n";
    unsigned int start_time = clock(); // время старта
    // Получаем закодированный текст с помощью потоков.
    // В качестве аргументов передаем сам текст, алфавит и число потоков.
    std::string text_code = briefcase(text, alphabet, numberOfThreads);

    unsigned int end_time = clock(); // конечное время
    unsigned int search_time = end_time - start_time; // искомое время
    std::cout << "Time: " << search_time << " milliseconds.\n";

    // Запись алфавита и закодированного текста в файл вывода.
    std::cout << "Output of encoded text";
    output(output_path, alphabet, text_code);
    return 0;
}
