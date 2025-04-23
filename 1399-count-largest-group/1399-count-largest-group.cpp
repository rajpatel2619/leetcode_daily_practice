class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> arr(n+1, 0);
        for(int i=1;i<=n;i++){
            int ds = 0;
            int t = i;
            while(t){
                ds+=(t%10);
                t/=10;
            }
            arr[ds]++;
        }
        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());
        int c = 1;
        int i =1;
        while(arr[i]==arr[i-1]){
            c++;
            i++;
        }
        return c;
    }
};