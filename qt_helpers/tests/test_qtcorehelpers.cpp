#include <gtest/gtest.h>
#include "qtcorehelpers.h"

#include <QBuffer>
#include <QFile>

using Aspose::QtHelpers::Convert;
using Aspose::QtHelpers::Wrap;

static const char* LoremIpsum = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.";

TEST(QtCoreHelpers, SystemStringToQString)
{
    // null string
    {
        const System::String source;
        const QString target = Convert(source);

        EXPECT_TRUE(target.isNull());
    }

    // empty string
    {
        const System::String source = u"";
        const QString target = Convert(source);

        EXPECT_FALSE(target.isNull());
        EXPECT_EQ(0, target.length());
        EXPECT_TRUE(target.toStdU16String().empty());
    }

    // short string
    {
        const System::String source = u"Hello, World!";
        const QString target = Convert(source);

        EXPECT_EQ(source.get_Length(), target.length());
        EXPECT_EQ(source.ToU16Str(), target.toStdU16String());
    }

    // long string
    {
        const System::String source = System::String::FromAscii(LoremIpsum);
        const QString target = Convert(source);

        EXPECT_EQ(source.get_Length(), target.length());
        EXPECT_EQ(source.ToU16Str(), target.toStdU16String());
    }
}

TEST(QtCoreHelpers, QStringToSystemString)
{
    // null string
    {
        const QString source;
        const System::String target = Convert(source);

        EXPECT_TRUE(target.IsNull());
    }

    // empty string
    {
        const QString source = "";
        const System::String target = Convert(source);

        EXPECT_FALSE(target.IsNull());
        EXPECT_EQ(0, target.get_Length());
        EXPECT_TRUE(target.ToU16Str().empty());
    }

    // short string
    {
        const QString source = "Hello, World!";
        const System::String target = Convert(source);

        EXPECT_EQ(source.length(), target.get_Length());
        EXPECT_EQ(source.toStdU16String(), target.ToU16Str());
    }

    // long string
    {
        const QString source = LoremIpsum;
        const System::String target = Convert(source);

        EXPECT_EQ(source.length(), target.get_Length());
        EXPECT_EQ(source.toStdU16String(), target.ToU16Str());
    }
}

