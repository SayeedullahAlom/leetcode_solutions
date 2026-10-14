class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > 9 * num) return "";
        string ans="";

        int q=sum/9;
        int r=sum%9;

        for(int i=0;i<q;i++){
            ans+='9';
        }
        
        if(r>0){
            ans+=to_string(r);
        }

        while(ans.size()<num){
            ans+='0';
        }

        return ans;
    }
};