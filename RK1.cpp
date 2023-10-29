#include <iostream>
#include <cstring>
#include <string>
#include <locale>
using namespace std;

//Вариант 5
int main(){

    setlocale(LC_ALL,"Russian");
    //создание динамических массивов размером 1 для задач, приоритетов и сроков выполнения

    int size = 1;
    int* priority = new int[size];
    char** point = new char*[size];
    char** deadline = new char*[size];
    while (true) {

        //Ввод всех параметров
        char buffer[100];
        cout<<"Введите название задачи: ";
        cin.getline(buffer,100);
        point[size-1] = new char[strlen(buffer)];
        strcpy(point[size-1],buffer);

        cout<<"Введите приоритет задачи (от 1 до 10): ";
        cin>>priority[size-1];
        cin.ignore();

        char buffer1[100];
        cout<<"Введите срок выполения: ";
        cin.getline(buffer1,100);
        deadline[size-1] = new char[strlen(buffer1)];
        strcpy(deadline[size-1],buffer1);

        //проверка на добавлнение задачи, если задачи добавлять не надо, происходит выход из цикла

        char answer[10];
        cout<<"Хотите добавить еще одну задачу (да/нет)? ";
        char a[10] = "да";
        cin.getline(answer,10);
        if (strcmp(answer,a)!=0) {
            break;
        }
        size++;

    }
    
    //сортировка массивов по убыванию приоритетов
    for (int i = 0; i<size-1; i++){
        for (int j = 0; j<size-1; j++){
            if (priority[j]<priority[j+1]) {
                swap(priority[j],priority[j+1]);
                swap(deadline[j],deadline[j+1]);
                swap(point[j],point[j+1]);
            }
        }
    }

    //вывод задач
    cout<<endl;
    for (int i=0; i<size; i++) {
        cout<<"Задача "<<i+1<<": "<<point[i]<<". Приоритет: "<<priority[i]<<". Срок выполнения: "<<deadline[i]<<". "<<endl;
    }

    delete[] priority;
    delete[] deadline;
    delete[] point;
    
    return 0;

}
