file(GLOB_RECURSE SOURCE *.cpp)

add_executable(snake ${SOURCE})

if( CMAKE_COMPILER_IS_GNUCXX OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    target_compile_options(snake PRIVATE "-Wall")
endif()

set_target_properties(snake PROPERTIES CXX_STANDARD 17)

target_include_directories(snake PUBLIC ${CMAKE_HOME_DIRECTORY}/include)

target_link_libraries(snake ncurses)
