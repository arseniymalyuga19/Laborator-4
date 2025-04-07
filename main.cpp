#include <iostream>
#include <vector>
#include "Sort.h"

int main() {
    // ����������� �� ���������� ����������
    Sort s1(10, 0, 100);
    std::cout << "Random values:\n";
    s1.Print();
    s1.BubbleSort(true);
    std::cout << "Bubble sorted ascending:\n";
    s1.Print();

    // ����������� � initializer list
    Sort s2{ 5, 3, 8, 1, 9 };
    std::cout << "Initializer list:\n";
    s2.Print();
    s2.InsertSort(false);
    std::cout << "Insert sorted descending:\n";
    s2.Print();

    // ����������� �� �������
    std::vector<int> vec = { 7, 2, 5, 4, 6 };
    Sort s3(vec, 5);
    std::cout << "From vector:\n";
    s3.Print();
    s3.QuickSort(true);
    std::cout << "Quick sorted ascending:\n";
    s3.Print();

    // ����������� � va_args
    Sort s4(4, 20, 10, 30, 15);
    std::cout << "Variadic:\n";
    s4.Print();
    s4.BubbleSort(false);
    std::cout << "Bubble sorted descending:\n";
    s4.Print();

    // ����������� �� ������
    Sort s5("10,40,100,5,70");
    std::cout << "From string:\n";
    s5.Print();
    s5.InsertSort(true);
    std::cout << "Insert sorted ascending:\n";
    s5.Print();

    return 0;
}

