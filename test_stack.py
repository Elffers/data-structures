import unittest
from hstack import HStack 

class TestHStackFunctions(unittest.TestCase):

	def setUp(self):
		self.stack = HStack()

	def test_push(self):
		self.stack.push(1)
		self.assertEqual(self.stack.contents[0], 1)
		
if __name__ == '__main__':
	    unittest.main()
