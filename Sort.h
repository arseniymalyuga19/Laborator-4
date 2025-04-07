#pragma once
#include <vector>
#include <string>

class Sort {
private:
    std::vector<int> elements; // Вектор для хранения элементов

    void QuickSortHelper(int low, int high, bool ascendent); // Вспомогательная функция
    int Partition(int low, int high, bool ascendent);        // Разделение для QuickSort

public:
    Sort(int count, int min, int max);                      // Конструктор со случайными числами
    Sort(std::initializer_list<int> list);                  // Конструктор с {}
    Sort(const std::vector<int>& vec, int count);           // Конструктор из вектора
    Sort(int count, ...);                                   // Конструктор с переменным числом аргументов
    Sort(const std::string& numbers);                       // Конструктор из строки

    void InsertSort(bool ascendent = false);                // Сортировка вставками
    void QuickSort(bool ascendent = false);                 // Быстрая сортировка
    void BubbleSort(bool ascendent = false);                // Пузырьковая сортировка

    void Print();                                           // Печать элементов
    int GetElementsCount();                                 // Кол-во элементов
    int GetElementFromIndex(int index);                     // Получить элемент по индексу
};
