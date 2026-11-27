class Solution {
public:
    int minRange(int a, int b, int c) {
        int ans=INT_MAX;
        int mina=min({a,b,c});
        int maxa=max({a,b,c});
        ans=min(ans,maxa-mina);

        mina=min({b+c,b,c});
        maxa=max({b+c,b,c});
        ans=min(ans,maxa-mina);

        mina=min({a,c+a,c});
        maxa=max({a,c+a,c});
        ans=min(ans,maxa-mina);

        mina=min({a,b,b+a});
        maxa=max({a,b,b+a});
        ans=min(ans,maxa-mina);


        return ans;
        
    }
};