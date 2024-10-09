#include "DynamicLibrary.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

std::string TEMP[100];

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
        cout << "Ошибка расчета! Выбраны/а неправильная позиция!\n";
        cout << endl;
        system("pause");
    }

}

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
        cout << "Ошибка расчета!\n";
        cout << endl;
        system("pause");
    }
}

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
        cout << "Ошибка перестановки!\n";
        cout << endl;
        system("pause");
    }
}