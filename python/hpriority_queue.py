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

class HPriorityQueue():
    def __init__(self):
	self._priorities = {}
    
    def __len__(self):
	count = 0
	for priority in self._priorities:
	    count += len(self._priorities[priority])
	return count

    def push(self,tuple):
	priority, value = tuple
	if self._priorities.has_key(priority):
	    self._priorities[priority].push(value)
	else:
	    hqueue = HQueue()
	    hqueue.push(value)
	    self._priorities[priority] = hqueue

    def dequeue(self):
	priority = min(self._priorities.keys())
	el = self._priorities[priority].dequeue()
	if not self._priorities[priority]:
	    self._priorities.pop(priority)
	return el

    def list_priorities(self):
	return self._priorities.keys()

    def get_queue(self, priority):
	return self._priorities[priority]
