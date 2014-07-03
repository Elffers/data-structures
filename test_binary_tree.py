import unittest
from binary_tree import BTree

class TestBtree(unittest.TestCase):
    def setUp(self):
	self.btree = BTree()
	self.node = BTree.Node(1)

    def test_node_complete(self):
	self.node.left = BTree.Node(2)
	self.node.right = BTree.Node(3)
	self.assertEqual(self.node.complete(), True)

    def test_node_incomplete(self):
	self.node.left = BTree.Node(2)
	self.assertEqual(self.node.complete(), False)

    def test_set_root(self):
	self.btree.push(10)
	self.assertEqual(self.btree._root.value, 10)
#	self.assertEqual(self.btree._root.index, 0)

    def test_push_on_leaf(self):
	self.btree.push(self.node)
	self.btree.push(2)
	self.assertEqual(self.btree._root.left.value, 2)
#	self.assertEqual(self.btree._last.index, 1)

    def test_push_on_left_filled(self):
	self.btree.push(self.node)
	self.btree.push(2)
	self.btree.push(3)
	self.assertEqual(self.btree._root.right.value, 3)
#	self.assertEqual(self.btree._root.left.index, 1)
#	self.assertEqual(self.btree._root.right.index, 2)
    
    def test_push_on_complete(self):
	self.btree.push(self.node)
	self.btree.push(2)
	self.btree.push(3)
	self.btree.push(4)
	self.assertEqual(self.btree._root.left.left.value, 4)
    
    def test_push_to_6(self):
	self.btree.push(self.node)
	self.btree.push(2)
	self.btree.push(3)
	self.btree.push(4)
	self.btree.push(5)
	self.btree.push(6)
	self.assertEqual(self.btree._root.left.right.value, 5)
	#self.assertEqual(self.btree._root.right.left.value, 6)

    def test_breadth_first_traversal(self):
	self.btree.push(1)
	self.btree.push(2)
	self.btree.push(3)
	self.btree.push(4)
	self.btree.push(5)
	self.assertEqual(self.btree.breadth_first_traversal(), [1, 2, 3, 4, 5])

    def test_breadth_traversal(self):
	self.btree.push(1)
	self.btree.push(2)
	self.btree.push(3)
	self.btree.push(4)
	self.btree.push(5)
	self.assertEqual(len(self.btree._breadth_traversal()._contents), 5)

    def test_node_has_children(self):
	self.btree.push(1)
	self.btree.push(2)
	self.btree.push(3)
	self.assertEqual(self.btree._root.children(), [2, 3])

