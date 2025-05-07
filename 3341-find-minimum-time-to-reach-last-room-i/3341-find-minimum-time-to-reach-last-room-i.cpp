class Solution {
public:
    struct node{
        int r, c, t;
        node(int r, int c, int t){
            this->r = r;
            this->c = c;
            this->t = t;
        }
    };
    
    struct comparator {
        bool operator()(node* p1, node* p2) {
            return p1->t > p2->t; // min-heap: smallest time first
        }
    };

    bool valid(int r, int c, int m, int n){
        return (r >= 0 && c >= 0 && r < m && c < n);
    }

    int minTimeToReach(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        priority_queue<node*, vector<node*>, comparator> pq;
        pq.push(new node(0, 0, 0));

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vis[0][0] = true;

        int dir[5] = {-1, 0, 1, 0, -1};

        while (!pq.empty()) {
            auto c = pq.top();
            pq.pop();

            if (c->r == m - 1 && c->c == n - 1) return c->t;

            for (int i = 0; i < 4; i++) {
                int nr = c->r + dir[i];
                int nc = c->c + dir[i + 1];
                if (valid(nr, nc, m, n) && !vis[nr][nc]) {
                    vis[nr][nc] = true;
                    int arrivalTime = max(c->t, grid[nr][nc]) + 1;
                    pq.push(new node(nr, nc, arrivalTime));
                }
            }
        }
        return -1;
    }
};
