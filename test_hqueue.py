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

    def test_dequeue_empty(self):
	with self.assertRaises(IndexError):
	    self.hqueue.dequeue()
    
#   def test_next(self):
#	self.hqueue.push(1)
#	self.hqueue.push(2)
#	self.assertEqual(self.hqueue.next(), 1)
#	self.assertEqual(self.hqueue.next(), 2)
    
#    def test_next_on_empty(self):
#	with self.assertRaises(StopIteration):
#	    self.hqueue.next()

    # def test_iter(self):
#	test_values = [1, 2, 3]
#	for test_value in test_values:
#	    self.hqueue.push(test_value)
#	for element, test_value in self.hqueue, test_values:
#	    self.assertEquals(element, test_value)
