class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& s) {
        queue<pair<string,int>> q;
        unordered_set<string> st;
        st.insert(s.begin(),s.end());

        q.push({beginWord,1});
        st.erase(beginWord);

        while(!q.empty()){
            auto word=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(word==endWord) return steps;

            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char j='a';j<='z';j++){
                    word[i]=j;

                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i]=original;

            }

            
            
            
        }
        return 0;

    }
};