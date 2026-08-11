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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> arr;
        if(root==NULL){
            return arr;
        }

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            vector<int> level;
            for(int i=0;i<s;i++){
                TreeNode* node=q.front();

                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);

                q.pop();
                level.push_back(node->val);
            }
            arr.push_back(level);
        }

        for(int i=0;i<arr.size();i++){
            if(i%2!=0){
                reverse(arr[i].begin(),arr[i].end());
            }
        }

        return arr;
    }
};