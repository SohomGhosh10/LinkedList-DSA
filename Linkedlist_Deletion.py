class Node:
    def __init__(self , data = None , next = None):
        self.data = data
        self.next = next
        
class linkedlist:
    def __init__(self):
        self.head = None
        
    def insert_At_First(self , data):
        node = Node(data , self.head)
        self.head = node
        
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
        
        else:
            itr = self.head
            while itr.next:
                itr = itr.next
                
            itr.next = Node(data , None)
            
    def delete_At_First(self):
        ptr = self.head
        self.head = self.head.next
        ptr = None
        
    def delete_At_End(self):
        ptr = self.head
        while ptr.next.next:
            ptr = ptr.next
            ptr = None
            
    def delete_At_Index(self , position):
        i = 0
        ptr = self.head
        
        while i < position - 1:
            ptr = ptr.next
            i += 1
            
        p = ptr.next
        ptr.next = p.next
        p = None
        
    def print(self):
        while self.head:
            print(self.head.data)
            self.head = self.head.next
            
if __name__ == '__main__':
    ll = linkedlist()
    ll.insert_At_End(12)
    ll.insert_At_End(76)
    ll.insert_At_End(87)
    ll.insert_At_First(65)
    ll.insert_At_First(43)
    ll.insert_At_Index(2 , 23)
    ll.insert_At_Index(0 , 565)
    ll.delete_At_Index(0)
    ll.delete_At_First()
    ll.print()
                