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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head->next;
        ListNode* dummy = new ListNode();
        ListNode* prev = dummy;
        int sum = 0;

        while(curr) {
            if(curr->val == 0) {
                ListNode* tmp = new ListNode(sum);
                prev->next = tmp;
                prev = prev->next;
                sum=0;
                curr = curr->next;
            } else {
                sum+=curr->val;
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};
