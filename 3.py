# Create a hash table for storing employee records (ID, Name).
# Implement collision handling using both linear probing and chaining. 
# Compare the performance.

import time

class probing:
    def __init__(self,n):
        self.n=n
        self.table=[None]*self.n
    def linearprobing(self,value,n,name):
        self.value=value
        self.name=name
        self.index = self.value % self.n 
        if self.table[self.index] is None:
            self.table[self.index]=(self.value,self.name)
        else:
            while(self.table[self.index] is not None):
                self.index=(self.index+1)%n
            self.table[self.index]=(self.value,self.name)

    def probingprint(self):
        for i in range (self.n):
            print(self.table[i] , end = " ")
        print("")

class chaining:
    def __init__(self,n):
        SIZE=30
        self.n=n
        self.table = []*SIZE
        for i in range(self.n):
            self.table.append([])
    def linearchaining(self,value,n,name):
        self.name=name
        self.value=value
        self.index = self.value % self.n
        self.table[self.index].append((self.value,self.name))
    def chainingprint(self):
        for i in range(self.n):
            print (i, "-> ", end = "")
            for j in range(len(self.table[i])):
                print(self.table[i][j] , end = "->")
            print("None")

#------------------------------------------------------

s1 = probing(10)
s2 = chaining(10)

start = time.time()
for i in range(10,40,5):
    s1.linearprobing(i,10,"ok")

s1.probingprint()
end = time.time()


diff = end-start

start1 = time.time()
for i in range(10,40,5):
    s2.linearchaining(i,10,"ok")
s2.chainingprint()
end1 = time.time()

diff1 = end1-start1
print("")
print ("time =", abs(diff - diff1))


