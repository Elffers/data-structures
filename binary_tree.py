from hqueue import HQueue
class BTree():
    def __init__(self):
        self._root = None

    def push(self, value):
        node = BTree.Node(value)
        if not self._root:
            self._root = node
        else:
            target = None
            nodes = self._breadth_traversal()._contents
            for	x in nodes:
                if not x.complete():
                    target = x
                    break
            target.attach(node)

    def breadth_first_traversal(self):
        """ returns values of nodes returned breadth-first """
        return [node.value for node in self._breadth_traversal()._contents]

    def _breadth_traversal(self):
        """ returns queue containing Node objects """
        queue = HQueue()
        queue.push(self._root)
        i = 0
        while i < len(queue._contents):
            el = queue._contents[i]
            if not el.childless():
                queue.push(el.left)
                if el.right:
                    queue.push(el.right)
            i += 1
        return queue

    class Node():
        def __init__(self, value):
            self.value = value
            self.index = None
            self.left = None
            self.right = None

        def complete(self):
            return self.right is not None and self.left is not None

        def childless(self):
            return self.right is None and self.left is None

        def children(self):
            children = []
            if not self.childless():
                children.append(self.left.value)
                if self.right:
                    children.append(self.right.value)
            return children

        def attach(self, node):
            if self.childless():
                self.left = node
           else:
               self.right = node
