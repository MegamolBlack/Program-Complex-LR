#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <cstdlib>
#include "DynamicLibrary.h"

//Файл в ветви MAIN

//Пространство имен
using namespace std;

//Глобальные переменные
typedef int (*function)(int a, int b);
const int MaxLeingh = 100;
/// @brief Массив Data содержит строку данных
string Data[MaxLeingh];
/// @brief Переменная FileNameInput содержит названия вхоного названия файла (например Data.txt)
string FileNameInput = "";
/// @brief Переменная FileNameOutput содержит названия выходного названия файла (например Data.txt)
string FileNameOutput = "";
/// @brief Переменная command содержит в себе текущее название вводимой команды (операции)
string command = "";
/// @brief lenght содержит длинну строки
int lenght = 0;

//Функция инициализации
/// @brief Функция выполняющая первоначальную инициализацию
/// @return Ничего
void Initialization() {

    setlocale(LC_ALL, "ru");

    for (int i = 0; i < MaxLeingh; i++) {
        Data[i] = "";
    }

    //Первичная загрузка файла
    int error = 1;
    while (error == 1) {
        cout << endl;
        cout << "Для начал работы необходимо ввести данные из файла!" << endl;
        cout << endl;
        cout << "Файл должен находится в той же директории что и программа! (Пример ввода: Data.txt)" << endl;
        cout << "Введите название файла: " << endl;
        cout << "> ";
        cin >> FileNameInput;
        cout << endl;
        string line;
        ifstream file(FileNameInput); // окрываем файл для чтения
        if (file) {
            while (getline(file, line))
            {
                Data[lenght] = line;
                lenght++;
            }
            file.close();     // закрываем файл

            cout << "Текущий массив: " << lenght << " элементов" << endl;
            for (int i = 0; i < lenght; i++) {
                cout << i + 1 << ". " << Data[i] << endl;
            }
            cout << endl;
            system("pause");

            error = 0;
        }
        else {
            file.close();     // закрываем файл
            cout << "Ошибка! Невозможно открыть данный файл!" << endl;
            cout << endl;
            system("pause");
            system("cls");
        }
    }
}

// Функция вывода главного меню
/// @brief Функция выполняющая вывод начального меню
/// @return Ничего
void PrintMenu() {
    system("cls");
    cout << endl;
    cout << "Программный комплекс\n";
    cout << endl;
    cout << "0. Выход\n";
    cout << "1. Ввести данные из файла\n";
    cout << "2. Сохранить данные в файл\n";
    cout << "3. Просмотреть текущие данные\n";
    cout << "4. Соединить слова\n";
    cout << "5. Разрезание слова по указанной длине\n";
    cout << "6. Изменения порядка слов\n";
    cout << endl;
    cout << "Введите комманду: " << endl;
    cout << "> ";
    cin >> command;
    system("cls");
}

