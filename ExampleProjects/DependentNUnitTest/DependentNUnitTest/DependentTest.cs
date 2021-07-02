using CommonLib;
using NUnit.Framework;

namespace DependentNUnitTest
{
    [TestFixture]
    public class DependentTest
    {
        [Test]
        public void CheckGetIntValue()
        {
            SomeClass impl = new SomeClass();
            Assert.AreEqual(666, impl.GetIntValue());
        }

        [Test]
        public void CheckGetStringValue()
        {
            SomeClass impl = new SomeClass();
            Assert.AreEqual("IDDQD", impl.GetStringValue());
        }
    }
}
