class Solution {
public:
    struct node{
        int r, c, t, s;
        node(int r, int c, int t, int s){
            this->r = r;
            this->c = c;
            this->t = t;
            this->s = s;
        }
    };
    struct comparator{
        int operator()(node* p1, node* p2){
            return p1->t > p2->t;
        }
    };
    bool valid(int r, int c, int m, int n){
        return (r>=0 and c>=0 and r<m and c<n);
    }
    int minTimeToReach(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<node*, vector<node*>, comparator> pq;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        pq.push(new node(0,0,0,2));
        vis[0][0] = true;
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            if(cur->r == m-1 and cur->c == n-1) return cur->t;
            int dir[5] = {-1,0,1,0,-1};
            for(int i=0;i<4;i++){
                int nr = cur->r + dir[i];
                int nc = cur->c + dir[i+1];
                if(valid(nr, nc, m, n) && !vis[nr][nc]){
                    vis[nr][nc] = true;
                    int tm = max(cur->t, grid[nr][nc]);
                    int ns = (cur->s==1)?2:1;
                    tm+=ns;
                    pq.push(new node(nr, nc, tm, ns));
                }
            }
        }
        return -1;
    }
};