TEST(QtCoreHelpers, SystemDateTimeToQDateTime)
{
    // System::DateTime::MinValue
    {
        const System::DateTime source = System::DateTime::MinValue;
        const QDateTime target = Convert(source);

        EXPECT_TRUE(target.isValid());
        EXPECT_EQ(QDate::fromString("0001-01-01", Qt::DateFormat::ISODate), target.date());
        EXPECT_EQ(QTime(0, 0, 0), target.time());
        EXPECT_EQ(Qt::TimeSpec::LocalTime, target.timeSpec());
        EXPECT_EQ("0001-01-01T00:00:00.000", target.toString(Qt::DateFormat::ISODateWithMs).toStdString());
    }

    // System::DateTime::MaxValue
    {
        const System::DateTime source = System::DateTime::MaxValue;
        const QDateTime target = Convert(source);

        EXPECT_TRUE(target.isValid());
        EXPECT_EQ(QDate(9999, 12, 31), target.date());
        EXPECT_EQ(QTime(23, 59, 59, 999), target.time());
        EXPECT_EQ(Qt::TimeSpec::LocalTime, target.timeSpec());
        EXPECT_EQ("9999-12-31T23:59:59.999", target.toString(Qt::DateFormat::ISODateWithMs).toStdString());
    }

    // System::DateTime::UnixEpoch
    {
        const System::DateTime source = System::DateTime::UnixEpoch;
        const QDateTime target = Convert(source);

        EXPECT_TRUE(target.isValid());
        EXPECT_EQ(QDate(1970, 1, 1), target.date());
        EXPECT_EQ(QTime(0, 0, 0), target.time());
        EXPECT_EQ(Qt::TimeSpec::LocalTime, target.timeSpec());
        EXPECT_EQ("1970-01-01T00:00:00.000", target.toString(Qt::DateFormat::ISODateWithMs).toStdString());
    }

    // 2077-10-27 14:45:38.835
    {
        const System::DateTime source(2077, 10, 27, 14, 45, 38, 835);
        const QDateTime target = Convert(source);

        EXPECT_TRUE(target.isValid());
        EXPECT_EQ(QDate(2077, 10, 27), target.date());
        EXPECT_EQ(QTime(14, 45, 38, 835), target.time());
        EXPECT_EQ(Qt::TimeSpec::LocalTime, target.timeSpec());
        EXPECT_EQ("2077-10-27T14:45:38.835", target.toString(Qt::DateFormat::ISODateWithMs).toStdString());
    }

    // 2077-10-27 14:45:38.835 (System::DateTimeKind::Local)
    {
        const System::DateTime source(2077, 10, 27, 14, 45, 38, 835, System::DateTimeKind::Local);
        const QDateTime target = Convert(source);

        EXPECT_TRUE(target.isValid());
        EXPECT_EQ(QDate(2077, 10, 27), target.date());
        EXPECT_EQ(QTime(14, 45, 38, 835), target.time());
        EXPECT_EQ(Qt::TimeSpec::LocalTime, target.timeSpec());
        EXPECT_EQ("2077-10-27T14:45:38.835", target.toString(Qt::DateFormat::ISODateWithMs).toStdString());
    }

    // 2077-10-27 14:45:38.835 (System::DateTimeKind::Utc)
    {
        const System::DateTime source(2077, 10, 27, 14, 45, 38, 835, System::DateTimeKind::Utc);
        const QDateTime target = Convert(source);

        EXPECT_TRUE(target.isValid());
        EXPECT_EQ(QDate(2077, 10, 27), target.date());
        EXPECT_EQ(QTime(14, 45, 38, 835), target.time());
        EXPECT_EQ(Qt::TimeSpec::UTC, target.timeSpec());
        EXPECT_EQ("2077-10-27T14:45:38.835Z", target.toString(Qt::DateFormat::ISODateWithMs).toStdString());
    }

    // System::DateTime::get_Now()
    {
        const System::DateTime source = System::DateTime::get_Now();
        const QDateTime target = Convert(source);

        EXPECT_TRUE(target.isValid());
        EXPECT_EQ(Qt::TimeSpec::LocalTime, target.timeSpec());
        EXPECT_EQ(
            source.ToString(u"yyyy-MM-ddTHH:mm:ss.fff").ToAsciiString(),
            target.toString(Qt::DateFormat::ISODateWithMs).toStdString());
    }

    // System::DateTime::get_UtcNow()
    {
        const System::DateTime source = System::DateTime::get_UtcNow();
        const QDateTime target = Convert(source);

        EXPECT_TRUE(target.isValid());
        EXPECT_EQ(Qt::TimeSpec::UTC, target.timeSpec());
        EXPECT_EQ(
            source.ToString(u"yyyy-MM-ddTHH:mm:ss.fffK").ToAsciiString(),
            target.toString(Qt::DateFormat::ISODateWithMs).toStdString());
    }

    // System::DateTime::get_Today()
    {
        const System::DateTime source = System::DateTime::get_Today();
        const QDateTime target = Convert(source);

        EXPECT_TRUE(target.isValid());
        EXPECT_EQ(Qt::TimeSpec::LocalTime, target.timeSpec());
        EXPECT_EQ(source.get_Year(), target.date().year());
        EXPECT_EQ(source.get_Month(), target.date().month());
        EXPECT_EQ(source.get_Day(), target.date().day());
        EXPECT_EQ(QTime(0, 0, 0), target.time());
    }
}

