class Solution:
    def isValid(self, s: str) -> bool:
        closeToOpen = {"}" : "{", ")" : "(", "]" : "["}
        stack = [ ]

        for char in s:
            # if current char is a closing char
            if char in closeToOpen:
                # if stack exists (there is an opening char in the stack), and if last element in stack (opening char) matches the 
                # closing char closeToOpen[char]
                if stack and stack[-1] ==  closeToOpen[char]:
                    stack.pop()
                # we return false otherwise since if not true it means that its in wrong order
                else:
                    return False 
            # else, current char is an opening char and we append that to stack
            else:
                stack.append(char)

        # if the stack is non-empty we know that the opening and closing chars did not all have a match, so we return False
        if stack:
            return False
        # else, all the opening and closing chars have a match and we return True 
        else:
            return True 


  