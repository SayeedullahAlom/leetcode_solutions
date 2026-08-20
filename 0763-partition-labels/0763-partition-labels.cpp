class Solution {
public:
    vector<int> partitionLabels(string s) {

        vector<int> ans;

        unordered_map<char, int> m;

        for(int i = 0; i < s.size(); i++){ // store the last appreance of the characters
            m[s[i]] = i;
        }

        int l = 0;
        int r = 0;
        int last_app = -1;

        while(r < s.size()){

            last_app = max(last_app, m[s[r]]);

            if(r == last_app){
                ans.push_back(r - l + 1);

                l = r + 1;
            }

            r++;
        }

        return ans;
    }
};