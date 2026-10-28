
class Solution {
    long long solve(vector<int>& arr, int k) {
        long long ans = 0;

        for (int i = 0; i < arr.size(); i++) {
            ans += (arr[i] + (long long)k - 1) / k;
        }

        return ans;
    }

public:
    int minEatingSpeed(vector<int>& arr, int h) {
        int maxa = 0;

        for (int it : arr) {
            maxa = max(maxa, it);
        }

        int s = 1;
        int e = maxa;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            long long ans = solve(arr, mid);

            if (ans <= h) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return s;
    }
};
