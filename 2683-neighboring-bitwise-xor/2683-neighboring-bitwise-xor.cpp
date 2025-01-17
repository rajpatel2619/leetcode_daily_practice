class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        if(derived.size()==1) return derived[0]==0;
        int xrr = 0;
        for(auto e:derived) xrr^=e;
        return xrr==0;
    }
};