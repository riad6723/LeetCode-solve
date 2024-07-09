class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int chefTime = customers[0][0] + customers[0][1];
        double ans = customers[0][1];
        double n = customers.size();

        for(int i=1;i<customers.size();i++) {
            int arrival = customers[i][0];
            int time = customers[i][1];

            if(arrival<=chefTime) {
                ans+=chefTime-arrival+time;
                chefTime+=time;
            }
            else {
                ans+=time;
                chefTime = arrival + time;
            }
        }
        return ans/n;
    }
};
