import java.util.Scanner;

class Matrix_Multiplication
{
	public void main(String args[])
	{
		Scanner s=new Scanner(System.in);

		int a[][]=new int[3][3];
		int b[][]=new int[3][3];
		int c[][]=new int[3][3];

		int m,n, p,q, i,j,k;

		System.out.print("\n Matrix A : \n");
		System.out.print("\n Rows     : ");
		m=s.nextInt();
		System.out.print("\n Columns  : ");
		n=s.nextInt();

		System.out.print("\n Matrix B : \n");
		System.out.print("\n Rows     : ");
		p=s.nextInt();
		System.out.print("\n Columns  : ");
		q=s.nextInt();

		if(n==p)
		{
			System.out.print("\n Matrix multiplication is possible \n");

			System.out.print("\n Enter the elements of matrix A : \n\n");
			for(i=0;i<m;i++)
			{
				System.out.print(" ");
				for(j=0;j<n;j++)
				{
					a[i][j]=s.nextInt();
					for(k=0;k<=j;k++)
						System.out.print("\t");
				}
				System.out.print("\n");
			}

			System.out.print("\n Enter the elements of matrix B : \n\n");
			for(i=0;i<p;i++)
			{
				System.out.print(" ");
				for(j=0;j<q;j++)
				{
					b[i][j]=s.nextInt();
					for(k=0;k<=j;k++)
						System.out.print("\t");
				}
				System.out.print("\n");
			}

			for(i=0;i<m;i++)
				for(j=0;j<q;j++)
				{
					c[i][j]=0;
					for(k=0;k<n;k++)
						c[i][j]+=a[i][k]*b[k][j];
				}

			System.out.print("\n Matrix A : \n\n");
			for(i=0;i<m;i++)
			{
				for(j=0;j<n;j++)
					System.out.print(" "+a[i][j]+"\t");
				System.out.print("\n\n");
			}

			System.out.print("\n Matrix B : \n\n");
			for(i=0;i<p;i++)
			{
				for(j=0;j<q;j++)
					System.out.print(" "+b[i][j]+"\t");
				System.out.print("\n\n");
			}

			System.out.print("\n Matrix C : \n\n");
			for(i=0;i<m;i++)
			{
				for(j=0;j<q;j++)
					System.out.print(" "+c[i][j]+"\t");
				System.out.print("\n\n");
			}

		}
		else System.out.print("\n Matrix multiplication not possible \n");
	}
}