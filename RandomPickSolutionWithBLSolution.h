//
// Created by Jian Wu on 26/06/2022.
//

#ifndef LEETCODE_RANDOMPICKSOLUTIONWITHBLSOLUTION_H
#define LEETCODE_RANDOMPICKSOLUTIONWITHBLSOLUTION_H

#endif //LEETCODE_RANDOMPICKSOLUTIONWITHBLSOLUTION_H

#include "Common.h"
#include <string>
#include <vector>
#include <queue>
#include <memory>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * Random pick with a given black list
 * Leetcode 710
 */
class RandomPickWithBlackListSolution{
private:
    unordered_map<int, int> b2w;
    int m_bound;
public:
    RandomPickWithBlackListSolution(int n, vector<int>& blacklist) {
        m_bound = n - blacklist.size();
        unordered_set<int> black_list_set;

        for (int b : blacklist) {
            if (b >= m_bound)
                black_list_set.emplace(b);
        }

        int w = m_bound;
        for (int b : blacklist) {
            if (b < m_bound) {
                while (black_list_set.count(w)) {
                    ++w;
                }

                b2w[b] = w++;
            }
        }
    }

    int Pick() {
        int x = rand() % m_bound;

        return b2w.count(x) ? b2w[x] : x;
    }
};
