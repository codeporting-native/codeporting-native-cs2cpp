# Conversion methods between Qt types and CodePorting.Translator.Cs2Cpp.Framework types

Header `qtcorehelpers.h` contains:
- conversions between `System::String` and `QString`
- conversions between `System::Array<uint8_t>` and `QByteArray`
- conversions between `System::DateTime` and `QDateTime`
- conversions between `System::DateTime` and `QDate`
- conversions between `System::DateTimeOffset` and `QDateTime`
- conversions between `System::TimeSpan` and `QTime`
- conversions between `System::Guid` and `QUuid`
- conversions between `System::Uri` and `QUrl`
- wrapper around `QIODevice`
- wrapper around `QFileDevice`

Header `qtguihelpers.h` contains:
- conversions between `System::Drawing::Color` and `QColor`
- conversions between `System::Drawing::Point` and `QPoint`
- conversions between `System::Drawing::PointF` and `QPointF`
- conversions between `System::Drawing::Size` and `QSize`
- conversions between `System::Drawing::SizeF` and `QSizeF`
- conversions between `System::Drawing::Rectangle` and `QRect`
- conversions between `System::Drawing::RectangleF` and `QRectF`

## How to build and run tests using Visual Studio 2019

1) Provide path to built instance of CodePorting.Translator.Cs2Cpp.Framework via ASPOSE_ROOT environment variable.

2) Generate Visual Studio solution:
   ```bat
   cmake -G "Visual Studio 16 2019" -Ax64 -B build -DQT_DIR=<path>
   ```

   The following parameters must be specified:
   - `QT_DIR` - path to the directory which contains `Qt5Config.cmake` (or `Qt6Config.cmake`).

   For example:
   ```bat
   cmake -G "Visual Studio 16 2019" -Ax64 -B build -DQT_DIR=C:\Qt\5.15.2\msvc2019_64\lib\cmake\Qt5
   ```

   An alternative is to use a `CMAKE_PREFIX_PATH` variable:
   ```bat
   cmake -G "Visual Studio 16 2019" -Ax64 -B build -DCMAKE_PREFIX_PATH=C:\Qt\5.15.2\msvc2019_64\lib\cmake
   ```

3) Build Visual Studio solution
   ```bat
   cmake --build build --config Debug
   ```

4) Run tests
   ```bat
   cd build
   ctest -C Debug -V
   ```

## How to build and run tests using Qt Creator

1) Provide path to built instance of CodePorting.Translator.Cs2Cpp.Framework via ASPOSE_ROOT environment variable.

2) Open Qt Creator.

3) Select **File > Open File or Project...** and specify the location of the `CMakeLists.txt`.

4) Select **Configure Project**.

5) Select **Tools > Tests > Run All Tests** (Alt+A).
