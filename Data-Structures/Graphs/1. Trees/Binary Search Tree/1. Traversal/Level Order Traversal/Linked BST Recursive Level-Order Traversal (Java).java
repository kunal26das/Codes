import java.util.Scanner;

class binary
{
	static class vertex
	{
		int value;
		vertex left;
		vertex right;
		public vertex(int _value) 
		{
			left=null;
			right=null;
			value=_value;
		}
	}

	static vertex root;
	binary(){root=null;}
	public static boolean exists()
	{
		if(root==null)
		return false;
		return true;
	}

	private static vertex insert(vertex ptr,int value) 
	{
		if(ptr==null) ptr=new vertex(value);
		else if(value<ptr.value) 
			ptr.left=insert(ptr.left,value);
		else if(value>ptr.value)
			ptr.right=insert(ptr.right,value);
		return ptr;
	}
	public static void insert(int value)
	{root=insert(root,value);}

	private static int height(vertex ptr,int h)
	{
		int left=h,right=h;
		if(ptr==null) return h;
		if(ptr.left!=null) left=height(ptr.left,h+1);
		if(ptr.right!=null) right=height(ptr.right,h+1);
		return left>right?left:right;
	}
	public static int height()
	{return height(root,0);}

	private static void levelorder(vertex ptr,int level)
	{
		if(ptr==null) return;
		if(level==0) System.out.print(ptr.value+", ");
		else
		{
			levelorder(ptr.left,level-1);
			levelorder(ptr.right,level-1);
		}
	}
	public static void levelorder()
	{
		int h=height();
		for(int i=0;i<=h;i++)
		{
			levelorder(root,i);
			System.out.print(" ");
		}
	}
	
	static Scanner read=new Scanner(System.in);
	public static void main(String[] args) 
	{
		int ch,value;
		do
		{
			System.out.print("\n 1. Insert ");
			System.out.print("\n 2. Height ");
			System.out.print("\n 3. Level-Order ");
			System.out.print("\n 4. End Program ");
			System.out.print("\n\n Enter>>");
			ch=read.nextInt();
			switch(ch)
			{
				case 1 :
				System.out.print("\n Enter a value : ");
				value=read.nextInt();
				insert(value);
				break;

				case 2 :
				System.out.print("\n Tree is of height ");
				if(exists()) System.out.print(height());
				else System.out.print("-1");
				break;

				case 3 :
				System.out.print("\n Tree is : ");
				if(exists()) levelorder();
				else System.out.print("empty!");
				break;
			}
			System.out.println();
		}while(ch!=4);
	}
}