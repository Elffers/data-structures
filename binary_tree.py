class BTree():
    def __init__(self):
	self._root = None
	self._last = None

    def push(self, value):
	node = BTree.Node(value)
	if not self._root:
	    self._root = node
	    node.index = 0
	else:
	   current = self._root
	   if current.childless():
	       current.left = node
	       node.index = current.index + 1
	       self._last = node
	   elif current.left and not current.right:
	       current.right = node
	       node.index = current.left.index + 1
	       self._last = node
	   elif current.complete():
	       current = current.left
	    

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
