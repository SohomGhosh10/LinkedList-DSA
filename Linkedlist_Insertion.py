class Node:
    def __init__(self , data = None , next = None):
        self.data = data
        self.next = next
    
class Linkedlist:
    def __init__(self):
        self.head = None
    
    def insert_At_begining(self , data):
        node = Node(data , self.head)
        self.head = node
    
    def print(self):    
        if self.head is None:
            print("NULL")
            return 
        else:
            itr = self.head
            llstr = ''
            while itr:
                llstr += str(itr.data)
                itr = itr.next
            print(llstr)
            
    def insert_At_Index(self , index , data):
        node = Node(data)
        ptr = self.head
        i = 0
        
        while i < index - 1:
            ptr = ptr.next
            i += 1
            
        node.next = ptr.next
        ptr.next = node
            
    def insert_At_End(self , data):
        if self.head is None:
            self.head = Node(data , None)
            return
        
        itr = self.head
        while itr.next:
            itr = itr.next
            
        itr.next = Node(data , None)
            
            
if __name__ == '__main__':
    ll = Linkedlist()
    ll.insert_At_begining(18)
    ll.insert_At_begining(45)
    ll.insert_At_End(60)
    ll.insert_At_Index(2 , 20)
    ll.print()
                
                
                
                
            
        
        
        
    