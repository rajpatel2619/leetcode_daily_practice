class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string maxi, mini;
        //finding maxi
        int i = 0;
        while(s[i]=='9')
            i++;
        if(i==s.size()) maxi = s;
        else{
            maxi = s;
            char ch = s[i];
            for(i;i<s.size();i++){
                if(s[i]==ch)
                    maxi[i] = '9';
            }
        }

        //finding mini
        i = 0;
        while(s[i]==0)
            i++;
        if(i==s.size()) mini = s;
        else{
            mini = s;
            char ch = s[i];
            for(i;i<s.size();i++){
                if(s[i]==ch)
                    mini[i] = '0';
            }
        }
        cout<<maxi<<" "<<mini;
        return stoi(maxi) - stoi(mini);
    }
};