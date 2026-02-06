arr=[14,5,6,4,3,3]
for i in range(len(arr)):
    if arr[i]==2:
        print("element found")
        break

print(len(arr))

#reverse an array
j=len(arr)-1
for i in range(len(arr)//2):
    temp=arr[i]
    arr[i]=arr[j]
    arr[j]=temp
    j=j-1
print(arr)

#max and min
max=arr[0]
min=arr[0]
for i in range(len(arr)):
    if(max<arr[i]):
        max=arr[i]
    if(min>arr[i]):
        min=arr[i]
print(max)
print(min)

#count frequency
count=[0]*len(arr)
visited=[False]*len(arr)
for i in range(0,len(arr)):
    if visited[i]:
        continue
    freq=1
    for j in range(i+1,len(arr)):
        if arr[i]==arr[j]:
            freq+=1
            visited[j]=True
    count[i]=freq
for i in range(0,len(arr),1):
    if not visited[i]:
        print(arr[i],"=",count[i])


#to find the second largest
largest=arr[0]
for i in range(len(arr)):
   if(largest<arr[i]):
       largest=arr[i]
slarge=float('-inf')
for i in range(len(arr)):
    if(arr[i]!=largest and slarge<arr[i]):
        slarge=arr[i]
print("slarge",slarge)