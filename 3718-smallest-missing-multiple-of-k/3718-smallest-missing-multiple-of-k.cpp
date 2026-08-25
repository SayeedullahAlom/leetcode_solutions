class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> m;

        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }

        int l;
        int i=1;

        while(i<=nums.size()+1){
            l=k*i;
            if(m.find(l)==m.end()){
                return l;
            }
            i++;
        }
        return l*i;
    }
};