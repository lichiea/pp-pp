#pragma once

#define NOMINMAX

#include <iostream>
#include <omp.h>
#include <vector>
#include <sstream>
#include <iomanip>
#include <random>
#include <Windows.h>

using namespace std;

static vector <string> tasks = { "end", "all", "task2", "task3", "task4", "task5", "task6", "task7", "task8", "task9", "task10", "task11", "task12", "task13",
											   "task14", "task15", "task16", "task17", "task18", "task19", "task20", "task21", "task22", "task23", "task24", "task25", "task26", "task27", "task28", "task29",
											   "task30", "task31", "task32" };

int find_t(string t);

void task2();
void task3_1();
void task3_2();
void task4();
void task5();
void task6();
void task7();
void task8();
void task9();
void task10();
void task11();
void task12();

