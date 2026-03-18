add_library(rc4
    lib/rc4.cpp
)

target_include_directories(rc4 PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/lib
)

add_executable(rc4_app
    src/main.cpp
)

target_link_libraries(rc4_app PRIVATE rc4)
