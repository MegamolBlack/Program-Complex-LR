#include <string>

using namespace std;

#pragma once

#ifdef DYNAMICLIBRARY_API_EXPORTS
#define DYNAMICLIBRARY_API __declspec(dllexport)
#else
#define DYNAMICLIBRARY_API __declspec(dllimport)
#endif

extern "C" DYNAMICLIBRARY_API void AddDataFiles(string* Data, int leinght, int PositionWordIn, int PositionWordOut);

extern "C" DYNAMICLIBRARY_API void SliceDataFiles(string* Data, int leinght, int PositionWord, int NumberSlice1, int NumberSlice2);

extern "C" DYNAMICLIBRARY_API void SwapDataFiles(string* Data, int leinght, int Position1, int Position2);

extern "C" DYNAMICLIBRARY_API string TEMP[100];