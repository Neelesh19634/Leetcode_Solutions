class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mina=INT_MAX;
        int maxa=0;
        for(int i=0;i<n;i++){
            if(prices[i]<mina){
                mina=prices[i];
            }else{
                maxa=max(maxa,prices[i]-mina);
            }
        }

        return maxa;
    }
};