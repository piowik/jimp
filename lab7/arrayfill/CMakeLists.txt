
project(arrayfill)

set(HEDEAR_FILES ArrayFill.h IncrementalFill.h SquaredFill.h RandomFill.h UniformFill.h Filler.h)
set(SOURCE_FILES ArrayFill.cpp IncrementalFill.cpp SquaredFill.cpp RandomFill.cpp UniformFill.cpp Filler.cpp)

add_library(libarrayfill STATIC ${SOURCE_FILES})
target_include_directories(libarrayfill PUBLIC .)

add_executable(arrayfill ${SOURCE_FILES} main.cpp)

target_link_libraries(arrayfill libarrayfill)

