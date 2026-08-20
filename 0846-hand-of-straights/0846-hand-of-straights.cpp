class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n=hand.size();

        sort(hand.begin(),hand.end());

        if(n%groupSize!=0 || groupSize>n) return false;

        unordered_map<int,int> m;

        for(int i=0;i<n;i++){
            m[hand[i]]++;
        }

        for(int i=0;i<n;i++){

            if(m[hand[i]]>0){

                int j=1;

                while(j<groupSize){
                    if(m.find(hand[i]+j)!=m.end()){
                        j++;
                    }
                    else{
                        break;
                    }
                }

                if(j==groupSize){

                    for(int j = 0; j < groupSize; j++){
                        m[hand[i] + j]--;
                    }

                }
                
            }
        }

        for(auto it:m){
            if(it.second!=0) return false;
        }

        return true;

    }
};