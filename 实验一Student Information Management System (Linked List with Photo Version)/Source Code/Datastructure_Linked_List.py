class Student:

    def __init__(self,ID,name,sex,age,image):
        self.ID=ID
        self.name=name
        self.sex=sex
        self.age=age
        self.image=image

class Node(object):
    
    def __init__(self,data):
        self.data=data
        self.next=None

class LinkedList(object):

    def __init__(self):
        self.head=None

    def clear(self):
        self.head=None

    def len(self):
        ans=0
        cur_node=self.head
        while cur_node is not None:
            ans+=1
            cur_node=cur_node.next
        return ans

    def init_list(self,list):
        self.head=Node(list[0])
        cur_node=self.head
        for i in range (1,len(list)):
            nex_node=Node(list[i])
            cur_node.next=nex_node
            cur_node=cur_node.next

    def add(self,student):
        add_node=Node(student)
        if self.head==None:
            self.head=add_node
        else:
            iterator=self.head
            while iterator.next!=None:
                iterator=iterator.next
            iterator.next=add_node

    def remove(self,key):
        cur_node=self.head
        pre_node=self.head  
        while cur_node!=None:
            if key==cur_node.data.ID or key==cur_node.data.name:
                pre_node.next=cur_node.next
                return
            else:
                pre_node=cur_node
                cur_node=cur_node.next

    def change(self,student):
        iterator=self.head
        while iterator!=None:
            if student.ID==iterator.data.ID or student.name==iterator.data.name:
                iterator.data.ID=student.ID
                iterator.data.name=student.name
                iterator.data.sex=student.sex
                iterator.data.age=student.age
                iterator.data.image=student.image
                return True
            else:
                iterator=iterator.next
        return False

    def traverse(self):
        iter_list=[]
        iterator=self.head
        while iterator is not None:
            iter_list.append(iterator.data)
            iterator=iterator.next
        return iter_list