TEST(QtCoreHelpers, SystemDateTimeOffsetToQDateTime)
{
    // System::DateTimeOffset::MinValue
    {
        const auto source = System::DateTimeOffset::MinValue;
        const QDateTime target = Convert(source);

        EXPECT_TRUE(target.isValid());
        EXPECT_EQ(QDate::fromString("0001-01-01", Qt::DateFormat::ISODate), target.date());
        EXPECT_EQ(QTime(0, 0, 0), target.time());
        EXPECT_EQ(Qt::TimeSpec::UTC, target.timeSpec());
        EXPECT_EQ("0001-01-01T00:00:00.000Z", target.toString(Qt::DateFormat::ISODateWithMs).toStdString());
    }

    // System::DateTimeOffset::MaxValue
    {
        const auto source = System::DateTimeOffset::MaxValue;
        const QDateTime target = Convert(source);

        EXPECT_TRUE(target.isValid());
        EXPECT_EQ(QDate(9999, 12, 31), target.date());
        EXPECT_EQ(QTime(23, 59, 59, 999), target.time());
        EXPECT_EQ(Qt::TimeSpec::UTC, target.timeSpec());
        EXPECT_EQ("9999-12-31T23:59:59.999Z", target.toString(Qt::DateFormat::ISODateWithMs).toStdString());
    }

    // System::DateTimeOffset::UnixEpoch
    {
        const auto source = System::DateTimeOffset::UnixEpoch;
        const QDateTime target = Convert(source);

        EXPECT_TRUE(target.isValid());
        EXPECT_EQ(QDate(1970, 1, 1), target.date());
        EXPECT_EQ(QTime(0, 0, 0), target.time());
        EXPECT_EQ(Qt::TimeSpec::UTC, target.timeSpec());
        EXPECT_EQ("1970-01-01T00:00:00.000Z", target.toString(Qt::DateFormat::ISODateWithMs).toStdString());
    }

    // 2077-10-27 14:45:38.835 +03:45
    {
        const System::DateTimeOffset source(2077, 10, 27, 14, 45, 38, 835, System::TimeSpan(3, 45, 0));
        const QDateTime target = Convert(source);

        EXPECT_TRUE(target.isValid());
        EXPECT_EQ(QDate(2077, 10, 27), target.date());
        EXPECT_EQ(QTime(14, 45, 38, 835), target.time());
        EXPECT_EQ(Qt::TimeSpec::OffsetFromUTC, target.timeSpec());
        EXPECT_EQ("2077-10-27T14:45:38.835+03:45", target.toString(Qt::DateFormat::ISODateWithMs).toStdString());
        EXPECT_EQ(
            source.ToString(u"yyyy-MM-ddTHH:mm:ss.fffzzz").ToAsciiString(),
            target.toString(Qt::DateFormat::ISODateWithMs).toStdString());
    }

    // System::DateTimeOffset::get_Now()
    {
        const auto source = System::DateTimeOffset::get_Now();
        const QDateTime target = Convert(source);

        EXPECT_TRUE(target.isValid());
        EXPECT_EQ(Qt::TimeSpec::OffsetFromUTC, target.timeSpec());
        EXPECT_EQ(
            source.ToString(u"yyyy-MM-ddTHH:mm:ss.fffzzz").ToAsciiString(),
            target.toString(Qt::DateFormat::ISODateWithMs).toStdString());
    }

    // System::DateTimeOffset::get_UtcNow()
    {
        const auto source = System::DateTimeOffset::get_UtcNow();
        const QDateTime target = Convert(source);

        EXPECT_TRUE(target.isValid());
        EXPECT_EQ(Qt::TimeSpec::UTC, target.timeSpec());
        EXPECT_EQ(
            source.ToString(u"yyyy-MM-ddTHH:mm:ss.fffZ").ToAsciiString(),
            target.toString(Qt::DateFormat::ISODateWithMs).toStdString());
    }
}

