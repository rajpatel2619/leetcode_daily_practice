class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum = accumulate(nums.begin(), nums.end(), 0.0);
        priority_queue<double>pq(nums.begin(), nums.end());
        int count = 0;
        double ssum = sum;
        while(ssum>sum/2){
            double el1 = pq.top();
            pq.pop();
            double t = el1/2;
            pq.push(t);
            ssum-=t;
            count++;
        }
        return count;
    }
};