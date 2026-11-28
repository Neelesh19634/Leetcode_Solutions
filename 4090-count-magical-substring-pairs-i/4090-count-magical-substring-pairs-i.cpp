class Solution {
        vector<vector<int>> fpse(string s) {
            int n = s.size();
            vector<vector<int>> pse(n, vector<int>(27, 0));

            for (int i = 0; i < n; i++) {
                int freq[26] = {};
                int distinct = 0;

                for (int j = i; j >= 0; j--) {
                    if (freq[s[j] - 'a'] == 0)
                        distinct++;

                    freq[s[j] - 'a']++;

                    pse[i][distinct]++;
                }
            }

            return pse;
        }

        vector<vector<int>> fnse(string s) {
            int n = s.size();
            vector<vector<int>> nse(n, vector<int>(27, 0));

            for (int i = 0; i < n; i++) {
                int freq[26] = {};
                int distinct = 0;

                for (int j = i; j < n; j++) {
                    if (freq[s[j] - 'a'] == 0)
                        distinct++;

                    freq[s[j] - 'a']++;

                    nse[i][distinct]++;
                }
            }

            return nse;
        }

    public:
        int countMagicalPairs(string s) {
            int n = s.size();

            vector<vector<int>> pse = fpse(s);
            vector<vector<int>> nse = fnse(s);

            long long count = 0;

            for (int i = 0; i < n - 1; i++) {
                for (int d = 1; d <= 26; d++) {
                    count += 1LL * pse[i][d] * nse[i + 1][d];
                }
            }

            return count;
        }
    };