import unittest
from hstack import HStack 

class TestHStackFunctions(unittest.TestCase):

	def setUp(self):
		self.stack = HStack()

	def test_push(self):
		self.stack.push(1)
		self.assertEqual(self.stack.contents[0], 1)

	def test_pop(self):
		self.stack.push(1)
		self.stack.push(2)
		self.assertEqual(self.stack.pop(), 2)

	def test_length(self):
		self.stack.push(1)
		self.stack.push("a")
		self.assertEqual(self.stack.length(), 2)

if __name__ == '__main__':
	    unittest.main()
