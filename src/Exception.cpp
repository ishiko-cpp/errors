/*
    Copyright (c) 2015-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/errors/blob/main/LICENSE.txt
*/

#include "Exception.hpp"

using namespace Ishiko;

Exception::Exception(const ErrorCode& code, const char* file, int line)
    : m_code(code), m_file(file), m_line(line)
{
}

Exception::Exception(int value, const ErrorCategory& category, const char* file, int line)
    : m_code(category, value), m_file(file), m_line(line)
{
}

Exception::Exception(int value, const ErrorCategory& category, const std::string& description, const char* file,
    int line)
    : m_code(category, value), m_what(description), m_file(file), m_line(line)
{
}

const char* Exception::what() const noexcept
{
    return m_what.c_str();
}

const ErrorCode& Exception::code() const noexcept
{
    return m_code;
}

const std::string& Exception::file() const
{
    return m_file;
}

int Exception::line() const
{
    return m_line;
}
