//Вариант 5
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MusicalInstrument {
    protected:
        string name;
        string material;
    public:
        MusicalInstrument(string i_name, string i_material) {
            name = i_name;
            material = i_material;
        }

        void setName(const string& n) {
            name = n;
        }

        void setMaterial(const string& m) {
            material = m;
        }

        virtual void display() const{
            cout << "   Name of instrument: " <<name <<endl;
            cout << "   Material: " << material <<endl;
        }

        ~MusicalInstrument(){}; 
};

class StringInstrument: public MusicalInstrument {
    protected:
        int strings;
    public:
        StringInstrument(const string& n, const string& m, const int& s): MusicalInstrument(n,m), strings(s) {};

        void display() const override {
            cout << "   Name of instrument: " <<name <<endl;
            cout << "   Material: " << material <<endl;
            cout << "   Strings: " << strings << endl;
        }

        ~StringInstrument(){};
};

class BrassInstrument: public MusicalInstrument {
    protected:
        string brass_type;
    public:
        BrassInstrument(const string& n, const string& m, const string& b): MusicalInstrument(n,m), brass_type(b) {};

        void display() const override {
            cout << "   Name of instrument: " <<name <<endl;
            cout << "   Material: " << material <<endl;
            cout << "   Type of brass: " << brass_type << endl;
        }

        ~BrassInstrument(){};
};

void UpdateObj(MusicalInstrument* ptr) {
    ptr->setMaterial("maple");
    ptr->setName("bass");
}

int main() {
    vector<MusicalInstrument*> vec;
    vec.push_back(new MusicalInstrument("Drums", "Metal"));
    vec.push_back(new StringInstrument("Guitar", "rosewood", 6));
    vec.push_back(new BrassInstrument("Saxophone", "brass", "strong"));

    for (const auto i: vec) {
        cout << "Instrument: " << endl;
        i->display();
        cout << "----------------------" << endl;
    }
    
    for (const auto i: vec) {
        cout << "Instrument: " << endl;
        UpdateObj(i);
        i->display();
        cout << "----------------------" << endl;
        delete i;
    }

    return 0;
}
