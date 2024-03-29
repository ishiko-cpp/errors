/*
    Copyright (c) 2020-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/errors/blob/main/LICENSE.txt
*/

#ifndef GUARD_ISHIKO_CPP_ERRORS_SUCCESSCATEGORY_HPP
#define GUARD_ISHIKO_CPP_ERRORS_SUCCESSCATEGORY_HPP

#include "ErrorCategory.hpp"
#include <ostream>

namespace Ishiko
{

class SuccessCategory : public ErrorCategory
{
public:
    static const SuccessCategory& Get() noexcept;

    const char* name() const noexcept override;
    std::ostream& streamOut(int value, std::ostream& os) const override;

private:
    SuccessCategory() noexcept = default;
};

}

#endif
