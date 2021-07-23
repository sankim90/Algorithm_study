# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
            return head

        tmp = ListNode()
        first_node = head
        ptr = tmp

        while head != None:
            if head.next == None:
                ptr.next = head #역순을 대입
                prev.next = None #현재 Node 삭제
                head = first_node #첫 Node로 초기화
                ptr = ptr.next
            prev = head
            head = head.next

        #마지막 노드 처리
        first_node.next = None
        ptr.next = first_node

        return tmp.next

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

    print(sol.reverseList(link1))
