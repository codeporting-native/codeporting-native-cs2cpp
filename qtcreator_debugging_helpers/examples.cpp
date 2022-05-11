#include <system/array.h>
#include <system/date_time.h>
#include <system/date_time_offset.h>
#include <system/guid.h>
#include <system/nullable.h>
#include <system/string.h>
#include <system/timespan.h>
#include <system/collections/arraylist.h>
#include <system/collections/dictionary.h>
#include <system/collections/hashset.h>
#include <system/collections/list.h>
#include <system/collections/sorted_dictionary.h>
#include <system/collections/sorted_list.h>
#include <system/collections/stack.h>
#include <system/globalization/culture_info.h>
#include <system/io/file_stream.h>
#include <system/io/memory_stream.h>
#include <system/text/string_builder.h>
#include <drawing/color.h>
#include <drawing/point.h>
#include <drawing/point_f.h>
#include <drawing/rectangle.h>
#include <drawing/rectangle_f.h>
#include <drawing/size.h>
#include <drawing/size_f.h>
#include <drawing/drawing2d/matrix.h>

using namespace System;

void system_array()
{
    auto empty = MakeArray<int>();
    auto array = MakeArray<int>({1, 2, 3});
    auto char_array = MakeArray<unsigned char>({ 1, 2, 3});
}

void system_datetime()
{
    DateTime default_value;
    DateTime min_value = DateTime::MinValue;
    DateTime max_value = DateTime::MaxValue;
    DateTime utc_time(2009, 10, 29, 17, 37, 54, 123, DateTimeKind::Utc);
    DateTime local_time(2009, 10, 29, 17, 37, 54, 123, DateTimeKind::Local);
    DateTime value1(2009, 10, 29, 17, 37, 54);
    DateTime value2(1, 1, 1, 17, 37, 54);
    DateTime value3(1904, 1, 1);
    DateTime value4(2099, 12, 31, 23, 59, 59, 999);
    DateTime value5(1905, 1, 1);
    DateTime value6(1908, 1, 1);
    DateTime value7(1904, 2, 29);
    DateTime value8(2000, 12, 31);
    DateTime value9(2000, 2, 29);
    DateTime value10(2001, 3, 1);
    DateTime value11(1899, 10, 30);
    DateTime value12 = DateTime(2001, 1, 31).Subtract(TimeSpan(1));
}

void system_datetimeoffset()
{
    DateTimeOffset default_value;
    DateTimeOffset min_value = DateTimeOffset::MinValue;
    DateTimeOffset max_value = DateTimeOffset::MaxValue;
    DateTimeOffset unix_epoch = DateTimeOffset::UnixEpoch;
    DateTimeOffset now = DateTimeOffset::get_Now();
    DateTimeOffset utc_now = DateTimeOffset::get_UtcNow();
    DateTimeOffset value1 = DateTimeOffset(DateTime(2017, 1, 31), TimeSpan::FromMinutes(95));
    DateTimeOffset value2 = DateTimeOffset(DateTime(2017, 1, 31), TimeSpan::FromMinutes(-95));
}

void system_guid()
{
    Guid default_value;
    Guid value = Guid::Parse(u"388637DF-AA50-4E8A-9968-AC57B8E67B3F");
}

void system_nullable()
{
    Nullable<int> null_value;
    Nullable<int> int_value(10);
    Nullable<String> string_value(u"Hello, World!");
}

void system_object()
{
    auto object = MakeObject<Object>();
    auto objectRef = object;

    auto object2 = MakeObject<Object>();
}

void system_string()
{
    String null_string;
    String empty_string = u"";
    String short_string = u"Hello, World!";
    String long_string = u"Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.";
    String very_long_string(u'A', 10000);
}

void system_stringbuilder()
{
    Text::StringBuilder sb;
    sb.Append(u"Hello, World!");
    sb.Append(u"Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.");
}

void system_shared_ptr()
{
    SharedPtr<Object> null_ptr;
    auto object = MakeObject<Object>();
    auto culture = Globalization::CultureInfo::get_CurrentCulture();
    auto string_builder = MakeObject<Text::StringBuilder>();
    string_builder->Append(u"Hello, World!");

    auto weak_ptr = MakeObject<Object>();
    {
        auto object_ptr = weak_ptr;
        weak_ptr.set_Mode(SmartPtrMode::Weak);
    }
}

void system_weak_ptr()
{
    SharedPtr<Object> shared_ptr = MakeObject<Object>();
    WeakPtr<Object> weak_ptr;
    weak_ptr = shared_ptr;
    shared_ptr = nullptr;
}

void system_timespan()
{
    TimeSpan zero_value;
    TimeSpan min_value = TimeSpan::MinValue;
    TimeSpan max_value = TimeSpan::MaxValue;
    TimeSpan value1(1);
    TimeSpan value2(1234567);
    TimeSpan value3(1234560);
    TimeSpan value4 = TimeSpan::FromMilliseconds(123);
    TimeSpan value5(0, 1, 2, 3, 456);
    TimeSpan value6(0, 11, 22, 33, 456);
    TimeSpan value7(1, 11, 22, 33, 456);
    TimeSpan value8(10, 11, 22, 33);
    TimeSpan value9(-10, 11, 22, 33);
    TimeSpan value10(-10, -11, -22, -33);
    TimeSpan value11 = TimeSpan::FromDays(12);
}

