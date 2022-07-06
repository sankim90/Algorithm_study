import collections
from collections import defaultdict


class Solution:
    def __init__(self):
        self.count = 0
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        # 1. 내 풀이, 파이써닉 방식 풀어놓은것
        for i in stones:
            if i in jewels:
                self.count += 1

        return self.count

        # defaultdict 이용해서 정석 방법으로 푼것
        # ddict = defaultdict(int)
        # for i in stones:
        #     ddict[i] += 1
        #
        # for i in jewels:
        #     self.count += ddict[i]
        #
        # Counter lib 사용한것, 유용하니 기억 하자
        # freq = collections.Counter(stones)

        # return self.count

        #파이써닉한 방식
        #return sum([i in jewels for i in stones])




if "__main__":
    sol = Solution()
    # jewels = "z"
    # stones = "ZZ"
    jewels = "aA"
    stones = "aAAbbbb"
    print(sol.numJewelsInStones(jewels, stones))