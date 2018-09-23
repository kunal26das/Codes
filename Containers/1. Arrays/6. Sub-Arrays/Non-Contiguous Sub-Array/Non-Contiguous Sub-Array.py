def getSubArrays(array):
    sub = []
    for a in array:
        temp = []
        for s in sub:
            temp.append(s+[a])
        sub = sub+temp
        sub.append([a])
    sub.sort(key = len)
    return sub

array = [1, 2, 3, 4, 5]
subarrays = getSubArrays(array)
for arrays in subarrays:
    print(arrays)
