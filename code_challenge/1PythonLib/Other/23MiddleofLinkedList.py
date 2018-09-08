# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # Find the middle of linked list
    def middleNode(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        count = 0
        copy = head
        while copy != None:
            count += 1
            #print(head.val)
            copy = copy.next
        
        for i in range(0, int(count / 2)):
            head = head.next
        return head

    # Print the rest of linked list
    def printRest(self, head):
        res = []
        while head != None:
            res.append(head.val)
            head = head.next
        return res

l5 = ListNode(5)
l4 = ListNode(4)
l4.next = l5
l3 = ListNode(3)
l3.next = l4
l2 = ListNode(2)
l2.next = l3
l1 = ListNode(1)
l1.next = l2
s = Solution()
middleHead = s.middleNode(l1)
res = s.printRest(middleHead)
print res


