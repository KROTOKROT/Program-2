#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
struct Worker {
    string name;
    string position;
    double salary;
};
void writeString(ofstream& file, const string& str) {
    size_t len = str.size();
    file.write(reinterpret_cast<const char*>(&len), sizeof(len));
    file.write(str.c_str(), len);
}
string readString(ifstream& file) {
    size_t len;
    file.read(reinterpret_cast<char*>(&len), sizeof(len));
    string str(len, '\0');
    file.read(&str[0], len);
    return str;
}
void writeDataToBinaryFile(const string& filename, const vector<Worker>& workers) {
    ofstream file(filename, ios::binary);

    for (const auto& worker : workers) {
        writeString(file, worker.name);
        writeString(file, worker.position);
        file.write(reinterpret_cast<const char*>(&worker.salary), sizeof(worker.salary));
    }
    file.close();
}
vector<Worker> readDataFromBinaryFile(const string& filename) {
    vector<Worker> workers;
    ifstream file(filename, ios::binary);
    while (file.peek() != EOF) {
        Worker worker;
        worker.name = readString(file);
        worker.position = readString(file);
        file.read(reinterpret_cast<char*>(&worker.salary), sizeof(worker.salary));
        workers.push_back(worker);
    }

    file.close();
    return workers;
}
int main() {
    string filename = "workers.bin";
    vector<Worker> workers = {
        {"Иванов", "слесарь", 30000},
        {"Петров", "инженер", 40000},
        {"Сидоров", "слесарь", 32000},
        {"Козлов", "слесарь", 28000},
        {"Михайлов", "инженер", 42000}
    };
    writeDataToBinaryFile(filename, workers);
    vector<Worker> loadedWorkers = readDataFromBinaryFile(filename);
    double totalSalary = 0;
    int count = 0;
    for (const auto& worker : loadedWorkers) {
        if (worker.position == "слесарь") {
            totalSalary += worker.salary;
            count++;
        }
    }
    double averageSalary = (count == 0) ? 0 : totalSalary / count;
    cout << "Средняя зарплата слесарей: " << averageSalary << endl;
    cout << "Количество слесарей: " << count << endl;
    return 0;
}