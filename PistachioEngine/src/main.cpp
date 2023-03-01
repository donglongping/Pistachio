//
// Created by dz on 2023/3/1.
//

#include <iostream>

#include "common/log/Logger.h"

#if defined(_WIN32) && !defined(IS_CONSOLE_APP)
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
#else
int main(int argc, char** argv)
#endif
{
    Logger::instance()->SetLogLevel("trace");
    LOG_DEBUG("Test: {0}, {1}", "Logger", "Singleton");



    return 0;
}