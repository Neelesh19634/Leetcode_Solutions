class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        
        
        if (s[0] == '0') {
            return 0;
        }
        
        vector<int> dp(n + 1, 0);
        
        // Base cases
        dp[0] = 1; 
        dp[1] = 1; 
        
        for (int i = 2; i <= n; i++) {
            // Choice 1: Decode as a single digit (must be 1-9)
            int digit = s[i - 1] - '0';
            if (digit != 0) {
                dp[i] += dp[i - 1];
            }
            
            // Choice 2: Decode as a two-digit block (must be 10-26)
            int twoDigits = stoi(s.substr(i - 2, 2));
            if (twoDigits >= 10 && twoDigits <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        
        return dp[n];
    }
};