class Solution {
public:

    bool check(vector<int> &vec,int m,int k,int x) {
        int ans=0;
        for(int i=0;i<vec.size();) {
            if(vec[i]<=x) {
                int cnt=0;
                while(i<vec.size() and vec[i]<=x) {
                    cnt++;
                    i++;
                }
                ans+=cnt/k;
            }
            else i++;
        }
        if(ans>=m)return true;
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k>bloomDay.size())return -1;

        int l=1,r=1e9;
        while(r-l>3) {
            int mid=(l+r)/2;
            if(check(bloomDay,m,k,mid)==true)r=mid;
            else l=mid;
        }

        for(int i=l;i<=r;i++) {
            if(check(bloomDay,m,k,i)==true)return i;
        }

        return -1;
    }
};
