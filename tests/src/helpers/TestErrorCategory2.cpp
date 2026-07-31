/*
    Copyright (c) 2021-2024 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/errors/blob/main/LICENSE.txt
*/

#include "TestErrorCategory2.hpp"

TestErrorCategory2::TestErrorCategory2() noexcept
    : Ishiko::ErrorCategory(ID(0x7fd3a6958d844665ULL, 0x8a1cab1292aff9c0ULL)) // 7fd3a695-8d84-4665-8a1c-ab1292aff9c0
{
}

const TestErrorCategory2& TestErrorCategory2::Get() noexcept
{
    static TestErrorCategory2 theTestErrorCategory2;
    return theTestErrorCategory2;
}

const char* TestErrorCategory2::name() const noexcept
{
    return "TestErrorCategory2";
}

const char* TestErrorCategory2::message(int ev, char* buffer, size_t len) const noexcept
{
    return "generic error";
}
