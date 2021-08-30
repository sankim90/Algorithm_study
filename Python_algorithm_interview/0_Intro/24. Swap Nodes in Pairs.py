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
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head

        prev = root = ListNode()
        prev.next = head

        while head and head.next:  # prev -> 1(head) -> 2 -> 3 -> 4
            tmp = head.next  # prev -> 1(head) -> 2(tmp) -> 3 -> 4
            head.next = tmp.next  # prev -> 1(head) -> 3 -> 4 // tmp -> 3 -> 4
            tmp.next = head  # prev -> 1(head) -> 3 -> 4
                             #           ^ 2(tmp)
            prev.next = tmp  # prev -> 2(tmp) -> 1(head) -> 3 -> 4

            head = head.next # prev -> 2 -> 1 -> 3(head) -> 4

            prev = prev.next.next

        return root.next


if "__main__":
    sol = Solution()
    link1 = ListNode()
    link2 = ListNode()
    link3 = ListNode()
    link4 = ListNode()
    link1.val = 1
    link1.next = link2
    link2.val = 2
    link2.next = link3
    link3.val = 3
    link3.next = link4
    link4.val = 4

    sol.swapPairs(link1)
