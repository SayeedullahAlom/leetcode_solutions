class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();

        if(m==0) return false;

        int l=0; 
        int r=m*n-1;

        while(l<=r){
            int mid=l+(r-l)/2;
            int mid_val=matrix[mid/n][mid%n];
            if(mid_val==target){
                return true;
            }
            else if(mid_val>target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        return false;
    }
};