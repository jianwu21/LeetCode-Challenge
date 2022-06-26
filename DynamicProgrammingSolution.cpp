//
// Created by Jian Wu on 22/02/2020.
//
#include <algorithm>
#include <numeric>
#include <cmath>

#include "DynamicProgrammingSolution.h"

/**
 *
 * @param nums
 * @return
 */
int DynamicProgrammingSolution::maxSubArray(vector<int>& nums)
{
    vector<int> dp;
    dp.push_back(nums.front());

    for (int i = 1; i < nums.size(); ++i) {
        if (dp[i-1] < 0)
            dp.push_back(nums[i]);
        else
            dp.push_back(dp[i-1]+nums[i]);
    }

    return *max_element(dp.begin(), dp.end());
}

int DynamicProgrammingSolution::maxProduct(vector<int>& nums) {
    if (nums.size() == 1) return nums.front();

    int size = nums.size();
    vector<int> pos(size, 0), neg(size, 0);
    pos[0] = nums[0] > 0 ? nums[0] : 0;
    neg[0] = nums[0] < 0 ? nums[0] : 0;

    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] > 0) {
            pos[i] = pos[i-1] == 0 ? nums[i] : pos[i-1] * nums[i];
            neg[i] = neg[i-1] * nums[i];
        } else if (nums[i] < 0) {
            pos[i] = neg[i-1] * nums[i];
            neg[i] = pos[i-1] == 0 ? nums[i] : pos[i-1] * nums[i];
        }
    }

    return *max_element(pos.begin(), pos.end());
}

int DynamicProgrammingSolution::minPathSum(vector<vector<int>> &grid) {
    if (grid.empty()) return 0;

    for (int i = 1; i < grid[0].size(); ++i) {
        grid[0][i] += grid[0][i-1];
    }

    for (int i = 1; i < grid.size(); ++i) {
        grid[i][0] += grid[i-1][0];
    }

    for (int i = 1; i < grid[0].size(); ++i) {
        for (int j = 1; j < grid.size(); ++j) {
            grid[j][i] += min(grid[j-1][i], grid[j][i-1]);
        }
    }

    return grid.back().back();
}

int DynamicProgrammingSolution::minimumTotal(vector<vector<int>>& triangle)
{
//    if (triangle.empty()) return 0;
//
//    for (int row = 1; row < triangle.size(); ++row) {
//        triangle[row].front() += triangle[row-1].front();
//        triangle[row].back() += triangle[row-1].back();
//
//        for (int col = 1; col < triangle[row].size() - 1; ++col) {
//            triangle[row][col] += min(triangle[row-1][col-1], triangle[row-1][col]);
//        }
//    }
//    return *min_element(triangle.back().begin(), triangle.back().end());
    if (triangle.empty()) return 0;
    int numOfRows = triangle.size();

    for (int row = numOfRows - 2; row >= 0 ; --row) {
        for (int col = 0; col < triangle[row].size(); ++col) {
            triangle[row][col] += min(triangle[row+1][col], triangle[row+1][col+1]);
        }
    }

    return triangle.front().front();
}

int DynamicProgrammingSolution::findLongestChain(vector<vector<int>> &pairs) {
    // Greedy implement

    sort(
            pairs.begin(),
            pairs.end(),
            [](const vector<int>& v1, const vector<int>& v2) -> bool {return v1[1] < v2[1];});

    int ans = 0, cur = INT_MIN;

    for (const auto& pair : pairs) {
        if (cur < pair[0]) {
            cur = pair[1];
            ans++;
        }
    }

    return ans;
}

vector<vector<int>> DynamicProgrammingSolution::findSubsequences(vector<int> &nums) {
    return vector<vector<int>>(9, vector<int>(9, 0));
}

bool DynamicProgrammingSolution::canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (sum % 2 == 1 || nums.size() == 1) return false;
    vector<vector<int>> dp(nums.size(), vector<int>(sum/2 + 1, 0));

    dp[0][nums[0]] = 1;
    dp[0][0] = 1;

    for (int i = 0; i < nums.size(); ++i) {
        dp[i][0] = 1;
    }

    for (int i = 1; i < nums.size(); ++i) {
        for (int j = 0; j < sum/2+1; ++j) {
            dp[i][j] = dp[i - 1][j] || ((j >= nums[i]) ? dp[i - 1][j - nums[i]] : 0);
        }

        if (dp[i].back() == 1) return true;
    }

    return false;
}

