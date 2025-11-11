# Construct Smart Library Management System: 
# Implementation and Comparison of Linear and Binary Search Algorithms 
# for Locating Books in an Unsorted Book Database.

class library:
	def __init__(self):
		self.arr=[]
	def insert(self,book):
		self.arr.append(book)
	def linears(self,key):
		for i in range(len(self.arr)):
			if(self.arr[i]==key):
				return True
		return False

	def binarys(self,key):
		for i in range(1,len(self.arr)):
			self.kkey = self.arr[i]
			j=i-1
			while(j>=0 and self.kkey<self.arr[j]):
				self.arr[j+1]=self.arr[j]
				j-=1
			self.arr[j+1]=self.kkey


		low=0
		high = len(self.arr)-1
		while(high>low):
			mid = (low+high)//2
			if(self.arr[mid]==key):
				return True
			elif(self.arr[mid]>key):
				high=mid-1
			else:
				low=mid+1
		return False

s1=library()
s1.insert("abc")
s1.insert("aaf")
s1.insert("aaaje")

print(s1.binarys("af"))
