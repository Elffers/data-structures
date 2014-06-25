# Priority Queue
# methods:
# get_queue(priority) should return queue of values
# push 
# dequeue
# len()
# list priorities

from hqueue import HQueue

class HPriorityQueue(HQueue):
    def __init__(self):
	self._priorities = []
	self._contents = []
