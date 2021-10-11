using LibraryA;
using LibraryB;

namespace ComplexLibrary
{
    public class SomeClass
    {
        private readonly ClassAImpl mAImpl = new ClassAImpl();
        private readonly ClassBImpl mBImpl = new ClassBImpl();

        public int GetIntValue()
        {
            return mAImpl.GetIntValue() + mBImpl.GetIntValue();
        }

        public string GetStringValue()
        {
            return mAImpl.GetStringValue() + mBImpl.GetStringValue();
        }
    }
}
