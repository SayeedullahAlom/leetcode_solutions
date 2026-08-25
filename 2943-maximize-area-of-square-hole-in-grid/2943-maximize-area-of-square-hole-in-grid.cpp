class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());

        int h=n+2;
        int w=m+2;

        int maxh=0;
        int counth=0;
        for(int i=0;i<hBars.size();i++){
            if(i==0){
                counth++;
            }
            else if(hBars[i]==hBars[i-1]+1){
                counth++;
            }
            else{
                counth=1;
            }
            maxh=max(counth,maxh);
        }

        int maxv=0;
        int countv=0;
        for(int i=0;i<vBars.size();i++){
            if(i==0){
                countv++;
            }
            else if(vBars[i]==vBars[i-1]+1){
                countv++;
            }
            else{
                countv=1;
            }
            maxv=max(countv,maxv);
        }
        
        return (min(maxh,maxv)+1) * (min(maxh,maxv)+1);
    }
};