//
// Created by dz on 2023/3/1.
//

#ifndef PISTACHIO_LOGGER_H
#define PISTACHIO_LOGGER_H

#include "utility/Singleton.h"

#include <spdlog/spdlog.h>
#include <filesystem>

namespace fs = std::filesystem;

class Logger : public Singleton<Logger>
{
public:
    Logger(void);
    ~Logger();

    std::shared_ptr<spdlog::logger> GetLogger()
    {
        return m_logger;
    }

    void SetLogLevel(const std::string& level);

private:
    std::shared_ptr<spdlog::logger> m_logger;
    fs::path m_logDir = fs::current_path();
    std::string m_logNamePrefix = "log_";
    bool m_console = true;
    std::string m_level = "debug";
};

#ifdef LOG_WITH_CODE_INFO
#define LOG_TRACE(...)      SPDLOG_LOGGER_CALL(Logger::instance()->GetLogger().get(), spdlog::level::trace, __VA_ARGS__)
#define LOG_DEBUG(...)      SPDLOG_LOGGER_CALL(Logger::instance()->GetLogger().get(), spdlog::level::debug, __VA_ARGS__)
#define LOG_INFO(...)       SPDLOG_LOGGER_CALL(Logger::instance()->GetLogger().get(), spdlog::level::info, __VA_ARGS__)
#define LOG_WARN(...)       SPDLOG_LOGGER_CALL(Logger::instance()->GetLogger().get(), spdlog::level::warn, __VA_ARGS__)
#define LOG_ERROR(...)      SPDLOG_LOGGER_CALL(Logger::instance()->GetLogger().get(), spdlog::level::err, __VA_ARGS__)
#define LOG_CRITICAL(...)   SPDLOG_LOGGER_CALL(Logger::instance()->GetLogger().get(), spdlog::level::critical, __VA_ARGS__)
#else

#define LOG_TRACE(...)      Logger::instance()->GetLogger().get()->trace(__VA_ARGS__)
#define LOG_DEBUG(...)      Logger::instance()->GetLogger().get()->debug(__VA_ARGS__)
#define LOG_INFO(...)       Logger::instance()->GetLogger().get()->info(__VA_ARGS__)
#define LOG_WARN(...)       Logger::instance()->GetLogger().get()->warn(__VA_ARGS__)
#define LOG_ERROR(...)      Logger::instance()->GetLogger().get()->err(__VA_ARGS__)
#define LOG_CRITICAL(...)   Logger::instance()->GetLogger().get()->critical(__VA_ARGS__)

#endif

#endif //PISTACHIO_LOGGER_H
