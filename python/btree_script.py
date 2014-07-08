from binary_tree import BTree

b = BTree()
b.push(1)
b.push(2)
b.push(3)
print b._root.childless()
print b.breadth_first_traversal()
