cmake_minimum_required(VERSION 3.16)
project(IshikoErrors LANGUAGES CXX)

set(SOURCE_FILES
    ../../src/Error.cpp
    ../../src/ErrorCategory.cpp
    ../../src/ErrorCode.cpp
    ../../src/ErrorsErrorCategory.cpp
    ../../src/ErrorString.cpp
    ../../src/Exception.cpp
    ../../src/InfoErrorExtension.cpp
    ../../src/SuccessCategory.cpp
)

set(HEADER_FILES
    ../../include/Ishiko/Errors.hpp
    ../../include/Ishiko/Errors/Error.hpp
    ../../include/Ishiko/Errors/ErrorCode.hpp
    ../../include/Ishiko/Errors/ErrorCategory.hpp
    ../../include/Ishiko/Errors/ErrorsErrorCategory.hpp
    ../../include/Ishiko/Errors/ErrorString.hpp
    ../../include/Ishiko/Errors/Exception.hpp
    ../../include/Ishiko/Errors/InfoErrorExtension.hpp
    ../../include/Ishiko/Errors/linkoptions.hpp
    ../../include/Ishiko/Errors/SuccessCategory.hpp
)

add_library(ishiko_errors STATIC
    ${SOURCE_FILES}
    ${HEADER_FILES}
)

set_target_properties(ishiko_errors PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY $<1:${CMAKE_CURRENT_SOURCE_DIR}/../../lib>
)

set_target_properties(ishiko_errors PROPERTIES
    PREFIX lib
)

if(CMAKE_VS_PLATFORM_NAME STREQUAL "x64")
    set(NUIME_ARCH_TAG "-x64")
elseif(CMAKE_VS_PLATFORM_NAME STREQUAL "Win32")
    set(NUIME_ARCH_TAG "-x86")
endif()

set_target_properties(ishiko_errors PROPERTIES
    OUTPUT_NAME ishiko_errors$<$<CONFIG:Debug>:-gd>${NUIME_ARCH_TAG}
)

target_include_directories(ishiko_errors PRIVATE
    ../../include/Ishiko/Errors
)
