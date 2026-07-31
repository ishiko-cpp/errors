/*
    Copyright (c) 2022-2024 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/errors/blob/main/LICENSE.txt
*/

#include "ErrorsErrorCategory.hpp"

using namespace Ishiko;

ErrorsErrorCategory::ErrorsErrorCategory() noexcept
    : ErrorCategory(ID(0x01675c42d6f843bfULL, 0xa52dd1af771c0857ULL)) // 01675c42-d6f8-43bf-a52d-d1af771c0857
{
}

const ErrorsErrorCategory& ErrorsErrorCategory::Get() noexcept
{
    static ErrorsErrorCategory theCategory;
    return theCategory;
}

const char* ErrorsErrorCategory::name() const noexcept
{
    return "Ishiko::ErrorsErrorCategory";
}

const char* ErrorsErrorCategory::message(int ev, char* buffer, size_t len) const noexcept
{
    switch (static_cast<Value>(ev))
    {
    case Value::generic_error:
        return "generic error";

    case Value::memory_allocation_error:
        return "memory allocation error";

    default:
        return "unknown value";
    }
}
