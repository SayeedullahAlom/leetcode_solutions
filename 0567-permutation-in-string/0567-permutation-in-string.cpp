class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> m1;

        if(s2.size()<s1.size()) return false;

        for(int i=0;i<s1.size();i++){
            m1[s1[i]]++;
        }

        int l=0;
        int r=l+s1.size()-1;

        while(r<s2.size()){
            unordered_map<char,int> m2;

            for(int i=l;i<=r;i++){
                m2[s2[i]]++;
            }

            if(m1==m2) return true;

            l++;
            r++;
        }

        return false;

    }
};