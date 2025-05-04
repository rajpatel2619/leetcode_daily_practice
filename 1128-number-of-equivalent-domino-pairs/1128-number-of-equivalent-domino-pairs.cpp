class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size();
        unordered_map<int, vector<int>> mp;
        int c = 0;
        for(int i=0;i<n;i++){
            vector<int> a = dominoes[i];
            sort(a.begin(), a.end());
            if(mp.find(a[0])!=mp.end()){
                if(mp[a[0]][0]==a[1]){
                    c+=mp[a[0]][1];
                    mp[a[0]][1]++;
                }
                continue;
            }
            mp[a[0]]={a[1],1};
        }
        return c;
    }
};