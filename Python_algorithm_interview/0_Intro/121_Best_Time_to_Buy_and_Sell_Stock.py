from typing import List

#https://ip99202.github.io/posts/%EC%B9%B4%EB%8D%B0%EC%9D%B8-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98(DP)/
#해당 설명 참고, 카데인 알고리즘(DP)

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        min_value = 0

        for i in prices:
            min_value = min(min_value, i)
            profit = max(profit, i - min_value)

        return profit


if "__main__":
    sol = Solution()
    prices = [7, 1, 5, 3, 6, 4]
    sol.maxProfit(prices)