void system_collections_arraylist()
{
    auto empty = MakeObject<Collections::Generic::ArrayList<int>>();
    auto array_list = MakeObject<Collections::Generic::ArrayList<int>>();
    array_list->Add(1);
    array_list->Add(2);
    array_list->Add(3);
}

void system_collections_dictionary()
{
    auto empty = MakeObject<Collections::Generic::Dictionary<String, int>>();
    auto dictionary = MakeObject<Collections::Generic::Dictionary<String, int>>();
    dictionary->Add(u"One", 1);
    dictionary->Add(u"Two", 2);
    dictionary->Add(u"Three", 3);
}

void system_collections_hashset()
{
    auto empty = MakeObject<Collections::Generic::HashSet<String>>();
    auto set = MakeObject<Collections::Generic::HashSet<String>>();
    set->Add(u"One");
    set->Add(u"Two");
    set->Add(u"Three");
}

void system_collections_list()
{
    auto empty = MakeObject<Collections::Generic::List<String>>();
    auto list = MakeObject<Collections::Generic::List<String>>();
    list->Add(u"One");
    list->Add(u"Two");
    list->Add(u"Three");
}

void system_collections_sorteddictionary()
{
    auto empty = MakeObject<Collections::Generic::SortedDictionary<String, int>>();
    auto dictionary = MakeObject<Collections::Generic::SortedDictionary<String, int>>();
    dictionary->Add(u"One", 1);
    dictionary->Add(u"Two", 2);
    dictionary->Add(u"Three", 3);
}

void system_collections_sortedlist()
{
    auto empty = MakeObject<Collections::Generic::SortedList<String, int>>();
    auto list = MakeObject<Collections::Generic::SortedList<String, int>>();
    list->Add(u"One", 1);
    list->Add(u"Two", 2);
    list->Add(u"Three", 3);
}

void system_collections_stack()
{
    auto empty = MakeObject<Collections::Generic::Stack<int>>();
    auto stack = MakeObject<Collections::Generic::Stack<int>>();
    stack->Push(1);
    stack->Push(2);
    stack->Push(3);
}

void system_io_filestream()
{
    auto stream = MakeObject<IO::FileStream>(u"C:\\Qt\\components.xml", IO::FileMode::Open);
    stream->ReadByte();
}

void system_io_memorystream()
{
    auto stream = MakeObject<IO::MemoryStream>();
    stream->WriteByte(1);
    stream->WriteByte(2);
}

void system_drawing_color()
{
    using Drawing::Color;
    Color red = Color::get_Red();
    Color color1 = Color::FromArgb(127, 10, 11, 12);
    Color color2 = Color::FromArgb(255, 255, 0, 0);
}

void system_drawing_point()
{
    Drawing::Point default_value;
    Drawing::Point value1(10, 20);
    Drawing::Point value2(-10, -20);
}

void system_drawing_point_f()
{
    Drawing::PointF default_value;
    Drawing::PointF value1(10, 20);
    Drawing::PointF value2(-10, -20);
    Drawing::PointF value3(0.0005f, 15.123f);
}

void system_drawing_rectangle()
{
    Drawing::Rectangle default_value;
    Drawing::Rectangle value1(1, 2, 3, 4);
    Drawing::Rectangle value2(-1, -2, 0, 10);
}

void system_drawing_rectangle_f()
{
    Drawing::RectangleF default_value;
    Drawing::RectangleF value1(1, 2, 3, 4);
    Drawing::RectangleF value2(-1, -2, 0, 10);
    Drawing::RectangleF value3(0.0005f, 15.123f, 0.7f, 0.15f);
}

void system_drawing_size()
{
    Drawing::Size default_value;
    Drawing::Size value1(1, 2);
    Drawing::Size value2(-1, -2);
}

void system_drawing_size_f()
{
    Drawing::SizeF default_value;
    Drawing::SizeF value1(1, 2);
    Drawing::SizeF value2(-1, -2);
    Drawing::SizeF value3(0.0005f, 15.123f);
}

void system_drawing2d_matrix()
{
    Drawing::Drawing2D::Matrix default_value;
    Drawing::Drawing2D::Matrix value1(1.1f, 1.2f, 2.1f, 2.2f, -1.0f, 1.0f);
}

void system_details_lazy()
{
    using namespace System::Details;
    Lazy<int> a;
    Lazy<int> b;
    b = 1;

    Lazy<String> c;
    c = u"String";

    ThreadSafeLazy<String, LazyValueStorageType::Dynamic> d;
    d = u"Dynamic";

    ThreadSafeLazy<String, LazyValueStorageType::Dynamic> e;
}

int main()
{
    system_array();
    system_datetime();
    system_datetimeoffset();
    system_guid();
    system_nullable();
    system_object();
    system_string();
    system_stringbuilder();
    system_shared_ptr();
    system_weak_ptr();
    system_timespan();
    system_collections_arraylist();
    system_collections_dictionary();
    system_collections_hashset();
    system_collections_list();
    system_collections_sorteddictionary();
    system_collections_sortedlist();
    system_collections_stack();
    system_io_filestream();
    system_io_memorystream();
    system_drawing_color();
    system_drawing_point();
    system_drawing_point_f();
    system_drawing_rectangle();
    system_drawing_rectangle_f();
    system_drawing_size();
    system_drawing_size_f();
    system_drawing2d_matrix();
    system_details_lazy();
    return 0;
}
