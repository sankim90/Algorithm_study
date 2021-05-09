from typing import List
from itertools import combinations, permutations, combinations_with_replacement

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)
        tmp = list(combinations(nums, 3))
        # print(tmp)
        rst = []
        for idx, val in enumerate(tmp):
            tmp2 = sum(val)
            if tmp2 == 0 and list(val) not in rst:
                rst.append(list(val))

        return rst

if "__main__":
    sol = Solution()
    rst = sol.threeSum([-1, 0, 1, 2, -1, -4])
    # rst = sol.threeSum([0])
    print(rst)
