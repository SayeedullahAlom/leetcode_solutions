class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string ans="";

        string temp="";

        for(int i=n-1;i>=0;i--){
            if(s[i]!=' '){
                temp+=s[i];
            }
            else {
                if(temp!=""){
                    reverse(temp.begin(),temp.end());
                    if(ans!=""){
                        ans+=" ";
                    }
                    ans+=temp;
                    temp="";
                }
            }

        }

        if(temp!=""){
            reverse(temp.begin(),temp.end());

            if(ans!=""){
                ans+=" ";
            }

            ans+=temp;
        }

        return ans;
    }
};