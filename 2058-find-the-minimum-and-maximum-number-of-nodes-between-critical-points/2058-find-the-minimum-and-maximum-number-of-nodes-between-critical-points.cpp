/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head==NULL){
            return {-1,-1};
        }

        vector<int> v;

        ListNode* temp=head;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp=temp->next;
        }

        int n=v.size();
        vector<int> pos;
        for(int i=1;i<n-1;i++){
            if(v[i]>v[i-1] && v[i]>v[i+1]){
                pos.push_back(i);
            }
            else if(v[i]<v[i-1] && v[i]<v[i+1]){
                pos.push_back(i);
            }
        }
        if(pos.size()<2) return {-1,-1};

        int mini=INT_MAX;
        for(int i=1;i<pos.size();i++){
            mini=min(mini,pos[i]-pos[i-1]);
        }

        return {mini,pos.back()-pos[0]};
    }
};