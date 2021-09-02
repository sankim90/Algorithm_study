from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def _print_all(self):
        while self:
            print(self.val, end=' ')
            self = self.next


class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head

        root = head
        even_root = head.next

        while head and head.next and head.next.next:
            even = head.next
            head.next = even.next
            head = head.next
            even.next = head.next

        head.next = even_root

        # root._print_all()

        return root

if "__main__":
    sol = Solution()
    link1 = ListNode()
    link2 = ListNode()
    link3 = ListNode()
    link4 = ListNode()
    # link5 = ListNode()

    # [1,2,3,4,5,6,7,8]
    link1.val = 1
    link1.next = link2
    link2.val = 2
    link2.next = link3
    link3.val = 3
    link3.next = link4
    link4.val = 4
    # link4.next = link5
    # link5.val = 5



    sol.oddEvenList(link1)