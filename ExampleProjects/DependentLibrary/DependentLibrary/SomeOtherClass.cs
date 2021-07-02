using CommonLib;

namespace DependentClassLibrary
{
    public class SomeOtherClass
    {
        public int GetIntValue()
        {
            SomeClass impl = new SomeClass();
            return impl.GetIntValue() + 777;
        }

        public string GetStringValue()
        {
            SomeClass impl = new SomeClass();
            return impl.GetStringValue().ToLower() + "idkfa";
        }
    }
}