TEST(QtCoreHelpers, QDateTimeToSystemDateTime)
{
    // null datetime
    {
        const QDateTime source;
        EXPECT_THROW(Convert(source), std::invalid_argument);
    }

    // invalid date
    {
        const QDateTime source(QDate(0, 1, 1), QTime(0, 0, 0));
        EXPECT_THROW(Convert(source), std::invalid_argument);
    }

    // year is less than 0
    {
        const QDateTime source(QDate(-1, 1, 1), QTime(0, 0, 0));
        EXPECT_THROW(Convert(source), std::out_of_range);
    }

    // year is greater than 9999
    {
        const QDateTime source(QDate(10000, 1, 1), QTime(0, 0, 0));
        EXPECT_THROW(Convert(source), std::out_of_range);
    }

    // 0001-01-01 00:00:00.000
    {
        const QDateTime source = QDateTime::fromString("0001-01-01", Qt::DateFormat::ISODate);
        const System::DateTime target = Convert(source);

        EXPECT_EQ(1, target.get_Year());
        EXPECT_EQ(1, target.get_Month());
        EXPECT_EQ(1, target.get_Day());
        EXPECT_EQ(0, target.get_Hour());
        EXPECT_EQ(0, target.get_Minute());
        EXPECT_EQ(0, target.get_Second());
        EXPECT_EQ(0, target.get_Millisecond());
        EXPECT_EQ(System::DateTimeKind::Local, target.get_Kind());
    }

    // 0001-01-01 00:00:00.000 (Utc)
    {
        const QDateTime source(QDate::fromString("0001-01-01", Qt::DateFormat::ISODate), QTime(0, 0, 0), Qt::TimeSpec::UTC);
        const System::DateTime target = Convert(source);

        EXPECT_EQ(1, target.get_Year());
        EXPECT_EQ(1, target.get_Month());
        EXPECT_EQ(1, target.get_Day());
        EXPECT_EQ(0, target.get_Hour());
        EXPECT_EQ(0, target.get_Minute());
        EXPECT_EQ(0, target.get_Second());
        EXPECT_EQ(0, target.get_Millisecond());
        EXPECT_EQ(System::DateTimeKind::Utc, target.get_Kind());
    }

    // 0001-01-01 00:00:00.000-01:00
    {
        const QDateTime source(QDate::fromString("0001-01-01", Qt::DateFormat::ISODate), QTime(0, 0, 0), Qt::TimeSpec::OffsetFromUTC, -1 * 60 * 60);
        const System::DateTime target = Convert(source);

        EXPECT_EQ(1, target.get_Year());
        EXPECT_EQ(1, target.get_Month());
        EXPECT_EQ(1, target.get_Day());
        EXPECT_EQ(1, target.get_Hour());
        EXPECT_EQ(0, target.get_Minute());
        EXPECT_EQ(0, target.get_Second());
        EXPECT_EQ(0, target.get_Millisecond());
        EXPECT_EQ(System::DateTimeKind::Utc, target.get_Kind());
    }

    // 9999-12-31 23:59:59.999
    {
        const QDateTime source(QDate(9999, 12, 31), QTime(23, 59, 59, 999));
        const System::DateTime target = Convert(source);

        EXPECT_EQ(9999, target.get_Year());
        EXPECT_EQ(12, target.get_Month());
        EXPECT_EQ(31, target.get_Day());
        EXPECT_EQ(23, target.get_Hour());
        EXPECT_EQ(59, target.get_Minute());
        EXPECT_EQ(59, target.get_Second());
        EXPECT_EQ(999, target.get_Millisecond());
        EXPECT_EQ(System::DateTimeKind::Local, target.get_Kind());
    }

    // 9999-12-31 23:59:59.999 (Utc)
    {
        const QDateTime source(QDate(9999, 12, 31), QTime(23, 59, 59, 999), Qt::TimeSpec::UTC);
        const System::DateTime target = Convert(source);

        EXPECT_EQ(9999, target.get_Year());
        EXPECT_EQ(12, target.get_Month());
        EXPECT_EQ(31, target.get_Day());
        EXPECT_EQ(23, target.get_Hour());
        EXPECT_EQ(59, target.get_Minute());
        EXPECT_EQ(59, target.get_Second());
        EXPECT_EQ(999, target.get_Millisecond());
        EXPECT_EQ(System::DateTimeKind::Utc, target.get_Kind());
    }

    // 9999-12-31 23:59:59.999+01:00
    {
        const QDateTime source(QDate(9999, 12, 31), QTime(23, 59, 59, 999), Qt::TimeSpec::OffsetFromUTC, 1 * 60 * 60);
        const System::DateTime target = Convert(source);

        EXPECT_EQ(9999, target.get_Year());
        EXPECT_EQ(12, target.get_Month());
        EXPECT_EQ(31, target.get_Day());
        EXPECT_EQ(22, target.get_Hour());
        EXPECT_EQ(59, target.get_Minute());
        EXPECT_EQ(59, target.get_Second());
        EXPECT_EQ(999, target.get_Millisecond());
        EXPECT_EQ(System::DateTimeKind::Utc, target.get_Kind());
    }

    // 2077-10-27 14:45:38.835
    {
        const QDateTime source(QDate(2077, 10, 27), QTime(14, 45, 38, 835));
        const System::DateTime target = Convert(source);

        EXPECT_EQ(2077, target.get_Year());
        EXPECT_EQ(10, target.get_Month());
        EXPECT_EQ(27, target.get_Day());
        EXPECT_EQ(14, target.get_Hour());
        EXPECT_EQ(45, target.get_Minute());
        EXPECT_EQ(38, target.get_Second());
        EXPECT_EQ(835, target.get_Millisecond());
        EXPECT_EQ(System::DateTimeKind::Local, target.get_Kind());
    }

    // QDateTime::currentDateTime()
    {
        const QDateTime source = QDateTime::currentDateTime();
        const System::DateTime target = Convert(source);

        EXPECT_EQ(System::DateTimeKind::Local, target.get_Kind());
        EXPECT_EQ(
            source.toString(Qt::DateFormat::ISODateWithMs).toStdString(),
            target.ToString(u"yyyy-MM-ddTHH:mm:ss.fff").ToAsciiString());
    }

    // QDateTime::currentDateTimeUtc()
    {
        const QDateTime source = QDateTime::currentDateTimeUtc();
        const System::DateTime target = Convert(source);

        EXPECT_EQ(System::DateTimeKind::Utc, target.get_Kind());
        EXPECT_EQ(
            source.toString(Qt::DateFormat::ISODateWithMs).toStdString(),
            target.ToString(u"yyyy-MM-ddTHH:mm:ss.fffK").ToAsciiString());
    }
}

