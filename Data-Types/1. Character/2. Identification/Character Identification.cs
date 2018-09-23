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
            if (n >= 48 && n <= 57)
                Console.Write("\n '" + ch + "' is a numeral digit. \n");
            else if (n >= 65 && n <= 90)
                Console.Write("\n '" + ch + "' is an uppercase alphabet. \n");
            else if (n >= 97 && n <= 122)
                Console.Write("\n '" + ch + "' is a lowercase alphabet. \n");
            else
                Console.Write("\n '" + ch + "' is a special character. \n");
            Console.ReadKey();
        }
    }
}