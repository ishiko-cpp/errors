/*
    Copyright (c) 2019-2024 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/errors/blob/main/LICENSE.txt
*/

#include "TestErrorCategory1.hpp"

TestErrorCategory1::TestErrorCategory1() noexcept
    : Ishiko::ErrorCategory(ID(0xce8041a5e5a34dffULL, 0xa3800e61c3f37664ULL)) // ce8041a5-e5a3-4dff-a380-0e61c3f37664
{
}

const TestErrorCategory1& TestErrorCategory1::Get() noexcept
{
    static TestErrorCategory1 theTestErrorCategory1;
    return theTestErrorCategory1;
}

const char* TestErrorCategory1::name() const noexcept
{
    return "TestErrorCategory1";
}

const char* TestErrorCategory1::message(int ev, char* buffer, size_t len) const noexcept
{
    return "generic error";
}
