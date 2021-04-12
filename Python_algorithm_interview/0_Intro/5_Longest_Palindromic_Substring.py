class Solution:
    def chk_palindrome(self, str_in): #펠린드롬 검사의 핵심
        return str_in == str_in[::-1]

    def longestPalindrome(self, s: str) -> str:
        result = []
        str_len = len(s)

        if s == s[::-1] or str_len < 2: # 알려진 케이스 빠르게 처리
            return s

        cnt = 0

        for i in range(str_len):    # 결국 문자열 전체를 하나하나 다 검사해 봐야하함
            for j in range(i, str_len + 1):
                # print(i, j, s[i:j])
                if self.chk_palindrome(s[i:j]): #내가 한 방식은 파이써닉 하진 않다, 속도도 답안보다 훨씬느림..
                    if cnt < len(s[i:j]):
                        cnt = len(s[i:j])
                        result = s[i:j]
        # print(result)
        return result


if "__main__":
    sol = Solution()
    sol.longestPalindrome("aabaad")




