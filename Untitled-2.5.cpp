#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;
struct Buyer {
    string surname;
    string name;
    string patronymic;
    string gender;
    string nationality;
    int height;
    int weight;
    string birthDate;
    string phoneNumber;
    string address;
    string creditCardNumber;
    string bankAccountNumber;
};
vector<Buyer> readBuyersFromFile(const string& filename) {
    vector<Buyer> buyers;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Buyer buyer;
        getline(ss, buyer.surname, ';');
        getline(ss, buyer.name, ';');
        getline(ss, buyer.patronymic, ';');
        getline(ss, buyer.gender, ';');
        getline(ss, buyer.nationality, ';');
        ss >> buyer.height;
        ss.ignore(1); 
        ss >> buyer.weight;
        ss.ignore(1);
        getline(ss, buyer.birthDate, ';');
        getline(ss, buyer.phoneNumber, ';');
        getline(ss, buyer.address, ';');
        getline(ss, buyer.creditCardNumber, ';');
        getline(ss, buyer.bankAccountNumber, ';');
        if (buyer.address.find("Ставрополь") != string::npos) {
            buyers.push_back(buyer);
        }
    }
    file.close();
    return buyers;
}
void writeBuyersToFile(const string& filename, const vector<Buyer>& buyers) {
    ofstream file(filename);
    for (const auto& buyer : buyers) {
        file << "Фамилия: " << buyer.surname << endl;
        file << "Имя: " << buyer.name << endl;
        file << "Отчество: " << buyer.patronymic << endl;
        file << "Пол: " << buyer.gender << endl;
        file << "Национальность: " << buyer.nationality << endl;
        file << "Рост: " << buyer.height << " см" << endl;
        file << "Вес: " << buyer.weight << " кг" << endl;
        file << "Дата рождения: " << buyer.birthDate << endl;
        file << "Номер телефона: " << buyer.phoneNumber << endl;
        file << "Адрес: " << buyer.address << endl;
        file << "Номер кредитной карты: " << buyer.creditCardNumber << endl;
        file << "Номер банковского счета: " << buyer.bankAccountNumber << endl;
        file << "---------------------------------------" << endl;
    }
    file.close();
}
int main() {
    string inputFilename = "buyers.txt";
    string outputFilename = "buyers_from_stavropol.txt";
    vector<Buyer> buyers = readBuyersFromFile(inputFilename);
    if (buyers.empty()) {
        cout << "Нет данных о покупателях из города Ставрополь." << endl;
    } else {
        cout << "Данные о покупателях из города Ставрополь:" << endl;
        for (const auto& buyer : buyers) {
            cout << "Фамилия: " << buyer.surname << endl;
            cout << "Имя: " << buyer.name << endl;
            cout << "Отчество: " << buyer.patronymic << endl;
            cout << "Пол: " << buyer.gender << endl;
            cout << "Национальность: " << buyer.nationality << endl;
            cout << "Рост: " << buyer.height << " см" << endl;
            cout << "Вес: " << buyer.weight << " кг" << endl;
            cout << "Дата рождения: " << buyer.birthDate << endl;
            cout << "Номер телефона: " << buyer.phoneNumber << endl;
            cout << "Адрес: " << buyer.address << endl;
            cout << "Номер кредитной карты: " << buyer.creditCardNumber << endl;
            cout << "Номер банковского счета: " << buyer.bankAccountNumber << endl;
            cout << "---------------------------------------" << endl;
        }
        writeBuyersToFile(outputFilename, buyers);
        cout << "Данные о покупателях из города Ставрополь сохранены в файле: " << outputFilename << endl;
    }
    return 0;
}