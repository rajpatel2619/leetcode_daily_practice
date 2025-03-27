class Solution {
public:
    bool check(int ind, int cc, int rc, int n){
        return (2*cc>ind+1) && (2*rc>(n-ind-1));
    }
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int el = nums[0];
        int c = 1;
        for(int i=1;i<n;i++){
            (nums[i]==el)?c++:c--;
            if(c==0){
                el = nums[i];
                c = 1;
            }
        }
        int tc = 0 ;
         for(auto e:nums)
            if(e==el)
                tc++;
        //
        int cc = 0;
        cout<<el<<endl;
        for(int i=0;i<n-1;i++){
            if(nums[i]==el){
                cc++;
                tc--;
            }
            if(check(i,cc,tc,n))
                return i;
            else cout<<i<<" "<<cc<<" "<<tc<<" "<<n<<endl;
        }
        return -1;
    }
};