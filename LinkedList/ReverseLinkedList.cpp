struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;      // Previous node (initially null)
    ListNode* curr = head;         // Current node starting at head
    while (curr) {
        ListNode* nextTemp = curr->next; // Store next node
        curr->next = prev;               // Reverse current node's pointer
        prev = curr;                     // Move prev to current
        curr = nextTemp;                 // Move to next node
    }
    return prev;  // New head of reversed list
}
