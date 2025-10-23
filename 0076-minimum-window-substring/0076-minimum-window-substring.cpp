class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";
        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;

        int have = 0, needCount = need.size();
        int l = 0, minLen = INT_MAX, start = 0;

        for (int r = 0; r < s.size(); r++) {
            char c = s[r];
            window[c]++;

            // Check if this character now satisfies one required frequency
            if (need.count(c) && window[c] == need[c])
                have++;

            // When all required chars are included
            while (have == needCount) {
                // Update minimum window
                if ((r - l + 1) < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }
                // Try to shrink from left
                window[s[l]]--;
                if (need.count(s[l]) && window[s[l]] < need[s[l]])
                    have--;
                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
