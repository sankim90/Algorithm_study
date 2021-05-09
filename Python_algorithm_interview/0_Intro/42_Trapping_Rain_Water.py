from typing import List

# 2 pointer Solution
# class Solution:
#     def trap(self, height: List[int]) -> int:
#         if not height:
#             return 0
#
#         volume = 0
#         left = 0
#         right = len(height) - 1
#         left_max = height[left]
#         right_max = height[right]
#
#         while left < right:
#             left_max = max(height[left], left_max)
#             right_max = max(height[right], right_max)
#             # 최고 높이를 향해 투 포인터 이동
#             if left_max <= right_max:
#                 volume += left_max - height[left]
#                 left += 1
#             else:
#                 volume += right_max - height[right]
#                 right -= 1
#         return volume

class Solution:
    def trap(self, height: List[int]) -> int:
        stack = []
        volume = 0
        for i in range(len(height)):
            while stack and height[i] > height[stack[-1]]:
                top = stack.pop()

                if not len(stack):
                    break

                # 이전과의 차이만큼 물 높이 처리
                dist = i - stack[-1] - 1
                waters = min(height[i], height[stack[-1]]) - height[top]

                volume += dist * waters

            stack.append(i)
        return volume

if "__main__":
    sol = Solution()
    # input_data = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
    input_data = [0, 1]
    ret = sol.trap(input_data)
