add_library(gf2_10
    lib/gf2_10.cpp
)

target_include_directories(gf2_10 PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/lib
)

add_executable(gf2_10_app
    src/main.cpp
)

target_link_libraries(gf2_10_app PRIVATE gf2_10)
