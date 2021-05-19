#include <gtest/gtest.h>
#include "qtguihelpers.h"

using Aspose::QtHelpers::Convert;

TEST(QtGuiHelpers, SystemDrawingColorToQColor)
{
    // default
    {
        const System::Drawing::Color source;
        const QColor target = Convert(source);

        EXPECT_EQ(source.get_R(), target.red());
        EXPECT_EQ(source.get_G(), target.green());
        EXPECT_EQ(source.get_B(), target.blue());
        EXPECT_EQ(source.get_A(), target.alpha());
    }

    // DarkOliveGreen
    {
        const auto source = System::Drawing::Color::get_DarkOliveGreen();
        const QColor target = Convert(source);

        EXPECT_EQ(source.get_R(), target.red());
        EXPECT_EQ(source.get_G(), target.green());
        EXPECT_EQ(source.get_B(), target.blue());
        EXPECT_EQ(source.get_A(), target.alpha());
    }
}

TEST(QtGuiHelpers, QColorToSystemDrawingColor)
{
    // RGBA(100, 150, 200, 255)
    {
        const QColor source = QColor(100, 150, 200, 255);
        const System::Drawing::Color target = Convert(source);

        EXPECT_EQ(source.red(), target.get_R());
        EXPECT_EQ(source.green(), target.get_G());
        EXPECT_EQ(source.blue(), target.get_B());
        EXPECT_EQ(source.alpha(), target.get_A());
    }
}

TEST(QtGuiHelpers, SystemDrawingPointToQPoint)
{
    // default
    {
        const System::Drawing::Point source;
        const QPoint target = Convert(source);

        EXPECT_EQ(0, target.x());
        EXPECT_EQ(0, target.y());
    }

    // (1, -1)
    {
        const System::Drawing::Point source(1, -1);
        const QPoint target = Convert(source);

        EXPECT_EQ(1, target.x());
        EXPECT_EQ(-1, target.y());
    }
}

TEST(QtGuiHelpers, QPointToSystemDrawingPoint)
{
    // (-5, 10)
    {
        const QPoint source(-5, 10);
        const auto target = Convert(source);

        EXPECT_EQ(-5, target.get_X());
        EXPECT_EQ(10, target.get_Y());
    }
}

TEST(QtGuiHelpers, SystemDrawingPointFToQPointF)
{
    // default
    {
        const System::Drawing::PointF source;
        const QPointF target = Convert(source);

        EXPECT_EQ(0.0f, target.x());
        EXPECT_EQ(0.0f, target.y());
    }

    // (1.5, -1.7)
    {
        const System::Drawing::PointF source(1.5f, -1.7f);
        const QPointF target = Convert(source);

        EXPECT_EQ(1.5f, target.x());
        EXPECT_EQ(-1.7f, target.y());
    }
}

TEST(QtGuiHelpers, QPointFToSystemDrawingPointF)
{
    // (-5.7, 10.123)
    {
        const QPointF source(-5.7f, 10.123f);
        const auto target = Convert(source);

        EXPECT_EQ(-5.7f, target.get_X());
        EXPECT_EQ(10.123f, target.get_Y());
    }
}

TEST(QtGuiHelpers, SystemDrawingSizeToQSize)
{
    // default
    {
        const System::Drawing::Size source;
        const QSize target = Convert(source);

        EXPECT_EQ(0, target.width());
        EXPECT_EQ(0, target.height());
    }

    // (1, -1)
    {
        const System::Drawing::Size source(1, -1);
        const QSize target = Convert(source);

        EXPECT_EQ(1, target.width());
        EXPECT_EQ(-1, target.height());
    }
}

TEST(QtGuiHelpers, QSizeToSystemDrawingSize)
{
    // (-5, 10)
    {
        const QSize source(-5, 10);
        const auto target = Convert(source);

        EXPECT_EQ(-5, target.get_Width());
        EXPECT_EQ(10, target.get_Height());
    }
}

TEST(QtGuiHelpers, SystemDrawingSizeFToQSizeF)
{
    // default
    {
        const System::Drawing::SizeF source;
        const QSizeF target = Convert(source);

        EXPECT_EQ(0.0f, target.width());
        EXPECT_EQ(0.0f, target.height());
    }

    // (1.5, -1.7)
    {
        const System::Drawing::SizeF source(1.5f, -1.7f);
        const QSizeF target = Convert(source);

        EXPECT_EQ(1.5f, target.width());
        EXPECT_EQ(-1.7f, target.height());
    }
}

TEST(QtGuiHelpers, QSizeFToSystemDrawingSizeF)
{
    // (-5.7, 10.123)
    {
        const QSizeF source(-5.7f, 10.123f);
        const auto target = Convert(source);

        EXPECT_EQ(-5.7f, target.get_Width());
        EXPECT_EQ(10.123f, target.get_Height());
    }
}

TEST(QtGuiHelpers, SystemDrawingRectangleToQRect)
{
    // default
    {
        const System::Drawing::Rectangle source;
        const QRect target = Convert(source);

        EXPECT_EQ(0, target.x());
        EXPECT_EQ(0, target.y());
        EXPECT_EQ(0, target.width());
        EXPECT_EQ(0, target.height());
    }

    // (1, -1, 2, 3)
    {
        const System::Drawing::Rectangle source(1, -1, 2, 3);
        const QRect target = Convert(source);

        EXPECT_EQ(1, target.x());
        EXPECT_EQ(-1, target.y());
        EXPECT_EQ(2, target.width());
        EXPECT_EQ(3, target.height());
    }
}

TEST(QtGuiHelpers, QRectToSystemDrawingRectangle)
{
    // (-5, 10, 3, 4)
    {
        const QRect source(-5, 10, 3, 4);
        const auto target = Convert(source);

        EXPECT_EQ(-5, target.get_X());
        EXPECT_EQ(10, target.get_Y());
        EXPECT_EQ(3, target.get_Width());
        EXPECT_EQ(4, target.get_Height());
    }
}

TEST(QtGuiHelpers, SystemDrawingRectangleFToQRectF)
{
    // default
    {
        const System::Drawing::RectangleF source;
        const QRectF target = Convert(source);

        EXPECT_EQ(0.0f, target.x());
        EXPECT_EQ(0.0f, target.y());
        EXPECT_EQ(0.0f, target.width());
        EXPECT_EQ(0.0f, target.height());
    }

    // (1.5, -1.7, 1.2, 4.7)
    {
        const System::Drawing::RectangleF source(1.5f, -1.7f, 1.2f, 4.7f);
        const QRectF target = Convert(source);

        EXPECT_EQ(1.5f, target.x());
        EXPECT_EQ(-1.7f, target.y());
        EXPECT_EQ(1.2f, target.width());
        EXPECT_EQ(4.7f, target.height());
    }
}

TEST(QtGuiHelpers, QRectFToSystemDrawingRectangleF)
{
    // (-5.7, 10.123, 1.2, 7.1)
    {
        const QRectF source(-5.7f, 10.123f, 1.2f, 7.1f);
        const auto target = Convert(source);

        EXPECT_EQ(-5.7f, target.get_X());
        EXPECT_EQ(10.123f, target.get_Y());
        EXPECT_EQ(1.2f, target.get_Width());
        EXPECT_EQ(7.1f, target.get_Height());
    }
}
