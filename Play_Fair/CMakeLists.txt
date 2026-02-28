add_library(playfair
    lib/playfair.cpp
)

target_include_directories(playfair PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/lib
)

add_executable(playfair_app
    src/main.cpp
)

target_link_libraries(playfair_app PRIVATE playfair)
