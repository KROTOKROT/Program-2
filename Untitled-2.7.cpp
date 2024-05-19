#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
vector<vector<vector<int>>> readMatricesFromFile(const string& filename) {
    vector<vector<vector<int>>> matrices;
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        vector<vector<int>> matrix;
        int rows, cols;
        file >> rows >> cols;
        for (int i = 0; i < rows; ++i) {
            vector<int> row;
            for (int j = 0; j < cols; ++j) {
                int num;
                file >> num;
                row.push_back(num);
            }
            matrix.push_back(row);
        }
        matrices.push_back(matrix);
    }

    file.close();
    return matrices;
}
void writeMatricesToFile(const string& filename, const vector<vector<vector<int>>>& matrices) {
    ofstream file(filename);
    
    for (const auto& matrix : matrices) {
        file << matrix.size() << " " << matrix[0].size() << endl;
        for (const auto& row : matrix) {
            for (const auto& num : row) {
                file << num << " ";
            }
            file << endl;
        }
    }

    file.close();
}
bool containsMatrix(const vector<vector<int>>& matrix, const vector<vector<vector<int>>>& matrices) {
    for (const auto& m : matrices) {
        if (matrix == m) {
            return true;
        }
    }
    return false;
}
int main() {
    string firstFilename = "first.txt";
    string secondFilename = "second.txt";
    vector<vector<vector<int>>> firstMatrices = readMatricesFromFile(firstFilename);
    vector<vector<vector<int>>> secondMatrices = readMatricesFromFile(secondFilename);
    for (const auto& matrix : firstMatrices) {
        if (!containsMatrix(matrix, secondMatrices)) {
            secondMatrices.push_back(matrix);
        }
    }
    cout << "Содержимое первого файла:" << endl;
    for (const auto& matrix : firstMatrices) {
        cout << "Матрица:" << endl;
        for (const auto& row : matrix) {
            for (const auto& num : row) {
                cout << num << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << "Содержимое второго файла после добавления:" << endl;
    for (const auto& matrix : secondMatrices) {
        cout << "Матрица:" << endl;
        for (const auto& row : matrix) {
            for (const auto& num : row) {
                cout << num << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    writeMatricesToFile(secondFilename, secondMatrices);
    cout << "Обновленное содержимое второго файла сохранено." << endl;
    return 0;
}