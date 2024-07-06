class Solution {
public:
    int passThePillow(int n, int time) {
        int m = n-1;
        int r = time%m;
        int p = time/m;
        if(p&1)return m-r+1;
        return r+1;
    }
};
