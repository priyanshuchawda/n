# Q1-b) Create an employee database (at least 10 records). 
# Database contains different fields of every employee like emp-id, emp-name and emp-salary. 
# a. Arrange list of employees according to EMP-ID in ascending order using Quick Sort.
# b. Arrange list of Employee alphabetically using Merge Sort.

class M:
	def __init__(self,name,salary):
		self.name=name
		self.salary=salary
    def quicksort(self, arr):
        if len(arr) <= 1:
            return arr

        pivot = arr[0]      # first element as pivot
        left = []           # smaller values
        right = []          # greater values

        for i in range(1, len(arr)):
            if arr[i] < pivot:
                left.append(arr[i])
            else:
                right.append(arr[i])

        # sort left and right parts recursively
        sorted_left = self.quicksort(left)
        sorted_right = self.quicksort(right)

        return sorted_left + [pivot] + sorted_right




s3= M("pr", 1)
s1 = M("ok",3)
s2= M("pe" , 2)

arr=[s3,s1,s2]

s1.quicksort(arr,0,len(arr)-1)
for i in range(len(arr)):
	print(arr[i].name)