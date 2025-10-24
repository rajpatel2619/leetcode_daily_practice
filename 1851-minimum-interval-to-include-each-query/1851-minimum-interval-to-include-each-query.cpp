class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& its, vector<int>& queries) {
        vector<pair<int,int>> q;
        for(int i=0;i<queries.size();i++){
            q.push_back({queries[i], i});
        }
        sort(q.begin(), q.end());
        sort(its.begin(), its.end());
        int qs = q.size();
        vector<int> res(qs,-1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int i=0, itsn = its.size();
        for(auto node:q){
            while(i<itsn and its[i][0]<=node.first){
                pq.push({its[i][1]-its[i][0]+1, its[i][1]});
                i++;
            }
            while(!pq.empty() and pq.top().second<node.first) pq.pop();
            if(pq.empty()){
                res[node.second] = -1;
            }else{
                res[node.second] = pq.top().first;
            }
        }
        return res;
    }
};