class Solution:
    def isValid(self, s: str) -> bool:
        closeToOpen = {"}" : "{", ")" : "(", "]" : "["}
        stack = [ ]

        for char in s:
            # if current char is a closing char
            if char in closeToOpen:
                if stack and stack[-1] ==  closeToOpen[char]:
                    stack.pop()
                else:
                    return False 
            # else, current char is an opening char and we append that to stack
            else:
                stack.append(char)

        if stack:
            return False
        else:
            return True 


  