// Функции исполнения команд
/// @brief Функция выполняющая загрузку файла
/// @return Ничего
void Command1() {
    ifstream file(""); // окрываем файл для чтения

    while (!file) {
        cout << endl;
        cout << "Файл должен находится в той же директории что и программа! (Пример ввода: Data.txt)" << endl;
        cout << "Введите название файла: " << endl;
        cout << "> ";
        cin >> FileNameInput;
        cout << endl;
        int lenght = 0;
        string line;
        ifstream file(FileNameInput); // окрываем файл для чтения

        if (file) {
            while (getline(file, line))
            {
                Data[lenght] = line;
                lenght++;
            }
            file.close();     // закрываем файл

            cout << "Текущий массив: " << lenght << " элементов" << endl;
            for (int i = 0; i < lenght; i++) {
                cout << i + 1 << ". " << Data[i] << endl;
            }
            cout << endl;
            system("pause");
            break;
        }
        else {
            file.close();     // закрываем файл
            cout << "Ошибка! Невозможно открыть данный файл!" << endl;
            cout << endl;
            cout << "Отменить операцию? (Y/N): " << endl;
            cout << "> ";
            string temp;
            cin >> temp;
            if (temp == "Y") {
                break;
            }
            system("cls");
        }
    }
}
/// @brief Функция выполняющая запись в файл
/// @return Ничего
void Command2() {
    cout << endl;
    cout << "Введите название файла для записи (пример: Data.txt): " << endl;
    cout << "> ";
    cin >> FileNameOutput;
    cout << endl;
    std::ofstream file;          // поток для записи
    file.open(FileNameOutput);      // открываем файл для записи
    if (file.is_open()) {
        for (int i = 0; i < lenght; i++) {
            file << Data[i] << endl;
        }
    }
    file.close();

    cout << "Файл " << FileNameOutput << " успешно сохранен!" << std::endl;


    cout << endl;
    system("pause");
}
/// @brief Функция выполняющая вывод текущего загруженного массива
/// @return Ничего
void Command3() {
    cout << endl;
    cout << "Текущий массив: " << lenght << " элементов" << endl;
    for (int i = 0; i < lenght; i++) {
        cout << i + 1 << ". " << Data[i] << endl;
    }
    cout << endl;
    system("pause");
}
/// @brief Функция выполняющая соединения выбраных слов
/// @return Ничего
void Command4() {
    cout << endl;
    cout << "Текущий массив: " << lenght << " элементов" << endl;
    for (int i = 0; i < lenght; i++) {
        cout << i + 1 << ". " << Data[i] << endl;
    }
    cout << endl;

    cout << "Введите позицию (от 1 до n), какое слово соединить: " << endl;
    cout << "> ";
    int PositionIn = -1;
    cin >> PositionIn;
    cout << "Введите позицию (от 1 до n), с каким словом соединить: " << endl;
    cout << "> ";
    int PositionOut = -1;
    cin >> PositionOut;
    AddDataFiles(Data, lenght, PositionIn, PositionOut);
    lenght--;
    for (int i = 0; i < lenght; i++) {
        Data[i] = TEMP[i];
    }
    cout << endl;
    cout << "Новый размер: " << lenght << " элементов" << endl;
    cout << "Измененный массив:" << endl;
    for (int i = 0; i < lenght; i++) {
        cout << i + 1 << ". " << Data[i] << endl;
    }

    cout << endl;
    system("pause");
}
/// @brief Функция выполняющая обрезание слов на выборанной позиции
/// @return Ничего
void Command5() {
    cout << endl;
    cout << "Текущий массив: " << lenght << " элементов" << endl;
    for (int i = 0; i < lenght; i++) {
        cout << i + 1 << ". " << Data[i] << endl;
    }
    cout << endl;

    cout << "Введите (от 1 до n)  позицию слова: " << endl;
    cout << "> ";
    int PositionWord = -1, NumberSlice1 = -1, NumberSlice2 = -1;
    cin >> PositionWord;
    cout << "Введите (от 1 до n)  позицию, с которой неоходимо отрезать: " << endl;
    cout << "> ";
    cin >> NumberSlice1;
    cout << "Введите (от 1 до n) сколько элементов необходимо убрать справа: " << endl;
    cout << "> ";
    cin >> NumberSlice2;
    cout << endl;

    SliceDataFiles(Data, lenght, PositionWord, NumberSlice1, NumberSlice2);
    for (int i = 0; i < lenght; i++) {
        Data[i] = TEMP[i];
    }
    cout << "Измененный массив:" << endl;
    for (int i = 0; i < lenght; i++) {
        cout << i + 1 << ". " << Data[i] << endl;
    }

    cout << endl;
    system("pause");
}
/// @brief Функция выполняющая изменение порядка слов
/// @return Ничего
void Command6() {
    cout << endl;
    cout << "Текущий массив: " << lenght << " элементов" << endl;
    for (int i = 0; i < lenght; i++) {
        cout << i + 1 << ". " << Data[i] << endl;
    }
    cout << endl;

    cout << "Введите (от 1 до n)  позицию первого слова: " << endl;
    cout << "> ";
    int Position1 = -1, Position2 = -1;
    cin >> Position1;
    cout << "Введите (от 1 до n)  позицию второго слова: " << endl;
    cout << "> ";
    cin >> Position2;
    cout << endl;

    SwapDataFiles(Data, lenght, Position1, Position2);
    for (int i = 0; i < lenght; i++) {
        Data[i] = TEMP[i];
    }
    cout << "Измененный массив:" << endl;
    for (int i = 0; i < lenght; i++) {
        cout << i + 1 << ". " << Data[i] << endl;
    }

    cout << endl;
    system("pause");
}

// Главная функция обработки
/// @brief Главная функция выполняющая всю обработку
/// @return Возвращает 0
int main()
{
    Initialization();

    
    while (command != "0") {

        PrintMenu();

        if (command == "1") {
            Command1();
        }
        else if (command == "2") {
            Command2();
        }
        else if (command == "3") {
            Command3();
        }
        else if (command == "4") {
            Command4();
        }
        else if (command == "5") {
            Command5();
        }
        else if (command == "6") {
            Command6();
        }
        else {
            //cout << "Введенной команды несуществует!" << endl;
        }
        
    }

    return 0;
}
