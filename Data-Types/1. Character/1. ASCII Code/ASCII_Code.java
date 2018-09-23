import java.util.Scanner;

class ASCII
{
    public static void main(String args[])
    {
        Scanner s=new Scanner(System.in);
        
        char ch;        
        System.out.print("\n Enter a character : ");
        ch=s.next().charAt(0);
        
        int n=ch;
        System.out.print("\n ASCII code of '"+ch+"' is "+n+".\n");
    }
}