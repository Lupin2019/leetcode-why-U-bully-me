#include <bits/stdc++.h>
// #include <fmt>
using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int S = 0;
    TreeNode* bstToGst(TreeNode* root) {
        if(root != nullptr) {
            bstToGst(root->right);
            S += root->val;
            root->val = S;
            bstToGst(root->left);
        }    
    }
};


int main(int arvc, char** argv){
    Solution S;
    return 0;
}
