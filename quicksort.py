def partition(arr,start,end):
    count = 0
    for i in range(start+1,end+1):
        if arr[i] < arr[start]:
            count += 1
    arr[start],arr[start+count] = arr[start+count],arr[start]
    index = start + count
    i = start
    j = end
    while i < index:
        if arr[i]<arr[index]:
            i+=1
        else:
            while j > index:
                if arr[j]>=arr[index]:
                    j -= 1
                else:
                    arr[i],arr[j] = arr[j],arr[i]
                    break
    return index

def quickSort(arr, start, end):
    l = len(arr[start:end])
    if l == 0 or l == 1:
        return arr
    index = partition(arr,start,end-1)
    quickSort(arr,start,index)
    quickSort(arr,index+1,end)

n=int(input())
arr=list(int(i) for i in input().strip().split(' '))
quickSort(arr, 0, n)
print(*arr)
