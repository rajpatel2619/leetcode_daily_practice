class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            vector<int> temp(graph[i].begin(), graph[i].end());
            adj[i] = temp;
        }

        vector<int> res;
        for(int i=0;i<n;i++){
            if(adj[i].empty()){
                res.push_back(i);
            }else{
                bool ok = true;
                for(auto e:adj[i]){
                    if(!adj[e].empty()){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    res.push_back(i);
                }
            }
        }
        return res;
    }
};