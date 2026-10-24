class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int n=v.size();
        int maxa=0;
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=v[i];
        }

        maxa=sum;
        int r=n-1;
        for(int i=k-1;i>=0;i--){
            sum-=v[i];
            sum+=v[r];
            r--;
            maxa=max(maxa,sum);
        }
        return maxa;
    }
};