from collections import defaultdict
class ListNode:
    def __init__(self, x=None):
        # self.key = key
        self.val = x
        self.next = None

class MyHashMap:

    def __init__(self):
        self.size = 1000
        self.table = defaultdict(ListNode)

    def put(self, key: int, value: int) -> None:
        ## 중복된 키값이 있는지 확인
        ## 있다면, 개별 체이닝 방식(링크드 리스트로 연결)으로 처리
        ## 새로운 값으로 업데이트 되어야함! New -> Old

        ## 책에서는 해쉬함수를 직접 만들었음, index = key % self.size
        ## index가 hash 값

        if key in self.table:
            tmp = self.table[key]
            self.table[key] = ListNode(value)
            self.table[key].next = tmp

        else:
            self.table[key] = ListNode(value)

    def get(self, key: int) -> int:
        return self.table[key].val if key in self.table else -1

    def remove(self, key: int) -> None:
        if key in self.table:
            del self.table[key]

if "__main__":
    hmap = MyHashMap()
    hmap.put(1, 1)
    hmap.put(2, 2)
    print(hmap.get(1))
    print(hmap.get(3))
    hmap.put(2, 1)
    print(hmap.get(2))
    hmap.remove(2)
    print(hmap.get(2))


