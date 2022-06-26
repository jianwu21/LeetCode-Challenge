//
// Created by Jian Wu on 25/02/2020.
//

#include "SortAlgorithm.h"
#include <exception>

inline void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int left, int right) {
    int pivot = arr[left];
    int start = left + 1, end = right;

    while (start < end)
    {
        while (arr[start] < pivot) start++;
        while (arr[end] > pivot) end--;

        if (start < end) swap(arr[start], arr[end]);
    }
    swap(arr[left], arr[start--]);

    return start;
}

void SortAlgorithm::quickSort(int arr[], int left, int right) {
    if (left >= right)
        return;
    int j = partition(arr, left, right);
    quickSort(arr, left, j - 1);
    quickSort(arr, j + 1, right);
}

void SortAlgorithm::mergeSort() {
    throw std::exception();
}