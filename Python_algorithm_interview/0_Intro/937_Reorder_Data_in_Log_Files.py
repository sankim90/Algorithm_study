from typing import List

class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        text_log = []
        digit_log = []
        for idx, val in enumerate(logs):
            split_text = val.split()
            if split_text[1].isalpha():
                text_log.append(val)

            elif split_text[1].isdigit():
                digit_log.append(val)

        for i in text_log:
            split_text2 = i.split()
            if split_text2[1:] in i[1:]:

                print(split_text2)
            if split_text[1:] == i[1:]:
                print("to do sort[0]")


if "__main__":
    sol = Solution()
    logs = ["dig1 8 1 5 1", "let1 art can", "dig2 3 6", "let2 own kit dig", "let3 art zero"]
    sol.reorderLogFiles(logs)
