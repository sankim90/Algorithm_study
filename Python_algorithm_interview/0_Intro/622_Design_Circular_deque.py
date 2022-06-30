class MyCircularQueue:

    def __init__(self, k: int):
        self.ringbuff = [None] * k
        self.front = 0
        self.rear = 0
        self.cnt = 0
        self.Max_len = k

    def enQueue(self, value: int) -> bool:
        if self.cnt == self.Max_len:
            return False
        else:
            self.ringbuff[self.rear] = value
            self.rear = (self.rear + 1) % self.Max_len
            self.cnt += 1
            return True

    def deQueue(self) -> bool:
        if self.cnt == 0:
            return False
        else:
            self.ringbuff[self.front] = None
            self.front = (self.front + 1) % self.Max_len
            self.cnt -= 1
            return True

    def Front(self) -> int:
        if self.isEmpty():
            return -1
        else:
            return self.ringbuff[self.front]

    def Rear(self) -> int:
        if self.isEmpty():
            return -1
        else:
            return self.ringbuff[self.rear - 1]

    def isEmpty(self) -> bool:
        return True if self.cnt == 0 else False

    def isFull(self) -> bool:
        return True if self.cnt == self.Max_len else False

if "__main__":
    obj = MyCircularQueue(3)
    obj.enQueue(2)
    obj.enQueue(3)
    print(obj.Rear())
    print(obj.Front())
    obj.deQueue()
    obj.Front()
    print()



    # ["MyCircularQueue","enQueue","Rear","Front","deQueue","Front","deQueue","Front","enQueue","enQueue","enQueue","enQueue"]
    # [[3],[2],[],[],[],[],[],[],[4],[2],[2],[3]]