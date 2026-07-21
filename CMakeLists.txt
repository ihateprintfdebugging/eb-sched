cmake_minimum_required(VERSION 3.20)
project(ServitorICService VERSION 1.0 LANGUAGES CXX)

if(CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64")
    message(STATUS "Configuring for Jetson/ARM64")
    # Add Jetson-specific flags or link libraries here (e.g., -march=armv8-a)
endif()

if(POLICY CMP0167)
  cmake_policy(SET CMP0167 NEW)
endif() 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Handle Windows specific requirements
if(WIN32)
    add_compile_definitions(_WIN32_WINNT=0x0A00)
    # Define platform-specific libraries
    set(PLATFORM_LIBS ws2_32 mswsock)
else()
    # Linux/Unix usually requires pthread and atomic for Boost.Asio
    set(PLATFORM_LIBS pthread)
endif()

if(MSVC)
    add_compile_options(/wd4251 /wd4275)
endif()

add_executable(EBSched 
    src/main.cpp 
)

target_include_directories(EBSched PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(EBSched PRIVATE 

    ${PLATFORM_LIBS}
)