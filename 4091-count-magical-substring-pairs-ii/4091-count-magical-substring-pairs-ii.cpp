class Solution {
    vector<vector<long long>> fpse(string s) {
        int n = s.size();
        vector<vector<long long>> pse(n, vector<long long>(27, 0));

        // atMostEnd[i][d] = number of substrings ending at i
        // having at most d distinct characters
        vector<vector<long long>> atMostEnd(n, vector<long long>(27, 0));

        for (int d = 1; d <= 26; d++) {
            int l = 0;
            int freq[26] = {};
            int distinct = 0;

            for (int r = 0; r < n; r++) {
                if (freq[s[r] - 'a']++ == 0)
                    distinct++;

                while (distinct > d) {
                    if (--freq[s[l] - 'a'] == 0)
                        distinct--;
                    l++;
                }

                atMostEnd[r][d] = r - l + 1;
            }
        }

        // Convert at-most counts to exact counts
        for (int i = 0; i < n; i++) {
            for (int d = 1; d <= 26; d++) {
                pse[i][d] = atMostEnd[i][d] - atMostEnd[i][d - 1];
            }
        }

        return pse;
    }

    vector<vector<long long>> fnse(string s) {
        int n = s.size();
        vector<vector<long long>> nse(n, vector<long long>(27, 0));

        // atMostStart[i][d] = number of substrings starting at i
        // having at most d distinct characters
        vector<vector<long long>> atMostStart(n, vector<long long>(27, 0));

        for (int d = 1; d <= 26; d++) {
            int r = n - 1;
            int freq[26] = {};
            int distinct = 0;

            for (int l = n - 1; l >= 0; l--) {
                if (freq[s[l] - 'a']++ == 0)
                    distinct++;

                while (distinct > d) {
                    if (--freq[s[r] - 'a'] == 0)
                        distinct--;
                    r--;
                }

                atMostStart[l][d] = r - l + 1;
            }
        }

        // Convert at-most counts to exact counts
        for (int i = 0; i < n; i++) {
            for (int d = 1; d <= 26; d++) {
                nse[i][d] = atMostStart[i][d] - atMostStart[i][d - 1];
            }
        }

        return nse;
    }

public:
    long long countMagicalPairs(string s) {
        int n = s.size();

        vector<vector<long long>> pse = fpse(s);
        vector<vector<long long>> nse = fnse(s);

        long long count = 0;

        // Every split: left ends at i, right starts at i + 1
        for (int i = 0; i < n - 1; i++) {
            for (int d = 1; d <= 26; d++) {
                count += pse[i][d] * nse[i + 1][d];
            }
        }

        return count;
    }
};