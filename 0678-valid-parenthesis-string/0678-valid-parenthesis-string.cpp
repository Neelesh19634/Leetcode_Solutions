class Solution {
public:
    bool checkValidString(string s) {
        int maxa=0;
        int mina=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                maxa++;
                mina++;
            }
            else if(s[i]==')'){
                mina--;
                maxa--;
            }else{
                mina--;
                maxa++;
            }

            if(mina<0) mina=0;
            if(maxa<0) return false;
        }

        return mina==0;
    }
};