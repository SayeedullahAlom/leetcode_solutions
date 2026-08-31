class Solution {
public:
    bool checkValidString(string s) {
        vector<pair<char,int>> v;
        vector<int> star;
        
        for(int i=0;i<s.size();i++){
            int size=v.size();
            if(s[i]=='*'){
                star.push_back(i);
            }
            else if(s[i]==')' && !v.empty() && v.back().first=='('){
                v.pop_back();
            }
            else{
                v.push_back({s[i],i});
            }
        }

        for(int i=0;i<v.size();i++){
            if(v[i].first==')'){
                for(int j=0;j<star.size();j++){
                    if(star[j]<v[i].second){
                        v[i].first='a';
                        star[j]=1e9;
                        
                        break;
                    }   
                }
            }
            if(v[i].first=='('){
                for(int j=0;j<star.size();j++){
                    if(star[j]>v[i].second && star[j]!=1e9){
                        star[j]=1e9;
                        v[i].first='a';
                        break;
                    }   
                }
            }
        }

        for(int i=0;i<v.size();i++){
            if(v[i].first!='a')  return false;
        }

        return true;
    }
};