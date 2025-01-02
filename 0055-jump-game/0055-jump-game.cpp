class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        queue<int> q;
        q.push(0);
        int far = 0;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            for(int i=max(node + 1, far + 1);i<=min(n-1, node+nums[node]);i++){
                if(i==n-1) return true;
                q.push(i);
            }
            far = max(far, node+nums[node]);
        }
        return far>=n-1;
    }
};