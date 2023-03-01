
file(GLOB UTILITY_SOURCES utility/*.cpp utility/*.h)
file(GLOB COMMON_SOURCES
    common/*.cpp
    common/*.h
    common/log/*.cpp
    common/log/*.h
)

file(GLOB Sources
    "*.cpp" "*.hpp" "*.c" "*.h"
    common/*.cpp
    common/*.h
    ${UTILITY_SOURCES}
    ${COMMON_SOURCES}
)

set(PROJECT PistachioSample)

set(PISTACHIO_CONSOLE_APP ON)
if (PISTACHIO_CONSOLE_APP)
    add_executable(${PROJECT} ${Sources})
    target_compile_definitions(${PROJECT} PRIVATE IS_CONSOLE_APP)
else()
    add_executable(${PROJECT} WIN32 ${Sources})
endif(PISTACHIO_CONSOLE_APP)


include_directories(./)


target_link_libraries(${PROJECT} donut_core donut_engine donut_app donut_render cxxopts)

#add_dependencies(${PROJECT} PistachioShaders)



set_target_properties(${PROJECT} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin"
    RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL "${CMAKE_BINARY_DIR}/bin"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin"
    RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_BINARY_DIR}/bin"
)