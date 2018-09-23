def getSubArrays(array):
    sub = []
    n = len(array)
    for i in range(1,n+1):
        index = n-i
        for j in range(0,index+1):
            sub.append(array[j:j+i])
    return sub

array = [1, 2, 3, 4, 5]
subarrays = getSubArrays(array)
for arrays in subarrays:
    print(arrays)
