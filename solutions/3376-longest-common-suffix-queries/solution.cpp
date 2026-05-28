class Solution {
public:

    vector<array<int,26>> trie;
    vector<int> bestIdx;

    vector<string>* words;

    bool better(int a, int b) {

        if(a == -1)
            return true;

        if((*words)[b].size() < (*words)[a].size())
            return true;

        if((*words)[b].size() == (*words)[a].size()
           && b < a)
            return true;

        return false;
    }

    Solution() {

        trie.push_back({});
        for(int i=0;i<26;i++)
            trie[0][i] = -1;

        bestIdx.push_back(-1);
    }

    void insert(string &s, int idx) {

        int node = 0;

        if(better(bestIdx[node], idx))
            bestIdx[node] = idx;

        for(int i=s.size()-1;i>=0;i--) {

            int c = s[i] - 'a';

            if(trie[node][c] == -1) {

                trie[node][c] = trie.size();

                trie.push_back({});
                for(int j=0;j<26;j++)
                    trie.back()[j] = -1;

                bestIdx.push_back(-1);
            }

            node = trie[node][c];

            if(better(bestIdx[node], idx))
                bestIdx[node] = idx;
        }
    }

    int query(string &s) {

        int node = 0;

        for(int i=s.size()-1;i>=0;i--) {

            int c = s[i] - 'a';

            if(trie[node][c] == -1)
                break;

            node = trie[node][c];
        }

        return bestIdx[node];
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        words = &wordsContainer;

        for(int i=0;i<wordsContainer.size();i++) {
            insert(wordsContainer[i], i);
        }

        vector<int> ans;

        for(string &q : wordsQuery) {
            ans.push_back(query(q));
        }

        return ans;
    }
};
