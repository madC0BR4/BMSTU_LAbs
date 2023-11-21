#include <iostream>
#include <fstream>
#include <string>
#include <locale>
using namespace std;

struct Product {
    string name;
    double cost;
    int count;
};

void addProductToFile(const Product& product) {
    ofstream outFile("products.txt", ios::app);
    if (outFile.is_open()) {
        outFile << product.name << "," << product.cost << "," << product.count << endl;
        outFile.close();
        cout << "Студент успешно добавлен!" << endl;
    } else {
        cerr << "Не удалось открыть файл для записи." << endl;
    }
}

void searchProductByName(const string& name) {
    ifstream inFile("products.txt");
    if (inFile.is_open()) {
        string line;
        bool found = false;
        while (getline(inFile, line)) {
            size_t pos = line.find(',');
            string Name = line.substr(0, pos);
            if (Name == name) {
                cout << "Найден продукт: " << line << endl;
                found = true;
                break;
            }
        }
        inFile.close();
        if (!found) {
            cout << "Продукт с таким названием не найден." << endl;
        }
    } else {
        cerr << "Не удалось открыть файл для чтения." << endl;
    }
}

void sortProductsByCost() {
    ifstream inFile("products.txt");
    if (inFile.is_open()){
        string lines[100];
        int c = 0;
        string line;
        while (getline(inFile,line)) {
            lines[c] = line;
            c++;
        }
        inFile.close();
        for (int i = 0; i < c - 1; i++) {
            for (int j = 0; j < c - i - 1; j++) {
                size_t pos1_1 = lines[j].find(',');
                size_t pos1_2 = lines[j].find_last_of(',');
                size_t pos2_1 = lines[j + 1].find(',');
                size_t pos2_2 = lines[j + 1].find_last_of(',');
                double cost1 = stod(lines[j].substr(pos1_1 + 1, pos1_2));
                double cost2 = stod(lines[j + 1].substr(pos2_1 + 1, pos2_2));
                if (cost1 < cost2) {
                    swap(lines[j], lines[j + 1]);
                }
            }
        }
        ofstream outFile("products.txt");
        if (outFile.is_open()) {
            for (int i = 0; i < c; i++) {
                outFile << lines[i] << endl;
            }
            outFile.close();
            cout << "Продукты отсортированы по цене." << endl;
        } else {
            cerr << "Не удалось открыть файл для записи." << endl;
        }
    } else {
        cerr << "Не удалось открыть файл для чтения." << endl;
    }
}

void ShowWithParametr(const double& max_cost) {
    ifstream inFile("products.txt");
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            double line_cost = stod(line.substr(line.find(",")+1, line.find_last_of(",")));
            if (line_cost <= max_cost) {
                cout << line << endl;
            }
        
        }
        inFile.close();
    }
    else {
        cerr << "Не удалось открыть файл для чтения." << endl;
    }
}

void ShowAllProducts() {
    ifstream inFile("products.txt");
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            cout << line <<endl;
        }
        inFile.close();
    }
    else {
        cerr << "Не удалось открыть файл для чтения." << endl;
    }
}

int main(){
    int choice;
    string name;
    do {
        cout << "Меню:" << endl;
        cout << "1. Добавить продукт" << endl;
        cout << "2. Поиск продукта по названию" << endl;
        cout << "3. Сортировать продуктов по цене" << endl;
        cout << "4. Вывод продуктов по цене меньше заданного значения" << endl;
        cout << "5. Вывод всех продуктов" << endl;
        cout << "0. Выйти" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        switch (choice){
            case 1: {
                cin.ignore();
                double cost;
                int count;
                cout << "Введите название продукта: ";
                getline(cin, name);
                cout << "Введите цену продукта: ";
                cin >> cost; 
                cout << "Введите количество продукта: ";
                cin >> count;   
                Product newProd = {name, cost, count};
                addProductToFile(newProd);
                break;
            }

            case 2: {
                cin.ignore();
                cout << "Введите название продукта: ";
                getline(cin, name);
                searchProductByName(name);
                break;
            }

            case 3: {
                sortProductsByCost();
                break;
            }

            case 4: {
                int max_cost;
                cout << "Введите максимальную цену продукта:";
                cin >> max_cost;
                ShowWithParametr(max_cost);
                break;
            }

            case 5: {
                ShowAllProducts();
                break;
            }

            default: {
                cout << "Неверный выбор. Попробуйте снова." << endl;
                break;
            }
        }
    } while (choice !=0);

    return 0;
}

