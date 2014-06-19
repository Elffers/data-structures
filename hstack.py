'''
    implementing a stack data structure
    functions: 
	push (return nothing),
	pop (should return the element),
	length
'''

class HStack():
    def __init__(self, max=None):
    	self._contents = []
	if max is None:
	    self._max = 20
	else:
	    self._max = max

    def push(self, el):
    	self._contents.append(el)
    
    def pop(self):
	if self.length == 0:
	    raise IndexError
	else:
	    last = self._contents[-1]
	    self._contents.pop()
	return last

    ## this uses the @property decorator to define 'length' as an attribute of
    ## an instance, so you can call hstack.length as opposed to calling
    ## hstack.length() as a function.

    @property
    def length(self):
	return len(self._contents)

    ## the following allows you to call len(hstack) to return the length
    ## def __len__(self);
    ##	    return len(self._contents)
