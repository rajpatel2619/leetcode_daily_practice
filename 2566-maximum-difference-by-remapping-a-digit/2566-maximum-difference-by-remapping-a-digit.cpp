class Solution {
public:
    int minMaxDifference(int num) {
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
        i = 0;
        while(s[i]=='0')
            i++;
        if(i<s.size()){
            char ch = s[i];
            for(i;i<s.size();i++){
                if(s[i]==ch)
                    mini[i] = '0';
            }
        }
        return stoi(maxi) - stoi(mini);
    }
};