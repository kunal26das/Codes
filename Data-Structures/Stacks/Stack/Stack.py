import msvcrt
import os

stack=[]
top=0
size=5

def main():
    choice=0
    while choice!=4:
        os.system('cls')
        print "\n 1. Push  "
        print " 2. Pop     "
        print " 3. Display "
        print " 4. Exit    "
        choice=int(input("\n Enter>>"))
        if choice==1:
            push()
        elif choice==2:
            pop()
        elif choice==3:
            display()

def push():
    global stack,top,size
    if top<size:
        top=top+1
        stack.append(input("\n Push value : "))
    else:
        print "\n Stack is overflowing!"
        char=msvcrt.getch()

def pop():
    global stack,top
    if top>0:
        print "\n Popped value :",stack.pop()
        top=top-1;
    else:
        print "\n Stack is underflowing!"
    char=msvcrt.getch()

def display():
    global stack,top
    if top>0:
        print "\n The stack is : \n"
        for i in reversed(stack):
            print "   ",i,"\n"
    else:
        print "\n Stack is underflowing!"
    char=msvcrt.getch()

main()
