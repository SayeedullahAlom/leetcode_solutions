class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> m;
        int n=s.size();

        int l=0;
        int r=0;

        int maxi=0;

        while(r<n){
            m[s[r]]++;
            if(m[s[r]]<=2){
                r++;
            }
            else{
                maxi=max(maxi,r-l);
                while(s[l]!=s[r]){
                    m[s[l]]--;
                    l++;
                }
                m[s[l]]--;
                l++;
                r=r+1;
            }
        }

        return max(maxi,r-l);
        
    }
};