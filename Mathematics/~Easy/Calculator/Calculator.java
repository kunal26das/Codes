import java.util.Scanner;

class calculator
{
	public static void main(String args[])
	{
		Scanner s=new Scanner(System.in);

		float a,b,c;
		char ch;

		System.out.print("\n Enter first no.  = ");
		a=s.nextFloat();

		System.out.print("\n Enter second no. = ");
		b=s.nextFloat();

		System.out.print("\n Enter operation  = ");
		ch=s.next().charAt(0);

		switch(ch)
		{
			case '+': c=a+b;
			System.out.print("\n "+a+" + "+b+" = "+c);
			break;

			case '-': c=a-b;
			System.out.print("\n "+a+" - "+b+" = "+c);
			break;

			case '*': c=a*b;
			System.out.print("\n "+a+" * "+b+" = "+c);
			break;

			case '/': c=a/b;
			System.out.print("\n "+a+" / "+b+" = "+c);
			break;

			default:
			System.out.print("\n Error!");
			break;
		}

		System.out.print("\n");
	}
}