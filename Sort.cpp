#include "Sort.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdarg>
#include <sstream>

Sort::Sort(int count, int min, int max) {
    srand((unsigned)time(0));
    for (int i = 0; i < count; i++) {
        elements.push_back(rand() % (max - min + 1) + min);
    }
}

Sort::Sort(std::initializer_list<int> list) {
    elements = list;
}

Sort::Sort(const std::vector<int>& vec, int count) {
    elements.assign(vec.begin(), vec.begin() + count);
}

Sort::Sort(int count, ...) {
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        elements.push_back(va_arg(args, int));
    }
    va_end(args);
}

Sort::Sort(const std::string& numbers) {
    std::stringstream ss(numbers);
    std::string item;
    while (std::getline(ss, item, ',')) {
        elements.push_back(std::stoi(item));
    }
}

void Sort::InsertSort(bool ascendent) {
    for (size_t i = 1; i < elements.size(); i++) {
        int key = elements[i];
        int j = static_cast<int>(i) - 1;
        while (j >= 0 && (ascendent ? elements[j] > key : elements[j] < key)) {
            elements[j + 1] = elements[j];
            j--;
        }
        elements[j + 1] = key;
    }
}

void Sort::BubbleSort(bool ascendent) {
    for (size_t i = 0; i < elements.size(); i++) {
        for (size_t j = 0; j < elements.size() - i - 1; j++) {
            if ((ascendent && elements[j] > elements[j + 1]) ||
                (!ascendent && elements[j] < elements[j + 1])) {
                std::swap(elements[j], elements[j + 1]);
            }
        }
    }
}

void Sort::QuickSort(bool ascendent) {
    QuickSortHelper(0, static_cast<int>(elements.size()) - 1, ascendent);
}

void Sort::QuickSortHelper(int low, int high, bool ascendent) {
    if (low < high) {
        int pi = Partition(low, high, ascendent);
        QuickSortHelper(low, pi - 1, ascendent);
        QuickSortHelper(pi + 1, high, ascendent);
    }
}

int Sort::Partition(int low, int high, bool ascendent) {
    int pivot = elements[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if ((ascendent && elements[j] < pivot) ||
            (!ascendent && elements[j] > pivot)) {
            i++;
            std::swap(elements[i], elements[j]);
        }
    }
    std::swap(elements[i + 1], elements[high]);
    return i + 1;
}

void Sort::Print() {
    for (int num : elements) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

int Sort::GetElementsCount() {
    return static_cast<int>(elements.size());
}

int Sort::GetElementFromIndex(int index) {
    if (index >= 0 && index < static_cast<int>(elements.size())) {
        return elements[index];
    }
    return -1;
}
