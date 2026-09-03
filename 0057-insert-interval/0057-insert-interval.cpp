class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;

        if(intervals.empty()){
            return {newInterval};
        }

        int i = 0;

        while(i < intervals.size()){

            // newInterval comes before current interval
            if(newInterval[1] < intervals[i][0]){
                intervals.insert(intervals.begin() + i, newInterval);
                break;
            }

            // newInterval is completely inside current interval
            else if(newInterval[0] >= intervals[i][0] &&
                    newInterval[1] <= intervals[i][1]){
                break;
            }

            // overlap: newInterval starts before current interval
            else if(newInterval[0] < intervals[i][0] &&
                    newInterval[1] >= intervals[i][0]){
                intervals[i][0] = newInterval[0];
                intervals[i][1] = max(intervals[i][1], newInterval[1]);
                break;
            }

            // overlap: newInterval starts inside current interval
            else if(newInterval[0] >= intervals[i][0] &&
                    newInterval[0] <= intervals[i][1]){
                intervals[i][1] = max(intervals[i][1], newInterval[1]);
                break;
            }

            i++;
        }

        // newInterval comes after all intervals
        if(i == intervals.size()){
            intervals.push_back(newInterval);
        }

        ans.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++){
            int s = ans.size() - 1;

            if(ans[s][1] >= intervals[i][0]){
                ans[s][1] = max(ans[s][1], intervals[i][1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};