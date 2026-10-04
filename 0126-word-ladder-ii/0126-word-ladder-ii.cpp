class Solution {
    vector<vector<string>> ans;
    unordered_map<string,int> mp;
    string b;

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

                if(mp.find(word)!=mp.end() && steps==mp[word]+1){
                    seq.push_back(word);
                    dfs(word,seq);
                    seq.pop_back();
                }
            }

            word[i]=original;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st(wordList.begin(),wordList.end());
        queue<string> q;
        mp[beginWord]=1;
        q.push(beginWord);
        b=beginWord;
        st.erase(beginWord);

        while(!q.empty()){
            string word=q.front();
            q.pop();
            int steps=mp[word];
            if(word==endWord) break;
            for(int i=0;i<word.size();i++){
                char original=word[i];
                
                for(char j='a';j<='z';j++){
                    word[i]=j;

                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push(word);
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