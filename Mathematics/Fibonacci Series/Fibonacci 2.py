n=input("\n Enter the number of terms to be printed : ")
a,b=0,1
print a
print b
for i in range(0,n-2):
    c=a
    a=b
    b+=c
    print b
