// Question
	// 141. Linked List Cycle
	// Given a linked list, determine if it has a cycle in it.
	// Follow up: Can you solve it without using extra space?
	
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /**
 use faster and lower runner solution. (2 pointers)
 the faster one move 2 steps, and slower one move only one step.
 if there's a circle, the faster one will finally "catch" the slower one. 
 (the distance between these 2 pointers will decrease one every time.)
 
 if there's no circle, the faster runner will reach the end of linked list. (NULL)
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL)    
            return false;
        ListNode *f = head, *s = head;
        while(f->next && f-> next -> next){
            f = f->next->next;
            s = s->next;
            if(f == s)
                return true;
        }
        return false;
    }
};