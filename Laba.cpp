#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
    setlocale(0,"RU");
    char str[200];
    int k_start_a = 0;
    int a_inlast = 0;
    int len_short = 100;
    int same_first_last = 0;

    cout<<"Input string: ";
    cin.getline(str,200);
    
    char* token = strtok(str," ");
    int counter = 1;
    char a[] = "a";

    cout<<endl;
    cout<<"Words in low register: "<<endl;

    while (token) {
        //Кол-во на а
        if (*(token)==a[0]) {k_start_a++;}
        //длина наименьшего
        if (strlen(token)<len_short) {len_short=strlen(token);}
        //кол-во а в последнем
        if (counter==10) { 
            for (int i = 0;token[i];i++) {
                if (token[i]==a[0]) {a_inlast++;} 
            }
        }
        //Кол-во слов, начиющихся и заканчивающихся на один символ
        if (token[0]==token[strlen(token)-1]) {same_first_last++;}
        //изменение в нижний регистр
        for (int i = 0; token[i]; i++) {
            token[i]=tolower(token[i]);
        }
        cout<<token<<" ";

        counter++;
        token = strtok(NULL," ");
    }
    cout<<endl;
    cout<<"Start with a: "<<k_start_a<<endl;
    cout<<"Shortest word: "<<len_short<<endl;
    cout<<"a in last word: "<<a_inlast<<endl;
    cout<<"Words with same first and last letter: "<<same_first_last;
    return 0;
}