using System;
using LibraryA;
using LibraryB;
using NUnit.Framework;

namespace ComplexNUnitTest
{
    [TestFixture]
    public class ComplexTest
    {
        [Test]
        public void CheckLibraryA()
        {
            ClassAImpl impl = new ClassAImpl();
            Console.WriteLine(impl.GetIntValue());
            Console.WriteLine(impl.GetStringValue());
        }

        [Test]
        public void CheckLibraryB()
        {
            ClassBImpl impl = new ClassBImpl();
            Console.WriteLine(impl.GetIntValue());
            Console.WriteLine(impl.GetStringValue());
        }
    }
}
