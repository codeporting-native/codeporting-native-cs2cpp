namespace PortingSln
{
    public class SimpleLibrary
    {
        public int GetIntValue()
        {
            return 666;
        }

        public string GetStringValue()
        {
            return "IdDqD";
        }

        private static bool IsPorted = false;
        public static bool Ported
        {
            get
            {
                return IsPorted;
            }
        }

        static SimpleLibrary()
        {
            //CPPCODE: IsPorted = true;
        }
    }
}
