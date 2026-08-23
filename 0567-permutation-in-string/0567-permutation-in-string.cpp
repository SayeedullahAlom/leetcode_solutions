class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;

        if(s2.size()<s1.size()) return false;

        for(int i=0;i<s1.size();i++){
            m1[s1[i]]++;
        }

        int l=0;
        int r=l+s1.size()-1;

        for(int i=0;i<s1.size()-1;i++){
            m2[s2[i]]++;
        }

        while(r<s2.size()){

            m2[s2[r]]++;

            if(m1==m2) return true;

            m2[s2[l]]--;
            if(m2[s2[l]]==0){
                m2.erase(s2[l]);
            }

            l++;
            r++;
        }

        return false;

    }
};