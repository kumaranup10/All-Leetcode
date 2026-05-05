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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) 
            return head;
        ListNode* curr = head;
        int count = 0;
        while (curr) {
            count++;
            curr = curr->next;
        }
        k = k % count;
        if (k == 0) return head;
        curr = head;
        ListNode* tail = nullptr;
        int steps = count - k;
        while (steps--) {
            tail = curr;
            curr = curr->next;
        }
        tail->next = nullptr;
        ListNode* newHead = curr;  

        ListNode* temp = newHead;
        while (temp->next) temp = temp->next;
        temp->next = head;  

        return newHead;
    }
};
