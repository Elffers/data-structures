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
	self._priorities = {}
	self._contents = []
    
    def push(self,tuple):
	priority, value = tuple
	if self._priorities.has_key(priority):
	    self._priorities[priority].append(value)
	else:
	    self._priorities[priority] = [value]
	self._contents.append(value)

    def list_priorities(self):
	return self._priorities.keys()

    def get_queue(self, priority):
	self._priorities[priority]
