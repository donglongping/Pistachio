cmake_minimum_required(VERSION 3.10)

project(Pistachio)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W3 /MP")

    macro(replace_msvcrt var value)
        # Remove the existing /MD-type flags
        string(REGEX REPLACE "/M[TD]d?\\s*" "" ${var} ${${var}})
        # Append the new flag
        set(${var} "${${var}} ${value}")
    endmacro(replace_msvcrt)

    replace_msvcrt(CMAKE_C_FLAGS_DEBUG "/MTd")
    replace_msvcrt(CMAKE_C_FLAGS_MINSIZEREL "/MT")
    replace_msvcrt(CMAKE_C_FLAGS_RELEASE "/MT")
    replace_msvcrt(CMAKE_C_FLAGS_RELWITHDEBINFO "/MT")

    replace_msvcrt(CMAKE_CXX_FLAGS_DEBUG "/MTd")
    replace_msvcrt(CMAKE_CXX_FLAGS_MINSIZEREL "/MT")
    replace_msvcrt(CMAKE_CXX_FLAGS_RELEASE "/MT")
    replace_msvcrt(CMAKE_CXX_FLAGS_RELWITHDEBINFO "/MT")

elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GUN")

endif(MSVC)


if (WIN32)
    set(EXE_SUFFIX ".exe")
else()
    set(EXE_SUFFIX "")
endif(WIN32)

set(COMPILER_DXC "${CMAKE_CURRENT_LIST_DIR}/dxc/bin/dxc${EXE_SUFFIX}")
if (EXISTS "COMPILER_DXC")
    if (WIN32 AND NOT DXC_DXIL_EXECUTABLE)
        set(DXC_DXIL_EXECUTABLE "COMPILER_DXC" CACHE STRING "Path to DirectX Shader Compiler for DXIL output.")
    endif()
    if (NOT DXC_SPIRV_EXECUTABLE)
        set(DXC_SPIRV_EXECUTABLE "COMPILER_DXC" CACHE STRING "Path to DirectX Shader Compiler for SPIRV output.")
    endif()
endif()


set(DONUT_SHADER_OUTPUT_DIR "${CMAKE_BINARY_DIR}/bin/shaders/framework")


if (EXISTS "${CMAKE_CURRENT_LIST_DIR}/donut")
    add_subdirectory(donut)
    set(DONUT_PATH "${CMAKE_CURRENT_LIST_DIR}/donut")
endif()

option(DONUT_USE_DXIL_ON_DX12 "" ON)
option(DONUT_WITH_VULKAN "" ON)


include_directories(
    ext/spdlog/include
)

add_subdirectory(ext)
add_subdirectory(PistachioEngine)