class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas=0;
        int total_cost=0;

        for(int i=0;i<gas.size();i++){
            total_gas+=gas[i];
            total_cost+=cost[i];
        }

        if(total_cost>total_gas) return -1;

        int idx=0;
        int curr_gas=0;

        for(int i=0;i<gas.size();i++){
            if(curr_gas+gas[i]>=cost[i]){
                curr_gas=curr_gas+gas[i]-cost[i];
            }
            else{
                idx=i+1;
                curr_gas=0;
            }
        }

        return idx;
    }
};