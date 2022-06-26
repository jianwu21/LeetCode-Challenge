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

/*
 *
 *
 * */
int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */
int guessNumber(int n) {
    return 0;
}

int searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = (right - left) / 2 + right;

        if (target >= nums[mid])
            left = mid;
        if (target <= nums[mid])
            right = mid;
    }

    return left;

}