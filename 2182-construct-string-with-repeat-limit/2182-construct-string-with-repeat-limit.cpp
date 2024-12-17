class Solution {
public:
    string repeatLimitedString(string s, int rl) {
        vector<int> f(26,0);
        for(auto &c:s)
            f[c-'a']++;
        
        priority_queue<pair<char,int>> pq;
        for(int i=0;i<26;i++){
            if(f[i]==0) continue;
            pq.push({i+'a', f[i]});}
        
        // while(!pq.empty()){
        //     auto [f,s] = pq.top();
        //     pq.pop();
        //     cout<<f<<" "<<s<<endl;
        // }
        string r = "";
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            if(r.size() && x.first==r[r.size()-1]) return r;
            if(x.second<=rl){
                for(int i=0;i<x.second;i++)
                    r+=x.first;
                continue;
            }else{
                for(int i=0;i<rl;i++){
                    r+=x.first;
                }
                x.second-=rl;
                if(pq.size()<1) return r;
                auto y = pq.top();
                pq.pop();
                r+=y.first;
                y.second-=1;

                pq.push({x.first, x.second});
                if(y.second>0)
                    pq.push({y.first, y.second});
            }
        }
        return r;
    }
};