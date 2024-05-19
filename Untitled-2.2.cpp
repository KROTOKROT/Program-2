#include <iostream>
#include <fstream>

double sumPositiveNumbers(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл: " << filename << std::endl;
        return 0.0;
    }

    double number, sum = 0.0;
    while (file >> number) {
        if (number > 0) {
            sum += number;
        }
    }

    file.close();
    return sum;
}

int main() {
    double sum1 = sumPositiveNumbers("a1.txt");
    double sum2 = sumPositiveNumbers("a2.txt");

    std::cout << "Сумма положительных чисел в файле a1.txt: " << sum1 << std::endl;
    std::cout << "Сумма положительных чисел в файле a2.txt: " << sum2 << std::endl;
    std::cout << "Общая сумма положительных чисел в обоих файлах: " << (sum1 + sum2) << std::endl;

    return 0;
}