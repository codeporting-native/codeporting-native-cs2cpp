using NUnit.Framework;

namespace PortingSln
{
    [TestFixture]
    public class SimpleNUnitTest
    {
        [Test]
        public void Test1()
        {
            Assert.AreEqual(12, 10 + 2);
        }

        [Test]
        public void Test2()
        {
            Assert.AreEqual("IDDQD", "iddqd".ToUpper());
        }
    }
}