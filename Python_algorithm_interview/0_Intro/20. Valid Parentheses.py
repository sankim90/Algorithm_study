class Solution:
    def isValid(self, s: str) -> bool:
        if not s:
            return False

        stk = []
        dict_s = {')': '(', ']': '[', '}': '{'}

        # for i in s:
        #     if i not in dict_s:
        #         stk.append(i)
        #     elif dict_s[i] != stk.pop():
        #         return False

        for i in s:
            if not stk:
                stk.append(i)
            elif i == ')' and stk[-1] == '(':
                stk.pop()
            elif i == '}' and stk[-1] == '{':
                stk.pop()
            elif i == ']' and stk[-1] == '[':
                stk.pop()
            else:
                stk.append(i)

        return stk == []

if "__main__":
    sol = Solution()
    rst = sol.isValid("(())")
    print(rst)
