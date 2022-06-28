class ListNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# 환형 데크의 정의를 잘 파악하자
# init시 head와 tail을 엮는것 중요
# _add, _del 함수 만들어 쓰자
# Head와 Tail은 Pointer로 쓰인다, 그 자체로 의미하는 값이 없다!
# EX) insertFront(10) case, Head.val -> None , Head.right.val -> 10
# insertFront(10), getRear -> 고려해야한다, front로 넣고 rear로 빼는 경우 당연히 지원, 반대로 물론

class MyCircularDeque:

    def __init__(self, k: int):
        self.head = ListNode(None)
        self.tail = ListNode(None)
        self.cnt = 0
        self.Max_len = k
        self.head.right, self.tail.left = self.tail, self.head

    def _add(self, node: ListNode, new: ListNode):
        tmp = node.right
        node.right = new
        new.left, new.right = node, tmp
        tmp.left = new

    def _del(self, node: ListNode):
        tmp = node.right.right
        node.right = tmp
        tmp.left = node

    def insertFront(self, value: int) -> bool:
        if self.cnt >= self.Max_len:
            return False
        else:
            self._add(self.head, ListNode(value))
            self.cnt += 1
            return True

    def insertLast(self, value: int) -> bool:
        if self.cnt >= self.Max_len:
            return False
        else:
            self._add(self.tail.left, ListNode(value))
            self.cnt += 1
            return True

    def deleteFront(self) -> bool:
        if self.cnt <= 0:
            return False
        else:
            self._del(self.head)
            self.cnt -= 1
            return True

    def deleteLast(self) -> bool:
        if self.cnt <= 0:
            return False
        else:
            self._del(self.tail.left.left)
            self.cnt -= 1
            return True

    def getFront(self) -> int:
        if self.isEmpty():
            return -1
        else:
            rtn_val = self.head.right.val

        return rtn_val

    def getRear(self) -> int:
        if self.isEmpty():
            return -1
        else:
            rtn_val = self.tail.left.val

        return rtn_val

    def isEmpty(self) -> bool:
        return self.cnt == 0

    def isFull(self) -> bool:
        return self.cnt == self.Max_len

if "__main__":
    obj = MyCircularDeque(4)
    obj.insertFront(9)
    # obj.deleteLast()
    print(obj.getFront())
    print(obj.getRear())
    print(obj.getFront())
    # print(obj.deleteFront())
    # obj.insertFront(6)


    # ["MyCircularDeque", "insertFront", "deleteLast", "getRear", "getFront", "getFront", "deleteFront", "insertFront",
    #  "insertLast", "insertFront", "getFront", "insertFront"]
    # [[4], [9], [], [], [], [], [], [6], [5], [9], [], [6]]

    # obj.insertLast(1)
    # obj.insertLast(2)
    #
    # obj.insertFront(4)
    # print(obj.getRear())
    # print(obj.isFull())
    # obj.deleteLast()
    # obj.insertFront(4)
    # print(obj.getFront())

