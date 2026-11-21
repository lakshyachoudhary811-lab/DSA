class Solution {
public:
    bool isMatch(string s, string p) {
        int strLen = s.length();
                int patLen = p.length();
                vector<vector<bool>> dp(strLen + 1, vector<bool>(patLen + 1, false));
                dp[0][0] = true;
                for (int pIdx = 1; pIdx <= patLen; ++pIdx) {
                    if (p[pIdx - 1] == '*') {
                        dp[0][pIdx] = dp[0][pIdx - 2];
                    }
                }
                for (int sIdx = 1; sIdx <= strLen; ++sIdx) {
                    for (int pIdx = 1; pIdx <= patLen; ++pIdx) {
                        if (p[pIdx - 1] == '.' || p[pIdx - 1] == s[sIdx - 1]) {
                            dp[sIdx][pIdx] = dp[sIdx - 1][pIdx - 1];
                        } else if (p[pIdx - 1] == '*') {
                            dp[sIdx][pIdx] = dp[sIdx][pIdx - 2];
                            if (p[pIdx - 2] == '.' || p[pIdx - 2] == s[sIdx - 1]) {
                                dp[sIdx][pIdx] = dp[sIdx][pIdx] || dp[sIdx - 1][pIdx];
                            }
                        }
                    }
                }
                return dp[strLen][patLen];
                            }
};