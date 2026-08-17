class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        if(nums.size()==0) return 0;

        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }

        int maxi=INT_MIN;

        for(auto it:s){
            int count=1;
            if(s.find(it-1)==s.end()){
                int k=it;
                while(s.find(k+1)!=s.end()){
                    count++;
                    k++;
                }
            }

            maxi=max(maxi,count);

        }

        return maxi;
    }
};