import msvcrt

ch=raw_input("\n Enter a character : ")

n=ord(ch)
if n>=48 and n<=57:
    print "\n '"+ch+"' is a numeral digit. \n"
elif n>=65 and ch<=90:
    print "\n '"+ch+"' is an uppercase alphabet. \n"
elif n>=97 and n<=122:
    print "\n '"+ch+"' is a lowercase alphabet. \n"
else:
    print "\n '"+ch+"' is a special character. \n"
char=msvcrt.getch()
