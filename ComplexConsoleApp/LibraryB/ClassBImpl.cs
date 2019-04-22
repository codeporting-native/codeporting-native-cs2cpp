using CommonLibrary;

namespace LibraryB
{
    public class ClassBImpl
    {
        private readonly BaseInterfaceSimplImpl mImpl = new BaseInterfaceSimplImpl();

        public int GetIntValue()
        {
            return mImpl.GetIntValue() * 54;
        }

        public string GetStringValue()
        {
            return mImpl.GetStringValue().ToLower();
        }
    }
}
