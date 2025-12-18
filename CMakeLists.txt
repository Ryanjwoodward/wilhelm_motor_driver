cmake_minimum_required(VERSION 3.12)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(wilhelm C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(${PROJECT_NAME}
    main.c
    src/command_handler.c
    src/motor_control.c
    src/ring_buffer.c
    src/uart_comm.c
    src/pin_definitions.c
)

target_include_directories(${PROJECT_NAME} PUBLIC
    include
)

pico_add_extra_outputs(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}
    pico_stdlib
    hardware_pwm
)
