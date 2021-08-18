# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseListRecur(self, head: ListNode) -> ListNode:
        def reverse(node: ListNode, prev: ListNode = None):
            if not node:
                return prev
            next, node.next = node.next, prev
            print(prev.val)
            return reverse(next, node)

        return reverse(head)

    def reverseListList(self, head: ListNode) -> ListNode:
        node = head
        prev = None

        while node:
            next, node.next = node.next, prev
            node, prev = next, node

        return prev


    def san_reverseListList(self, head: ListNode) -> ListNode:
        Node = head
        prev = None
        # 목표는 방향을 바꾸고, prev를 맨 끝으로 보내는것!
        # NULL->1->2->3->4
        # NULL<-1<-2<-3<-4

        while Node:
            Next = Node.next
            Node.next = prev
            prev = Node
            Node = Next

        return prev

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

    print(sol.reverseListList(link1))
