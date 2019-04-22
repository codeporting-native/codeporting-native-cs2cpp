using System;
using LibraryA;
using LibraryB;

namespace ComplexDependentConsoleApp
{
    public class Program
    {
        public static void Main(string[] args)
        {
            ClassAImpl aImpl = new ClassAImpl();
            ClassBImpl bImpl = new ClassBImpl();
            Console.WriteLine(aImpl.GetIntValue());
            Console.WriteLine(aImpl.GetStringValue());
            Console.WriteLine(bImpl.GetIntValue());
            Console.WriteLine(bImpl.GetStringValue());
        }
    }
}