TEST(QtCoreHelpers, QDateToSystemDateTime)
{
    // null date
    {
        const QDate source;
        EXPECT_THROW(Convert(source), std::invalid_argument);
    }

    // invalid date
    {
        const QDate source(0, 1, 1);
        EXPECT_THROW(Convert(source), std::invalid_argument);
    }

    // year is less than 0
    {
        const QDate source(-1, 1, 1);
        EXPECT_THROW(Convert(source), std::out_of_range);
    }

    // year is greater than 9999
    {
        const QDate source(10000, 1, 1);
        EXPECT_THROW(Convert(source), std::out_of_range);
    }

    // 0001-01-01 (System::DateTime::MinValue)
    {
        const QDate source = QDate::fromString("0001-01-01", Qt::DateFormat::ISODate);
        const System::DateTime target = Convert(source);

        EXPECT_EQ(1, target.get_Year());
        EXPECT_EQ(1, target.get_Month());
        EXPECT_EQ(1, target.get_Day());
        EXPECT_EQ(System::DateTimeKind::Unspecified, target.get_Kind());
    }

    // 9999-12-31 (System::DateTime::MaxValue)
    {
        const QDate source = QDate::fromString("9999-12-31", Qt::DateFormat::ISODate);
        const System::DateTime target = Convert(source);

        EXPECT_EQ(9999, target.get_Year());
        EXPECT_EQ(12, target.get_Month());
        EXPECT_EQ(31, target.get_Day());
        EXPECT_EQ(System::DateTimeKind::Unspecified, target.get_Kind());
    }

    // 2077-10-27
    {
        const QDate source = QDate::fromString("2077-10-27", Qt::DateFormat::ISODate);
        const System::DateTime target = Convert(source);

        EXPECT_EQ(2077, target.get_Year());
        EXPECT_EQ(10, target.get_Month());
        EXPECT_EQ(27, target.get_Day());
        EXPECT_EQ(System::DateTimeKind::Unspecified, target.get_Kind());
    }
}

