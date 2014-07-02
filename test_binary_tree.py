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
