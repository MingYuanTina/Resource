// 21. Merge Two Sorted Lists
// Merge two sorted linked lists and 
// return it as a new list. The new list
// should be made by splicing together 
// the nodes of the first two lists.

// Test Cases
	// Both NULL --> NULL
	// [], [1] --> [1]
	// [1], [] --> [1]
	// [1,2], [1] --> [1,1,2]

// Solution: Recursion
/**
 * Definition for singly-linked list.
 * struct ListNode ls *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // Base Case
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        
        // Other Case
        if (l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};