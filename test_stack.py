import unittest
from hstack import HStack 

class TestHStackFunctions(unittest.TestCase):

	def setUp(self):
		self.stack = HStack()
		self.stack10 = HStack(10)
		self.stack1 = HStack(1)

	def test_push(self):
		self.stack.push(1)
		self.assertEqual(self.stack._contents[0], 1)

	def test_push_on_max(self):
		self.stack1.push(1)
		with self.assertRaises(IndexError):
			self.stack1.push(1)

	def test_pop(self):
		self.stack.push(1)
		self.stack.push(2)
		self.assertEqual(self.stack.pop(), 2)

	def test_pop_on_empty(self):
		with self.assertRaises(IndexError):
			self.stack.pop()
	def test_pop_and_push_maintains_order(self):
		self.stack.push(1)
		self.stack.push(2)
		self.stack.pop()
		self.stack.push(3)
		self.assertEqual(self.stack._contents, [1, 3])

	def test_length(self):
		self.stack.push(1)
		self.stack.push("a")
		self.assertEqual(self.stack.length, 2)

	def test_max(self):
		self.assertEqual(self.stack._max, 20)
		self.assertEqual(self.stack10._max, 10)
		
# this is so you can run this as a python script independent of nosetests
if __name__ == '__main__':
	    unittest.main()
