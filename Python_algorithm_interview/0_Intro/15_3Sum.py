from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = []
        nums.sort()

        for i in range(len(nums) - 2):
            if i > 0 and nums[i] == nums[i - 1]: # i = 0일때, i - 1 = -1 즉 index 맨앞과 맨끝 비교
                continue

            # 간격을 좁혀가며 sum 계산, left right는 index
            left, right = i + 1, len(nums) - 1
            while left < right:
                sum = nums[i] + nums[left] + nums[right]
                if sum < 0:
                    left += 1
                elif sum > 0:
                    right -= 1
                else:
                    # sum = 0인 경우이므로 정답 및 스킵 처리
                    result.append((nums[i], nums[left], nums[right]))

                    while left < right and nums[left]  == nums[left  + 1]:
                        left += 1
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1

                    left += 1
                    right -= 1

        return result


if "__main__":
    sol = Solution()
    rst = sol.threeSum([-1,0,1,2,-1,-4])
    print(rst)