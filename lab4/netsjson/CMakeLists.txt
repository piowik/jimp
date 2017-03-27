
project(netsjson)

set(HEDEAR_FILES Netsjson.h)
set(SOURCE_FILES Netsjson.cpp)

add_library(libnetsjson STATIC ${SOURCE_FILES})
target_include_directories(libnetsjson PUBLIC .)

add_executable(netsjson ${SOURCE_FILES} main.cpp)

target_link_libraries(netsjson libnetsjson)

