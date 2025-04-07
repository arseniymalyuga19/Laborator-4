#pragma once
#include <vector>
#include <string>

class Sort {
private:
    std::vector<int> elements; // ������ ��� �������� ���������

    void QuickSortHelper(int low, int high, bool ascendent); // ��������������� �������
    int Partition(int low, int high, bool ascendent);        // ���������� ��� QuickSort

public:
    Sort(int count, int min, int max);                      // ����������� �� ���������� �������
    Sort(std::initializer_list<int> list);                  // ����������� � {}
    Sort(const std::vector<int>& vec, int count);           // ����������� �� �������
    Sort(int count, ...);                                   // ����������� � ���������� ������ ����������
    Sort(const std::string& numbers);                       // ����������� �� ������

    void InsertSort(bool ascendent = false);                // ���������� ���������
    void QuickSort(bool ascendent = false);                 // ������� ����������
    void BubbleSort(bool ascendent = false);                // ����������� ����������

    void Print();                                           // ������ ���������
    int GetElementsCount();                                 // ���-�� ���������
    int GetElementFromIndex(int index);                     // �������� ������� �� �������
};
