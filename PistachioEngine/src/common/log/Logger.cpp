//
// Created by dz on 2023/3/1.
//

#include "Logger.h"

#include <spdlog/async.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <iostream>

Logger::Logger(void)
{
    try {
        const std::string loggerName = m_logNamePrefix + std::string("Pistachio");
        if (m_console) {
            m_logger = spdlog::stderr_color_mt(loggerName);
        } else {
            // multi part log files, with every 50M per part, max 100 files
            m_logger = spdlog::create_async<spdlog::sinks::rotating_file_sink_mt>(
                loggerName, m_logDir.append(loggerName + ".log").u8string(), 50 * 1024 * 1024, 100);
        }
    } catch (const spdlog::spdlog_ex& ex) {
        std::cout << "[Logger] Initialization Failed: " << ex.what() << std::endl;
    }
}

Logger::~Logger()
{
    spdlog::shutdown();
}

void Logger::SetLogLevel(const std::string &level)
{
    m_level = level;

    if (m_level == "trace") {
        m_logger->set_level(spdlog::level::trace);
        m_logger->flush_on(spdlog::level::trace);
    } else if (m_level == "debug") {
        m_logger->set_level(spdlog::level::debug);
        m_logger->flush_on(spdlog::level::debug);
    } else if (m_level == "info") {
        m_logger->set_level(spdlog::level::info);
        m_logger->flush_on(spdlog::level::info);
    } else if (m_level == "warn") {
        m_logger->set_level(spdlog::level::warn);
        m_logger->flush_on(spdlog::level::warn);
    } else if (m_level == "error") {
        m_logger->set_level(spdlog::level::err);
        m_logger->flush_on(spdlog::level::err);
    } else if (m_level == "critical") {
        m_logger->set_level(spdlog::level::critical);
        m_logger->flush_on(spdlog::level::critical);
    }
}
