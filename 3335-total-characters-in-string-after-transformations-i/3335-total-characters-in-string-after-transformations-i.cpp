class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> cnt(26);
        for (char ch : s) {
            cnt[ch - 'a']++;
        }
        for (int round = 0; round < t; ++round) {
            int zz = cnt[25];
            for (int i = 25; i >0; --i) {
                cnt[i] = cnt[i - 1];
            }
            cnt[0] = zz;
            cnt[1] = (cnt[1]+zz)%mod;
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans = (ans + cnt[i]) % mod;
        }
        return ans;
    }

private:
    int mod = 1000000007;
};