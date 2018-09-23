import java.util.Scanner;

class Identifier
{
    public static void main(String args[])
    {
        Scanner s=new Scanner(System.in);
        
        char ch;
        System.out.print("\n Enter a character : ");
        ch=s.next().charAt(0);
        
        if(ch>=48 && ch<=57)
         System.out.print("\n '"+ch+"' is a numeral digit. \n");
        else if(ch>=65 && ch<=90)
         System.out.print("\n '"+ch+"' is an uppercase alphabet. \n");
        else if(ch>=97 && ch<=122)
         System.out.print("\n '"+ch+"' is a lowercase alphabet. \n");
        else
         System.out.print("\n '"+ch+"' is a special character. \n");
    }
}