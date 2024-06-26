/*
    Copyright (c) 2019-2024 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/errors/blob/main/LICENSE.txt
*/

#include "ErrorCodeTests.hpp"
#include "ErrorExtensionsTests.hpp"
#include "ErrorStringTests.hpp"
#include "ErrorTests.hpp"
#include "InfoErrorExtensionTests.hpp"
#include "ExceptionTests.hpp"
#include <Ishiko/TestFramework/Core.hpp>
#include <exception>

using namespace Ishiko;

int main(int argc, char* argv[])
{
    try
    {
        TestHarness::CommandLineSpecification commandLineSpec;
        Configuration configuration = commandLineSpec.createDefaultConfiguration();
        CommandLineParser::parse(commandLineSpec, argc, argv, configuration);

        TestHarness theTestHarness("Ishiko/C++ Errors Library Tests", configuration);

        TestSequence& theTests = theTestHarness.tests();
        theTests.append<ErrorCodeTests>();
        theTests.append<ErrorStringTests>();
        theTests.append<ErrorExtensionsTests>();
        theTests.append<ErrorTests>();
        theTests.append<InfoErrorExtensionTests>();
        theTests.append<ExceptionTests>();

        return theTestHarness.run();
    }
    catch (const std::exception& e)
    {
        return TestApplicationReturnCode::exception;
    }
    catch (...)
    {
        return TestApplicationReturnCode::exception;
    }
}
