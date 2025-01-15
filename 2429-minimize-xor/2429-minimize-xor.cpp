class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int n = 0;
        while(num2){
            if(num2&1)
                n++;
            num2>>=1;
        }
        int ans = 1<<n;;
        ans-=1;
        if(num1<=ans)
            return ans;
        vector<int> arr(32,0);
        int i=0;
        while(num1){
            if(num1&1)
                arr[i]++;
            num1/=2;
            i++;
        }

        
        
        for(i=31;i>=0;i--){
            if(arr[i] && n){
                n--;
            }else
                arr[i] = 0;
        }
        // for(auto e:arr)
        //     cout<<e<<' ';

        i = 0;
        while(n){
            if(arr[i]==0){
                arr[i] = 1;
                n--;
            }
            i++;
        }
        
        ans = 0;
        for(i=0; i<=31;i++){
            int t = 0;
            if(arr[i])
                t = 1<<i;
            // t--;
            ans+=t;
        }
        return ans;
    }
};