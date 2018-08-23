file(GLOB_RECURSE TESTSRC *.cpp)
set(SOURCEDIR ${CMAKE_HOME_DIRECTORY}/src)

add_executable(test ${TESTSRC} ${SOURCEDIR}/Player.cpp ${SOURCEDIR}/Point.cpp ${SOURCEDIR}/Menu/Menu.cpp ${SOURCEDIR}/Menu/MenuItem.cpp)
target_include_directories(test PUBLIC ${CMAKE_HOME_DIRECTORY}/include)