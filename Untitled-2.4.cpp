#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("numbers.txt");
    if (!file.is_open()) {
        std::cerr << "Ошибка при открытии файла." << std::endl;
        return 1;
    }

    int number;
    int count = 0;
    int position = 1;

    while (file >> number) {
        if (position % 2 != 0 && number < 0) {
            count++;
        }
        position++;
    }

    file.close();

    std::cout << "Количество отрицательных чисел на нечетных позициях: " << count << std::endl;

    return 0;
}