int DynamicProgrammingSolution::numDecodings(string s) {
    if (s.empty()) return 0;
    vector<int> ans(s.size() + 1, 0);
    ans[0] = 1;
    ans[1] = s[0] == '0' ? 0 : 1;

    for (int i = 2; i < s.size() + 1; ++i) {
        int index = s[i-1] - '0';
        ans[i] = ans[i-1] * (index > 0 ? 1 : 0);
        int doubleChar = index + 10 * (s[i - 2] - '0');
        if (doubleChar <= 26 && doubleChar >= 10)
            ans[i] += ans[i-2];
    }

    return ans.back();
}

vector<TreeNode *> DynamicProgrammingSolution::generateTrees(int n) {
    if (n == 1) return vector<TreeNode*> {new TreeNode(n)};
    vector<vector<TreeNode*>> ans(n);
    ans[0] = {new TreeNode(n)};

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < ans[i-1].size(); ++j) {
            while (i)
            {
                TreeNode* cur = new TreeNode(0);
                cur->right = ans[i-1][j];
                TreeNode* newTreeNode = new TreeNode(i+1);

                ans[i].push_back(cur->right);
            }
        }
    }

    return ans.back();
}

int DynamicProgrammingSolution::numSquares(int n) {
    vector<int> ans(n+1, INT_MAX);
    ans[0] = 0;

    for (int i = 1; i < n+1; ++i) {
        int maxSqrt = sqrt(i);

        for (int j = 1; j <= maxSqrt; ++j) {
            ans[i] = min(ans[i], ans[i-j * j] + 1);
        }
    }

    return ans.back();
}

int DynamicProgrammingSolution::countPrimes(int n) {
    if (n <= 1) return 0;

    int dp[n]; //array is faster than vector
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    dp[1] = 0;

    for (int i = 2; i < n; ++i) {
        if(dp[i] == -1){
            for(int j=2;i*j < n;j++){
                dp[i*j]=0;
            }
        }
    }

    return -accumulate(dp, dp + n, 0);
}

int DynamicProgrammingSolution::lenLongestFibSubseq(vector<int> &A) {
    return 0;
}

int DynamicProgrammingSolution::integerBreak(int n) {
    vector<int> ans(n + 1, 0);
    ans[1] = 1;

    for (int i = 2; i < n+1; ++i) {
        for (int j = 1; j < i; ++j) {
            ans[i] = max(ans[i], j * ans[i-j]);
            ans[i] = max(ans[i], j * (i-j));
        }
    }

    return ans.back();
}

vector<int> DynamicProgrammingSolution::countBits(int num) {
    if (!num) return {0};

    vector<int> res(num+1, 0);
    for (int i = 1; i <= num; ++i) {
        res[i] = (i & 1) == 1 ? 1 + res[i-1] : res[i>>1];
    }
    return res;
}

int DynamicProgrammingSolution::rob(vector<int> &nums) {
    int len = nums.size();

    if (!len) return 0;
    if (len == 1) return nums[0];

    vector<int> ans(nums.size(), 0);
    ans[0] = nums[0], ans[1] = max(nums[0], nums[1]);
    for (int i = 2; i < len; ++i) {
        ans[i] = max(ans[i-1], nums[i] + ans[i-2]);
    }

    return ans.back();
}

int DynamicProgrammingSolution::robInCircle(vector<int> &nums) {
    int len = nums.size();
    if (!len) return 0;
    if (len <= 3) return *max_element(nums.begin(), nums.end());

    vector<int> fromFirst(len-1, 0);
    fromFirst[0] = nums[0], fromFirst[1] = max(nums[0], nums[1]);

    vector<int> fromSecond(len-1, 0);
    fromSecond[0] = nums[1], fromSecond[1] = max(nums[1], nums[2]);

    for (int i = 2; i < len-1; ++i) {
        fromFirst[i] = max(fromFirst[i-1], nums[i] + fromFirst[i-2]);
        fromSecond[i] = max(fromSecond[i-1], nums[i+1] + fromSecond[i-2]);
    }

    return max(fromFirst.back(), fromSecond.back());
}

bool DynamicProgrammingSolution::wordBreak(const string& s, vector<string>& wordDict) {
    vector<bool> dp(s.size()+1, false);
    dp[0] = true;

    for (int i = 1; i <= s.size(); ++i) {
        for (const auto& word : wordDict)
        {
            int startIndex = i - word.size();
            if (startIndex < 0 || !dp[startIndex]) continue;
            if (s.substr(startIndex, i - startIndex) == word && dp[startIndex])
            {
                dp[i] = true;
                break;
            }
        }
    }

    return dp.back();
}

