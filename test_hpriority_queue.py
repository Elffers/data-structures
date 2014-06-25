import unittest
from hqueue import HQueue
from hpriority_queue import HPriorityQueue

class TestHPriorityQueue(unittest.TestCase):
    def setUp(self):
	self.hpq = HPriorityQueue()

    def test_push(self):
	self.hpq.push([1,5])
	self.assertEqual(self.hpq._contents[0], 5)

    def test_dequeue(self):
	self.hpq.push([1,5])
	self.assertEqual(self.hpq.dequeue(), 5)

    def test_list_priorities(self):
	self.hpq.push([1,5])
	self.hpq.push([2,3])
	self.assertEqual(self.hpq.list_priorities(), [1,2])

    def test_get_priorities(self):
	self.hpq.push([1,5])
	self.hpq.push([2,3])
	self.hpq.push([1, 7])
	self.assertEqual(self.hpq.get_queue(1)._contents, [5, 7])
