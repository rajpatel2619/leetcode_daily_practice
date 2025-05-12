class Solution {
public:
    // Check if there's a square of side 'a' full of '1's
    bool ok(vector<vector<char>>& matrix, int m, int n, int a) {
        for (int i = 0; i <= m - a; ++i) {
            for (int j = 0; j <= n - a; ++j) {
                bool allOne = true;
                for (int x = i; x < i + a; ++x) {
                    for (int y = j; y < j + a; ++y) {
                        if (matrix[x][y] != '1') {
                            allOne = false;
                            break;
                        }
                    }
                    if (!allOne) break;
                }
                if (allOne) return true;
            }
        }
        return false;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();

        int l = 1, r = min(m, n), ans = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (ok(matrix, m, n, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans * ans; // Return area
    }
};
