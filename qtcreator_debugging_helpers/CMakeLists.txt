cmake_minimum_required(VERSION 3.5)

project(qtcreator-debugging-helpers LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (NOT DEFINED ASPOSE_ROOT)
    set(ASPOSE_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../..)
endif()

find_package(CodePorting.Native.Cs2Cpp REQUIRED CONFIG PATHS ${ASPOSE_ROOT})

add_executable(${PROJECT_NAME} examples.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE Aspose::CodePorting.Native.Cs2Cpp)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Aspose::CodePorting.Native.Cs2Cpp> $<TARGET_FILE_DIR:${PROJECT_NAME}>
)
