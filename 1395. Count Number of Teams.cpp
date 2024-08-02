//
//  ViewController.swift
//  dropDownMenu
//
//  Created by Ajijul Hakim Riad on 29/7/24.
//



class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        vector<int> increasing(n+10, 0);
        vector<int> decreasing(n+10, 0);
        int ans = 0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(rating[j] < rating[i]) {
                    increasing[i]++;
                    ans+=increasing[j];
                }
                else if(rating[j] > rating[i]) {
                    decreasing[i]++;
                    ans+=decreasing[j];
                }
            }
        }

        return ans;
    }
};
