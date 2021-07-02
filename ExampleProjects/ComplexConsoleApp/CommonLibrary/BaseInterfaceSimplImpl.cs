using System;
using BaseLibrary;
using CommonLibrary.Helpers;

namespace CommonLibrary
{
    public class BaseInterfaceSimplImpl : IBaseInterface
    {
        public int GetIntValue()
        {
            return ValueProvider.GetIntValue();
        }

        public string GetStringValue()
        {
            return ValueProvider.GetStringValue();
        }

        public void DoIt()
        {
            Console.WriteLine("CommonLibrary Do");
        }
    }
}
