/*
    Copyright (c) 2022-2024 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/errors/blob/main/LICENSE.txt
*/

#include "ErrorCategory.hpp"
#include "Error.hpp"

using namespace Ishiko;

ErrorCategory::ErrorCategory(ID id) noexcept
    : m_id(id)
{
}

ErrorCategory::ID ErrorCategory::id() const noexcept
{
    return m_id;
}

std::string ErrorCategory::message(int ev) const
{
    return message(ev, nullptr, 0);
}
