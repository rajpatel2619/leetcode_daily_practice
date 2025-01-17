class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        // rock..
        if(a==e){
            if(a==c){
                if((d>b && d<f)||(d>f && d<b))
                    return 2;
                return 1;
            }else
                return 1;
        }else if(b==f){
            if(b==d){
                if((c>a && c<e)||(c>e && c<a))
                    return 2;
                return 1;
            }else 
                return 1;
        }
        // bishobh
        if(abs(c-e)==abs(d-f)){
            if(abs(c-a)==abs(d-b)){
                if(abs(c-a)<=abs(c-e) || (abs(d-b)<=abs(d-f))){
                    if((abs(a-e)+abs(b-f))>= (abs(c-e)+abs(d-f)))
                        return 1;
                }else 
                    return 1;
            }else
                return 1;
        }
        //
        return 2;
    }
};