class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int m) {
        int n=hand.size();
        if(n%m) return false;
        map<int,int> mp;
        for(auto &it:hand){
            mp[it]++;
        }

        while(!mp.empty()){
            int c=mp.begin()->first;
            for(int i=0;i<m;i++){
                if(mp[c+i]==0) return false;
                mp[c+i]--;
                if(mp[c+i]<1) mp.erase(c+i);
            }
        }

        return true;
    }

};