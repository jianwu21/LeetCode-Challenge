//
// Created by Jian Wu on 04/03/2020.
//

#ifndef LEETCODE_BINARYSEARCHSOLUTION_H
#define LEETCODE_BINARYSEARCHSOLUTION_H

#include <vector>

using namespace std;

class BinarySearchSolution {
    bool searchMatrix(vector<vector<int>>& matrix, int target);

    int search(vector<int>& nums, int target); // basic binary search 704

    int guessNumber(int n); // 374

    int searchInsert(vector<int>& nums, int target); // 35
};


#endif //LEETCODE_BINARYSEARCHSOLUTION_H
