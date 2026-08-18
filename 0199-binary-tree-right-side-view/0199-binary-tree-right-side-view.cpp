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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        map<int,int> m;

        if(root==NULL){
            return ans;
        }

        queue<pair<TreeNode*,int>> q;

        q.push({root,0});

        while(!q.empty()){
            TreeNode* node=q.front().first;
            int level=q.front().second;

            q.pop();

            m[level]=node->val;

            if(node->left!=NULL){
                q.push({node->left,level+1});
            }

            if(node->right!=NULL){
                q.push({node->right,level+1});
            }

        }

        for(auto it:m){
            ans.push_back(it.second);
        }

        return ans;

    }
};