using System;

namespace Calculator
{
	class Calculator
	{
		static void Main(string[] args)
		{
			float a, b, c;
			char ch;

			Console.Write("\n Enter first no.: ");
			a = float.Parse(Console.ReadLine());

			Console.Write("\n Enter second no. : ");
			b = float.Parse(Console.ReadLine());

			Console.Write("\n Input Operation: ");
			ch = char.Parse(Console.ReadLine());

			switch (ch)
			{
				case '+': c = a + b;
				Console.Write("\n " + a + " + " + b + " = " + c);
				break;

				case '-': c = a - b;
				Console.Write("\n " + a + " - " + b + " = " + c);
				break;

				case '*': c = a * b;
				Console.Write("\n " + a + " * " + b + " = " + c);
				break;

				case '/': c = a / b;
				Console.Write("\n " + a + " / " + b + " = " + c);
				break;
				
				default:
				Console.Write("\n Error!");
				break;
			}
			Console.ReadKey();
		}
	}
}