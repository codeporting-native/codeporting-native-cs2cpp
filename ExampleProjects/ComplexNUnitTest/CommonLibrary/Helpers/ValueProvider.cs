using BaseLibrary.Utils;

namespace CommonLibrary.Helpers
{
    public static class ValueProvider
    {
        public static int GetIntValue()
        {
            return ValueHelper.GetDefaultIntValue() + 13;
        }

        public static string GetStringValue()
        {
            return ValueHelper.GetDefaultStringValue() + "iDkFa";
        }
    }
}