TEST(QtCoreHelpers, QTimeToSystemTimeSpan)
{
    // null time
    {
        const QTime source;
        EXPECT_THROW(Convert(source), std::invalid_argument);
    }

    // invalid time
    {
        const QTime source(-1, 0, 0);
        EXPECT_THROW(Convert(source), std::invalid_argument);
    }

    // 00:00:00.000
    {
        const QTime source(0, 0, 0);
        const System::TimeSpan target = Convert(source);

        EXPECT_EQ(0, target.get_Days());
        EXPECT_EQ(0, target.get_Hours());
        EXPECT_EQ(0, target.get_Minutes());
        EXPECT_EQ(0, target.get_Seconds());
        EXPECT_EQ(0, target.get_Milliseconds());
    }

    // 23:59:59.999
    {
        const QTime source(23, 59, 59, 999);
        const System::TimeSpan target = Convert(source);

        EXPECT_EQ(0, target.get_Days());
        EXPECT_EQ(23, target.get_Hours());
        EXPECT_EQ(59, target.get_Minutes());
        EXPECT_EQ(59, target.get_Seconds());
        EXPECT_EQ(999, target.get_Milliseconds());
    }

    // 12:17:21.347
    {
        const QTime source(12, 17, 21, 347);
        const System::TimeSpan target = Convert(source);

        EXPECT_EQ(0, target.get_Days());
        EXPECT_EQ(12, target.get_Hours());
        EXPECT_EQ(17, target.get_Minutes());
        EXPECT_EQ(21, target.get_Seconds());
        EXPECT_EQ(347, target.get_Milliseconds());
    }
}

TEST(QtCoreHelpers, SystemGuidToQUuid)
{
    // zeros
    {
        const System::Guid source;
        const QUuid target = Convert(source);

        EXPECT_EQ("{00000000-0000-0000-0000-000000000000}", target.toString().toStdString());
    }

    // custom guid
    {
        const System::Guid source = System::Guid::Parse(u"28D08742-BD44-4939-8846-D957AA3E0EEB");
        const QUuid target = Convert(source);

        EXPECT_EQ("{28D08742-BD44-4939-8846-D957AA3E0EEB}", target.toString().toUpper().toStdString());
    }

    // random guid
    {
        const System::Guid source = System::Guid::NewGuid();
        const QUuid target = Convert(source);

        EXPECT_EQ(source.ToString(u"B").ToAsciiString(), target.toString().toStdString());
    }
}

TEST(QtCoreHelpers, QUuidToSystemGuid)
{
    // zeros
    {
        const QUuid source;
        const System::Guid target = Convert(source);

        EXPECT_EQ("00000000-0000-0000-0000-000000000000", target.ToString().ToAsciiString());
    }

    // custom guid
    {
        const QUuid source("28D08742-BD44-4939-8846-D957AA3E0EEB");
        const System::Guid target = Convert(source);

        EXPECT_EQ("28d08742-bd44-4939-8846-d957aa3e0eeb", target.ToString().ToAsciiString());
    }

    // random guid
    {
        const QUuid source = QUuid::createUuid();
        const System::Guid target = Convert(source);

        EXPECT_EQ(source.toString().toStdString(), target.ToString(u"B").ToAsciiString());
    }
}

