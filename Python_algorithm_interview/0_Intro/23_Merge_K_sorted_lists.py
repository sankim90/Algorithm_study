import heapq
from typing import List


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


# Node를 끝까지 탐색
# 끝까지 탐색 후, next가 none일 경우 찾기(마지막 노드임)
# 찾은 후 다음 Node가 있을경우, Node.next = 다음노드의 시작
# 없을경우 종료 후 우선순위 큐에 넣고 리턴

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        root = result = ListNode(None)
        heap = []

        # 각 연결 리스트의 루트를 힙에 저장
        for i in range(len(lists)):
            if lists[i]:
                heapq.heappush(heap, (lists[i].val, i, lists[i]))

        # 힙 추출 이후 다음 노드는 다시 저장
        while heap:
            node = heapq.heappop(heap) ## 튀어나온 놈이 가장 작은값, 입력값은 이미 오름차순 정렬 되었음을 잊지 말자
            idx = node[1] ## heappush에서 index값
            result.next = node[2] ## heappush에서 다음 링크드리스트의 루트 node

            result = result.next ## 정답에 추가
            if result.next:  ## 다음 값이 있으면, 즉 끝이 아니면
                heapq.heappush(heap, (result.next.val, idx, result.next)) ## 다음값을 우선순위 큐에 넣어서 다시 최솟값을 뽑아낼 준비를 해야함

        return root.next

if "__main__":
    sol = Solution()
    Node1 = ListNode(1)
    Node1.next = ListNode(4)
    Node1.next.next = ListNode(5)

    Node2 = ListNode(1)
    Node2.next = ListNode(3)
    Node2.next.next = ListNode(4)

    Node3 = ListNode(2)
    Node3.next = ListNode(6)

    rst = sol.mergeKLists([Node1, Node2, Node3])
    print("test")
