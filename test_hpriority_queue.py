import unittest
from hqueue import HQueue
from hpriority_queue import HPriorityQueue

class TestHPriorityQueue(unittest.TestCase):
    def setUp(self):
	self.hpq = HPriorityQueue()

    def test_length(self):
	self.hpq.push([2,3])
	self.hpq.push([1,5])
	self.assertEqual(len(self.hpq), 2)

    def test_push(self):
	self.hpq.push([1,5])
	self.hpq.push([2,3])
	self.hpq.push([1,2])
	self.assertEqual(self.hpq.dequeue(),5)
	self.assertEqual(self.hpq.dequeue(),2)
	self.assertEqual(self.hpq.dequeue(),3)

    def test_dequeue(self):
	self.hpq.push([1,1])
	self.hpq.push([2,3])
	self.hpq.push([1,2])
	self.assertEqual(self.hpq.dequeue(), 1)
	self.assertEqual(self.hpq.dequeue(), 2)
	self.assertEqual(self.hpq.dequeue(), 3)

    def test_list_priorities(self):
	self.hpq.push([1,5])
	self.hpq.push([2,3])
	self.hpq.push([1,7])
	self.hpq.push([2,4])
	self.assertEqual(self.hpq.list_priorities(), [1,2])

    def test_get_priorities(self):
	self.hpq.push([1,5])
	self.hpq.push([2,3])
	self.hpq.push([1,7])
	self.assertEqual(self.hpq.get_queue(1)._contents, [5, 7])
	self.assertEqual(self.hpq.get_queue(2)._contents, [3])
