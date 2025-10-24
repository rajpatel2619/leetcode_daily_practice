class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char c : tasks)
            freq[c - 'A']++;
        
        int time = 0;
        while (true) {
            sort(freq.rbegin(), freq.rend());
            if (freq[0] == 0) break; // all done
            
            int i = 0;
            // execute up to n+1 tasks in one cycle
            while (i <= n && i < 26 && freq[i] > 0) {
                freq[i]--;
                i++;
            }
            
            // if tasks remain, add full cycle, else only actual tasks
            time += (freq[0] > 0) ? (n + 1) : i;
        }
        return time;
    }
};
