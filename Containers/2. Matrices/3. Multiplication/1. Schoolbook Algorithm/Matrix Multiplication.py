import msvcrt
import os

a=[]
print "\n Matrix A : "
m=int(input("\n Rows     : "))
n=int(input("\n Columns  : "))

b=[]
print "\n Matrix B : "
p=int(input("\n Rows     : "))
q=int(input("\n Columns  : "))

if n==p:
    print("\n Matrix multiplication is possible")
    char=msvcrt.getch()
    os.system('cls')
else:
    print "\n Matrix multiplication not possible"
    char=msvcrt.getch()
    exit()
    
print("\n Enter the elements of matrix A : ")
for i in range(0,m):
    a.append([])
    for j in range(0,n):
        a[i].append(input())
    print(" ")

print("\n Enter the elements of matrix B : ")
for i in range(0,p):
    b.append([])
    for j in range(0,q):
        b[i].append(input())
    print(" ")

c=[]
for i in range(0,m):
    c.append([])
    for j in range(0,q):
        temp=0
        for k in range(0,n):
            temp+=a[i][k]*b[k][j]
        c[i].append(temp)

os.system('cls')

print("\n Matrix A : \n")
for i in range(0,m):
    print a[i],"\n"

print("\n Matrix B : \n")
for i in range(0,p):
    print b[i],"\n"

print("\n Matrix C : \n")
for i in range(0,m):
    print c[i],"\n"

char=msvcrt.getch()
