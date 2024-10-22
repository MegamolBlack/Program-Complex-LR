#include "DynamicLibrary.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

/// @brief Переменная TEMP[] хранит в себе значения в процессе выполнения определенных функций
std::string TEMP[100];

/// @brief Функция выполняющая первоначальную инициализацию
/// @param *Data массив данных текущих слов
/// @param leinght длинна массива Data
/// @param PositionWordIn переменная содержащая позицию первого слова
/// @param PositionWordOut переменная содержащая позицию второго слова
/// @return Ничего
void AddDataFiles(string *Data,int leinght, int PositionWordIn, int PositionWordOut) {
    PositionWordIn--;
    PositionWordOut--;
    for (int i = 0; i < leinght;i++) {
        TEMP[i]=Data[i];
    }
    if ((PositionWordIn < leinght) && (PositionWordOut < leinght) && (PositionWordIn != PositionWordOut)) {
        TEMP[PositionWordIn] = TEMP[PositionWordIn] + TEMP[PositionWordOut];
        for (int i = PositionWordOut; i < (leinght-1);i++) {
                TEMP[i] = TEMP[i + 1];
        }
    }
    else {
        cout << endl;
        cout << "Îøèáêà ðàñ÷åòà! Âûáðàíû/à íåïðàâèëüíàÿ ïîçèöèÿ!\n";
        cout << endl;
        system("pause");
    }

}

/// @brief Функция выполняющая первоначальную инициализацию
/// @param *Data массив данных текущих слов
/// @param leinght длинна массива Data
/// @param PositionWord переменная содержащая позицию слова в массиве
/// @param NumberSlice1 переменная содержащая первую позицию для разрезки слова
/// @param NumberSlice2 переменная содержащая вторую позицию для разрезки слова
/// @return Ничего
void SliceDataFiles(string* Data, int leinght, int PositionWord, int NumberSlice1, int NumberSlice2) {
    PositionWord--;

    for (int i = 0; i < leinght; i++) {
        TEMP[i] = Data[i];
    }
    if ((PositionWord < leinght) && (NumberSlice1 < sizeof(TEMP[PositionWord])) && (NumberSlice2 < sizeof(TEMP[PositionWord]))) {
        TEMP[PositionWord] = TEMP[PositionWord].erase(NumberSlice1, NumberSlice2);
    }
    else {
        cout << endl;
        cout << "Îøèáêà ðàñ÷åòà!\n";
        cout << endl;
        system("pause");
    }
}

/// @brief Функция выполняющая первоначальную инициализацию
/// @param *Data массив данных текущих слов
/// @param leinght длинна массива Data
/// @param Position1 переменная содержащая позицию первого слова
/// @param Position2 переменная содержащая позицию второго слова
/// @return Ничего
void SwapDataFiles(string *Data, int leinght, int Position1, int Position2) {
    for (int i = 0; i < leinght; i++) {
        TEMP[i] = Data[i];
    }
    string tmp1, tmp2;
    Position1--;
    Position2--;

    if ((Position1 < leinght) && (Position2 < leinght)) {
        tmp1 = TEMP[Position1];
        tmp2 = TEMP[Position2];
        TEMP[Position1] = tmp2;
        TEMP[Position2] = tmp1;
    }
    else {
        cout << endl;
        cout << "Îøèáêà ïåðåñòàíîâêè!\n";
        cout << endl;
        system("pause");
    }
}
