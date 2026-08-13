class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        string ans = "";

        if (numRows == 1)
            return s;

        for (int i = 0; i < numRows; i++) {
            int j = i;

            while (j < n) {

                ans += s[j];

                if (i != 0 && i != numRows - 1) {
                    int diagonal = j + 2 * numRows - 2 - 2 * i;

                    if (diagonal < n)
                        ans += s[diagonal];
                }

                j += 2 * numRows - 2;
            }
        }

        return ans;
    }
};