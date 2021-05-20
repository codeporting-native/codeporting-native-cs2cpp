using System;
using CommonLib;

namespace DependentConsoleApp
{
    public class Program
    {
        public static void Main(string[] args)
        {
            SomeClass impl = new SomeClass();
            Console.WriteLine(impl.GetIntValue());
            Console.WriteLine(impl.GetStringValue());
        }
    }
}
