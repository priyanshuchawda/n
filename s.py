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
            if arr[i].name < pivot.name:
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

ans=s1.quicksort(arr)
for i in range(len(ans)):
    print(ans[i].name)