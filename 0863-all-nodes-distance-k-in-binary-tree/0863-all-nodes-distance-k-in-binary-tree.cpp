/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent_track){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
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

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent_track;
        parent(root,parent_track);

        unordered_map<TreeNode*,bool> vis;

        queue<TreeNode*> q;

        q.push(target);
        vis[target] = true;

        int dist=0;

        while(!q.empty()){
            int size=q.size();
            if(dist==k) break;
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

        vector<int> result;

        while(!q.empty()){
            TreeNode* v=q.front();
            result.push_back(v->val);
            q.pop();
        }

        return result;
    }
};