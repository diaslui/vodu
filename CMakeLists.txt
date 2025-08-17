cmake_minimum_required(VERSION 3.10)
project(vodu)

include(FetchContent)

FetchContent_Declare(
    libdatachannel
    GIT_REPOSITORY https://github.com/paullouisageneau/libdatachannel.git
    GIT_TAG v0.23
)

FetchContent_MakeAvailable(libdatachannel)

add_executable(vodu
    src/main.cpp
    src/utils.cpp
    src/settings.cpp
)

target_link_libraries(vodu PRIVATE datachannel)
