import unittest
from hqueue import HQueue

class TestHQueueFunctions(unittest.TestCase):
    def setUp(self):
	self.hqueue = HQueue()
    
    def test_push(self):
	self.hqueue.push(1)
	self.assertEqual(self.hqueue._contents[0], 1)