int DynamicProgrammingSolution::lengthOfLIS(vector<int> &nums) {
    /*
     * O(n^2)
     */
    if (!nums.size()) return 0;
    // Array is faster than Vector
    int* dp = (int*)malloc(sizeof(int) * (nums.size()));
    dp[0] = 1;
    int length = 1;

    for (int i = 1; i < nums.size(); ++i) {
        dp[i] = 1;

        for (int j = 0; j < i; ++j) {
            if (nums[i] >= nums[j]) {
                dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
            }
        }

        length = length > dp[i] ? length : dp[i];
    }

    return length;
}

/*
 * O(n * log(n))
 */
int DynamicProgrammingSolution::lengthOfLIS(vector<int> &nums, bool useBinarySeaarch) {
    if (!useBinarySeaarch) 
        return this->lengthOfLIS(nums);
    
    return 0;
}

int DynamicProgrammingSolution::maxProfit(vector<int> &prices) {
    if (prices.size() <= 1) return 0;
    int buyPrice = prices[0], maxProfit = 0;

    for (int i = 1; i < prices.size(); ++i) {
        buyPrice = prices[i-1] < buyPrice ? prices[i-1] : buyPrice;
        maxProfit = max(prices[i] - buyPrice, maxProfit);
    }

    return maxProfit;
}

int DynamicProgrammingSolution::maxProfitWithMultiTransactions(vector<int> &prices) {

    // TODO: Implement
    if (prices.size() <= 1) return 0;
    int maxProfit = 0;

    for (int i = 1; i < prices.size(); ++i) {
        int profit = prices[i] - prices[i-1];
        maxProfit += profit > 0 ? profit : 0;
    }

    return maxProfit;
}

