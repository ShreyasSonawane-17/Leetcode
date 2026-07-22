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
    void inorder(TreeNode* root, vector<int>& v) {
        if (root == nullptr)
            return;

        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> one;
        vector<int> two;

        inorder(root1 , one);
        inorder(root2 , two);

        vector<int> ans;
        for(int i = 0; i< one.size(); i++){
            ans.push_back(one[i]);
        }
        for(int i = 0; i< two.size(); i++){
            ans.push_back(two[i]);
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};