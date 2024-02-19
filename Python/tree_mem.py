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


class Node:
    def __init__(self, p):
        self._left_child = None
        self._right_child = None
        self._parent = p
        self._data = "a"
    


tree = Tree(100000)
print("done")
input()