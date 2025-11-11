# Q1-b) Create an employee database (at least 10 records). 
# Database contains different fields of every employee like emp-id, emp-name and emp-salary. 
# a. Arrange list of employees according to EMP-ID in ascending order using Quick Sort.
# b. Arrange list of Employee alphabetically using Merge Sort.

class M:
	def __init__(self, name, salary):
		self.name = name
		self.salary = salary

	def mergesort(self,arr,low,high):
		if(low>=high):
			return
		mid=(low+high)//2
		self.mergesort(arr,low,mid)
		self.mergesort(arr,mid+1,high)
		self.merge(arr,low,mid,high)

		
	def merge(self,arr,low,mid,high):
		left=low
		right = mid+1
		temp = []

		while(left<=mid and right<=high):
			if(arr[left].name>arr[right].name):
				temp.append(arr[right])
				right+=1
			else:
				temp.append(arr[left])
				left+=1
		while(left<=mid):
				temp.append(arr[left])
				left+=1
		while(right<=high):
				temp.append(arr[right])
				right+=1

		for i in range(low,high+1):
			arr[i]=temp[i-low]

	def quicksort(self,arr,low,high):
        if(low<high):
            pivot=self.function(arr,low,high)
            self.quicksort(arr,low,pivot-1)
            self.quicksort(arr,pivot+1,high)

    def function(self,arr,low,high):
        pivot=arr[low].salary
        i=low
        j=high

        while True:
            while(arr[i].salary<=pivot and i<=high-1):
                i+=1
            while(arr[j].salary>pivot and j<=low+1):
                j-=1
            if(i<j):
                arr[i],arr[j]=arr[j],arr[i]
            else:
                break
        arr[low],arr[j]=arr[j],arr[low]
        return j



#----------------------------------------------------
s3= M("pr", 84)
s1 = M("ok",3)
s2= M("pe" , 2)

arr=[s3,s1,s2]

s1.quicksort(arr,0,len(arr)-1)
for i in range(len(arr)):
	print(arr[i].salary)



