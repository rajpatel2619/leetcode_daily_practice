class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> mp;
        vector<int> indg(n,0);
        for(auto e:pre){
            mp[e[0]].push_back(e[1]);
            indg[e[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
            if(!indg[i])
                q.push(i);

        unordered_map<int, unordered_set<int>> qmp;
        while(!q.empty()){
            int s = q.size();
            for(int j=0;j<s;j++){
                auto node = q.front();
                q.pop();
                for(auto nb:mp[node]){
                    qmp[nb].insert(node);
                    for (auto prereq : qmp[node]) {
                    qmp[nb].insert(prereq);
                }
                    indg[nb]--;
                    if(indg[nb]==0){
                        q.push(nb);
                    }
                }
            }
        }
        vector<bool> ans;
        for(auto q:queries){
            if(qmp[q[1]].contains(q[0]))
                ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};