class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        unordered_map<char,string> m1;
        unordered_map<string,char> m2;
        

        int l=0;
        int r=0;
        while(r<s.size()){
            if(s[r]!=' '){
                r++;
            }
            else{
                string word="";
                while(l<r){
                    word+=s[l];
                    l++;
                }
                r++;
                l=r;
                v.push_back(word);
            }
        }

        string word="";
        while(l<r){
            word+=s[l];
            l++;
        }

        v.push_back(word);

        

        if(pattern.size()!=v.size()) return false;

        for(int i=0;i<pattern.size();i++){
            if(m1.find(pattern[i])==m1.end()){
                m1[pattern[i]]=v[i];
            }
            else{
                if(m1[pattern[i]]!=v[i]) return false;
            }
        }

        for(int i=0;i<v.size();i++){
            if(m2.find(v[i])==m2.end()){
                m2[v[i]]=pattern[i];
            }
            else{
                if(m2[v[i]]!=pattern[i]) return false;
            }
        }

        return true;

    }
};