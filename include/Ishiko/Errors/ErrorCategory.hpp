/*
    Copyright (c) 2020-2024 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/errors/blob/main/LICENSE.txt
*/

#ifndef GUARD_ISHIKO_CPP_ERRORS_ERRORCATEGORY_HPP
#define GUARD_ISHIKO_CPP_ERRORS_ERRORCATEGORY_HPP

#include <cstdint>
#include <string>
#include <system_error>

namespace Ishiko
{

class Error;

class ErrorCategory : public std::error_category
{
public:
    /// A 128-bit value that uniquely identifies an ErrorCategory.
    /**
        Category identity is value-based, not address-based. Two copies of the same category (e.g. one per DLL) hold
        the same id and therefore compare equal. This is what makes the singletons safe to duplicate across shared
        library boundaries. The value is a version-4 UUID.
    */
    class ID
    {
    public:
        inline ID(std::uint64_t high, std::uint64_t low) noexcept;

        inline bool operator==(const ID& other) const noexcept;
        inline bool operator!=(const ID& other) const noexcept;

    private:
        std::uint64_t m_high;
        std::uint64_t m_low;
    };

    /// Returns the value-based identity of the category. Use this for equality, never the category's address.
    inline ID id() const noexcept;

    std::string message(int ev) const override;
    virtual const char* message(int ev, char* buffer, size_t len) const noexcept = 0;

protected:
    explicit ErrorCategory(ID id) noexcept;
    virtual ~ErrorCategory() = default;

private:
    ID m_id;
};

}

Ishiko::ErrorCategory::ID::ID(std::uint64_t high, std::uint64_t low) noexcept
    : m_high(high), m_low(low)
{
}

bool Ishiko::ErrorCategory::ID::operator==(const ID& other) const noexcept
{
    return ((m_high == other.m_high) && (m_low == other.m_low));
}

bool Ishiko::ErrorCategory::ID::operator!=(const ID& other) const noexcept
{
    return !(*this == other);
}

Ishiko::ErrorCategory::ID Ishiko::ErrorCategory::id() const noexcept
{
    return m_id;
}

#endif
