import collections

class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        counter, seen, stack = collections.Counter(s), set(), []

        for char in s:
            counter[char] -= 1  # 한글자 처리 됨
            if char in seen:  # 중복 문자 스킵
                continue
            # 뒤에 붙일 문자가 남아 있다면 스택에서 제거
            while stack and char < stack[-1] and counter[stack[-1]] > 0:  # 스택에 값이 있고, 사전 순이 아니고, 유일하게 남은 글자가 아닐 경우
                seen.remove(stack.pop())  # 반복해서 값을 지움
            stack.append(char)  # 결과 값 만들기
            seen.add(char)  # 중복된 문자 확인

        return ''.join(stack)  # str으로 변환 후 리턴

if "__main__":
    sol = Solution()
    sol.removeDuplicateLetters("cbacdcbc")