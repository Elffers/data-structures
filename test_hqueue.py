import unittest
from hqueue import HQueue

class TestHQueueFunctions(unittest.TestCase):
    def setUp(self):
	self.hqueue = HQueue()
    
    def test_push(self):
	self.hqueue.push(1)
	self.assertEqual(self.hqueue._contents[0], 1)

    def test_dequeue(self):
	self.hqueue.push(1)
	self.hqueue.push(2)
	self.assertEqual(self.hqueue.dequeue(), 1)

    def test_length(self):
	self.hqueue.push(1)
	self.hqueue.push(2)
	self.assertEqual(len(self.hqueue), 2)

    def test_push_after_dequeue(self):
	self.hqueue.push(1)
	self.hqueue.push(2)
	self.hqueue.dequeue()
	self.hqueue.push(3)
	self.assertEqual(self.hqueue.dequeue(),2)
