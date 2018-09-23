x  = int(input("\n Enter first number  : "))

y  = int(input("\n Enter second number : "))

print("\n 1. Addition")

print("\n 2. Subtraction")

print("\n 3. Multiplication")

print("\n 4. Division")

ch = int(input("\n Enter operation     : "))

print("\n Result = ")

if ch==1 :
    result = x+y
    print(result)
    
elif ch==2 :
    result = x-y
    print(result)
    
elif ch==3 :
    result = x*y
    print(result)
    
elif ch==4 :
    result = x/y
    print(result)
    
else :
    print("Error!")
    
ch=chr(input())

