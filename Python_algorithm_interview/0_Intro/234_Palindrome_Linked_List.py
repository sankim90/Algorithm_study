# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def chk_palindrome(self, str_in): #펠린드롬 검사의 핵심
        return str_in == str_in[::-1]


    def isPalindrome(self, head: ListNode) -> bool:
        if head == None:
            return True

        tmp = []
        # node = head

        while head != None:
            tmp.append(head.val)
            head = head.next

        print(tmp)
        return self.chk_palindrome(tmp)

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
    #p     #p.next     #head   #head  #p     #head.next
    link1, link1.next, link3 = link3, link1, link3.next
    #다중 할당(Multiple Assignment)
    #한 줄로 표기하면 모든 값들은 이전의 값을 유지한다!
    #link 1 = link3 을 수행했다고 link1.next에서 link1이 link3이 되지 않음, link1 유지.


    print(sol.isPalindrome(link1))

