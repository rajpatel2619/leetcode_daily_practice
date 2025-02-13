class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        auto comp = [](int a, int b){
            return a>b;
        };
        priority_queue<long long, vector<long long>, greater<long long>>pq(nums.begin(), nums.end());
        int count = 0;
        while(pq.size()>1 && pq.top()<k){
            long long el1 = pq.top();
            pq.pop();
            long long el2 = pq.top();
            pq.pop();
            pq.push(min(el1,el2)*2+max(el1,el2));
            count++;
        }
        return count;
    }
};