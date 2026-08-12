class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> v(n);
        vector<int> ans(n);

        // Left -> Right
        for(int i = 0; i < n; i++) {

            if(i == 0) {
                v[i] = 1;
            }
            else if(ratings[i] > ratings[i-1]) {
                v[i] = v[i-1] + 1;
            }
            else {
                v[i] = 1;
            }
        }

        int prev = 0;

        // Right -> Left
        for(int i = n-1; i >= 0; i--) {

            if(i == n-1) {
                ans[i] = max(v[i], 1);
                prev = 1;
            }
            else if(ratings[i] > ratings[i+1]) {   
                ans[i] = max(v[i], prev + 1);
                prev += 1;
            }
            else if(ratings[i] < ratings[i+1]) {   
                ans[i] = max(v[i], 1);
                prev = 1;
            }
            else {
                ans[i] = max(v[i], 1);
                prev = ans[i];
            }
        }

        int sum = 0;

        for(int i = 0; i < n; i++) {
            sum += ans[i];
        }

        return sum;
    }
};