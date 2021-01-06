from typing import List
import re
from collections import Counter, defaultdict

class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:

        text = re.sub("[^\w]", " ", paragraph) # 문자를 제외한 모든것을 공백 처리
        text = text.lower().split()
#         words = [word for word in re.sub(r'[^\w]', ' ', paragraph)
#             .lower().split()
#                  if word not in banned]

        result = []
        for i in text:             #리스트 컴프리헨션으로 처리하는 방법을 권장하나 난 요렇게 했음
            if i not in banned:
                result.append(i)

        cnt = Counter(result)   #내장 함수에서 counter 관련
        return cnt.most_common(1)[0][0] # 가장 흔한문자 1등 리스트에서 다시 val 값을 파싱

        # cnt2 = defaultdict(int) #int 값을 default로 부여하는 dict으로도 문제 해결 가능
        # for i in result:
        #     cnt2[i] += 1
        # print(cnt2, max(cnt2, key=cnt2.get))
        # print(cnt.most_common(1)[0][0])

if "__main__":
    sol = Solution()
    paragraph = "a, a, a, a, b,b,b,c, c"
    #paragraph = "Bob. hIt, baLl"
    #banned = ["bob", "hit"]
    banned = ["a"]
    sol.mostCommonWord(paragraph, banned)
