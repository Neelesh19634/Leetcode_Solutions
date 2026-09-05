class Solution {
    vector<int> size, parent;

    int findp(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = findp(parent[i]);
    }
    void dsu(int i, int j) {
        int pi = findp(i);
        int pj = findp(j);
        if (pi == pj)
            return;
        if (size[pi] < size[pj]) {
            parent[pi] = pj;
            size[pj] += size[pi];
        } else {
            parent[pj] = pi;
            size[pi] += size[pj];
        }
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        parent.resize(n * m);
        size.resize(n * m, 1);
        for (int i = 0; i < n * m; i++) {
            parent[i] = i;
        }
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0)
                    continue;
                for (int k = 0; k < 4; k++) {
                    int nr = i + dx[k];
                    int nc = j + dy[k];

                    if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                        grid[nr][nc] == 1) {
                        int nn = i * n + j;
                        int ann = nr * n + nc;
                        dsu(nn, ann);
                    }
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {
               
                if (grid[i][j] == 1)
                    continue;
                     unordered_set<int> st;
                int res = 0;
                for (int k = 0; k < 4; k++) {
                    int nr = i + dx[k];
                    int nc = j + dy[k];
                    if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                        grid[nr][nc] == 1) {
                        st.insert(findp(nr * n + nc));
                    }
                }
                for (auto& it : st) {
                    res += size[it];
                }
                ans = max(ans, res + 1);
            }
        }

        for(int i=0;i<n;i++){
            ans=max(ans,size[findp(i)]);
        }

        return ans;
    }
};