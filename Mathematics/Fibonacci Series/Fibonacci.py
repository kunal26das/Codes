n=input("\n Enter the range : ")
a,b=0,1
for i in range(0,n):
    if n>a:
        c=a+b
        print a
        a=b
        b=c
    else:
        break


    
