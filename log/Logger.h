#ifndef KIKUKE_LOGGER_H
#define KIKUKE_LOGGER_H

#include <stdio.h>

#define MAX_LOG_BUFFER_SIZE 4096

enum LOGLEVEL {
    DEBUG,
    WARNING,
    ERROR,
    INFO
};

class Logger
{
private:
    static LOGLEVEL runLevel;

    FILE *logFile;
    char logBuffer[MAX_LOG_BUFFER_SIZE];

    /**
     * logBuffer에 prefix를 붙임.
     * 성공시 0, 실패시 -1 리턴
    */
    int SetNowTime();

public:
    Logger(const char *saveDir, const char *saveFile, const char *mode = "a+");
    ~Logger();

    //로그 레벨을 설정합니다.
    static void LoggerSetting(LOGLEVEL runLevel);

    //로그를 남깁니다.
    void Log(LOGLEVEL logLevel, const char *format, ...);
};

#endif