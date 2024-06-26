/*
    Copyright (c) 2022-2024 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/errors/blob/main/LICENSE.txt
*/

#ifndef GUARD_ISHIKO_CPP_ERRORS_ERRORSERRORCATEGORY_HPP
#define GUARD_ISHIKO_CPP_ERRORS_ERRORSERRORCATEGORY_HPP

#include "ErrorCategory.hpp"

namespace Ishiko
{

class ErrorsErrorCategory : public ErrorCategory
{
public:
    enum class Value
    {
        generic_error = -1,
        memory_allocation_error = -2
    };

    static const ErrorsErrorCategory& Get() noexcept;

    const char* name() const noexcept override;
    const char* message(int ev, char* buffer, size_t len) const noexcept override;

private:
    ErrorsErrorCategory() noexcept = default;
};

}

#endif
