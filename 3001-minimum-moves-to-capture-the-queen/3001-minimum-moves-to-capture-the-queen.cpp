class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if(a==e || b==f){
            if(b==f && b==d && (c-a)*(c-e)<0) return 2;
            if(a==c && a==e && (d-b)*(d-f)<0) return 2;
            return 1;
        }
        if(abs(c-e)==abs(d-f)){
            if(abs(c-a) == abs(d-b) && ((b-d)*(b-f)<0)) return 2;
            return 1;
        }
        return 2;
    }
};