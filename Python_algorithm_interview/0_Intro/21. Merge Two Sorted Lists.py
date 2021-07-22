# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        Head = ListNode()
        ptr = Head

        while l1 != None and l2 != None:
            if l1.val <= l2.val:
                ptr.next = l1
                l1 = l1.next
            else:
                ptr.next = l2
                l2 = l2.next

            ptr = ptr.next

        if l1 != None:
            ptr.next = l1
        if l2 != None:
            ptr.next = l2

        return Head.next

if "__main__":
    sol = Solution()
    link1 = ListNode()
    link2 = ListNode()
    link3 = ListNode()
    link4 = ListNode()
    link5 = ListNode()

    link1.val = 3
    link1.next = link2
    link2.val = 6

    link3.val = 2
    link3.next = link4
    link4.val = 4
    link4.next = link5
    link5.val = 1

    print(sol.mergeTwoLists(link1, link3))