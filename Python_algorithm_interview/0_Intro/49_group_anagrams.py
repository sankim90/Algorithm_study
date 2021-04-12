from typing import List
from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ana = defaultdict(list)

        for word in strs:
            ana[''.join(sorted(word))].append(word)

        return ana.values()

if "__main__":
    sol = Solution()
    strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
    ret = sol.groupAnagrams(strs)
    print(ret)
