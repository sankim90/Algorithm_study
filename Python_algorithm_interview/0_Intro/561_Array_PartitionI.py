from typing import List

class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums.sort()
        sum = 0
        for idx, val in enumerate(nums):
            if idx % 2 == 0:
                sum += val
        return sum