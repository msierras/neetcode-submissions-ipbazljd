class MinStack:

    def __init__(self):
        self.stack = []      # array for stack
        self.minStack = []   # array for minimum value of stack

    def push(self, val: int) -> None:
        self.stack.append(val)   # we MUST append val to stack so this is the first thing we do in def push

        if not(self.minStack):
            self.minStack.append(val)
        elif self.minStack and val <= self.minStack[-1]:
            self.minStack.append(val)


    def pop(self) -> None:
        # if stack's top and minStack's top are the same then we pop both
        if(self.stack and self.minStack and self.stack[-1] == self.minStack[-1]):
            self.stack.pop()
            self.minStack.pop()
        # else, we only delete the top value of stack 
        else:
            self.stack.pop()

    def top(self) -> int:
        return self.stack[-1]   # returning the "top" item can also be interpreted as the last item of the stack

    def getMin(self) -> int:
        return self.minStack[-1] # only one minimum can exist at a time, thus we can return the last item of minStack
