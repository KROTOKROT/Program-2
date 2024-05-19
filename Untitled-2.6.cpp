#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;
vector<double> readDataFromFile(const string& filename) {
    vector<double> data;
    ifstream file(filename);
    double num;

    while (file >> num) {
        data.push_back(num);
    }

    file.close();
    return data;
}
void writeResultToFile(const string& filename, double result) {
    ofstream file(filename);
    file << "Сумма наибольшего и наименьшего чисел: " << fixed << setprecision(2) << result << endl;
    file.close();
}
int main() {
    string inputFilename = "data.txt";
    string outputFilename = "result.txt";
    vector<double> data = readDataFromFile(inputFilename);
    if (data.empty()) {
        cout << "Файл пустой или не удалось прочитать данные из файла." << endl;
    } else {
        auto minmax_pair = minmax_element(data.begin(), data.end());
        double min_val = *minmax_pair.first;
        double max_val = *minmax_pair.second;
        double sum = min_val + max_val;
        cout << "Наименьшее число: " << min_val << endl;
        cout << "Наибольшее число: " << max_val << endl;
        cout << "Сумма наибольшего и наименьшего чисел: " << fixed << setprecision(2) << sum << endl;
        writeResultToFile(outputFilename, sum);
        cout << "Результат сохранен в файле: " << outputFilename << endl;
    }
    return 0;
}