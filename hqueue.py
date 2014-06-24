# Implement Queue data structure in Python
# first in first out
# functions include:
# push (adds element to end of queue)
# dequeue (takes off the first element and return the value of that element) 
# length
# can only use list primitive

class HQueue():
    def __init__(self):
	self._contents = []

    def push(self, el):
	self._contents.append(el)

    def dequeue(self):
	el = self._contents[0]
	self._contents = self._contents[1:]
	# print self._contents
	return el
    
    def __len__(self):
	return len(self._contents)
