//Вариант 1
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T1, typename T2>
class Pair {
public:
    Pair(const T1& first, const T2& second) : first(first), second(second) {}

    void displayPair() const {
        std::cout << first << ": " << second << std::endl;
    }

    void savePairToFile(std::ofstream& outFile) const {
        outFile << first << " " << second << " ";
    }

private:
    T1 first;
    T2 second;
};

class Product {
    protected:
        string name;
        double price;
        int quantity;
    public:
        Product(string p_name, double p_price, int p_quantity){
            name = p_name;
            price = p_price;
            quantity = p_quantity;
        }

        const string& getName() const{
            return name;
        }

        const double& getPrice() const{
            return price;
        }

        const int& getQuantity() const{
            return quantity;
        }

        void setName(const string& n){
            name = n;
        }

        void setPrice(const double& p){
            price = p;
        }

        void setQuantity(const int& q){
            quantity = q;
        }

        void saveToFile(ofstream& outFile) const {
            outFile << name << " " << price << " " << quantity << " " << endl;
        }

        virtual void displayInfo() const{
            cout << "Name of product: " << name << endl;
            cout << "Price of product: " << price << endl;
            cout << "Quantity of product: " << quantity << endl;
        }

        ~Product(){};
};

class Clothing: public Product {
    public:
        Clothing(const string& n, const double& p, const int& q): Product(n,p,q) {};

        void displayInfo() const override {
            cout << "Name of clothing: " << name << endl;
            cout << "Price of clothing: " << price << endl;
            cout << "Quantity of clothing: " << quantity << endl;
        }
};

class Electronics: public Product {
    public:
        Electronics(const string& n, const double& p, const int& q): Product(n,p,q) {};

        void displayInfo() const override {
            cout << "Name of electronics: " << name << endl;
            cout << "Price of electronics: " << price << endl;
            cout << "Quantity of electronics: " << quantity << endl;
        }
};

void addProduct(vector <Product*>& products) {
    string Name;
    double Price;
    int Quantity;
    cout << "Input name of product: ";
    cin >> Name;
    cout << "Input price of product: ";
    cin >> Price;
    cout << "Input quantity of product: ";
    cin >> Quantity;
    products.push_back(new Product(Name, Price, Quantity));
}

void searchProduct(vector <Product*> products) {
    string Name;
    cout << "Input name of product: ";
    cin >> Name;
    auto it = std::find_if(products.begin(), products.end(), [&](const Product* product) {
        //cout << "Product is found: "
        return product->getName() == Name;
    });
    if (it != products.end()) {
        (*it)->displayInfo();
    } else {
        cout << "Product not found." << endl;
    }
}

void saveProductsToFile(const vector<Product*>& products, const string& filename) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Error of file opening." << endl;
        return;
    }

    for (const auto* product : products) {
        product->saveToFile(outFile);
    }

    outFile.close();
}

int main() {
    vector <Product*> products;
    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "1 - Add product" << endl;
        cout << "2 - Find product" << endl;
        cout << "3 - Save products to file" << endl;
        cout << "4 - Show all products" << endl;
        cout << "5 - Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;
        switch(choice) {
            case 1: {
                addProduct(products);
                break;
            }
            case 2: {
                searchProduct(products);
                break;
            }
            case 3: {
                saveProductsToFile(products,"products.txt");
                break;
            }
            case 4: {
                for (const auto* product : products) {
                    product->displayInfo();
                    cout << "---------------------" << endl;
                }
                break;
            }
            case 5: {
                cout << "Exit" << endl;
                break;
            }
            default: {
                cout << "Incorrect input";
                break;
            }
        }
    } while (choice!=5);

    for (const auto* product : products) {
        delete product;
    }
    return 0;
}
