'''
	implementing a stack data structure
	functions: 
		push (return nothing),
		pop (should return the element),
		length
'''

class HStack():
	def __init__(self):
		self.contents = []

	def push(self, el):
		self.contents.append(el)

	def pop(self):
		last = self.contents[-1]
		self.contents.pop()
		return last

	def length(self):
		return len(self.contents)
