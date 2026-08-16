class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> m;

        int l = 0;
        int r = 0;
        int maxi = 0;

        while (r < n) {
            if (m.find(s[r]) == m.end() || m[s[r]] == 0) {
                m[s[r]]++;
                r++;
            }
            else {
                maxi = max(maxi, r - l);

                while (s[l] != s[r]) {
                    m[s[l]]--;
                    l++;
                }
                m[s[l]]--;
                l++;
            }
        }

        return max(maxi, r - l);
    }
};