from typing import List

class Solution:
    def trap(self, height: List[int]) -> int:
        start_stk = []
        end = 0
        height_val = 0
        cnt = 0
        rst = 0
        # cnt == len(start_stk)
        for elem in height:
            if len(start_stk) == 0: #init
                if elem > 0:
                    start_stk.append(elem)
                    height_val = elem

            elif height_val < elem: #오르막
                cnt = len(start_stk)
                rst = rst + cnt * height_val
                tmp_len = len(start_stk)
                for i in range(tmp_len):
                    tmp = start_stk.pop()
                    rst = rst - tmp
            elif height_val > elem: #내리막
                height_val = elem

            else:
                start_stk.append(elem)



if "__main__":
    sol = Solution()
    input_data = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
    ret = sol.trap(input_data)
    print(ret)
