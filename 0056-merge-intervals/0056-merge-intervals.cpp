class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<vector<int>> ans;

        if (n == 0) return ans;

        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            return a[0] < b[0];
        });

        int l = intervals[0][0];
        int r = intervals[0][1];

        for (int i = 1; i < n; i++) {

            if (intervals[i][0] <= r) {
                r = max(r, intervals[i][1]);
            }
            else {
                ans.push_back({l, r});

                l = intervals[i][0];
                r = intervals[i][1];
            }
        }

        ans.push_back({l, r});

        return ans;
    }
};