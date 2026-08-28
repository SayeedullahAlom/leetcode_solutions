class Solution {
public:
    bool f(int i, string &s, unordered_map<string, int> &m,
           vector<int> &dp) {

        if(i == s.size())
            return true;

        if(dp[i] != -1)
            return dp[i];

        string str = "";

        for(int j = i; j < s.size(); j++) {

            str += s[j];

            if(m.find(str) != m.end()) {

                if(f(j + 1, s, m, dp))
                    return dp[i] = true;
            }
        }

        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_map<string, int> m;

        for(string word : wordDict)
            m[word]++;

        vector<int> dp(s.size(), -1);

        return f(0, s, m, dp);
    }
};