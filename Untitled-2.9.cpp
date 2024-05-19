#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;
void writeCharsToBinaryFile(const string& filename, const string& chars) {
    ofstream file(filename, ios::binary);
    file.write(chars.c_str(), chars.size());
    file.close();
}
string readCharsFromBinaryFile(const string& filename) {
    ifstream file(filename, ios::binary);
    file.seekg(0, ios::end);
    streampos fileSize = file.tellg();
    file.seekg(0, ios::beg);
    string chars(fileSize, '\0');
    file.read(&chars[0], fileSize);
    file.close();
    return chars;
}
void convertToUpperCase(string& chars) {
    for (char& c : chars) {
        if (islower(c)) {
            c = toupper(c);
        }
    }
}
int main() {
    string filename = "characters.bin";
    string originalChars, modifiedChars;
    cout << "Введите некоторое количество символов латинского алфавита: ";
    getline(cin, originalChars);
    writeCharsToBinaryFile(filename, originalChars);
    modifiedChars = readCharsFromBinaryFile(filename);
    cout << "Символы до изменения: " << originalChars << endl;
    convertToUpperCase(modifiedChars);
    writeCharsToBinaryFile(filename, modifiedChars);
    cout << "Символы после изменения: " << modifiedChars << endl;
    return 0;
}