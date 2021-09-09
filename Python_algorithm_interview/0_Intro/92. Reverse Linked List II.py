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
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        root = start = ListNode()
        root.next = head

        for i in range(left - 1):
            start = start.next

        end = start.next

        node, prev = start.next, None
        for i in range(right - left + 1):
            next, node.next = node.next, prev
            node, prev = next, node

        start.next = prev
        end.next = node

        return root.next

if "__main__":
    sol = Solution()
    link1 = ListNode()
    link2 = ListNode()
    link3 = ListNode()
    link4 = ListNode()
    link5 = ListNode()

    # [1,2,3,4,5,6,7,8]
    link1.val = 1
    link1.next = link2
    link2.val = 2
    link2.next = link3
    link3.val = 3
    link3.next = link4
    link4.val = 4
    link4.next = link5
    link5.val = 5

    sol.reverseBetween(link1, 2, 4)