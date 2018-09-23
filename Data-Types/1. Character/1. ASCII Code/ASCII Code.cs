using System;

namespace ASCII
{
    class ASCII
    {
        static void Main(string[] args)
        {
            char ch;
            Console.Write("\n Enter a character : ");
            ch = char.Parse(Console.ReadLine());

            int n=ch;
            Console.Write("\n ASCII code of '" + ch + "' is " + n + ".\n");
            Console.ReadKey();
        }
    }
}