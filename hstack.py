'''
	implementing a stack data structure
	functions: 
		push (return nothing),
		pop (should return the element),
		length
'''

class HStack():
	contents = []

	def push(self, el):
		self.contents.append(el)
