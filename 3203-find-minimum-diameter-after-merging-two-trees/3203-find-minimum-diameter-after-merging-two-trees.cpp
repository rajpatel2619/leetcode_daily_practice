class Solution {
public:
    int dia(int node, vector<vector<int>> &adj, int par = -1){
        int dm = 0;
        for(auto &nb:adj[node]){
            if(nb==par) continue;
            dm = max(dm, 1+ dia(nb, adj, node));
        }
        return dm;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        // for tree 1
        vector<vector<int>> adj1(edges1.size()+1);
        for(auto e:edges1){
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }

        int maxi1 = 0, mini1 = INT_MAX;
        for(int i=0;i<adj1.size();i++){
            int el = dia(i, adj1);
            maxi1 = max(el,maxi1);
            mini1 = min(mini1, el);
        }

        // for tree 2
        vector<vector<int>> adj2(edges2.size()+1);
        for(auto e:edges2){
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }
        
        int maxi2 = 0, mini2 = INT_MAX;
        for(int i=0;i<adj2.size();i++){
            int el = dia(i, adj2);
            maxi2 = max(el,maxi2);
            mini2 = min(mini2, el);
        }

        return max(maxi1, max(maxi2, mini1+mini2+1));
    }
};