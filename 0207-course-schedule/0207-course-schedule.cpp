class Solution {
public:
    vector<int> kanhsAlgo(int n, vector<vector<int>>&adj){
        vector<int> indegree(n,0);
        for(int u=0;u<n;u++){
            for(int v:adj[u]){
                indegree[v]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(int v:adj[node]){
                indegree[v]--;
                if(indegree[v]==0)
                    q.push(v);
            }
        }
        return topo;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto el:prerequisites){
            adj[el[1]].push_back(el[0]);
        }
        vector<int> topo = kanhsAlgo(numCourses, adj);
        if(topo.size()<numCourses)
            return false;
        return true;
    }
};