class LinkedList:
    
    def __init__(self):
        self.linked_list = [] # empty list named self.linked_list. 
        self.temp_list = []       # where we put head 
    
    def get(self, index: int) -> int:
        if index < len(self.linked_list): # if index is within bounds 
            return self.linked_list[index]
        else:                      # when index is out of bounds return -1
            return -1 
        

    def insertHead(self, val: int) -> None:
        self.temp_list.append(val)
        for i in range(0, len(self.linked_list)):
            self.temp_list.append(self.linked_list[i])
        self.linked_list = self.temp_list
        self.temp_list = [] 

    def insertTail(self, val: int) -> None:
        self.linked_list.append(val)


    def remove(self, index: int) -> bool:
        if index < len(self.linked_list) :
            self.linked_list.pop(index)
            return True 
        else:
            return False 

    def getValues(self) -> List[int]:
        return self.linked_list 
