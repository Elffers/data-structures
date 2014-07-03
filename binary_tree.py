class BTree():
    def __init__(self):
	self._root = None

    def push(self, value):
	node = BTree.Node(value)
	if not self._root:
	    self._root = node
	else:
	   current = self._root
	   if current.complete():
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

	def attach(self, node):
	   if self.childless():
	       self.left = node
	   else:
	       self.right = node
