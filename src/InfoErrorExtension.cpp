/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/errors/blob/main/LICENSE.txt
*/

#include "InfoErrorExtension.hpp"
#include <codecvt>
#include <locale>

using namespace Ishiko;

InfoErrorExtension::InfoErrorExtension()
    : m_line(-1)
{
}

InfoErrorExtension::InfoErrorExtension(const std::string& message, const char* file, int line)
    : m_line(line)
{
    m_message.assign(message);
    m_file.assign(file);
}

InfoErrorExtension::InfoErrorExtension(const std::wstring& message, const char* file, int line)
    : m_line(line)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    m_message.assign(converter.to_bytes(message));
    m_file.assign(file);
}

void InfoErrorExtension::Set(Error& error, const std::string& message, const char* file, int line) noexcept
{
    InfoErrorExtension* extension;
    if (error.extensions().tryGet(extension))
    {
        extension->m_message.assign(message);
        extension->m_file.assign(file);
        extension->m_line = line;
    }
}

void InfoErrorExtension::Set(Error& error, const std::wstring& message, const char* file, int line) noexcept
{
    InfoErrorExtension* extension;
    if (error.extensions().tryGet(extension))
    {
        std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
        extension->m_message.assign(converter.to_bytes(message));
        extension->m_file.assign(file);
        extension->m_line = line;
    }
}

std::ostream& InfoErrorExtension::streamOut(std::ostream& os) const
{
    if (m_message.size() > 0)
    {
        os << ", " << m_message;
    }
    if (m_file.size() > 0)
    {
        os << " [file: " << m_file << ", line: " << m_line << "]";
    }
    return os;
}

const ErrorString& InfoErrorExtension::message() const noexcept
{
    return m_message;
}

const ErrorString& InfoErrorExtension::file() const
{
    return m_file;
}

int InfoErrorExtension::line() const
{
    return m_line;
}
