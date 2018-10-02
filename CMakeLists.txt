cmake_minimum_required(VERSION 2.8)
project(Tlm2c)

include(GNUInstallDirs)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})

add_library(tlm2c STATIC
    src/environment.c
    src/genericPayload.c
    src/method.c
    src/model.c
    src/socket.c
    src/spinlock.c
)
add_library(Tlm2c::tlm2c ALIAS tlm2c)

target_compile_options(tlm2c PUBLIC -Wall -Werror -pedantic -O2)
if(NOT MINGW)
    target_compile_options(tlm2c PUBLIC -fPIC)
endif()
target_compile_options(tlm2c PUBLIC $<$<CONFIG:Debug>:-g>)

target_include_directories(tlm2c PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

install(DIRECTORY include/tlm2c DESTINATION include PATTERN "*~" EXCLUDE)
install(TARGETS tlm2c DESTINATION ${CMAKE_INSTALL_LIBDIR})

enable_testing()
add_subdirectory(tests)

