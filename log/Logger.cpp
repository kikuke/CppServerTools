#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include <sys/time.h>

#include "file.h"
#include "Logger.h"

LOGLEVEL Logger::runLevel;

const char *LogPrefix[4] = {
    "DEBUG: ",
    "WARNING: ",
    "ERROR: ",
    "INFO: "
};

Logger::Logger(const char *saveDir, const char *saveFile, const char *mode) {
    char savePath[MAX_PATH_SIZE] = {};

    if (access(saveDir, F_OK) < 0) {
        if (mkdirs(saveDir, DEFAULT_DIR_AUTH) < 0) {
            perror("mkdirs");
        }
    }

    sprintf(savePath, "%s/%s", saveDir, saveFile);
    if ((logFile = fopen(savePath, mode)) == NULL) {
        perror("fopen");
    }
}

Logger::~Logger() {
    if (fclose(logFile) <0) {
        perror("fclose");
    }
}

void Logger::LoggerSetting(LOGLEVEL runLevel) {
    Logger::runLevel = runLevel;
}

void Logger::Log(LOGLEVEL logLevel, const char* format, ...) {
    va_list args;
    size_t logLen = 0;

    if (runLevel > logLevel)
        return;
    
    SetNowTime();
    strcat(logBuffer, LogPrefix[logLevel]);

    logLen = strlen(logBuffer);
    va_start(args, format);
    vsnprintf(logBuffer + logLen, MAX_LOG_BUFFER_SIZE - logLen - 10, format, args);
    va_end(args);

    strcat(logBuffer, "\n");
    fputs(logBuffer, logFile);
    fputs(logBuffer, stdout);
}

int Logger::SetNowTime()
{
    struct timeval now;
    struct tm* tm_now;

    if(gettimeofday(&now, NULL) < 0) {
        perror("gettimeofday() Error");
        return -1;
    }
    tm_now = localtime(&now.tv_sec);

    sprintf(logBuffer, "[%02d-%02d-%02d %02d:%02d:%02d:%03ld]",
        tm_now->tm_year+1900, tm_now->tm_mon+1, tm_now->tm_mday,
        tm_now->tm_hour, tm_now->tm_min, tm_now->tm_sec, now.tv_usec);

    return 0;
}