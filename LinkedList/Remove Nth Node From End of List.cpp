#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* first = &dummy;
        ListNode* second = &dummy;

        // Move first n+1 steps ahead
        for (int i = 0; i <= n; ++i)
            first = first->next;

        // Move first to end, second follows
        while (first) {
            first = first->next;
            second = second->next;
        }

        // Remove nth node
        second->next = second->next->next;

        return dummy.next;
    }
};
