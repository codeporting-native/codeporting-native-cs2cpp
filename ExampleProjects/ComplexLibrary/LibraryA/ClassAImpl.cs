using CommonLibrary;

namespace LibraryA
{
    public class ClassAImpl
    {
        private readonly BaseInterfaceSimplImpl mImpl = new BaseInterfaceSimplImpl();

        public int GetIntValue()
        {
            return mImpl.GetIntValue() * 66;
        }

        public string GetStringValue()
        {
            return mImpl.GetStringValue().ToUpper();
        }
    }
}
