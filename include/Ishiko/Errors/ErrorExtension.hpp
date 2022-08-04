/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/errors/blob/main/LICENSE.txt
*/

#ifndef GUARD_ISHIKO_CPP_ERRORS_ERROREXTENSION_HPP
#define GUARD_ISHIKO_CPP_ERRORS_ERROREXTENSION_HPP

#include <ostream>
#include <string>

namespace Ishiko
{

/// Base class for the error extensions.
class ErrorExtension
{
public:
    /// Destroys the extension.
    /**
        The default implementation calls delete(this).
    */
    virtual void release() noexcept;

    virtual void onFail(int code, const std::string& message, const char* file, int line) noexcept;

    virtual std::ostream& operator<<(std::ostream& os) const;

protected:
    virtual ~ErrorExtension() noexcept = default;
};

}

#endif