TEST(QtCoreHelpers, SystemUriToQUrl)
{
    // null uri
    {
        const System::SharedPtr<System::Uri> source;
        const QUrl target = Convert(source);
        EXPECT_TRUE(target.isEmpty());
    }

    // "https://user:password@www.site.com:80/view/index.htm?q1=v1&q2=v2#fragment1"
    {
        const auto source = System::MakeObject<System::Uri>(u"https://user:password@www.site.com:80/view/index.htm?q1=v1&q2=v2#fragment1");
        const QUrl target = Convert(source);

        EXPECT_FALSE(target.isLocalFile());
        EXPECT_EQ("user:password@www.site.com:80", target.authority().toStdString());
        EXPECT_EQ("index.htm", target.fileName().toStdString());
        EXPECT_EQ("fragment1", target.fragment().toStdString());
        EXPECT_EQ("www.site.com", target.host().toStdString());
        EXPECT_EQ("password", target.password().toStdString());
        EXPECT_EQ("/view/index.htm", target.path().toStdString());
        EXPECT_EQ(80, target.port());
        EXPECT_EQ("q1=v1&q2=v2", target.query().toStdString());
        EXPECT_EQ("https", target.scheme().toStdString());
        EXPECT_EQ("user", target.userName().toStdString());
        EXPECT_EQ(source->ToString().ToAsciiString(), target.toString().toStdString());
    }

    // "C:/test/file.txt"
    {
        const auto source = System::MakeObject<System::Uri>(u"C:/test/file.txt");
        const QUrl target = Convert(source);

        EXPECT_TRUE(target.isLocalFile());
        EXPECT_EQ("", target.authority().toStdString());
        EXPECT_EQ("file.txt", target.fileName().toStdString());
        EXPECT_EQ("", target.fragment().toStdString());
        EXPECT_EQ("", target.host().toStdString());
        EXPECT_EQ("", target.password().toStdString());
        EXPECT_EQ("/C:/test/file.txt", target.path().toStdString());
        EXPECT_EQ(-1, target.port());
        EXPECT_EQ("", target.query().toStdString());
        EXPECT_EQ("file", target.scheme().toStdString());
        EXPECT_EQ("", target.userName().toStdString());
        EXPECT_EQ(source->ToString().ToAsciiString(), target.toString().toStdString());
    }
}

TEST(QtCoreHelpers, QUrlToSystemUri)
{
    // empty url
    {
        const QUrl source;
        const auto target = Convert(source);
        EXPECT_TRUE(target == nullptr);
    }

    // "https://user:password@www.site.com:80/view/index.htm?q1=v1&q2=v2#fragment1"
    {
        const QUrl source("https://user:password@www.site.com:80/view/index.htm?q1=v1&q2=v2#fragment1");
        const auto target = Convert(source);

        EXPECT_FALSE(target->get_IsFile());
        EXPECT_EQ("www.site.com:80", target->get_Authority().ToAsciiString());
        EXPECT_EQ("#fragment1", target->get_Fragment().ToAsciiString());
        EXPECT_EQ("www.site.com", target->get_Host().ToAsciiString());
        EXPECT_EQ("user:password", target->get_UserInfo().ToAsciiString());
        EXPECT_EQ("/view/index.htm", target->get_LocalPath().ToAsciiString());
        EXPECT_EQ(80, target->get_Port());
        EXPECT_EQ("?q1=v1&q2=v2", target->get_Query().ToAsciiString());
        EXPECT_EQ("https", target->get_Scheme().ToAsciiString());
        EXPECT_EQ(source.toString().toStdString(), target->ToString().ToAsciiString());
    }

    // "C:/test/file.txt"
    {
        const QUrl source("C:/test/file.txt");
        const auto target = Convert(source);

        EXPECT_TRUE(target->get_IsFile());
        EXPECT_EQ("", target->get_Authority().ToAsciiString());
        EXPECT_EQ("", target->get_Fragment().ToAsciiString());
        EXPECT_EQ("", target->get_Host().ToAsciiString());
        EXPECT_EQ("", target->get_UserInfo().ToAsciiString());
        EXPECT_EQ("c:\\test\\file.txt", target->get_LocalPath().ToAsciiString());
        EXPECT_EQ(-1, target->get_Port());
        EXPECT_EQ("", target->get_Query().ToAsciiString());
        EXPECT_EQ("file", target->get_Scheme().ToAsciiString());
        EXPECT_EQ("file:///c:/test/file.txt", target->ToString().ToAsciiString());
    }
}

