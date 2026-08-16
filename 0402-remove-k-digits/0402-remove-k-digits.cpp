class Solution {
    private:
    string nse(int n,string s,int k){
         stack<char> st;
         string res="";
        for(int i=0;i<n;i++){
            char num=s[i];
            while(!st.empty() && st.top()>num && k>0) {
                st.pop();
                k--;
            }
            st.push(num);
        }

        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }

        while(res.size()>0 && res.back()=='0'){
            res.pop_back();
        }
        reverse(res.begin(),res.end());
        if(res.empty()) return "0";
        return res;
        
    }
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
       
        if(k==n) return "0";
         string res=nse(n,num,k);

       

      
        return res;

    }
};