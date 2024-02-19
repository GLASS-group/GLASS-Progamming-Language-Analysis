import time

ONE_MILLION = 1000000
ONE_BILLION = 1000000000
NUM_TRIALS = 50
cumulative = 0

class Tree:
    def __init__(self, nodeNum):
        self._root = Node(None)
        node_queue = []
        node_queue.append(self._root)
        for i in range(nodeNum):
            current_node = node_queue.pop(0)
            current_node._left_child = Node(current_node)
            current_node._right_child = Node(current_node)
            node_queue.append(current_node._left_child)
            node_queue.append(current_node._right_child)

    def DFS(self):
        self._root.DFS()


class Node:
    def __init__(self, p):
        self._left_child = None
        self._right_child = None
        self._parent = p
        self._data = 0

    def DFS(self):
        self._data += 1
        if self._left_child != None:
            self._left_child.DFS()
        if self._right_child != None:
            self._right_child.DFS()
    


tree = Tree(ONE_MILLION)

NUM_TRIALS = 50
cumulative = 0

for t in range(NUM_TRIALS):
    startTime = time.time_ns()
    tree.DFS()
    endTime = time.time_ns()
    difference = endTime - startTime
    cumulative += difference
    seconds = difference / ONE_BILLION
    print(f"Time to process: {seconds} seconds")
    time.sleep(0.0003)

seconds = cumulative / ONE_BILLION / NUM_TRIALS
print(f"Average time to process: {seconds} seconds")