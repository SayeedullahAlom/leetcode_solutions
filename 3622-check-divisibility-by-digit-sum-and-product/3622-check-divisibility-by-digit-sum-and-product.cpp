class Solution {
public:
    bool checkDivisibility(int n) {
        int k=n;
        int sum=0;
        int prod=1;
        while(k>0){
            int rem=k%10;
            sum+=rem;
            prod*=rem;
            k/=10;
        }

        return n%(sum+prod)==0;
    }
};