import re
from collections import deque

class Solution:
    def isPalindrome(self, s: str) -> bool:
        result = re.sub('[^0-9a-zA-Z]', '', s)
        result = result.lower()
        str_len = len(result)
        for idx, i in enumerate(result):
            if i != result[str_len - idx - 1]:
                return False

        return True

    def isPalindrome2(self, s: str) -> bool:
        # strs = deque()
        strs = []
        for c in s:
            if c.isalnum():
                strs.append(c.lower())


        return strs == strs[::-1]

if "__main__":
    sol = Solution()
    print(sol.isPalindrome2("race a car"))
    #print(sol.isPalindrome("raar")) True





