class Solution {
    map<string,int> mp;
    string b;
    vector<vector<string>> ans;
    private:
    void dfs(string word,vector<string> &seq){
        if(word==b){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }

        int steps=mp[word];
        for(int i=0;i<word.size();i++){
            char original=word[i];
            for(char j='a';j<='z';j++){
                word[i]=j;
                if(mp.find(word)!=mp.end() && mp[word]+1==steps){
                    seq.push_back(word);
                    dfs(word,seq);
                    seq.pop_back();
                }
            }

            word[i]=original;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& s) {
        
        queue<string> q;
        unordered_set<string> st(s.begin(),s.end());

        mp[beginWord]=1;
        st.erase(beginWord);
        q.push(beginWord);
        b=beginWord;

        while(!q.empty()){
            auto word=q.front();
            int steps=mp[word];
            q.pop();
            if(word==endWord) break;

            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char j='a';j<='z';j++){
                    word[i]=j;
                    if(st.find(word)!=st.end()){
                        q.push(word);
                        st.erase(word);
                        mp[word]=steps+1;
                    }
                }
                word[i]=original;
            }
        }

        if(mp.find(endWord)!=mp.end()){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord,seq);
            
        }

        return ans;
    }
};