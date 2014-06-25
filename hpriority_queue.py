# Priority Queue
# methods:
# get_queue(priority) should return queue of values
# push 
# dequeue
# len()
# list priorities

# if need to import a file not in cwd, import sys and then sys.path.append
# sys.path.append("/somedir/somesubdir")

# other (better) options are to put file in cwd or create python egg

from hqueue import HQueue

class HPriorityQueue(HQueue):
    def __init__(self):
	self._priorities = []
	self._contents = []
    
    def push(self,tuple):
	priority, value = tuple
	self._contents.append(value)

    def get_queue(self, priority):
	self._priorities[priority]
