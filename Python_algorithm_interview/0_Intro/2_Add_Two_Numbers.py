# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        carry = 0
        result_list = tmp_list = ListNode()

        while l1 or l2 or carry:
            if l1:
                l1_tmp = l1.val
                l1 = l1.next
            if l2:
                l2_tmp = l2.val
                l2 = l2.next

            sum = l1_tmp + l2_tmp + carry

            adder = sum % 10
            carry = sum // 10
            # print("addr {} carry {}".format(adder, carry))

            l1_tmp, l2_tmp = 0, 0
            tmp_list.next = ListNode(adder)
            tmp_list = tmp_list.next

        return result_list.next


if "__main__":
    sol = Solution()
    link1 = ListNode()
    link2 = ListNode()
    link3 = ListNode()
    link4 = ListNode()

    link1.val = 9
    link1.next = link2
    link2.val = 9

    link3.val = 9
    link3.next = link4
    link4.val = 9


    print(sol.addTwoNumbers(link1, link2))