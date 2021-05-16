from typing import List


def multi_sum(input_list, idx_cnt):
    tmp = 1
    tmp_list = input_list[:]
    tmp_list.pop(idx_cnt)

    for i in tmp_list:
        tmp *= i

    return tmp


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        rst = []
        input_len = len(nums)
        for i in range(input_len):
            tmp = multi_sum(nums, i)
            rst.append(tmp)

        print(rst)
        return rst


if "__main__":
    sol = Solution()
    sol.productExceptSelf([1, 2, 3, 4])
