struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);        // Dummy node to simplify edge cases
    ListNode* tail = &dummy;  // Pointer to build merged list

    while(l1 && l2) {
        if(l1->val < l2->val) { // Choose smaller value
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;     // Move tail forward
    }

    // Attach remaining nodes if any
    tail->next = l1 ? l1 : l2;

    return dummy.next;  // Return merged list head
}
