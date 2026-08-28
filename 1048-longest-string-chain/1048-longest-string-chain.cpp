class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<int> v(n,1);

        sort(words.begin(),words.end(), [](string &a, string &b){
            return a.size()<b.size();
        });

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(words[i].size()==words[j].size()+1){
                    int c=1;
                    int l=0;
                    int r=0;
                    while(l<words[j].size() and r<words[i].size()){
                        if(words[j][l]!=words[i][r]){
                            r++;
                            c--;
                        }
                        else{
                            l++;
                            r++;
                        }
                    }
                    if(c>=0 and v[j]+1>v[i]){
                        v[i]=v[j]+1;
                    }

                }
            }
        }
        
        int prev=0;
        for(int i=1;i<n;i++){
            if(v[i]>v[prev]){
                prev=i;
            }
        }

        return v[prev];
        
    }
};