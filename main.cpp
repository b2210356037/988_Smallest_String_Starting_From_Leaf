#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    string dfs(TreeNode* root, string path, string& res) {
        if (!root) return "";
        path = char('a' + root->val) + path;
        if (!root->left && !root->right) {
            if (res == "") res = path;
            else res = min(res, path);
        }
        dfs(root->left, path, res);
        dfs(root->right, path, res);
        return path;
    }

    string smallestFromLeaf(TreeNode* root) {
        //solution with dfs
        string res = "";
        dfs(root, "", res);
        return res;

    }
};

TreeNode* insertLevelOrder(vector<int>& arr, TreeNode* root, int i, int n) {
    // Base case for recursion
    if (i < n) {
        TreeNode* temp = new TreeNode(arr[i]);
        root = temp;

        // insert left child
        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);

        // insert right child
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

int main() {
    Solution s;
    vector<int> arr = {0,1,2,3,4,3,4};
    TreeNode* root = insertLevelOrder(arr, root, 0, arr.size());
    cout << s.smallestFromLeaf(root) << endl;
    return 0;
}

