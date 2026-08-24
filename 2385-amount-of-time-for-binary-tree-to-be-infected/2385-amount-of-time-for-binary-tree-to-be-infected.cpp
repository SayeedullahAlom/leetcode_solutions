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
    void parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent_track,int start,TreeNode* &target){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            if(curr->val==start){
                target=curr;
            }
            q.pop();
            if(curr->left!=NULL){
                parent_track[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                parent_track[curr->right]=curr;
                q.push(curr->right);
            }
        }
        return ;
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> parent_track;
        TreeNode* target=NULL;
        parent(root,parent_track,start,target);

        unordered_map<TreeNode*,bool> vis;

        queue<TreeNode*> q;

        q.push(target);
        vis[target] = true;

        int dist=0;

        while(!q.empty()){
            int size=q.size();
            dist++;
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left!=NULL && !vis[curr->left]){
                    vis[curr->left]=true;
                    q.push(curr->left);
                }
                if(curr->right!=NULL && !vis[curr->right]){
                    vis[curr->right]=true;
                    q.push(curr->right);
                }
                if(parent_track.find(curr)!=parent_track.end() && !vis[parent_track[curr]]){
                    vis[parent_track[curr]]=true;
                    q.push(parent_track[curr]);
                }
            }
        }

        return dist-1;       
    }
};