from typing import List

class Solution:
    def reverseString(self, s: List[str]) -> None:
        #1 method
            #s.reverse()

        #2 method
        nums = len(s)
        for i in range(nums//2):
            tmp = s[i]
            s[i] = s[nums - i - 1]
            s[nums - i - 1] = tmp


if "__main__":
    sol = Solution()
    sol.reverseString(["h", "e", "l", "l", "o"])
