#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream file("a.txt");
    if (!file.is_open()) {
        std::cerr << "Ошибка при открытии файла." << std::endl;
        return 1;
    }

    double number;
    int count_equal_to_five = 0;
    double sum_of_positive = 0.0;

    // Чтение чисел из файла и обработка условий
    while (file >> number) {
        if (number == 5) {
            count_equal_to_five++;
        }
        if (number > 0) {
            sum_of_positive += number;
        }
    }

    file.close();

    std::cout << "Количество элементов, равных 5: " << count_equal_to_five << std::endl;
    std::cout << "Сумма положительных элементов: " << sum_of_positive << std::endl;

    return 0;
}