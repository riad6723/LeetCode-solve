/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        int cnt=0;
        vector<int> vec;
        while(curr) {
            cnt++;
            if(prev and curr->next) {
                int l = prev->val;
                int mid = curr->val;
                int r = curr->next->val;
                if(mid>l and mid>r)vec.push_back(cnt);
                else if(mid<l and mid<r)vec.push_back(cnt);
            }
            prev=curr;
            curr = curr->next;
        }
        int mn=1e9;
        if(vec.size()<2)return {-1,-1};
        for(int i=1;i<vec.size();i++) {
            mn=min(mn,vec[i]-vec[i-1]);
        }
        return {mn,vec[vec.size()-1]-vec[0]};
    }
};
