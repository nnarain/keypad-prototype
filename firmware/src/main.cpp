#include <ftl/platform/platform.hpp>
#include <ftl/logging/logger.hpp>

using namespace ftl::logging;
using namespace ftl::platform;

int main()
{
    Logger<Hardware::UART1> logger{ftl::comms::uart::BaudRate::Rate_9600};
    SystemLogger::instance().setLogger(&logger);

    auto led = Hardware::GPIOB<7>{ftl::GpioState::Output};

    auto col0 = Hardware::GPIOB<2>{ftl::GpioState::Output};
    auto row0 = Hardware::GPIOB<3>{ftl::GpioState::Input};

    col0.reset();

    for(;;)
    {
        if (!row0.read())
        {
            LOG_INFO("Pressed!");
        }
    }

    return 0;
}