int DynamicProgrammingSolution::longestCommonSubsequence(string text1, string text2) {
    if (!text1.size() || !text2.size()) return 0;
    vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));

    for (int i = 1; i < text1.size()+1; ++i)
    {
        for (int j = 1; j < text2.size()+1; ++j)
        {
            if (text1[i-1] == text2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp.back().back();
}

int DynamicProgrammingSolution::findLength(vector<int> &A, vector<int> &B) {
    if (!A.size() || !B.size()) return 0;

    int longest = 0;
    vector<vector<int>> dp(A.size(), vector<int>(B.size(), 0));

    for (int i = 0; i < A.size(); ++i) {
        dp[i].front() = (A[i] == B.front()) ? 1 : 0;
    }

    for (int i = 0; i < B.size(); ++i) {
        dp.front()[i] = (A.front() == B[i]) ? 1 : 0;
    }

    for (int i = 1; i < A.size(); ++i) {
        for (int j = 1; j < B.size(); ++j) {
            if (A[i] == B[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            longest = max(dp[i][j], longest);
        }
    }

    return longest;
}

vector<string> DynamicProgrammingSolution::generateParenthesis(int n)
{
    if (n == 1) return {"()"};
    vector<string> results;

    for (const auto& oldRe : generateParenthesis(n-1))
    {
        results.push_back("(" + oldRe + ")");
        results.push_back("()" + oldRe);
        if ("()" + oldRe != oldRe + "()")
        {
            results.push_back(oldRe + "()");
        }
    }

    return results;
}

vector<vector<int>> DynamicProgrammingSolution::permute(vector<int> &nums) {
    if (nums.empty()) return {};
    vector<vector<vector<int>>> res;
    res.push_back({{ nums[0] }});

    for (int i = 1; i < nums.size(); ++i)
    {
        vector<vector<int>> cur;
        for (const vector<int>& r : res.back())
        {
            for (int it = 0; it <= r.size(); ++it)
            {
                auto n = r;
                n.insert(n.begin()+it, nums[i]);
                cur.push_back(n);
            }
        }
        res.push_back(cur);
    }

    return res.back();
}

vector<vector<int> > DynamicProgrammingSolution::permuteUnique(vector<int> &nums) {
    if (nums.empty()) return {};
    vector<vector<vector<int>>> res;
    res.push_back({{nums[0]}});

    for (int i = 1; i < nums.size(); ++i)
    {
        vector<vector<int>> cur;
        for (const vector<int>& r : res.back())
        {
            for (int it = 0; it <= r.size(); ++it)
            {
                if (it >= 1 && nums[i] == r[it-1]) continue;
                auto n = r;
                n.insert(n.begin()+it, nums[i]);
                cur.push_back(n);
            }
        }
        res.push_back(cur);
    }

    return res.back();
}

int DynamicProgrammingSolution::nthUglyNumber(int n)
{
	if (n <= 1) return n;
	vector<int> res(n, INT_MAX);
	res[0] = 1;
	int p2 = 0, p3 = 0, p5 = 0;

	for (int i = 1; i < n; ++i)
	{
		res[i] = min(min(2 * res[p2], 3 * res[p3]), 5 * res[p5]);

		if (res[i] == 2 * res[p2]) ++p2;
		if (res[i] == 3 * res[p3]) ++p3;
		if (res[i] == 5 * res[p5]) ++p5;
	}

	return res.back();
}

int DynamicProgrammingSolution::nthUglyNumber(int n, bool useMinHeap)
{
	priority_queue<long, vector<long>, greater<long>> q;
	long ans = 1;

	for (int i = 1; i < n; ++i)
	{
		q.push(ans * 2);
		q.push(ans * 3);
		q.push(ans * 5);
		ans = q.top();
		q.pop();
		while (!q.empty() && q.top() == ans)
		{
			q.pop();
		}
	}

	return ans;
}

int DynamicProgrammingSolution::maximalSquare(vector<vector<char>> &matrix)
{
//	if ()
	return 0;
}

inline int permutation9(int n)
{
	if (n > 9) return 0;

	if (!n) return 1;

	int ans = 1;
	while (n--)
	{
		ans *= (10-n);
	}

	return ans;
}

int DynamicProgrammingSolution::countNumbersWithUniqueDigits(int n)
{
	vector<int> ans(n+1, 0);

	ans[0] = 1;

	for (int i = 1; i < n + 1; ++i)
	{
		ans[i] = ans[i-1] + 9 * permutation9(i-1);
	}

	return ans.back();
}

int DynamicProgrammingSolution::fib(int n)
{
	if (n <= 1)
		return n;
	vector<long> dp(n+1, 0);

	dp[0] = 0, dp[1] = 1;

	for (int i = 1; i <= n; ++i)
	{
		dp[i] = dp[i-1] % 1000000007 + dp[i-2] % 1000000007;
	}

	return dp.back() % 1000000007;
}

int DynamicProgrammingSolution::largest1BorderedSquare(vector<vector<int> > &grid)
{
	int largestLen = 0;

	vector<vector<vector<int>>> dp(
		grid.size(), vector<vector<int>>(grid.front().size(), vector<int>(2, 0)));

	dp[0][0] = grid[0][0] == 1 ? vector<int>{1, 1} : vector<int>{0, 0};

	for (int i = 1; i < grid.size(); ++i)
	{
		dp[i][0][0] = grid[i][0] == 1 ? 1 : 0;
		dp[i][0][1] = grid[i][0] == 1 ? dp[i-1][0][1] + 1: 0;
		largestLen = grid[i][0] > largestLen ? grid[i][0] : largestLen;
	}

	for (int i = 1; i < grid.front().size(); ++i)
	{
		dp[0][i][0] = grid[0][i] == 1 ? dp[0][i-1][0] + 1 : 0;
		dp[0][i][1] = grid[0][i] == 1 ? 1 : 0;
		largestLen = grid[i][0] > largestLen ? grid[0][i] : largestLen;
	}

	for (int i = 1; i < grid.size(); ++i)
	{
		for (int j = 1; j < grid.front().size(); ++j)
		{
			if (grid[i][j] == 1)
			{
				dp[i][j][0] = dp[i][j-1][0] + 1;
				dp[i][j][1] = dp[i-1][j][1] + 1;

				int depth = min(dp[i][j][0], dp[i][j][1]);

				while (depth)
				{
					if (dp[i-depth+1][j][0] >= depth && dp[i][j-depth+1][1] >= depth)
					{
						largestLen = depth > largestLen ? depth : largestLen;
					}

					depth--;
				}
			}
			else
				dp[i][j] = {0, 0};
		}
	}

	return largestLen * largestLen;
}

int DynamicProgrammingSolution::waysToChange(int n)
{
	vector<int> dp(n+1, 1);
	vector<int> coins = {1, 5, 10, 25};

	for (int i = 1; i < 4; ++i)
	{
		for (int j = coins[i]; j < n+1; ++j)
		{
			dp[j] = (dp[j] + dp[j-coins[i]]) % 1000000007;
		}
	}

	return dp.back();
}

bool DynamicProgrammingSolution::canIWin(int maxChoosableInteger, int desiredTotal)
{
	vector<int> dp(desiredTotal+1, 1);
//	shared_ptr<int> ps(new int(3));

	for (int j = maxChoosableInteger+1; j < desiredTotal+1; ++j)
	{
		int firstCanWin = 1;
		for (int i = 1; i <= maxChoosableInteger; ++i)
		{
			firstCanWin |= dp[j-i];
		}

		dp[j] = !firstCanWin;
	}

	return dp.back() == 1;
}

inline int* countZeroAndOnes(string s) {
	int c[2] = {0, 0};

	for (int I = 0; I < s.size(); ++I)
	{
		c[s[I]-'0']++;
	}
	return c;
}

int DynamicProgrammingSolution::findMaxForm(vector<string> &strs, int m, int n) {
	vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

	for (size_t k = 0; k < strs.size(); ++k)
	{
		int* counts = countZeroAndOnes(strs[k]);
		int numOfZeros = counts[0];
		int numOfOnes = counts[1];

		for (size_t i = m; i >= numOfZeros; --i)
		{
			for (size_t j = n; j >= numOfOnes; --j)
			{

				dp[i][j] = max(dp[i][j], 1+dp[i-numOfZeros][j-numOfOnes]);
			}
		}
	}

	return dp.back().back();
}

/**
 *
 * @param nums
 * @return
 */
int DynamicProgrammingSolution::jump(vector<int>& nums) {
/** DP
 * vector<int> dp(nums.size(), 0);
 *
 * for (int i = 1; i < nums.size(); ++i) {
 *     dp[i] = INT32_MAX;
 *
 *     for (int j = 0; j < i; ++j) {
 *         if (i - j <= nums[j]) {
 *             dp[i] = min(dp[i], dp[j] + 1);
 *         }
 *     }
 * }
 *
 * return dp.back();
 */
    int ans=0, end = 0, maxPos = 0;

    for (int i = 0; i < nums.size()-1; ++i) {
        maxPos = max(i + nums[i], maxPos);

        if (end == i) {
            end = maxPos;
            ans++;
        }
    }

    return ans;
}

/**
 *
 * @param numRows
 * @return
 */
vector<vector<int>> DynamicProgrammingSolution::generate(int numRows) {
    vector<vector<int>> dp;

    dp.push_back(vector<int> {1});

    for (int i = 1; i < numRows; ++i) {
        vector<int> cur(i+1, 1);

        for (int j = 1; j < i; ++j) {
            cur[j] = dp[i-1][j-1] + dp[i-1][j];
        }

        dp.push_back(cur);
    }

    return dp;
}

/**
 * test
 * @param costs
 * @return
 */
int DynamicProgrammingSolution::minCost(vector<vector<int>> &costs) {
    for (size_t i = 1; i < costs.size(); ++i) {
        costs[i][0] =min(costs[i-1][1]+costs[i][0], costs[i-1][2]+costs[i][0]);
        costs[i][1] = min(costs[i-1][0]+costs[i][1], costs[i-1][2]+costs[i][1]);
        costs[i][2] = min(costs[i-1][0]+costs[i][2], costs[i-1][1]+costs[i][2]);
    }

    return min(min(costs.back()[0], costs.back()[1]), costs.back()[2]);
}

inline static int doOp(int a, int b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
    }

    return -1;
}

/**
 *
 * @param expression
 * @return
 */
vector<int> DynamicProgrammingSolution::diffWaysToCompute(string expression) {
    return vector<int>(1, 0);
}

/**
 *
 * @param n
 * @param primes
 * @return
 */
int DynamicProgrammingSolution::nthSuperUglyNumber(int n, vector<int> &primes) {
    if (n == 1) return 1;

    // use long type here to resolve overflow
    vector<long> uglyNumbers(n, 1);
    vector<int> indexes(primes.size(), 0);

    for (int i = 1; i < n; ++i) {
        int min_num = INT32_MAX, min_index;

        for (int j = 0; j < indexes.size(); ++j) {
            if (primes[j] * uglyNumbers[indexes[j]] <= uglyNumbers[i-1])
                indexes[j] += 1;

            if (primes[j] * uglyNumbers[indexes[j]] < min_num)
            {
                min_num = primes[j] * uglyNumbers[indexes[j]];
                min_index = j;
            }
        }

        uglyNumbers[i] = primes[min_index] * uglyNumbers[indexes[min_index]];
        indexes[min_index] += 1;
    }

    return uglyNumbers.back();
}
