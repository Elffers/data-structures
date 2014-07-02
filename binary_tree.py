class BTree():
    def __init__(self):
	self._root = None

    def push(self, value):
	node = BTree.Node(value)
	if not self._root:
	    self._root = node
	    node.index = 0
	else:
	    current = self._root

	    

    class Node():
	def __init__(self, value):
	    self.value = value
	    self.index = None
	    self.left = None
	    self.right = None
	
	def complete(self):
	    return self.right is not None and self.left is not None
