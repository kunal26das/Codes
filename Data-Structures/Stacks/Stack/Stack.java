import java.util.Scanner;

class Stack
{
	static Scanner s=new Scanner(System.in);
	
	static int stack[]=new int[10];
	static int top=0,size=5;
	
	public static void main(String args[])
	{
		int choice;
		do
		{
			System.out.print("\n 1. Push ");
			System.out.print("\n 2. Pop ");
			System.out.print("\n 3. Display ");
			System.out.print("\n 4. End Program ");
			System.out.print("\n Enter>>");
			choice=s.nextInt();
			switch(choice)
			{
				case 1 : push(); 	break;
				case 2 : pop();  	break;
				case 3 : display(); break;
			}
		}while(choice!=4);
	}
	
	public static void push()
	{
		if(top<size)
		{
			top+=1;
			System.out.print("\n Push : ");
			stack[top]=s.nextInt();
		}
		else
		 System.out.print("\n Stack is overflowing! \n");
	}
	
	public static void pop()
	{
		if(top>0)
		{
			System.out.print("\n Popped value : "+stack[top]+"\n");
			top=top-1;
		}
		else
         System.out.print("\n Stack is underflowing! \n");
	}
	
	public static void display()
	{
		if(top>0)
		{
			System.out.print("\n The stack is : \n\n");
			for(int i=top;i>0;i--)
		     System.out.print(" "+stack[i]+"\n\n");
		}
		else
         System.out.print("\n Stack is underflowing! \n");
	}
}