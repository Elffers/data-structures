# Implement Queue data structure in Python
# push
# dequeue
# length
# can only use list primitive

class HQueue():
    def __init__(self):
	self._contents = []

    def push(self, el):
	self._contents.append(el)
