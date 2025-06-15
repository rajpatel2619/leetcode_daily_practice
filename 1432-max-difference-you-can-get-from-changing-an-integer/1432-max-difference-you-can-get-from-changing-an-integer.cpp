class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string maxi = s, mini = s;

        //modifyng maxi for the max value
        int i = 0;
        while(s[i]=='9') i++;
        replace(maxi.begin()+i, maxi.end(), s[i], '9');

        //modifying mini for the min value
        if(s[0]=='1'){
            i = 1;
            while(s[i]=='1' or s[i]=='0') i++;
            replace(mini.begin()+i, mini.end(), s[i], '0');
        }else{
            replace(mini.begin(), mini.end(), s[0], '1');
        }
        // max diff
        return stoi(maxi) - stoi(mini);
    }
};