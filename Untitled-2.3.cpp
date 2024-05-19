#include <iostream>
#include <fstream>
#include <sstream>

int main() {
    std::ifstream source("source.txt");
    std::ofstream destination("destination.txt");

    if (!source.is_open() || !destination.is_open()) {
        std::cerr << "Ошибка при открытии файлов." << std::endl;
        return 1;
    }
    std::string line;
    while (std::getline(source, line)) {
        std::istringstream iss(line);
        std::string word;
        bool firstWord = true;
        while (iss >> word) {
            if (!firstWord) {
                destination << ' ';
            }
            destination << word;
            firstWord = false;
        }
        destination << '\n';
    }

    source.close();
    destination.close();
    std::cout << "Преобразование файла завершено. Лишние пробелы удалены." << std::endl;
    return 0;
}