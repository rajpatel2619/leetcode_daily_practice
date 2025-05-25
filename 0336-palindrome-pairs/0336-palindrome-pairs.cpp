class Solution {
public:
    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> wordIndex;
        vector<vector<int>> res;

        // Step 1: Store reversed word -> index
        for (int i = 0; i < words.size(); ++i) {
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            wordIndex[rev] = i;
        }

        // Step 2: For each word, split into prefix and suffix
        for (int i = 0; i < words.size(); ++i) {
            string word = words[i];
            int len = word.length();

            for (int j = 0; j <= len; ++j) {
                string prefix = word.substr(0, j);
                string suffix = word.substr(j);

                // Case 1: If prefix is palindrome, look for reverse of suffix
                if (isPalindrome(word, 0, j - 1)) {
                    if (wordIndex.count(suffix) && wordIndex[suffix] != i) {
                        res.push_back({wordIndex[suffix], i});
                    }
                }

                // Case 2: If suffix is palindrome, look for reverse of prefix
                if (j != len && isPalindrome(word, j, len - 1)) {
                    if (wordIndex.count(prefix) && wordIndex[prefix] != i) {
                        res.push_back({i, wordIndex[prefix]});
                    }
                }
            }
        }
        return res;
    }
};
