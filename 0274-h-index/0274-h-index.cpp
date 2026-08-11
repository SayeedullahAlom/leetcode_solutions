class Solution {
public:
    int hIndex(vector<int>& citations) {

        sort(citations.begin(),citations.end());

        int n=citations.size();

        if(citations[0]>=n){
            return n;
        }

        int maxi=0;

        for(int i=0;i<n;i++){
            if(citations[i]<=n-i){
                maxi=max(maxi,citations[i]);
            }
            else if(citations[i]>n-i){
                maxi=max(maxi,n-i);
            }
        }

        return maxi;
    }
};