class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();

        vector<vector<int>> ans;

        priority_queue<pair<int,pair<int,int>>,
                        vector<pair<int,pair<int,int>>>,
                        greater<pair<int,pair<int,int>>>> pq;

        for(int i=0;i<n;i++){
            int x=points[i][0]*points[i][0];
            int y=points[i][1]*points[i][1];

            int dis=x+y;

            pq.push({dis,{points[i][0],points[i][1]}});
        }

        for(int i=0;i<k;i++){
            ans.push_back({pq.top().second.first,pq.top().second.second});

            pq.pop();
        }

        return ans;
    }
};