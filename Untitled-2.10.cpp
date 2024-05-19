#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct Student {
    string name;
    string group;
    int grades[3];
    double scholarship;
};
void writeStudentToBinaryFile(const string& filename, const Student& student) {
    ofstream file(filename, ios::binary | ios::app);
    file.write(reinterpret_cast<const char*>(&student), sizeof(Student));
    file.close();
}
void readStudentFromBinaryFile(const string& filename) {
    ifstream file(filename, ios::binary);
    Student student;
    while (file.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        bool allExcellent = true;
        for (int grade : student.grades) {
            if (grade < 5) {
                allExcellent = false;
                break;
            }
        }
        if (allExcellent) {
            student.scholarship *= 1.5;
        }
        cout << "Студент: " << student.name << endl;
        cout << "Группа: " << student.group << endl;
        cout << "Успеваемость: ";
        for (int i = 0; i < 3; ++i) {
            cout << student.grades[i] << " ";
        }
        cout << endl;
        cout << "Размер стипендии: " << student.scholarship << endl;
        cout << endl;
    }
    file.close();
}
int main() {
    string filename = "students.bin";
    writeStudentToBinaryFile(filename, {"Иванов И.И.", "Группа 1", {5, 5, 5}, 2200});
    writeStudentToBinaryFile(filename, {"Петров П.П.", "Группа 2", {4, 5, 5}, 2200});
    writeStudentToBinaryFile(filename, {"Сидоров С.С.", "Группа 3", {5, 4, 5}, 2200});
    writeStudentToBinaryFile(filename, {"Козлов К.К.", "Группа 1", {5, 5, 5}, 2200});
    cout << "Информация о студентах после обработки:" << endl;
    readStudentFromBinaryFile(filename);
    return 0;
}