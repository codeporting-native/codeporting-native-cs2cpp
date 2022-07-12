cmake_minimum_required(VERSION 3.5)

project(test-qt-helpers LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (NOT DEFINED ASPOSE_ROOT)
    set(ASPOSE_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../..)
endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Gui REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Gui REQUIRED PATHS ${QT_DIR})

find_package(CodePorting.Translator.Cs2Cpp.Framework REQUIRED PATHS ${ASPOSE_ROOT})

file(READ "${ASPOSE_ROOT}/external/gtest.version" GTEST_VERSION)
set(GTEST_ROOT "${ASPOSE_ROOT}/external/${GTEST_VERSION}/fused-src")

add_library(gtest STATIC
    ${GTEST_ROOT}/gtest/gtest_main.cc
    ${GTEST_ROOT}/gtest/gtest-all.cc)

find_package(Threads)
target_include_directories(gtest PUBLIC ${GTEST_ROOT})
target_link_libraries(gtest PUBLIC Threads::Threads)

set(PROJECT_SOURCES
    tests/test_qtcorehelpers.cpp
    tests/test_qtguihelpers.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
else()
    add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
endif()

target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Gui Aspose::CodePorting.Translator.Cs2Cpp.Framework gtest)

enable_testing()
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Aspose::CodePorting.Translator.Cs2Cpp.Framework> $<TARGET_FILE_DIR:${PROJECT_NAME}>
)

if(WIN32)
    get_target_property(QMAKE_EXECUTABLE Qt${QT_VERSION_MAJOR}::qmake IMPORTED_LOCATION)
    get_filename_component(WINDEPLOYQT_EXECUTABLE ${QMAKE_EXECUTABLE} PATH)
    set(WINDEPLOYQT_EXECUTABLE "${WINDEPLOYQT_EXECUTABLE}/windeployqt.exe")

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
       COMMAND ${WINDEPLOYQT_EXECUTABLE} --no-compiler-runtime $<TARGET_FILE:${PROJECT_NAME}>)
endif()
