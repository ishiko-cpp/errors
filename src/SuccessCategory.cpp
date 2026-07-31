/*
    Copyright (c) 2020-2024 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/errors/blob/main/LICENSE.txt
*/

#include "SuccessCategory.hpp"

using namespace Ishiko;

SuccessCategory::SuccessCategory() noexcept
    : ErrorCategory(ID(0xbd99cf104a10431aULL, 0x87b114371e6229daULL)) // bd99cf10-4a10-431a-87b1-14371e6229da
{
}

const SuccessCategory& SuccessCategory::Get() noexcept
{
    static SuccessCategory theCategory;
    return theCategory;
}

const char* SuccessCategory::name() const noexcept
{
    return "Ishiko::SuccessCategory";
}

const char* SuccessCategory::message(int ev, char* buffer, size_t len) const noexcept
{
    return ((ev == 0) ? "success" : "unknown value");
}
