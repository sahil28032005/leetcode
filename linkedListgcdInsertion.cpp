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
    int gcd(int a, int b) {
        // Find Minimum of a and b
        int result = min(a, b);
        while (result > 0) {
            if (a % result == 0 && b % result == 0) {
                break;
            }
            result--;
        }

        // Return gcd of a and b
        return result;
    }
    void manageLinks(ListNode* head) {
        // base case
        if (head->next == NULL) {
            return;
        }
        //calculate gcd
        int gcdVal = gcd(head->val, head->next->val);
        //manage node links
        ListNode *n=new ListNode(gcdVal);
        n->next=head->next;
        head->next=n;
        //make recursive call as tail recursion
        manageLinks(head->next->next);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;
        manageLinks(temp);
        return head;
    }
};