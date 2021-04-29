from typing import List

def sum_list(s_idx, nums: List[int], target: int):
    for i in range(len(nums) - (s_idx + 1)):
        sum = nums[s_idx] + nums[s_idx + i + 1]
        if sum == target:
            return [s_idx, s_idx + i + 1]

    rtn = sum_list(s_idx + 1, nums, target)
    return rtn

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        result = sum_list(0, nums, target)
        return result







if "__main__":
    sol = Solution()
    rtn = sol.twoSum([2, 7, 11, 15], 22)
    # rtn = sol.twoSum([3, 2, 4], 6)
    print(rtn)

    # Input: nums = [2, 7, 11, 15], target = 9
    # Output: [0, 1]
    # Output: Because
    # nums[0] + nums[1] == 9, we
    # return [0, 1].

    # Example
    # 2:
    #
    # Input: nums = [3, 2, 4], target = 6
    # Output: [1, 2]

    # Example
    # 3:
    #
    # Input: nums = [3, 3], target = 6
    # Output: [0, 1]