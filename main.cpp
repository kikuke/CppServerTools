#include <stdlib.h>

#include "Logger.h"

int main(void)
{
    Logger::LoggerSetting(LOGLEVEL::DEBUG);
    Logger log("../", "test");

    

    exit(0);
}