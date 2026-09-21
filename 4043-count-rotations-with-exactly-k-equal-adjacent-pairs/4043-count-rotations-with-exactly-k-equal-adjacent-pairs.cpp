class Solution {
public:
    int countRotations(string s, int k) {
        int n=s.size();
        int count=0;
        if(n==0) return 0;

        for(int i=0;i<n;i++){
            count+=s[i]==s[(i+1)%n];
        }

        if(count-1==k) {
            return count;
        }else{
            if(k==count){
                return n-count;
            }else{
                return 0;
            }
        }
        return 0;
    }
};