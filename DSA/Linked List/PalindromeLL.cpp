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
        ListNode* reverse(ListNode* h)
        {
            ListNode* prev = nullptr;
            ListNode* curr = h;
            while(curr!=nullptr)
            {
                ListNode* newnode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = newnode;
            }
            return prev;
        }
        bool isPalindrome(ListNode* head) {
            if(head==nullptr || head->next==nullptr) return true;
            ListNode* slow = head;
            ListNode* fast = head;
            ListNode* temp = head;
            while(fast->next!=nullptr && fast->next->next!=nullptr)
            {
                slow=slow->next;
                fast=fast->next->next;
            }
            ListNode* newhead = reverse(slow->next);
            ListNode* temp1 = newhead;
            while(temp1!=nullptr)
            {
                if(temp->val != temp1->val)
                {
                    reverse(newhead);
                    return false;
                }
                temp = temp->next;
                temp1 = temp1->next;
            }
            reverse(newhead);
            return true;
        }
    };