TEST(QtCoreHelpers, WrapQBuffer)
{
    const QString str = LoremIpsum;
    QByteArray data = str.toLatin1();
    QBuffer buffer(&data);
    buffer.open(QIODevice::ReadWrite);

    const auto stream = Wrap(buffer);

    EXPECT_TRUE(stream->get_CanRead());
    EXPECT_TRUE(stream->get_CanSeek());
    EXPECT_TRUE(stream->get_CanWrite());

    EXPECT_EQ(str.length(), stream->get_Length());
    EXPECT_EQ(0, stream->get_Position());

    EXPECT_EQ('L', stream->ReadByte());
    stream->WriteByte('a');

    const auto array = System::MakeArray<uint8_t>(1000);

    EXPECT_THROW(stream->Read(static_cast<System::ArrayPtr<uint8_t>>(nullptr), 0, 0), System::ArgumentNullException);
    EXPECT_THROW(stream->Read(array, -1, 0), System::ArgumentOutOfRangeException);
    EXPECT_THROW(stream->Read(array, 0, -1), System::ArgumentOutOfRangeException);
    EXPECT_THROW(stream->Read(array, 0, 1001), System::ArgumentOutOfRangeException);
    EXPECT_THROW(stream->Read(array, 1, 1000), System::ArgumentOutOfRangeException);

    EXPECT_EQ(2, stream->get_Position());
    stream->set_Position(0);

    EXPECT_EQ(str.length(), stream->Read(array, 0, array->get_Length()));
    EXPECT_EQ(str.length(), stream->get_Position());

    ASSERT_EQ('L', array[0]);
    ASSERT_EQ('a', array[1]);
    for (int i = 2; i < str.length(); ++i)
    {
        ASSERT_EQ(str[i].toLatin1(), array[i]);
    }
}


TEST(QtCoreHelpers, WrapQFile)
{
    QFile file("QtCoreHelpers.WrapQFile.txt");
    if (file.exists())
        ASSERT_TRUE(file.remove());

    ASSERT_TRUE(file.open(QFile::ReadWrite));

    try
    {
        const int length = static_cast<int>(std::strlen(LoremIpsum));
        ASSERT_EQ(length, file.write(LoremIpsum, length));
        ASSERT_TRUE(file.seek(0));

        const auto stream = Wrap(file);

        EXPECT_TRUE(stream->get_CanRead());
        EXPECT_TRUE(stream->get_CanSeek());
        EXPECT_TRUE(stream->get_CanWrite());

        EXPECT_EQ(length, stream->get_Length());
        EXPECT_EQ(0, stream->get_Position());

        EXPECT_EQ('L', stream->ReadByte());
        stream->WriteByte('a');

        const auto array = System::MakeArray<uint8_t>(1000);

        EXPECT_THROW(stream->Read(static_cast<System::ArrayPtr<uint8_t>>(nullptr), 0, 0), System::ArgumentNullException);
        EXPECT_THROW(stream->Read(array, -1, 0), System::ArgumentOutOfRangeException);
        EXPECT_THROW(stream->Read(array, 0, -1), System::ArgumentOutOfRangeException);
        EXPECT_THROW(stream->Read(array, 0, 1001), System::ArgumentOutOfRangeException);
        EXPECT_THROW(stream->Read(array, 1, 1000), System::ArgumentOutOfRangeException);

        EXPECT_EQ(2, stream->get_Position());
        stream->set_Position(0);

        stream->SetLength(10);

        EXPECT_EQ(10, stream->Read(array, 0, array->get_Length()));
        EXPECT_EQ(10, stream->get_Position());

        EXPECT_EQ('L', array[0]);
        EXPECT_EQ('a', array[1]);
        EXPECT_EQ('r', array[2]);
        EXPECT_EQ('e', array[3]);
        EXPECT_EQ('m', array[4]);
        EXPECT_EQ(' ', array[5]);
        EXPECT_EQ('i', array[6]);
        EXPECT_EQ('p', array[7]);
        EXPECT_EQ('s', array[8]);
        EXPECT_EQ('u', array[9]);
    }
    catch (...)
    {
        file.remove();
        throw;
    }
}
