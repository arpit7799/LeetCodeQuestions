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

    ListNode* getKthNode(ListNode* temp, int k) {
        k--;

        while(temp != NULL && k > 0) {
            temp = temp->next;
            k--;
        }

        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        ListNode* prevLast = NULL;

        while(temp) {

            ListNode* kthNode = getKthNode(temp, k);

            // Less than k nodes left
            if(kthNode == NULL) {
                if(prevLast)
                    prevLast->next = temp;
                break;
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;

            // Reverse current k-group
            ListNode* prev = NULL;
            ListNode* curr = temp;

            while(curr) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // Connect with previous group
            if(temp == head) {
                head = kthNode;
            }
            else {
                prevLast->next = kthNode;
            }

            prevLast = temp;
            temp = nextNode;
        }

        return head;
    }
};