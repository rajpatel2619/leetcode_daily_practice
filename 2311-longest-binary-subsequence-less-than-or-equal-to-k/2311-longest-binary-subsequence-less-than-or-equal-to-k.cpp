class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int count = 0;
        long long value = 0;
        long long power = 1;

        int i = n - 1;
        for (; i >= 0; --i) {
            if (s[i] == '0') {
                count++;
            } else {
                if (power <= k && value + power <= k) {
                    value += power;
                    count++;
                }
            }
            power *= 2;
            if (power > k) break;
        }

        // After breaking the loop, include remaining '0's on the left
        while (--i >= 0) {
            if (s[i] == '0') count++;
        }

        return count;
    }
};
