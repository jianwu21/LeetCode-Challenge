//
// Created by Jian Wu on 04/03/2020.
//

#include "BinarySearchSolution.h"

bool BinarySearchSolution::searchMatrix(vector<vector<int>> &matrix, int target) {
    int h = matrix.size(), w = matrix.front().size();

    int front = 0, back = h - 1;

    while (front < back) {
        int mid = (back + front) / 2;

        if (matrix[mid].front() <= target) front = mid;
        else back = mid - 1;
    }

    return false;
}