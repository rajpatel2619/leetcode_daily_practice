class Solution {
public:
    vector<int> ps(vector<int> &arr){
        int n = arr.size();
        vector<int> res(n, -1);
        stack<pair<int, int>> st;
        for(int i=0;i<n;++i){
            int el = arr[i];
            if(st.empty() or st.top().first<el) st.push({el, i});
            else{
                while(!st.empty() and st.top().first>=el){
                    auto node = st.top();
                    st.pop();
                    if(!st.empty())
                        res[node.second] = st.top().second;
                }
                st.push({el, i});
            }
        }
        while(!st.empty()){
            auto node = st.top();
            st.pop();
            if(!st.empty())
                res[node.second] = st.top().second;
        }
        return res;
    }
    vector<int> gs(vector<int> &arr){
        int n = arr.size();
        vector<int> res(n, n);
        stack<pair<int, int>> st;
        for(int i=n-1;i>=0;--i){
            int el = arr[i];
            if(st.empty() or st.top().first<el) st.push({el, i});
            else{
                while(!st.empty() and st.top().first>=el){
                    auto node = st.top();
                    st.pop();
                    if(!st.empty())
                        res[node.second] = st.top().second;
                }
                st.push({el, i});
            }
        }
        while(!st.empty()){
            auto node = st.top();
            st.pop();
            if(!st.empty())
                res[node.second] = st.top().second;
        }
        return res;
    }
    int largestRectangleArea(vector<int>& nums) {
        vector<int> psi = ps(nums);
        vector<int> gsi = gs(nums);
        int maxi = 0;
        for(int i=0;i<nums.size();i++){
            maxi = max(maxi, abs(gsi[i]-1-psi[i])*nums[i]);
        }
        return maxi;
    }
};