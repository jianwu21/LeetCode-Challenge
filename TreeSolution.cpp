//
// Created by Jian Wu on 22/02/2020.
//

#include "TreeSolution.h"
#include <stack>


inline TreeNode* CreateBT(vector<int>& _vec)
{
    // TODO: Implement
    return nullptr;
};

int TreeSolution::rangeSumBST(TreeNode *root, int L, int R) {
    if (!root) return 0;
    return (
        (root->val <= R && root->val >= L) ? root->val : 0) +
        rangeSumBST(root->left, L, R) +
        rangeSumBST(root->right, L, R);
}

bool TreeSolution::isValidBST(TreeNode *root)
{
	if (!root) return true;

	if (isValidBST(root->left))
	{
		if (!s.empty() && root->val <= s.top())
			return false;
		s.push(root->val);

		return isValidBST(root->right);
	}

	return false;
}