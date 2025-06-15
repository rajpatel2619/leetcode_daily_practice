class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string maxi = s, mini = s;

        //modifyng maxi for the max value
        int i = 0;
        while(s[i]=='9')
            i++;
        if(i<s.size()){
            char ch = s[i];
            for(i;i<s.size();i++){
                if(s[i]==ch)
                    maxi[i] = '9';
            }
        }

        //modifying mini for the min value
        if(s[0]=='1'){
            i = 1;
            while(s[i]=='1' or s[i]=='0')
                i++;
            char ch = s[i];
            for(i;i<s.size();i++){
                if(s[i]==ch)
                    mini[i] = '0';
            }
        }else{
            i = 0;
            char ch = s[i];
            for(i;i<s.size();i++){
                if(s[i]==ch)
                    mini[i] = '1';
            }
        }
        cout<<maxi<<" "<<mini;
        return stoi(maxi) - stoi(mini);
    }
};