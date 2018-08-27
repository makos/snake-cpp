file(GLOB_RECURSE TESTSRC *.cpp)
set(SOURCEDIR ${CMAKE_HOME_DIRECTORY}/src)
# .cpp files needed for tests to compile
set(SOURCES ${SOURCEDIR}/Entities/Player.cpp ${SOURCEDIR}/Entities/PlayerPart.cpp 
            ${SOURCEDIR}/Util/Point.cpp ${SOURCEDIR}/Menu/Menu.cpp
            ${SOURCEDIR}/Menu/MenuItem.cpp ${SOURCEDIR}/Renderer/Window.cpp) 

add_executable(tests ${TESTSRC} ${SOURCES})
target_include_directories(tests PUBLIC ${CMAKE_HOME_DIRECTORY}/include)
target_link_libraries(tests ncurses)