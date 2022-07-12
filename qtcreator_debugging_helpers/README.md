# QtCreator debugging helpers for CodePorting.Translator.Cs2Cpp.Framework

## How to install debugging helpers

Open Qt Creator and specify the location of the `asposetypes.py` in **Tools > Options > Debugger > Locals & Expressions > Extra Debugging Helpers**.

More info here: https://doc.qt.io/qtcreator/creator-debugging-helpers.html

## How to build examples

1) Provide path to built instance of CodePorting.Translator.Cs2Cpp.Framework via ASPOSE_ROOT environment variable.
2) Open Qt Creator.
3) Select **File > Open File or Project...** and specify the location of the `CMakeLists.txt`.
4) Select **Configure project**.
5) Select **Debug > Start and Break on Main** (F10).
