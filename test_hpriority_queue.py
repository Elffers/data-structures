import unittest
from hqueue import HQueue
from hpriority_queue import HPriorityQueue

class TestHPriorityQueue(unittest.TestCase):
    def setUp(self):
	self.hpq = HPriorityQueue()

    def test_push(self):
	self.hpq.push(1)
	self.assertEqual(self.hpq._contents[0], 1)

    def test_dequeue(self):
	self.hpq.push(1)
	self.assertEqual(self.hpq.dequeue(), 1)
