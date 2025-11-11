# Consider a student database of SY computer class (at least 10 records). 
# Database contains different fields of every student like Roll No, Name and SGPA.
# Implement the following using insertion sort 
#a. Arrange list of students according to roll numbers in ascending order. 
#b. Organize the list of students alphabetically.
#c. Arrange list of students to identify five toppers from a class.

class Student:
	def __init__(self):
		self.arr = []
		
	def add_student(self,roll,name,sgpa):
		self.roll=roll
		self.name=name
		self.sgpa=sgpa
		self.arr.append((self.roll , self.name, self.sgpa))		

	#[4,2,6,8,3]
	#[]

	def insertion(self):
		for i in range(1,len(self.arr)):
			j=i-1
			key = self.arr[i]
			while(j>=0 and self.arr[j][0]>key[0]):
				self.arr[j+1]=self.arr[j]
				j-=1
			self.arr[j+1]=key

	def printt(self):
		for i in self.arr:
			print (i)
#--------------------------------------------------------------
db=Student()
            

db.add_student(12, "Shruti", 8.5)
db.add_student(7, "Madhura", 9.2)
db.add_student(3, "Priyanshu", 7.8)
db.add_student(18, "Chawda", 9.0)
db.add_student(5, "Aditya", 8.9)
db.add_student(10, "Ariv", 7.6)
db.add_student(4, "Puja" , 5.5)

db.insertion()
db.printt()


